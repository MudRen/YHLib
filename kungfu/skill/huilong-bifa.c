#include <ansi.h>

inherit SKILL;

int valid_learn(object me)
{
        object ob;
  
        if (me->query_skill("throwing", 1) < 100)
                return notify_fail("��İ������ܲ�����졣\n");

        if ((int)me->query_skill("throwing", 1) < (int)me->query_skill("huilong-bifa", 1))
                return notify_fail("��Ļ�������ˮƽ���ޣ�������������Ļ����ڷ���\n");

        return 1;
}

int valid_enable(string usage)
{
        return usage == "throwing";
}

int practice_skill(object me)
{
        if ((int)me->query("qi") < 80)
                return notify_fail("�����������û�а취��ϰ�����ڷ���\n");

        if ((int)me->query("neili") < 60)
                return notify_fail("�������������û�а취��ϰ�����ڷ���\n");

        me->receive_damage("qi", 70);
        me->add("neili", -50);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"huilong-bifa/" + action;
}
