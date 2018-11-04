#include <ansi.h>
#include <combat.h>

#define CHAN "��" HIG "���־�" NOR "��"

inherit F_SSERVER;

int perform(object me, object target)
{
	object weapon;
	string msg;
        int level;

        if (userp(me) && ! me->query("can_perform/dagou-bang/chan"))
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(CHAN "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if (! objectp(weapon = me->query_temp("weapon")) ||
	    (string)weapon->query("skill_type") != "staff")
                return notify_fail("��ʹ�õ��������ԣ�����ʩչ" CHAN "��\n");

        if (target->is_busy())
                return notify_fail(target->name() + "Ŀǰ���Թ˲�Ͼ���ŵ������ɡ�\n");

        level = me->query_skill("dagou-bang", 1);

        if (level < 60)
		return notify_fail("��򹷰���������죬����ʩչ" CHAN "��\n");

        if (me->query_skill_mapped("staff") != "dagou-bang")
                return notify_fail("��û�м����򹷰���������ʩչ" CHAN "��\n");

	if ((int)me->query_skill("force") < 100)
		return notify_fail("����ڹ�����㣬����ʩչ" CHAN "��\n");

        if (me->query("neili") < 100)
                return notify_fail("�����ڵ���������������ʩչ" CHAN "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

	msg = HIG "$N" HIG "ʹ���򹷰�����" HIC "��" HIG "���־�����ͷ��"
              "�������㣬���಻��������$n" HIG "��С�Ⱥͽ��ס�\n" NOR;

        me->add("neili", -50);
        if (level / 2 + random(level) > target->query_skill("dodge", 1))
        {
		msg += HIR "��Ӱ�ܶ���$n" HIR "��ʽ��Ȼһ�����ѱ�$N"
                       HIR "���ı�����ͣ����æ���ң�\n" NOR;
                target->start_busy(level / 18 + 2);
                me->start_busy(1);
	} else
        {
		msg += CYN "����$n" CYN "������$N"
                       CYN "����ͼ���򶨽��У�һ˿���ҡ�\n" NOR;
                me->start_busy(2);
	}
	message_combatd(msg, me, target);

	return 1;
}
