#include <ansi.h>
#include <combat.h>

#define CHAN "��" HIW "���־�" NOR "��"

inherit F_SSERVER;

int perform(object me, object target)
{
	string msg;
        object weapon;

        if (userp(me) && ! me->query("can_perform/yunlong-bian/chan"))
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

	if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(CHAN "ֻ����ս���жԶ���ʹ�á�\n");

        if (! objectp(weapon = me->query_temp("weapon"))
           || weapon->query("skill_type") != "whip")
                return notify_fail("��ʹ�õ��������ԣ�����ʩչ" CHAN "��\n");

	if ((int)me->query_skill("yunlong-bian",1) < 50)
		return notify_fail("�������޷����̫ǳ������ʩչ" CHAN "��\n");

        if (me->query_skill_mapped("whip") != "yunlong-bian")
                return notify_fail("��û�м��������޷�������ʩչ" CHAN "��\n");

	if (target->is_busy())
                return notify_fail(target->name() + "Ŀǰ���Թ˲�Ͼ���ŵ������ɡ�\n");

        if ((int)me->query("neili") < 50)
                return notify_fail("�����ڵ��������㣬����ʩչ" CHAN "��\n");

        if (! living(target))
               return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

	msg = WHT "$N" WHT "ʹ�������޷��������־�������" + weapon->name() +
              WHT"��ͼ��$n"  WHT "��ȫ���ס��\n" NOR;

	if (random(me->query_skill("whip")) > target->query_skill("parry") / 2)
        {
		msg += HIR "���$p" HIR "��ʱ��$P" HIR "�ı������β�ס��"
                       "���ô��ֲ�����\n" NOR;
		target->start_busy((int)me->query_skill("whip") / 22 + 1);
	} else
        {
		msg += CYN "����$p" CYN "������$P" CYN "����ͼ����û����"
                "����\n" NOR;
	}
        me->add("neili", -30);
	me->start_busy(2);
	message_combatd(msg, me, target);
	return 1;
}
