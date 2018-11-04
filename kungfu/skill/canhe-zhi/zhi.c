#include <ansi.h>
#include <combat.h>

#define ZHI "��" HIW "����ָѨ" NOR "��"

inherit F_SSERVER;

int perform(object me, object target)
{
	object weapon;
	string msg;
        int ap, dp;
        int skill;

        if (userp(me) && ! me->query("can_perform/canhe-zhi/zhi"))
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

        if (! target)
        {
                me->clean_up_enemy();
                target = me->select_opponent();
        }

        if (! me->is_fighting(target))
                return notify_fail(ZHI "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if (target->is_busy())
		return notify_fail(target->name() + "Ŀǰ���Թ˲�Ͼ���ŵ������ɡ�\n");

        skill = me->query_skill("canhe-zhi", 1);

        if (skill < 120)
                return notify_fail("��Ĳκ�ָ��Ϊ���ޣ�����ʩչ" ZHI "��\n");

        if (me->query("neili") < 150)
                return notify_fail("�����������������ʩչ" ZHI "��\n");

        if (me->query_skill_mapped("finger") != "canhe-zhi")
                return notify_fail("��û�м����κ�ָ, ����ʩչ" ZHI "��\n");

        if (me->query_skill_prepared("finger") != "canhe-zhi")
                return notify_fail("������û��׼��ʹ�òκ�ָ, ����ʩչ" ZHI "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = HIG "$N" HIG "һ����ߣ�������ʳ��ָ��£��ббָ������$n"
              HIG "���������¡�\n" NOR;

        me->add("neili", -120);
        me->start_busy(1);
        ap = me->query_skill("finger");
        dp = target->query_skill("parry");

	if (ap * 2 / 3 + random(ap) > dp)
        {
		msg += HIR "���ֻ���������ۡ�������$p" HIR "����$P"
                       HIR "��ָ����סѨ�����������á�\n" NOR;
		target->start_busy(ap / 20 + random(4));
	} else
        {
		msg += CYN "����$p" CYN "������$P"
                       CYN "����ͼ������һԾ���㿪����һ�С�\n" NOR;
		me->start_busy(2);
	}
	message_combatd(msg, me, target);

	return 1;
}

