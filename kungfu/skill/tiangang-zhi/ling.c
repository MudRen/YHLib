#include <ansi.h>
#include <combat.h>

#define LING "��" HIC "���ָѨ" NOR "��"

inherit F_SSERVER;

int perform(object me, object target)
{
	string msg;
        int ap, dp;

        if (userp(me) && ! me->query("can_perform/tiangang-zhi/ling"))
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

	if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(LING "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if ((int)me->query_skill("force") < 150)
		return notify_fail("���ڹ���򲻹�������ʩչ" LING "��\n");

	if ((int)me->query_skill("tiangang-zhi") < 100)
		return notify_fail("������ָѨ����Ϊ����������ʩչ" LING "��\n");

	if ((int)me->query("neili") < 100)
		return notify_fail("����������ڲ���������ʩչ" LING "��\n");

	if (target->is_busy())
		return notify_fail(target->name() + "Ŀǰ���Թ˲�Ͼ���ŵ������ɡ�\n");

        if (me->query_skill_mapped("finger") != "tiangang-zhi")
                return notify_fail("��û�м������ָѨ��������ʩչ" LING "��\n");

       if (! living(target))
              return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

	msg = HIC "$N" HIC "ʹ�����ָѨ�����������ָѨ��������"
              "һ����ָ����$n" HIC "��ǰ��Ѩ����������\n" NOR;
        ap = me->query_skill("finger");
        dp = target->query_skill("dodge");
	if (ap / 2 + random(ap) > dp)
	{
		msg += HIR "���$p" HIR "�������У�ƴ�����$P"
                       HIR "ָ����ʱ�������ң�\n" NOR;
		target->start_busy((int)me->query_skill("tiangang-zhi", 1) / 22 + 2);
		me->add("neili", -100);
	} else
	{
		msg += CYN "$p" CYN "�鼱����������һԾ���˳���Զ��\n" NOR;
		me->start_busy(3);
                me->add("neili", -30);
	}
	message_combatd(msg, me, target);

	return 1;
}

