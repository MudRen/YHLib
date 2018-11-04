#include <ansi.h>

#define JUE "��" HIC "�ܾ�ʽ" NOR "��"

inherit F_SSERVER;

int perform(object me)
{
        string msg;
        object weapon;
        int skill, jing_cost;
        int improve;

        skill = me->query_skill("dugu-jiujian", 1);

        if (skill < 60)
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

        jing_cost = 80 - (int)me->query("int");
        if (jing_cost < 30) jing_cost = 30;

        if (environment(me)->query("no_fight") && me->query("doing") != "scheme")
                return notify_fail("����Χ�������ӣ���������" JUE "��\n");

        if (me->is_fighting())
                return notify_fail(JUE "������ս����������\n");

        if (! objectp(weapon = me->query_temp("weapon")) ||
            (string)weapon->query("skill_type") != "sword")
                return notify_fail("��ʹ�õ��������ԣ���������" JUE "��\n");

        if (! skill || skill < 60)
                return notify_fail("��Ķ��¾Ž��ȼ���������������" JUE "��\n");

        if (me->query_skill("sword", 1) < skill)
                return notify_fail("��Ļ��������ȼ����ޣ���������" JUE "��\n");

        if (me->query("neili") < 85)
                return notify_fail("�������������㣬��������" JUE "��\n");

        if (me->query("jing") < -jing_cost)
                return notify_fail("�����ھ��񲻼ѣ���������" JUE "��\n");

        if (! me->can_improve_skill("dugu-jiujian"))
                return notify_fail("��ʵս���鲻�㣬��������" JUE "��\n");

        msg = HIC "$N" HIC "ʹ�����¾Ž�֮��" HIW "�ܾ�ʽ"
              HIC "����������" + weapon->name() + HIC "��"
              "�������̡�\n" NOR;
        message_combatd(msg, me);

        me->add("neili", -50 - random(30));
        me->receive_damage("jing", jing_cost);

        improve = 1 + random(me->query("int")) / 2;

        tell_object(me, HIY "��ԡ������������͡����¾Ž���"
                        "�����µ�����\n" NOR);
        me->improve_skill("sword", improve);
        me->improve_skill("dugu-jiujian", improve);
        me->start_busy(random(3));
        return 1;
}
