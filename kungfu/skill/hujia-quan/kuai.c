#include <ansi.h>
#include <combat.h>

#define KUAI "��" WHT "��ȭ���" NOR "��"

inherit F_SSERVER;

int perform(object me, object target)
{
	object weapon;
	string msg;

        if (userp(me) && ! me->query("can_perform/hujia-quan/kuai"))
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

	if (! target) target = offensive_target(me);

	if (! target || ! me->is_fighting(target))
		return notify_fail(KUAI "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail(KUAI "ֻ�ܿ���ʩչ��\n");

	if (target->is_busy())
		return notify_fail(target->name() + "Ŀǰ���Թ˲�Ͼ���ŵ������ɡ�\n");

	if ((int)me->query_skill("force") < 100)
		return notify_fail("����ڹ�����㣬����ʩչ" KUAI "��\n");

	if ((int)me->query_skill("hujia-quan", 1) < 80)
		return notify_fail("��ĺ���ȭ��������죬����ʩչ" KUAI "��\n");

        if (me->query_skill_mapped("cuff") != "hujia-quan")
                return notify_fail("��û�м�������ȭ��������ʩչ" KUAI "��\n");

        if (me->query_skill_prepared("cuff") != "hujia-quan")
                return notify_fail("��û��׼������ȭ��������ʩչ" KUAI "��\n");

        if (me->query("neili") < 80)
                return notify_fail("��������������������ʩչ" KUAI "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

	msg = WHT "$N" WHT "�ݲ���ǰ��ȭ�е��������籼�ף���ʱ����$n" WHT "������ȭ��\n" NOR;

        me->add("neili", -40);
	if (random(me->query("combat_exp")) > (int)target->query("combat_exp") / 3)
        {
		msg += HIR "���$n" HIR "�޷�����$N" HIR "��ʽ�е���ʵ��"
                       "������æ���ҡ�\n" NOR;
		target->start_busy((int)me->query_skill("cuff") / 25 + 2);
	} else
        {
		msg += CYN "����$p" CYN "������$P" CYN "�����У�����һ����"
                       "�ܿ�����������ȭӰ��\n" NOR;
		me->start_busy(2);
	}
	message_combatd(msg, me, target);

	return 1;
}
