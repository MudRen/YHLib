#include <ansi.h>
#include <combat.h>

#define HUI "��" HIG "�ط�������" NOR "��"

inherit F_SSERVER;

int perform(object me, object target)
{
	object weapon;
	string msg;
        int level;

        if (userp(me) && ! me->query("can_perform/wushen-jian/hui"))
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(HUI "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if (! objectp(weapon = me->query_temp("weapon"))
           || (string)weapon->query("skill_type") != "sword")
                return notify_fail("��ʹ�õ��������ԣ�����ʩչ" HUI "��\n");

        if (target->is_busy())
                return notify_fail(target->name() + "Ŀǰ���Թ˲�Ͼ���ŵ������ɡ�\n");

        level = me->query_skill("wushen-jian", 1);

        if (level < 180)
		return notify_fail("���ɽ���񽣲�����죬����ʩչ" HUI "��\n");

        if (me->query_skill_mapped("sword") != "wushen-jian")
                return notify_fail("��û�м�����ɽ���񽣣�����ʩչ" HUI "��\n");

	if ((int)me->query_skill("force") < 250)
		return notify_fail("����ڹ�����㣬����ʩչ" HUI "��\n");

        if (me->query("neili") < 160)
                return notify_fail("�����ڵ���������������ʩչ" HUI "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

	msg = HIG "\n$N" HIG "ʹ����ɽ���񽣡�" HIC "�ط�������" HIG "����"
              "����" + weapon->name() + HIG "��Ȼ��ת�������ػع��죬��"
              "��Ϯ��$n" HIG "��" NOR;

        message_sort(msg, me, target);

        me->add("neili", -100);
        if (level / 2 + random(level) > target->query_skill("dodge", 1))
        {
		msg = HIR "�����ػؼ�$N" HIR "��ʽ��Ȼ��죬$n�ѱ�$N"
                      HIR "����Ŀ��Ͼ�ӣ���æ���ң�\n" NOR;
                target->start_busy(level / 18 + 2);
                me->start_busy(1);
	} else
        {
		msg = CYN "����$n" CYN "������$N"
                      CYN "����ͼ���򶨽��У�һ˿���ҡ�\n" NOR;
                me->start_busy(2);
	}
	message_combatd(msg, me, target);

	return 1;
}
