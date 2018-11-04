#include <ansi.h>
#include <combat.h>

#define LONG "��" HIR "��Ӱ��" NOR "��"

inherit F_SSERVER;

int perform(object me, object target)
{
	object weapon;
	string msg;
        int ap, dp;
        int level;

        if (userp(me) && ! me->query("can_perform/tie-zhang/long"))
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(LONG "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail(LONG "ֻ�ܿ���ʩչ��\n");

        if (target->is_busy())
                return notify_fail(target->name() + "Ŀǰ���Թ˲�Ͼ���ŵ������ɡ�\n");

        if ((level = (int)me->query_skill("tie-zhang", 1)) < 100)
                return notify_fail("�������Ʒ���򲻹�������ʩչ" LONG "��\n");

        if (me->query_skill_mapped("strike") != "tie-zhang")
                return notify_fail("��û�м��������Ʒ�������ʩչ" LONG "��\n");

        if (me->query_skill_prepared("strike") != "tie-zhang")
                return notify_fail("��û��׼�������Ʒ�������ʩչ" LONG "��\n");

        if ((int)me->query_skill("force") < 150)
                return notify_fail("����ڹ���Ϊ����������ʩչ" LONG "��\n");

        if ((int)me->query("max_neili") < 1500)
                return notify_fail("���������Ϊ����������ʩչ" LONG "��\n");

        if ((int)me->query("neili") < 200)
                return notify_fail("�����ڵ��������㣬����ʩչ" LONG "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = WHT "$N" WHT "˫�ƽ���ʩ�����ƾ�����" HIR "��Ӱ��" NOR +
              WHT "�����������Ӱ������$n" WHT "�ķ���\n" NOR;  

        ap = me->query_skill("strike") + me->query("str") * 5;
        dp = target->query_skill("parry") + target->query("dex") * 5;

        if (ap / 2 + random(ap) > dp)
        {
		msg += HIR "��Ӱ�ζ���$n" HIR "��ʽ��Ȼһ��������$N"
                       HIR "������ǣ������æ���ң�\n" NOR;
                target->start_busy(level / 18 + 2);
                me->start_busy(2);
                me->add("neili", -100);
	} else
        {
		msg += CYN "����$n" CYN "������$N"
                       CYN "����ͼ���򶨽��У�һ˿���ҡ�\n" NOR;
                me->start_busy(2);
                me->add("neili", -80);
	}
	message_combatd(msg, me, target);

	return 1;
}
