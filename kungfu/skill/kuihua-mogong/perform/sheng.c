// sheng.c ������Ϣ

#include <ansi.h>

inherit F_SSERVER;

#define XI "��" HIW "������Ϣ" NOR "��"

int perform(object me, object target)
{
	string msg;
        int ap, dp;

        if (userp(me) && ! me->query("can_perform/kuihua-mogong/sheng"))
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

	if (! target) target = offensive_target(me);

	if (! target || ! me->is_fighting(target))
		return notify_fail(XI "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if (target->is_busy())
		return notify_fail(target->name() + "Ŀǰ���Թ˲�Ͼ���ŵ������ɣ�\n");
		
	if ((int)me->query_skill("kuihua-mogong", 1) < 200)
		return notify_fail("��Ŀ���ħ��������񣬲���ʹ��" XI "��\n");

        if ((int)me->query("max_neili") < 3000)
                return notify_fail("���������Ϊ���㣬����ʩչ" XI "��\n");

	if (me->query("neili") < 200)
		return notify_fail("��������������޷�ʩչ" XI "��\n");

        if (me->query_skill_mapped("dodge") != "kuihua-mogong")
                return notify_fail("�㻹û�м�������ħ��Ϊ�Ṧ���޷�ʩչ" XI "��\n");            

       if (! living(target))
              return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

	msg = HIR "$N" HIR "���Ӻ������ˣ����ι����쳣����$n"
              HIR "���Ʈ��������\n" NOR;

        ap = me->query_skill("kuihua-mogong", 1) * 3 / 2 +
             me->query_skill("martial-cognize", 1);
        dp = target->query_skill("parry") +
             target->query_skill("martial-cognize", 1);

	if (ap * 3 / 5 + random(ap) > dp)
        {
		msg += HIR "���$p" HIR "ֻ�ܽ����Ż����������Գ�����\n" NOR;
		target->start_busy(ap / 45 + 2);
                me->add("neili", -120);
                me->start_busy(1);
	} else
        {
		msg += CYN "����$p" CYN "������$P" CYN "��������û"
                       "���ܵ��κ�Ӱ�졣\n" NOR;
		me->start_busy(1 + random(2));
                me->add("neili", -80);
	}
	message_combatd(msg, me, target);

	return 1;
}
