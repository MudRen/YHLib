#include <ansi.h>
#include <combat.h>

#define FENG "��" HIG "���־�" NOR "��"

inherit F_CLEAN_UP;
inherit F_SSERVER;

int perform(object me, object target)
{
        object weapon;
        string wp;
        int skill;

        if (userp(me) && ! me->query("can_perform/dagou-bang/feng"))
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

        if (! target) target = offensive_target(me);

        if ((int)me->query_temp("feng_zijue"))
                return notify_fail("����������ʩչ" FENG "��\n");

	if (! objectp(weapon = me->query_temp("weapon")) ||
	    (string)weapon->query("skill_type") != "staff")
                return notify_fail("��ʹ�õ��������ԣ�����ʩչ" FENG "��\n");

        skill = me->query_skill("dagou-bang", 1);

        if (skill < 120)
		return notify_fail("��򹷰���������죬����ʩչ" FENG "��\n");

        if (me->query_skill_mapped("staff") != "dagou-bang")
                return notify_fail("��û�м����򹷰���������ʩչ" FENG "��\n");

	if ((int)me->query_skill("force") < 180)
		return notify_fail("����ڹ�����㣬����ʩչ" FENG "��\n");

        if (me->query("neili") < 200)
                return notify_fail("�����ڵ���������������ʩչ" FENG "��\n");

        wp = weapon->name();

        message_combatd(HIG "$N" HIG "ʹ���򹷰�����" HIY "��"
                        HIG "���־�������" + wp + HIG "������"
                        "�����ó������Ӱ��ס����\n" NOR, me);

        me->add("neili", -150);
        me->add_temp("apply/parry", skill / 3);
        me->set_temp("feng_zijue", 1);

        me->start_call_out((: call_other, __FILE__, "remove_effect",
                              me, skill / 3 :), skill / 2);

        if (me->is_fighting())
                me->start_busy(2);

        return 1;
}

void remove_effect(object me, int amount)
{
        if ((int)me->query_temp("feng_zijue"))
        {
                me->add_temp("apply/parry", -amount);
                me->delete_temp("feng_zijue");
                tell_object(me, "���" FENG "ʩչ��ϣ��������ջص��\n");
        }
}
