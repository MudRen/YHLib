#include <ansi.h>
#include <combat.h>

#define ZHUAN "��" HIW "�����ת" NOR "��"

inherit F_SSERVER;

int perform(object me, object target)
{
	object weapon;
	string msg;
	int ap, dp;
        int count;
	int i, attack_time;

        if (userp(me) && ! me->query("can_perform/taiji-jian/zhuan"))
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

	if (! target) target = offensive_target(me);

	if (! target || ! me->is_fighting(target))
                return notify_fail(ZHUAN "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if (! objectp(weapon = me->query_temp("weapon")) ||
            (string)weapon->query("skill_type") != "sword")
                return notify_fail("��ʹ�õ��������ԣ�����ʩչ" ZHUAN "��\n");

	if ((int)me->query_skill("taiji-jian", 1) < 160)
		return notify_fail("���̫������������죬����ʩչ" ZHUAN "��\n");

	if (me->query("neili") < 250)
		return notify_fail("�����������������ʩչ" ZHUAN "��\n");

        if (me->query_skill_mapped("sword") != "taiji-jian")
                return notify_fail("��û�м���̫������������ʩչ" ZHUAN "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

	msg = HIW "$N" HIW "һ����Х������" + weapon->name() +
              HIW "��������������һ����ԲȦ����$n" HIW "Ȧ�ڵ�"
              "�С�\n" NOR;

	ap = me->query_skill("sword");
	dp = target->query_skill("parry");
        attack_time = 5;
	if (ap / 2 + random(ap * 2) > dp)
	{
		msg += HIY "���$p" HIY "��$P" HIY
                       "���˸����ֲ������������˲�Ͼ��\n" NOR;
                count = ap / 10;
                me->add_temp("apply/attack", count);
                attack_time += random(ap / 45);
        } else
        {
                msg += HIC "$n" HIC "��$N" HIC "�⼸����������"
                       "�����Ҵ��⣬С��Ӧ����\n" NOR;
                count = 0;
        }
                
	message_combatd(msg, me, target);

        if (attack_time > 10)
                attack_time = 10;

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
