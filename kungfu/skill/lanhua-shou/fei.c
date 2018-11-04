#include <ansi.h>
#include <combat.h>

#define FEI "��" HIC "Ӱ��ɻ�" NOR "��"

inherit F_SSERVER;

int perform(object me, object target)
{
        string msg;
        mapping p;
        int i, af, lvl, count;

        if (userp(me) && ! me->query("can_perform/lanhua-shou/fei"))
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(FEI "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (objectp(me->query_temp("weapon")))
                return notify_fail(FEI "ֻ�ܿ���ʩչ��\n");

        if ((lvl = (int)me->query_skill("lanhua-shou", 1)) < 140)
                return notify_fail("��������Ѩ�ֲ�����죬����ʩչ" FEI "��\n");

        if (me->query_skill_mapped("hand") != "lanhua-shou")
                return notify_fail("��û�м���������Ѩ�֣�����ʩչ" FEI "��\n");

        if (! mapp(p = me->query_skill_prepare())
           || p["hand"] != "lanhua-shou")
                return notify_fail("��û��׼��������Ѩ�֣�����ʩչ" FEI "��\n");

        if ((int)me->query("neili") < 300)
                return notify_fail("�������������㣬����ʩչ" FEI "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = HIC "$N" HIC "΢һ����˫��������״����������һ�����ľ�����ʱֱ��$n"
              HIC "ȫ�����ҪѨ��\n" NOR;
        me->add("neili", -150);

        if (random(me->query_skill("parry") + me->query_skill("hand")) >
            target->query_skill("parry"))
        {
                msg += HIR "$n" HIR "��ʱ�����ۻ����ң�ȫȻ�ֱ�"
                       "������α��ֻ��ƴ���˶��ֵ���\n" NOR;
                count = lvl / 5;
                me->add_temp("apply/attack", count);
        } else
        {
                msg += HIY "����$n" HIY "��������������ֵ���˿"
                       "��������Ӱ�ĸ��ţ���\n" NOR;
                count = 0;
        }
        message_combatd(msg, me, target);

        af = member_array("hand", keys(p));

        for (i = 0; i < 6; i++)
        {
                if (! me->is_fighting(target))
                        break;

                me->set_temp("action_flag", af);
                COMBAT_D->do_attack(me, target, 0, 0);
        }
        me->start_busy(random(3));
        me->add_temp("apply/attack", -count);
        return 1;
}
