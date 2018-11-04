#include <ansi.h>
#include <combat.h>

#define JUE "��" HIR "����һ��" NOR "��"

inherit F_SSERVER;
 
int perform(object me, object target)
{
	string msg;
	int ap, dp, pp;
        int damage;

        if (userp(me) && ! me->query("can_perform/jueming-tui/jue"))
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

        if (! target)
        {
        	me->clean_up_enemy();
        	target = me->select_opponent();
        }

        if (! target || ! me->is_fighting(target))
                return notify_fail(JUE "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail(JUE "ֻ�ܿ���ʩչ��\n");

	if (me->query_skill("jueming-tui", 1) < 80)
                return notify_fail("������ȷ�������죬����ʩչ" JUE "��\n");

        if (me->query_skill_mapped("unarmed") != "jueming-tui")
                return notify_fail("��û�м��������ȷ�������ʩչ" JUE "��\n");
 
        if (me->query_skill_prepared("unarmed") != "jueming-tui")
                return notify_fail("��û��׼�������ȷ�������ʩչ" JUE "��\n");

        if (me->query("neili") < 200)
                return notify_fail("��Ŀǰ����������������ʩչ" JUE "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        switch (random(3))
        {
        case 0:
	        msg = HIR "ֻ��$N" HIR "һ����ߣ�������ߣ����Ⱥ�"
                      "ɨ��$n" HIR "�������������ɵ���\n" NOR;
                break;

        case 1:
                msg = HIR "$N" HIR "��ش��һ�����������߶�����ֱ"
                      "��$n" HIR "���ʣ���ʽ��ΪѸ�͡�\n" NOR;
                break;

        default:
                msg = HIR "ͻȻֻ��$N" HIR "˫�������߳���Ю������"
                      "��������ǧ��֮��ɨ��$n" HIR "��\n" NOR;
                break;
        }
 
	ap = me->query_skill("unarmed") + me->query("str") * 10;
	dp = target->query_skill("dodge") + target->query("dex") * 10;
	pp = target->query_skill("parry") + target->query("str") * 10;

        if (ap * 7 / 10 + random(ap) < pp)
        {
                msg += HIC "����$n" HIC "����һ�Σ�Ӳ������ס��$N"
                       HIC "��һ�ȡ�\n" NOR;
                me->start_busy(3);
                me->add("neili", -30);
        } else
        if (ap * 7 / 10 + random(ap) < dp)
        {
		msg += CYN "ȴ��$n" CYN "�򶨵����һ�ݣ�������$N"
                       CYN "��һ�ȡ�\n" NOR;
                me->start_busy(3);
                me->add("neili", -30);
        } else
	{
                damage = ap / 3 + random(ap / 3);
                msg += COMBAT_D->do_damage(me, target, UNARMED_ATTACK, damage, 60,
                                           HIR "$n" HIR "��æ�񵲣�ȴֻ����������"
                                           "�ó��棬��ʱ��һ���ߵ÷���\n" NOR);
                me->start_busy(2);
                me->add("neili", -100);
	}
	message_combatd(msg, me, target);
	return 1;
}
