// feng.c ����ȭ������֡�

#include <ansi.h>

#define FENG "��" HIG "�����" NOR "��"

inherit F_SSERVER;

int perform(object me, object target)
{
	object weapon;
	string msg;

	if (! target) target = offensive_target(me);

        if (userp(me) && ! me->query("can_perform/poyu-quan/feng"))
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

	if (! target || ! me->is_fighting(target))
		return notify_fail(FENG "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if (target->is_busy())
		return notify_fail(target->name() + "Ŀǰ���Թ˲�Ͼ���ŵ������ɣ�\n");
		
	if ((int)me->query_skill("poyu-quan", 1) < 60)
		return notify_fail("�����ʯ����ȭ������죬����ʹ��" FENG "��\n");

        if (me->query_skill_prepared("cuff") != "poyu-quan")
                return notify_fail("��û��׼��ʹ����ʯ����ȭ���޷�ʩչ" FENG "��\n");

        if (me->query("neili") < 80)
                return notify_fail("�����������������޷�ʩչ" FENG "��\n");

       if (! living(target))
              return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = HIC "\nֻ��$N" HIC "������̽����ȭ쬵�һ�����Ʒ���"
              "�ʹ�������������ʯ����ȭ���ľ���֮һ��" HIG "�����" HIC "����\n" NOR;

        me->add("neili", -40);
	if (random(me->query_skill("cuff")) > (int)target->query_skill("force") / 2)
        {
		msg += HIR "���$p" HIR "�����мܣ�һʱȴ����"
                       "�������ã���$P" HIR "��ס����һ������ʱ����"
                       "���ȣ��������������Ȧ�ӡ�\n" NOR;
		target->start_busy((int)me->query_skill("cuff") / 20 + 2);
	} else
        {
		msg += CYN "����$p" CYN "����һ�ܣ�Ӳ��������$P"
                       CYN "��һȭ��\n" NOR;
		me->start_busy(1);
	}
	message_sort(msg, me, target);

	return 1;
}
