#include <ansi.h>
#include <combat.h>

#define DIAN "��" HIR "��ָ��Ѩ" NOR "��"

inherit F_SSERVER;

int perform(object me, object target)
{
	object weapon;
	string msg;
        int ap, dp;
        if (userp(me) && ! me->query("can_perform/yiyang-zhi/dian"))
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(DIAN "ֻ�ܶ�ս���еĶ���ʹ�á�\n");
 
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail(DIAN "ֻ�ܿ���ʩչ��\n");

        if ((int)me->query_skill("yiyang-zhi", 1) < 120)
                return notify_fail("��һ��ָ��������죬����ʩչ" DIAN "��\n");

        if ((int)me->query_skill("jingluo-xue", 1) < 120)
                return notify_fail("��Ծ���ѧ�˽ⲻ��������ʩչ" DIAN "��\n");

        if (me->query_skill_mapped("finger") != "yiyang-zhi")
                return notify_fail("��û�м���һ��ָ��������ʩչ" DIAN "��\n");

        if (me->query_skill_prepared("finger") != "yiyang-zhi")
                return notify_fail("��û��׼��һ��ָ��������ʩչ" DIAN "��\n");

        if ((int)me->query_skill("force") < 160)
                return notify_fail("����ڹ���򲻹�������ʩչ" DIAN "��\n");

        if (me->query("max_neili") < 1800)
                return notify_fail("���������Ϊ���㣬����ʩչ" DIAN "��\n");

        if ((int)me->query("neili") < 200)
                return notify_fail("�����ڵ���������������ʩչ" DIAN "��\n");

        if (target->is_busy())
                return notify_fail(target->name() + "Ŀǰ���Թ˲�Ͼ���ŵ������ɡ�\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

	msg = HIR "$N" HIR "����һ��ָ����������Ȼ���һָ���仯��ˣ��ɱ�$n"
              HIR "���Ѩ��\n" NOR;

        ap = me->query_skill("finger");
        dp = target->query_skill("parry");
	if (ap / 2 + random(ap) > dp)
        {
		msg += HIR "���$p" HIR "��$P" HIR "�Ƶ���"
                       "�ܲ�����һʱ�޷�������\n" NOR;
		target->start_busy((int)me->query_skill("finger") / 20 + 2);
	} else
        {
		msg += CYN "����$p" CYN "������$P" CYN "�ı仯��"
                       "С���мܣ���ס��$P" CYN "�Ľ�����\n" NOR;
		me->start_busy(1);
	}
	message_combatd(msg, me, target);

	return 1;
}
