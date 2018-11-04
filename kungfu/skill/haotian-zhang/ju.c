#include <ansi.h>
#include <combat.h>

#define JU "��" HIW "�����۶�" NOR "��"

inherit F_SSERVER;

int perform(object me, object target)
{
        object weapon;
        int damage;
        string msg;

        if (userp(me) && ! me->query("can_perform/haotian-zhang/ju"))
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

        if (! target)
        {
	        me->clean_up_enemy();
	        target = me->select_opponent();
        }

	if (! target || ! me->is_fighting(target))
		return notify_fail(JU "ֻ�ܶ�ս���еĶ���ʹ�á�\n");
 
	if (objectp(me->query_temp("weapon")))
                return notify_fail(JU "ֻ�ܿ���ʩչ��\n");

        if ((int)me->query_skill("haotian-zhang", 1) < 120)
                return notify_fail("�������Ʋ�����죬����ʩչ" JU "��\n");

        if ((int)me->query_skill("force") < 180)
                return notify_fail("����ڹ���Ϊ����������ʩչ" JU "��\n");

        if (me->query_skill_mapped("strike") != "haotian-zhang")
                return notify_fail("��û�м�������Ʒ�������ʩչ" JU "��\n");

        if (me->query_skill_prepared("strike") != "haotian-zhang")
                return notify_fail("��û��׼������Ʒ�������ʩչ" JU "��\n");

        if ((int)me->query("neili") < 300)
                return notify_fail("�����ڵ��������㣬����ʩչ" JU "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = HIY "$N" HIY "���һ����������$n" HIY "���ϣ�˫��ͬʱ"
              "����������һ�С�" HIW "�����۶�" HIY "����\n" NOR;

        if (random(me->query_skill("force")) > target->query_skill("force") / 2)
        {
                me->start_busy(2);
                me->add("neili", -200);
                damage = me->query_skill("strike");
                damage = damage / 2 + random(damage / 2);
                msg += COMBAT_D->do_damage(me, target, UNARMED_ATTACK, damage, 50,
                                           HIR "���$p" HIR "��$P" HIR "��������"
                                           "�㣬��æ���ˣ�ȴ��$P" HIR "һ�ƻ�����"
                                           "�У���Ѫ��ֹ��\n" NOR);
        } else
        {
                me->start_busy(3);
                me->add("neili", -60);
                msg += CYN "����$p" CYN "ʶ����$P"
                       CYN "��һ�У�ббһԾ�ܿ���\n" NOR;
        }
        message_combatd(msg, me, target);

        return 1;
}
