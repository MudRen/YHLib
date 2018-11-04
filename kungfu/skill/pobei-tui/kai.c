#include <ansi.h>
#include <combat.h>

#define KAI "��" WHT "����Ϊ��" NOR "��"

inherit F_SSERVER;

int perform(object me, object target)
{
        string msg;
        int count;
        int lvl;
        int i;

        if (userp(me) && ! me->query("can_perform/pobei-tui/kai"))
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(KAI "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (objectp(me->query_temp("weapon")))
                return notify_fail("�������ֲ���ʹ��" KAI "��\n");

        if ((int)me->query_skill("force") < 150)
                return notify_fail("����ڹ����̫ǳ������ʩչ" KAI "��\n");

        if ((lvl = (int)me->query_skill("pobei-tui", 1)) < 100)
                return notify_fail("����Ʊ��Ȳ�����죬����ʩչ" KAI "��\n");

        if (me->query_skill_mapped("unarmed") != "pobei-tui")
                return notify_fail("������û�м����Ʊ��ȣ�����ʩչ" KAI "��\n");

        if (me->query_skill_prepared("unarmed") != "pobei-tui")
                return notify_fail("������û��׼���Ʊ��ȣ�����ʩչ" KAI "��\n");

        if ((int)me->query("neili", 1) < 150)
                return notify_fail("����������̫��������ʩչ" KAI "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = WHT "ֻ��$N" WHT "������ת�����Ǽ�˫�����ǰ������߳�������糾����Ӱ��$n"
              WHT "�������֡�\n" NOR;
        me->add("neili", -100);

        if (random(me->query_skill("force") + me->query_skill("unarmed")) >
            target->query_skill("force"))
        {
                msg += HIR "$n" HIR "��������Ӱ���Լ�Ϯ����ȫȻ�ֱ�"
                       "������α��ֻ��ƴ���˶��ֵ���\n" NOR;
                count = lvl / 5;
                me->add_temp("apply/attack", count);
        } else
        {
                msg += HIC "����$n" HIC "��������������ֵ���˿����"
                       "����Ӱ�ĸ��ţ���\n" NOR;
                count = 0;
        }
        message_combatd(msg, me, target);

        for (i = 0; i < 4; i++)
        {
                if (! me->is_fighting(target))
                        break;
                COMBAT_D->do_attack(me, target, 0, 0);
        }
        me->start_busy(random(4));
        me->add_temp("apply/attack", -count);
        return 1;
}
