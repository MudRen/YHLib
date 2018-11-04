#include <ansi.h>
#include <combat.h>

#define HONG "��" HIY "�������" NOR "��"

inherit F_SSERVER;

int perform(object me, object target)
{
	object weapon;
	string msg, wp;
        int ap, dp, damage;

        if (userp(me) && ! me->query("can_perform/dali-chu/hong"))
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

	if (! target ) target = offensive_target(me);

	if (! target || ! me->is_fighting(target))
		return notify_fail(HONG "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (! objectp(weapon = me->query_temp("weapon"))
           || (string)weapon->query("skill_type") != "hammer")
                return notify_fail("����ʹ�õ��������ԣ�����ʩչ" HONG "��\n");

        if (me->query_skill_mapped("hammer") != "dali-chu")
                return notify_fail("��û�м������ϴ����ƣ�����ʩչ" HONG "��\n");

        if ((int)me->query_skill("dali-chu", 1) < 80)
                return notify_fail("�����ϴ����ƻ���㣬����ʩչ" HONG "��\n");

        if ((int)me->query_skill("force") < 120)
                return notify_fail("����ڹ�����㣬����ʩչ" HONG "��\n");

        if ((int)me->query("max_neili") < 800)
                return notify_fail("���������Ϊ���㣬����ʩչ" HONG "��\n");

        if ((int)me->query("neili") < 200)
                return notify_fail("�����ڵ��������㣬����ʩչ" HONG "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        wp = weapon->name();

	msg = HIR "$N" HIR "�趯����" + wp + HIR "��һ�С�" HIY "�������"
              HIR "��Ю������ײ��֮����$n" HIR "��ͷ���£�\n" NOR;

	ap = me->query_skill("hammer");
	dp = target->query_skill("force");

	if (ap / 2 + random(ap) > dp)
	{
		me->add("neili", -150);
		damage = ap / 3 + random(ap / 2);
                msg += COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage, 55,
                                           HIR "$n" HIR "��$N" HIR "������ӿ����"
                                           "֪�������Ȼ������ܣ����ⴸ������"
                                           "�ڣ���Ѫ������\n" NOR);
		me->start_busy(3);

	} else
	{
		msg += CYN "����$p" CYN "��֪$P"
		       CYN "�д�һ�ţ����������мܣ��񵲿�����\n"NOR;
		me->add("neili", -100);
		me->start_busy(3);
	}
	message_combatd(msg, me, target);

	return 1;
}
