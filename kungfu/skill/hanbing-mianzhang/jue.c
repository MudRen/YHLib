#include <ansi.h>
#include <combat.h>

#define FEI "��" HIG "���಻��" NOR "��"

inherit F_SSERVER;

int perform(object me, object target)
{
        string msg;
        int ap, dp;
        int attack_time, i;

        if (userp(me) && ! me->query("can_perform/hanbing-mianzhang/jue"))
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(FEI "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail(FEI "ֻ�ܿ���ʩչ��\n");

        if ((int)me->query_skill("hanbing-mianzhang", 1) < 100)
                return notify_fail("�㺮�����Ʋ�����죬����ʩչ" FEI "��\n");

        if (me->query_skill_mapped("strike") != "hanbing-mianzhang")
                return notify_fail("��û�м����������ƣ�����ʩչ" FEI "��\n");

        if (me->query_skill_prepared("strike") != "hanbing-mianzhang")
                return notify_fail("��û��׼���������ƣ�����ʩչ" FEI "��\n");

        if ((int)me->query("neili") < 250)
                return notify_fail("�����ڵ���������������ʩչ" FEI "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        ap = me->query_skill("strike");
        dp = target->query_skill("parry");

        msg = HIC "\n$N" HIC "˫�ƶ�Ȼ�����ĳ����Ʒ������ޱȣ�һ��"
              "��" HIG "���಻��" HIC "��������������$n" HIC "��\n" NOR;
        message_sort(msg, me, target);

        attack_time += 3 + random(ap / 40);

        if (attack_time > 7)
                attack_time = 7;

	me->add("neili", -attack_time * 30);
        me->add_temp("apply/attack", 10);

	for (i = 0; i < attack_time; i++)
	{
		if (! me->is_fighting(target))
			break;
                if (! target->is_busy() && random(3) == 1) 
                        target->start_busy(1);

                COMBAT_D->do_attack(me, target, 0, 0);
	}
	me->start_busy(1 + random(attack_time));
        me->add_temp("apply/attack", -10);

	return 1;
}
