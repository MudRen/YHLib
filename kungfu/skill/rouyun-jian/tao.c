#include <ansi.h>

#define TAO "��" HIC "��������" NOR "��"

inherit F_SSERVER;
 
int perform(object me, object target)
{
	object weapon;
	string msg;

	if (! target) target = offensive_target(me);

        if (userp(me) && ! me->query("can_perform/rouyun-jian/tao"))
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

	if (! target || ! me->is_fighting(target))
	        return notify_fail(TAO "ֻ����ս���жԶ���ʹ�á�\n");

	if (! objectp(weapon = me->query_temp("weapon")) ||
              (string)weapon->query("skill_type") != "sword")
		return notify_fail("��ʹ�õ��������ԡ�\n");

	if (me->query_skill("rouyun-jian", 1) < 140)
		return notify_fail("������ƽ�����Ϊ����������ʩչ" TAO "��\n");

	if (me->query_skill("force") < 180)
		return notify_fail("����ڹ���Ϊ����������ʩչ" TAO "��\n");

	if (me->query_skill("dodge") < 180)
		return notify_fail("����Ṧ��Ϊ����������ʩչ" TAO "��\n");

	if (me->query("neili") < 200)
		return notify_fail("�����������������ʩչ" TAO "��\n");

        if (me->query_skill_mapped("sword") != "rouyun-jian")
                return notify_fail("��û�м������ƽ���������ʩչ" TAO "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

	msg = HIC "$N" HIC "ʹ�����ƽ������������¡���һ��֮���������У�����"
              "�ǵ�����$n" HIC "��\n" NOR;
        message_combatd(msg, me, target);
	me->add("neili", -150);

        me->add_temp("apply/attack", 40);
      	COMBAT_D->do_attack(me, target, weapon, 0);

        me->add_temp("apply/attack", 60);
	COMBAT_D->do_attack(me, target, weapon, 0);

        me->add_temp("apply/attack", 80);
	COMBAT_D->do_attack(me, target, weapon, 0);

        me->add_temp("apply/attack", -180);
	me->start_busy(1 + random(3));
	return 1;
}
