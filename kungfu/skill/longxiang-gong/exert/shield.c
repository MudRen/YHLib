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
                return notify_fail("��ֻ�������Լ��ķ�������\n");

        if (layer < 3)
                return notify_fail("�������������Ϊ�����������˹���\n");

        if ((int)me->query("neili") < 500)
                return notify_fail("��Ŀǰ������������\n");

        if ((int)me->query_temp("shield"))
                return notify_fail("���Ѿ����˹����ˡ�\n");

        skill = me->query_skill("force");

        message_combatd(HIW "$N" HIW "���������������" + chinese_number(layer) +
                        "�㹦������ʱһ�ɰ������ڶ���˲������$N" HIW "ȫ��\n"
                        NOR, me);

        me->add_temp("apply/armor", skill / 2);
        me->add("neili", -100);
        me->set_temp("shield", 1);

        me->start_call_out((: call_other, __FILE__, "remove_effect",
                              me, skill / 2:), skill);

        if (me->is_fighting()) me->start_busy(2);

        return 1;
}

void remove_effect(object me, int amount)
{
        if (me->query_temp("shield"))
        {
                me->add_temp("apply/armor", -amount);
                me->delete_temp("shield");
                tell_object(me, "������������������ϣ��������ջص��\n");
        }
}
