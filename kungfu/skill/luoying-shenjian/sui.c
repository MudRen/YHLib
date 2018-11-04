#include <ansi.h>
#include <combat.h>

#define SUI "��" HIG "�沨����" NOR "��"

inherit F_SSERVER;

int perform(object me, object target)
{
	object weapon;
        int ap, dp, damage;
	string msg;

        if (userp(me) && ! me->query("can_perform/luoying-shenjian/sui"))
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

	if (! target) target = offensive_target(me);

	if (! target || ! me->is_fighting(target))
		return notify_fail(SUI "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if (! objectp(weapon = me->query_temp("weapon")) ||
	    (string)weapon->query("skill_type") != "sword")
		return notify_fail("��ʹ�õ��������ԣ�����ʩչ" SUI "��\n");

	if (target->is_busy())
		return notify_fail(target->name() + "Ŀǰ���Թ˲�Ͼ���ŵ������ɡ�\n");

	if ((int)me->query_skill("luoying-shenjian", 1) < 80)
		return notify_fail("����Ӣ�񽣲�����죬����ʩչ" SUI "��\n");

        if (me->query_skill_mapped("sword") != "luoying-shenjian")
                return notify_fail("��û�м�����Ӣ�񽣣�����ʩչ" SUI "��\n");

	if ((int)me->query_skill("force") < 100)
		return notify_fail("����ڹ�����㣬����ʩչ" SUI "��\n");

	if ((int)me->query("neili") < 100)
		return notify_fail("�����ڵ��������㣬����ʩչ" SUI "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = HIG "$N" HIG "����" + weapon->name() + HIG "��ת����Ļ���ƣ�������"
              "Χ�����������ѣ�����$n" HIG "�ķ���\n" NOR;

	me->add("neili", -80);

        ap = me->query_skill("sword");
        dp = target->query_skill("parry");

        if (ap / 2 + random(ap) > dp)

	{
		msg += HIR "$n" HIR "����͸$N" HIR "���а���������Գ��У���ʱ"
                       "��ʧ���Ȼ���\n" NOR;
		target->start_busy((int)me->query_skill("luoying-shenjian", 1) / 22 + 1);
	} else
	{
		msg += CYN "����$p" CYN "���Ų�æ�������˴���"
                       "��ʵ����û���ܵ����Ӱ�졣\n" NOR;
		me->add("neili", -100);
		me->start_busy(1);
	}
	message_combatd(msg, me, target);

	return 1;
}
