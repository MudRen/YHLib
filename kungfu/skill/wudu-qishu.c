// wudu-qishu.c

inherit SKILL;

string type() { return "knowledge"; }

int valid_enable(string usage) { return usage == "poison"; }

int valid_learn(object me)
{
        if ((int)me->query_skill("poison", 1) < 50)
                return notify_fail("��Ļ�����������̫ǳ����"
                                   "�������µ��嶾������\n");

        if ((int)me->query_skill("poison", 1) < (int)me->query_skill("wudu-qishu", 1))
                return notify_fail("��Ļ�������ˮƽ���ޣ���"
                                   "�����ո���µ��嶾������\n");

        return 1;
}
