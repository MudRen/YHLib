// dian.c ��ָ��Ѩ

#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
	object weapon;
	string msg;
        int ap, dp;

	if (! target) target = offensive_target(me);

	if (! target || ! me->is_fighting(target))
		return notify_fail("����ָ��Ѩ��ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if (target->is_busy())
		return notify_fail(target->name() + "Ŀǰ���Թ˲�Ͼ���ŵ������ɣ�\n");
		
	if ((int)me->query_skill("sun-finger", 1) < 80)
		return notify_fail("���һ��ָ��������죬����ʹ�á���ָ��Ѩ����\n");

        if (me->query_skill_mapped("finger") != "sun-finger")
                return notify_fail("��û�м���һ��ָ��������ʹ�á���ָ��Ѩ����\n");

       if (! living(target))
              return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

	msg = HIY "$N" HIY "���񹥳�һָ���仯��ˣ��������в$n"
              HIY "���Ѩ��\n" NOR;

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
