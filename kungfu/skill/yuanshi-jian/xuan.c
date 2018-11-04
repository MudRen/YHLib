#include <ansi.h>
#include <combat.h>

#define XUAN "��" HIW "������ת" NOR "��"

inherit F_SSERVER;

int perform(object me, object target)
{
	object weapon;
	string msg;
	int ap, dp;
        int count;
	int i, attack_time;

        if (userp(me) && ! me->query("can_perform/yuanshi-jian/xuan"))
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

	if (! target) target = offensive_target(me);

	if (! target || ! me->is_fighting(target))
                return notify_fail(XUAN "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if (! objectp(weapon = me->query_temp("weapon")) ||
            (string)weapon->query("skill_type") != "sword")
                return notify_fail("��ʹ�õ��������ԣ�����ʩչ" XUAN "��\n");

	if ((int)me->query_skill("yuanshi-jian", 1) < 180)
		return notify_fail("���ԭʼ����������죬����ʩչ" XUAN "��\n");

	if (me->query("neili") < 400)
		return notify_fail("�����������������ʩչ" XUAN "��\n");

        if (me->query_skill_mapped("sword") != "yuanshi-jian")
                return notify_fail("��û�м���ԭʼ����������ʩչ" XUAN "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

	msg = HIW "$N" HIW "һ������" + weapon->name() + HIW "��������佣������"
              "��ӿ��$n" HIW"�����糱ˮ��һ�˸߹�һ�ˡ�\n" NOR;

	ap = me->query_skill("sword");
	dp = target->query_skill("force");
        attack_time = 5;
	if (ap / 2 + random(ap * 2) > dp)
	{
		msg += HIR "$n" HIR "��ʱֻ����ͷ��Ŀѣ��������ת��һʱ"
                       "�����мܡ�\n" NOR;
                count = ap / 16;
                me->add_temp("apply/attack", count);
                attack_time += random(ap / 45);
        } else
        {
                msg += HIC "$n" HIC "��$N" HIC "������ӿ����æ����ֵ�"
                       "����Ϊ������\n" NOR;
                count = 0;
        }
                
	message_combatd(msg, me, target);

        if (attack_time > 7)
                attack_time = 7;

	me->add("neili", -attack_time * 30);

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
