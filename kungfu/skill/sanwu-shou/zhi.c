#include <ansi.h>
#include <combat.h>

#define ZHI "��" HIW "��������" NOR "��"

inherit F_SSERVER;

int perform(object me, object target)
{
	object weapon;
	string msg;
	int ap, dp;
        int count;
	int i, attack_time;

        if (userp(me) && ! me->query("can_perform/sanwu-shou/zhi"))
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

	if (! target) target = offensive_target(me);

	if (! target || ! me->is_fighting(target))
                return notify_fail(ZHI "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (! objectp(weapon = me->query_temp("weapon"))
           || (string)weapon->query("skill_type") != "whip")
                return notify_fail("����ʹ�õ��������ԣ�����ʩչ" ZHI "��\n");

	if ((int)me->query_skill("sanwu-shou", 1) < 100)
		return notify_fail("�����������ֲ�����죬����ʩչ" ZHI "��\n");

        if (me->query_skill_mapped("whip") != "sanwu-shou")
                return notify_fail("��û�м������������֣�����ʩչ" ZHI "��\n");

	if (me->query("neili") < 140)
		return notify_fail("�����ڵ���������������ʩչ" ZHI "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

	msg = HIM "\n$N" HIM "��Хһ�����ڿն���ʩ������ ��" HIW "��"
              "������" HIM "������" + weapon->name() + HIM "��������"
              "��㣬�������컨�������$nȫ�����" HIM "��" NOR;

        message_sort(msg, me, target);

	ap = me->query_skill("whip");
	dp = target->query_skill("dodge");
        attack_time = 4;

	if (ap / 2 + random(ap * 2) > dp)
	{
		msg = HIR "���$n" HIR "��$N" HIR "���˸����ֲ�����$n"
                      HIR "��æ�мܣ����нпࡣ\n" NOR;
                count = ap / 8;
                attack_time += random(ap / 45);
                me->add_temp("apply/attack", count);
        } else
        {
                msg= HIC "$n" HIC "��$N" HIC "�⼸����ʽ������������"
                     "����ֻ�ÿ���мܡ�\n" NOR;
                count = 0;
        }
	message_combatd(msg, me, target);

        if (attack_time > 7)
                attack_time = 7;

	me->add("neili", -attack_time * 20);

	for (i = 0; i < attack_time; i++)
	{
		if (! me->is_fighting(target))
			break;

	        COMBAT_D->do_attack(me, target, weapon, 0);
	}
        me->add_temp("apply/attack", -count);
	me->start_busy(1 + random(attack_time));

	return 1;
}
