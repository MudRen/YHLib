#include <ansi.h>
#include <combat.h>

#define LUO "��" HIW "��Ӣ�׷�" NOR "��"

inherit F_SSERVER;

int perform(object me, object target)
{
	object weapon;
	string msg;
	int ap, dp;
        int count;
	int i, attack_time;

        if (userp(me) && ! me->query("can_perform/shilin-jian/luo"))
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

	if (! target) target = offensive_target(me);

	if (! target || ! me->is_fighting(target))
                return notify_fail(LUO "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (! objectp(weapon = me->query_temp("weapon"))
           || (string)weapon->query("skill_type") != "sword")
                return notify_fail("����ʹ�õ��������ԣ�����ʩչ" LUO "��\n");

	if ((int)me->query_skill("shilin-jian", 1) < 120)
		return notify_fail("��ʯ�޽���������죬����ʩչ" LUO "��\n");

        if (me->query_skill_mapped("sword") != "shilin-jian")
                return notify_fail("��û�м���ʯ�޽���������ʩչ" LUO "��\n");

	if (me->query("neili") < 140)
		return notify_fail("�����ڵ���������������ʩչ" LUO "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

	msg = HIY "$N" HIY "��Хһ��������" + weapon->name() + HIY "����"
              "�������⣬������磬��������$n" HIY "��\n" NOR;

	ap = me->query_skill("sword");
	dp = target->query_skill("dodge");
        attack_time = 4;

	if (ap / 2 + random(ap * 2) > dp)
	{
		msg += HIR "���$n" HIR "��$N" HIR "���˸����ֲ�����$n"
                       HIR "��æ�мܣ����нпࡣ\n" NOR;
                count = ap / 8;
                attack_time += random(ap / 45);
                me->add_temp("apply/attack", count);
        } else
        {
                msg += HIC "$n" HIC "��$N" HIC "�⼸����ʽ������������"
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
