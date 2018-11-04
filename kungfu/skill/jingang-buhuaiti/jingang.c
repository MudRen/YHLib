#include <ansi.h>

inherit F_CLEAN_UP;

void remove_effect(object me, int amount);

int perform(object me, object target)
{
        int skill;

        if ((int)me->query("neili") < 100)
                return notify_fail("�������������\n");

        if ((int)me->query_skill("jingang-buhuaiti", 1) < 100)
                return notify_fail("��Ľ�ղ�����������Ϊ������\n");

        if ((int)me->query_temp("jingangbuhuai"))
                return notify_fail("���Ѿ������ղ����������ˡ�\n");

        skill = me->query_skill("force");
        me->add("neili", -100);
        me->receive_damage("qi", 0);

        message_combatd(HIY "ֻ��$N" HIY "�ߺ���ţ�ȫ������������Ǽ�Ƥ��������ƽ�һ�㣬�����Ӳӽ�⡣\n" NOR, me);

        me->add_temp("apply/armor", skill / 2);
        me->add_temp("apply/force", skill / 3);
        me->set_temp("jingangbuhuai", 1);

        me->start_call_out((: call_other, __FILE__, "remove_effect", me, skill :), skill);

        if (me->is_fighting()) me->start_busy(2);

        return 1;
}

void remove_effect(object me, int amount)
{
        if (me->query_temp("jingangbuhuai"))
        {
                me->add_temp("apply/armor", -(amount / 2));
                me->add_temp("apply/force", -(amount / 3));
                me->delete_temp("jingangbuhuai");
                tell_object(me, "��Ľ�ղ���������������ϣ��������ջص��\n");
        }
}
