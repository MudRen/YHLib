#include <ansi.h>

inherit F_CLEAN_UP;

void remove_effect(object me, int amount);

int exert(object me, object target)
{
        int skill, lvl, layer;

        lvl = me->query_skill("longxiang-gong", 1);
        layer = lvl / 30;

        if (layer > 13) layer = 13;

        if (target != me)
                return notify_fail("��ֻ�������Լ���ս������\n");

        if (layer < 3)
                return notify_fail("�������������Ϊ�����������˹���\n");

        if ((int)me->query("neili") < 500)
                return notify_fail("��Ŀǰ������������\n");

        if ((int)me->query_temp("powerup"))
                return notify_fail("���Ѿ����˹����ˡ�\n");

        skill = me->query_skill("force");

        message_vision(HIY "$N" HIY "���������������" + chinese_number(layer) +
                       "�㹦����ȫ������ڽڱ��죬�����������ɢ������\n" NOR, me);

        me->add_temp("apply/attack", (skill / 3) + (layer * 15));
        me->add_temp("apply/parry", skill / 3);
        me->add_temp("apply/dodge", skill / 3);
        me->set_temp("powerup", 1);
        me->add("neili", -100);

        me->start_call_out((: call_other, __FILE__, "remove_effect",
                              me, skill / 3 :), skill);

        if (me->is_fighting()) me->start_busy(3);

        return 1;
}
/*
void remove_effect(object me, int amount)
{
        if ((int)me->query_temp("powerup"))
        {
                me->add_temp("apply/attack", -(amount - (layer * 15)));
                me->add_temp("apply/parry", -amount);
                me->add_temp("apply/dodge", -amount);
                me->delete_temp("powerup");
                tell_object(me, "������������������ϣ��������ջص��\n");
        }
}*/
