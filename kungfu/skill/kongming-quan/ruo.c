#include <ansi.h>

#define RUO "��" HIG "��������" NOR "��"

inherit F_SSERVER;

int perform(object me, object target)
{
	int level;
	string msg;

        if (userp(me) && ! me->query("can_perform/kongming-quan/ruo"))
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(RUO "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (objectp(me->query_temp("weapon")))
                return notify_fail(RUO "ֻ�ܿ���ʩչ��\n");

        if (target->is_busy())
                return notify_fail(target->name() + "Ŀǰ���Թ˲�Ͼ���ŵ������ɡ�\n");

        if ((level = me->query_skill("kongming-quan", 1)) < 100)
                return notify_fail("��Ŀ���ȭ������죬����ʩչ" RUO "��\n");

        if (me->query_skill_mapped("unarmed") != "kongming-quan")
                return notify_fail("��û�м�������ȭ������ʩչ" RUO "��\n");

        if (me->query_skill_prepared("unarmed") != "kongming-quan")
                return notify_fail("��û��׼������ȭ������ʩչ" RUO "��\n");

        if ((int)me->query("neili", 1) < 100)
                return notify_fail("�����ڵ�����̫��������ʩչ" RUO "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

	msg = WHT "$N" WHT "ʹ������ȭ��" HIG "��������" NOR + WHT "����˫��"
              "���²�������ת���⣬��ͼ����$n" WHT "�Ĺ��ơ�\n" NOR;

        me->add("neili", -50);
        if (random(level) > (int)target->query_skill("parry", 1) / 2)
        {
		msg += HIR "���$n" HIR "��$N" HIR "��ȭ����ǣ�ƣ��м�"
                       "������ȫȻ�޷�������\n" NOR;
		target->start_busy(level / 16 + 2);
	} else
        {
		msg += CYN "����$p" CYN "������$P" CYN "����ͼ������"
                       "�㣬ȫ��Ӧ�����硣\n" NOR;
		me->start_busy(2);
	}
	message_combatd(msg, me, target);

	return 1;
}
