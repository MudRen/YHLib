#include <ansi.h>
inherit F_CLEAN_UP;

#define FRE "��" HIW "��������" NOR "��"

void remove_effect(object me);

int exert(object me, object target)
{
        int skill;

        if (userp(me) && ! me->query("can_perform/hanbing-zhenqi/freezing"))
                return notify_fail("����ѧ���ڹ���û�����ֹ��ܡ�\n");

        if ((int)me->query_temp("freezing"))
                return notify_fail("����������ʩչ" FRE "��\n");

        if (target != me)
                return notify_fail(FRE "ֻ�ܶ��Լ�ʹ�á�\n");


        if (me->query("con") < 34)
                return notify_fail("���������ǲ��㣬�޷�ʩչ" FRE "��\n");

        if (skill < 120)
                return notify_fail("��ĺ�����������������ʩչ" FRE "��\n");

        if ((int)me->query("max_neili") < 2200)
                return notify_fail("���������Ϊ���㣬����ʩչ" FRE "��\n");

        if (! me->query_temp("powerup"))
                return notify_fail("��������δ���˹�������ʩչ" FRE "��\n");

        if ((int)me->query("neili") < 1000)
                return notify_fail("��Ŀǰ����������������ʩչ" FRE "��\n");

        me->add("neili", -300);

        message_combatd(HIW "$N" HIW "һ����Ц�����ں�������Ѹ�ټ�ת������"
                        "�죬�����������ġ�\n" NOR, me);
        me->set_temp("freezing", 1);

        me->start_call_out((: call_other, __FILE__, "remove_effect",
                              me, skill :), skill);
        if (me->is_fighting())
                me->start_busy(3);

        return 1;
}

void remove_effect(object me)
{
        if (me->query_temp("freezing"))
        {
                me->delete_temp("freezing");
                tell_object(me, "���" FRE "������ϣ��������ջص��\n");
        }
}
