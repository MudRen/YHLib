// xuwen-qixingding.c �������Ƕ�
// Edit By Vin On 26/2/2001

#include <ansi.h>

inherit SKILL;

int valid_learn(object me)
{
        object ob;
  
        if (me->query_skill("throwing", 1) < 20)
                return notify_fail("��İ������ܲ�����졣\n");

        if ((int)me->query_skill("throwing", 1) < (int)me->query_skill("xuwen-qixingding", 1))
                return notify_fail("��Ļ�������ˮƽ���ޣ���������������������Ƕ���\n");

        return 1;
}

int valid_enable(string usage)
{
        return usage == "throwing";
}

int practice_skill(object me)
{
        object weapon;

        if ((int)me->query("qi") < 110)
                return notify_fail("�������������ϰ�������Ƕ���\n");

        me->receive_damage("qi", 100);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"xuwen-qixingding/" + action;
}
