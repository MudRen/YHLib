// MODIFY BY RCWIZ 2003

#include <ansi.h>

#define FEI "��" HIG "����Ʈ��" NOR "��"

inherit F_SSERVER;

int perform(object me, object target)
{
	object weapon;
	string msg;

	if (! target) target = offensive_target(me);

        if (userp(me) && ! me->query("can_perform/huashan-zhang/piao"))
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

	if (! target || ! me->is_fighting(target))
		return notify_fail(FEI "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if (target->is_busy())
		return notify_fail(target->name() + "Ŀǰ���Թ˲�Ͼ���ŵ������ɣ�\n");
		
	if ((int)me->query_skill("huashan-zhang", 1) < 30)
		return notify_fail("��Ļ�ɽ�Ʒ�������죬����ʹ��" FEI  "��\n");

        if (me->query_skill_prepared("strike") != "huashan-zhang")
                return notify_fail("��û��׼��ʹ�û�ɽ�Ʒ����޷�ʩչ" FEI  "��\n");

        if (me->query("neili") < 60)
                return notify_fail("�����������������޷�ʩչ" FEI  "��\n");

        if (! living(target))
               return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = HIM "\n��Ȼ��$N" HIM "˫�Ʋ�������$n" HIM "������������������;�к�����"
              "�����������������������ʵʵ��Ʈ�첻�������ǻ�ɽ���С�" HIG  "����Ʈ��" HIM 
              "���� ��̽�$n" HIM "�ѱ�$N" HIM "�Ʒ����֡�\n" NOR;

        me->add("neili", -30);
	if (random(me->query_skill("cuff")) > (int)target->query_skill("force") / 2)
        {
		msg += HIR "���$p" HIR "һʱ�޷����������ʵ�����޷�ʩ�С�\n" NOR;
		target->start_busy((int)me->query_skill("strike") / 25 + 2);
	} else
        {
		msg += CYN "����$n" CYN "����������ʵ��������ᡣ\n" NOR;
		me->start_busy(1);
	}
	message_sort(msg, me, target);

	return 1;
}
