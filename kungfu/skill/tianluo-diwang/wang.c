#include <ansi.h>

#define WANG "��" HIW "���޵���" NOR "��"

inherit F_SSERVER;

int perform(object me, object target)
{
	object weapon;
	int level;
	string msg;

	if (! target) target = offensive_target(me);

        if (userp(me) && ! me->query("can_perform/tianluo-diwang/wang"))
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

	if (! target || ! me->is_fighting(target))
		return notify_fail(WANG "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if (me->query_temp("weapon"))
		return notify_fail("�������ֲ���ʩչ" WANG "��\n");

	if (target->is_busy())
		return notify_fail(target->name() + "Ŀǰ���Թ˲�Ͼ���ŵ������ɣ�\n");
		
	if ((level = me->query_skill("tianluo-diwang", 1)) < 60)
		return notify_fail("������޵����ƻ�������죬�޷�ʩչ" WANG "��\n");

	if (me->query_skill("dodge") < 40)
		return notify_fail("����Ṧ��Ϊ�������޷�ʩչ" WANG "��\n");

        if (me->query_skill_prepared("strike") != "tianluo-diwang")
                return notify_fail("��û��׼�����޵����ƣ�����ʩչ" WANG "��\n");

        if (me->query("neili") < 70)
                return notify_fail("�����������������޷�ʹ��" WANG "��\n");

        if (! living(target))
               return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

	msg = HIG "\n$N" HIG "˫��������û���������Ӱ����$n" HIG "�������֡�" NOR;
        message_sort(msg, me, target);

        me->add("neili", -60);
        if (random(level) > (int)target->query_skill("dodge", 1) / 2)
        {
		msg = HIR "���$p" HIR "��$P" HIR "ѹ�Ƶ����Է�����"
                      "ֻ�ܽ����ֵ���\n" NOR;

		target->start_busy(level / 16 + 2);
                me->start_busy(2 + random(2));
	} else
        {
		msg = CYN "����$p" CYN "����һ����Ծ��$P" CYN "������"
                      "�����ķ�Χ��\n" NOR;

		me->start_busy(1);
	}
	message_vision(msg, me, target);

	return 1;
}
