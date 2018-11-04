#include <ansi.h>

inherit F_SSERVER;

int perform(object me)
{
        string msg;
        object weapon;
        int skill, jing_cost;
        int improve;

        skill = me->query_skill("lonely-sword", 1);

        jing_cost = 80 - (int)me->query("int");
        if (jing_cost < 30) jing_cost = 30;

        if (environment(me)->query("no_fight") && me->query("doing") != "scheme")
                return notify_fail("����̫���ӣ��㲻�ܾ�������������\n");

        if (me->is_fighting())
                return notify_fail("���ܾ�ʽ��������ս����������\n");

        if (! objectp(weapon = me->query_temp("weapon")) ||
            (string)weapon->query("skill_type") != "sword")
                return notify_fail("�������ȥ��һ�ѽ���\n");

        if (! skill || skill < 20)
                return notify_fail("��Ķ��¾Ž��ȼ�����, �����������ܾ�ʽ����\n");

        if (me->query("neili") < 50)
                return notify_fail("�������������û�������������ܾ�ʽ����\n");

        if (me->query("jing") < -jing_cost)
                return notify_fail("������̫���ˣ��޷����о����������ܾ�ʽ����\n");

        if (! me->can_improve_skill("lonely-sword"))
                return notify_fail("���ʵս���鲻�����޷���ᡸ�ܾ�ʽ����\n");

        msg = HIG "$N" HIG "ʹ�����¾Ž�֮���ܾ�ʽ����������" +
              weapon->name() + HIG "���������̡�\n" NOR;
        message_combatd(msg, me);

        me->add("neili", -40 - random(10));
        me->receive_damage("jing", jing_cost);

        improve = 1 + random(me->query("int"));

        tell_object(me, MAG "��ġ������������͡����¾Ž��������ˣ�\n" NOR);
        me->improve_skill("sword", improve / 2);
        me->improve_skill("lonely-sword", improve);
        me->start_busy(random(3));
        return 1;
}
