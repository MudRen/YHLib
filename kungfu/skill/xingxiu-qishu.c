// xingxiu-qishu.c

inherit SKILL;

string type() { return "knowledge"; }

int valid_enable(string usage)
{
        return usage == "poison";
}

int valid_learn(object me)
{
        if ((int)me->query_skill("poison", 1) < 100)
                return notify_fail("��Ļ�����������̫ǳ����"
                                   "�������µ�����������\n");

        if ((int)me->query_skill("poison", 1) < (int)me->query_skill("xingxiu-qishu", 1))
                return notify_fail("��Ļ�������ˮƽ���ޣ���"
                                   "�����ո���µ�����������\n");

        return 1;
}
