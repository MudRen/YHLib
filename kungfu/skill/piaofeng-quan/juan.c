
#include <ansi.h>

#define JUAN "��" HIW "���־�" NOR "��"

inherit F_SSERVER;

int perform(object me, object target)
{
	object weapon;
	string msg;

	if (! target) target = offensive_target(me);

        if (userp(me) && ! me->query("can_perform/piaofeng-quan/juan"))
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

	if (! target || ! me->is_fighting(target))
		return notify_fail(JUAN "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if (target->is_busy())
		return notify_fail(target->name() + "Ŀǰ���Թ˲�Ͼ���ŵ������ɣ�\n");
		
	if ((int)me->query_skill("piaofeng-quan", 1) < 30)
		return notify_fail("���Ʈ��ȭ��������죬����ʹ��" JUAN "��\n");

        if (me->query_skill_prepared("cuff") != "piaofeng-quan")
                return notify_fail("��û��׼��ʹ��Ʈ��ȭ�����޷�ʩչ" JUAN "��\n");

        if (me->query("neili") < 80)
                return notify_fail("�����������������޷�ʩչ" JUAN "��\n");

        if (! living(target))
               return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = HIC "\nֻ��$N" HIC "��ȭֱ������;�͵�һת��ͻȻ��������"
              "���죬��$n" HIC "���֣� ����Ʈ��ȭ�����С�" HIW "���־�" HIC "����\n" NOR;

        me->add("neili", -40);
	if (random(me->query_skill("cuff")) > (int)target->query_skill("force") / 2)
        {
		msg += HIR "���$p" HIR "�����мܣ�һʱȴ����"
                       "�������ã���$P" HIR "��ס����һ������ʱ����"
                       "���ȣ��������������Ȧ�ӡ�\n" NOR;
		target->start_busy((int)me->query_skill("cuff") / 22);
	} else
        {
		msg += CYN "����$p" CYN "����һ�ܣ�Ӳ��������$P"
                       CYN "��һȭ��\n" NOR;
		me->start_busy(1);
	}
	message_sort(msg, me, target);

	return 1;
}
