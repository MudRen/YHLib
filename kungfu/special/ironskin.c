// ironskin.c ͭƤ����
// Created by Vin 1/9/2001

#include <ansi.h>

inherit F_CLEAN_UP;

string name() { return YEL "ͭƤ����" NOR; }

int perform(object me, string skill)
{
        int count;

        if (me->query("qi") < 40)
                return notify_fail("���������֧���޷�Ѹ�������Լ��ķ�������\n");

        message_vision(YEL "$N" YEL "΢һ�����������˫Ŀ��Ȼ"
                       "�������䡣\n" NOR, me);
        count = me->query_str() * 3 / 2;

        if (me->query_temp("special_skill/ironskin", 1))
                return notify_fail("���Ѿ����������Լ��ķ������ˡ�\n");

        me->receive_damage("qi", 20 + random(20));
        me->set_temp("special_skill/ironskin", 1);
        me->add_temp("apply/armor", count);
        me->start_call_out((: call_other, __FILE__, "remove_effect", me,
                              count :), 60 + random(30));

        return 1;
}

void remove_effect(object me, int count)
{
        me->delete_temp("special_skill/ironskin", 1);
        me->add_temp("apply/armor", -count);
        tell_object(me, "��ʩչ��ͭƤ���ǣ�������ȫ��ľ�����\n");
}
