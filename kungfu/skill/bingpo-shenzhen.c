#include <ansi.h>

inherit SKILL;

int valid_enable(string usage) 
{ 
       return usage == "throwing"; 
}

int valid_learn(object me)
{
        if ((int)me->query_skill("force") < 80)
                return notify_fail("����ڹ��ķ���򲻹����޷�ѧ�������롣\n");

        if ((int)me->query_skill("dodge") < 100)
                return notify_fail("����Ṧ��򲻹����޷�����������롣\n");

        if ((int)me->query_dex() < 34)
                return notify_fail("������������ɣ��޷�����������롣\n");

        if ((int)me->query_skill("throwing", 1) < (int)me->query_skill("bingpo-shenzhen", 1))
                return notify_fail("��Ļ�������ˮƽ���ޣ�������������ı������롣\n");

        return 1;
}

int practice_skill(object me)
{
        object weapon;

        if ((int)me->query("qi") < 80)
                return notify_fail("�������̫���ˡ�\n");

        if ((int)me->query("neili") < 80)
                return notify_fail("��������������������롣\n");

        me->receive_damage("qi", 72);
        me->add("neili", -65);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"bingpo-shenzhen/" + action;
}
