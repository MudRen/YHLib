#include <ansi.h>
#include <combat.h>

#define PIAO "��" HIW "����Ʈ��" NOR "��"

inherit F_SSERVER;

int perform(object me, object target)
{
        string msg;
        int count;
        int lvl;
        int i;

        if (userp(me) && ! me->query("can_perform/piaoxu-zhang/piao"))
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(PIAO "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (objectp(me->query_temp("weapon")))
                return notify_fail(PIAO "ֻ�ܿ���ʩչ��\n");

        if ((lvl = (int)me->query_skill("piaoxu-zhang", 1)) < 80)
                return notify_fail("��Ʈ���Ʒ�������죬����ʩչ" PIAO "��\n");

        if (me->query_skill_mapped("strike") != "piaoxu-zhang")
                return notify_fail("��û�м���Ʈ���Ʒ�������ʩչ" PIAO "��\n");

        if (me->query_skill_prepared("strike") != "piaoxu-zhang")
                return notify_fail("��û��׼��Ʈ���Ʒ�������ʩչ" PIAO "��\n");

        if ((int)me->query("neili") < 100)
                return notify_fail("�������������㣬����ʩչ" PIAO "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = HIW "$N" HIW "΢΢һЦ������ʩ��Ʈ���Ʒ�����������Ʈ�㡹����ʱ��"
              "Ӱ���أ���ʵ�ѱ棬ȫȫ����$n" HIW "��ȥ��\n" NOR;
        me->add("neili", -50);

        if (random(me->query_skill("force") + me->query_skill("strike")) >
            target->query_skill("force"))
        {
                msg += HIR "$n" HIR "��ʱ�����ۻ����ң�ȫȻ�ֱ�"
                       "������α��ֻ��ƴ���˶��ֵ���\n" NOR;
                count = lvl / 5;
                me->add_temp("apply/attack", count);
        } else
        {
                msg += HIC "����$n" HIC "��������������ֵ���˿"
                       "��������Ӱ�ĸ��ţ���\n" NOR;
                count = 0;
        }
        message_combatd(msg, me, target);

        for (i = 0; i < 3; i++)
        {
                if (! me->is_fighting(target))
                        break;
                COMBAT_D->do_attack(me, target, 0, 0);
        }
        me->start_busy(random(3));
        me->add_temp("apply/attack", -count);
        return 1;
}
