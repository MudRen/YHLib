#include <ansi.h>

inherit F_CLEAN_UP;

string *force_name = ({ NOR + HIB "��׺�", HIY "����",
                        HIR "Ѫ��", NOR + CYN "������", }); 

void remove_effect(object me, int amount);

int exert(object me, object target)
{
        int skill;
        string name;
        name = force_name[random(sizeof(force_name))];

        if (target != me)
                return notify_fail("��ֻ���û��챦���������Լ���ս������\n");

        if ((int)me->query("neili") < 150)
                return notify_fail("�������������\n");

        if ((int)me->query_temp("powerup"))
                return notify_fail("���Ѿ����˹����ˡ�\n");

        skill = me->query_skill("force");
        me->add("neili", -100);
        me->receive_damage("qi", 0);

        message_combatd(HIW "$N" HIW "΢һ����������챦��֮��" + name +
                        HIW "���ķ���һ�������ٽ�������������\n" NOR, me);

        me->add_temp("apply/attack", skill / 2);
        me->add_temp("apply/defense", skill / 2);
        me->set_temp("powerup", 1);

        me->start_call_out((: call_other, __FILE__, "remove_effect",
                              me, skill / 2 :), skill);

        if (me->is_fighting())
                me->start_busy(3);

        return 1;
}

void remove_effect(object me, int amount)
{
        if (me->query_temp("powerup"))
        {
                me->add_temp("apply/attack", -amount);
                me->add_temp("apply/defense", -amount);
                me->delete_temp("powerup");
                tell_object(me, "��Ļ��챦��������ϣ��������ջص��\n");
        }
}
