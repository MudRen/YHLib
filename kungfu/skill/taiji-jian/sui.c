#include <ansi.h>
#include <combat.h>

#define SUI "��" HIC "���־�" NOR "��"

inherit F_SSERVER;

inherit F_CLEAN_UP;

void remove_effect(object me, int amount);

int perform(object me)
{
	object weapon;
	int skill;
	string msg;

        if (userp(me) && ! me->query("can_perform/taiji-jian/sui"))
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

	if ((int)me->query_temp("tjj_sui"))
                return notify_fail("����������ʩչ" SUI "��\n");

	if (! objectp(weapon = me->query_temp("weapon")) ||
	    (string)weapon->query("skill_type") != "sword")
                return notify_fail("��ʹ�õ��������ԣ�����ʩչ" SUI "��\n");

	if ((int)me->query_skill("taiji-jian", 1) < 60)
		return notify_fail("���̫������������죬����ʩչ" SUI "��\n");

	if (me->query_skill_mapped("sword") != "taiji-jian") 
		return notify_fail("��û�м���̫��������������ʩչ" SUI "��\n");

	if ((int)me->query("neili") < 300)
		return notify_fail("�����ڵ��������㣬����ʩչ" SUI "��\n");

	message_combatd(HIC "$N" HIC "ʹ��̫��������" NOR + CYN "��"
                        HIC "���־�������" + weapon->name() + HIC
                        "Բת��������Ȧ����С������ס��\n" NOR, me);

	skill = me->query_skill("taiji-jian", 1);

	me->add_temp("apply/defense", skill / 3);
	me->add_temp("apply/attack", -skill / 6);
	me->set_temp("tjj_sui", 1);

	me->start_call_out((: call_other, __FILE__, "remove_effect",
                              me, skill / 3 :), skill / 3);

	me->add("neili", -100);

	if (me->is_fighting())
                me->start_busy(3);

	return 1;
}

void remove_effect(object me, int amount)
{
        if (me->query_temp("tjj_sui"))
        {
        	me->add_temp("apply/defense", -amount);
        	me->add_temp("apply/attack", amount / 2);
        	me->delete_temp("tjj_sui");
        	tell_object(me, "���" SUI "������ϣ��������ջص��\n");
        }
}

