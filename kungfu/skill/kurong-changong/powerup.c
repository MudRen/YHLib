#include <ansi.h>

inherit F_CLEAN_UP;

void remove_effect(object me, int amount);

int exert(object me, object target)
{
        int skill;

        if (target != me)
                return notify_fail("��ֻ���ÿ��������������Լ���ս������\n");

        if ((int)me->query("neili") < 150)
                return notify_fail("�������������\n");

        if ((int)me->query_temp("powerup"))
                return notify_fail("���Ѿ����˹����ˡ�\n");

        skill = me->query_skill("force");
        me->add("neili", -100);
        me->receive_damage("qi", 0);

        // �������
        if ((int)me->query_skill("kurong-changong", 1) > 250)
	        message_combatd(HIG "$N" HIG "�������������ȫ��Ƥ�������һ����"
                                "��Ӥ������һ��ȴ�Ƹ������Ƥ��\n" NOR, me);
        // ȫ��
        else if ((int)me->query_skill("kurong-changong", 1) > 200)
	        message_combatd(HIC "$N" HIC "���������������������ȫ��Ƥ����"
                                "�������Ӥ����⻬����\n" NOR, me);
        // ȫ��
        else if ((int)me->query_skill("kurong-changong", 1) > 150)
	        message_combatd(YEL "$N" YEL "���������������������ȫ��Ƥ����"
                                "���������Ƥ�������ϡ�\n" NOR, me);
        // ��ݰ���
        else
	        message_combatd(HIY "$N" HIY "���������������������������ʱ��"
                                "��ȫ��\n" NOR, me);

        me->add_temp("apply/attack", skill / 3);
        me->add_temp("apply/defense", skill / 3);
        me->set_temp("powerup", 1);

        me->start_call_out((:call_other, __FILE__, "remove_effect", me,
                           skill / 3:), skill);
        if (me->is_fighting()) me->start_busy(3);
        return 1;
}

void remove_effect(object me, int amount)
{
        if (me->query_temp("powerup"))
        {
                me->add_temp("apply/attack", -amount);
                me->add_temp("apply/defense", -amount);
                me->delete_temp("powerup");
                tell_object(me, "��Ŀ�������������ϣ��������ջص��\n");
        }
}
