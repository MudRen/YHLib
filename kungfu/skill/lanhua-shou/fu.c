#include <ansi.h>
#include <combat.h>

#define FU "��" HIC "������Ѩ" NOR "��"

inherit F_SSERVER;

int perform(object me, object target)
{
	string msg;
        int ap, dp;

        if (userp(me) && ! me->query("can_perform/lanhua-shou/fu"))
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(FU "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (objectp(me->query_temp("weapon")))
                return notify_fail(FU "ֻ�ܿ���ʩչ��\n");

        if (target->is_busy())
                return notify_fail(target->name() + "Ŀǰ���Թ˲�Ͼ���ŵ������ɡ�\n");

        if ((int)me->query_skill("lanhua-shou", 1) < 120)
                return notify_fail("��������Ѩ�ֲ�����죬����ʩչ" FU "��\n");

        if ((int)me->query_skill("jingluo-xue", 1) < 120)
                return notify_fail("��Ծ���ѧ���˽ⲻ��������ʩչ" FU "��\n");

        if (me->query_skill_mapped("hand") != "lanhua-shou")
                return notify_fail("��û�м���������Ѩ�֣�����ʩչ" FU "��\n");

        if (me->query_skill_prepared("hand") != "lanhua-shou")
                return notify_fail("��û��׼��������Ѩ�֣�����ʩչ" FU "��\n");

        if ((int)me->query("neili") < 100)
                return notify_fail("�������������㣬����ʩչ" FU "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

	msg = HIC "$N" HIC "�������������ָ����ת��һ��ʢ�������������$n"
              HIC "в��ҪѨ��\n";

        ap = me->query_skill("hand");
        dp = target->query_skill("parry") / 2;
	if (ap / 2 + random(ap) > dp)
	{
		msg +=  HIR "$p" HIR "ֻ��в��һ�飬�ѱ�$P"
                        HIR "������ţ���ʱȫ����������������\n" NOR;
		target->start_busy(ap / 30 + 2);
		me->add("neili", -100);
                me->start_busy(1);
	} else
	{
		msg += CYN "����$p" CYN "������$P" CYN
		       "����ͼ������һԾ�����˿�ȥ��\n" NOR;
		me->start_busy(2);
	}
	message_combatd(msg, me, target);

	return 1;
}
