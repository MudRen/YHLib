#include <ansi.h>
#include <combat.h>

#define FAN "��" HIW "����������" NOR "��"

inherit F_SSERVER;

int perform(object me, object target)
{
        string msg;
        int count;
        int lvl;
        int i;

        if (userp(me) && ! me->query("can_perform/youshen-zhang/fan"))
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(FAN "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail(FAN "ֻ�ܿ���ʩչ��\n");

        if ((int)me->query_skill("force") < 160)
                return notify_fail("����ڹ���Ϊ����������ʩչ" FAN "��\n");

        if ((lvl = (int)me->query_skill("youshen-zhang", 1)) < 120)
                return notify_fail("�����������Ʋ�����죬����ʩչ" FAN "��\n");

        if (me->query_skill_mapped("unarmed") != "youshen-zhang")
                return notify_fail("��û�м�����������ƣ�����ʩչ" FAN "��\n");

        if (me->query_skill_prepared("unarmed") != "youshen-zhang")
                return notify_fail("��û��׼����������ƣ�����ʩչ" FAN "��\n");

        if ((int)me->query("neili") < 200)
                return notify_fail("��������������������ʩչ" FAN "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = HIW "ֻ��$N" HIW "��̤�����ķ�֮λ��������ȫ�����߲�����˫������"
              "�Ķ���������������$n" HIW "��\n" NOR;
        me->add("neili", -150);

        if (random(me->query_skill("force") + me->query_skill("bazhen-zhang")) >
            target->query_skill("force"))
        {
                msg += HIR "$n" HIR "��ʱ���ú���������ȫȻ��$N"
                       HIR "�����ֵ��������ƣ�ֻ��ƴ���˶��ֵ�"
                       "��\n" NOR;
                count = lvl / 5;
                me->add_temp("apply/attack", count);
        } else
        {
                msg += HIC "$n" HIC "����һ����������ֵ�������"
                       "��Χ$N" HIC "��Ӱ���أ�$p" HIC "ȴ����Σ"
                       "���ң��򶨲��С�\n" NOR;
                count = 0;
        }
        message_combatd(msg, me, target);

        for (i = 0; i < 6; i++)
        {
                if (! me->is_fighting(target))
                        break;
                COMBAT_D->do_attack(me, target, 0, 0);
        }
        me->start_busy(1 + random(6));
        me->add_temp("apply/attack", -count);
        return 1;
}
