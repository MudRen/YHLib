#include <ansi.h>
#include <combat.h>

#define ZHEN "��" HIR "�����" NOR "��"

inherit F_SSERVER;
 
int perform(object me, object target)
{
	object weapon;
        string msg;
        int i;
 
        if (userp(me) && ! me->query("can_perform/xiangmo-chu/zhen"))
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

        if (! target)
        {
	        me->clean_up_enemy();
	        target = me->select_opponent();
        }

        if (! target || ! me->is_fighting(target))
                return notify_fail(ZHEN "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (! objectp(weapon = me->query_temp("weapon"))
           || (string)weapon->query("skill_type") != "hammer")
                return notify_fail("����ʹ�õ��������ԣ�����ʩչ" ZHEN "��\n");

        if (me->query_skill_mapped("hammer") != "xiangmo-chu")
                return notify_fail("��û�м�����ս�ħ�ƣ�����ʩչ" ZHEN "��\n");

	if ((int)me->query_skill("xiangmo-chu", 1) < 100)
		return notify_fail("���ս�ħ�ƻ���㣬����ʩչ" ZHEN "��\n");

        if ((int)me->query_skill("force") < 150)
                return notify_fail("����ڹ�����㣬����ʩչ" ZHEN "��\n");

        if ((int)me->query("neili") < 200)
                return notify_fail("�����ڵ��������㣬����ʩչ" ZHEN "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

	msg = HIY "$N" HIY "һ���Ϻȣ�ʩ����" HIR "�����" HIY "������������"
              "ׯ�ϣ�������ǧ������" + weapon->name() + HIY "��$n" HIY "����"
              "���¡�\n" NOR;
	message_combatd(msg, me, target);

	me->add("neili", -150);

        for (i = 0; i < 5; i++)
        {
                if (! me->is_fighting(target))
                        break;
        	COMBAT_D->do_attack(me, target, weapon, 0);
        }

	me->start_busy(1 + random(5));
	return 1;
}
