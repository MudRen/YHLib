#include <ansi.h>
#include <combat.h>

#define KUANG "��" HIY "������" NOR "��"

inherit F_SSERVER;
 
int perform(object me, object target)
{
	object weapon;
        string msg;
	int i;

        if (userp(me) && ! me->query("can_perform/xuanfeng-tui/kuang"))
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

	if (! target)
	{
		me->clean_up_enemy();
	        target = me->select_opponent();
	}

        if (! target || ! me->is_fighting(target))
                return notify_fail(KUANG "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail(KUANG "ֻ�ܿ���ʩչ��\n");

        if ((int)me->query_skill("xuanfeng-tui", 1) < 100)
                return notify_fail("������ɨҶ�Ȳ�����죬����ʩչ" KUANG "��\n");

        if ((int)me->query_skill("xuanfeng-tui", 1) < 100)
                return notify_fail("�������ɨҶ�Ȳ�����죬����ʩչ" KUANG "��\n");

        if (me->query_skill_mapped("unarmed") != "xuanfeng-tui")
                return notify_fail("��û�м�������ɨҶ�ȣ�����ʩչ" KUANG "��\n");

        if (me->query_skill_prepared("unarmed") != "xuanfeng-tui")
                return notify_fail("��û��׼������ɨҶ�ȣ�����ʩչ" KUANG "��\n");

        if (me->query("neili") < 300)
                return notify_fail("�����������������ʩչ" KUANG "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

	msg = HIY "$N" HIY "ʹ���һ�������������Ʈ������������糾����Я"
              "������������ɣ�\n" NOR;
	message_combatd(msg, me);
	me->add("neili", -100);

	for (i = 0; i < 6; i++)
	{
		if (! me->is_fighting(target))
			break;
                if (random(3) == 0 && ! target->is_busy())
                        target->start_busy(1);
		COMBAT_D->do_attack(me, target, 0, 0);
	}

	me->start_busy(1 + random(6));
	return 1;
}
