
inherit SKILL;

string type() { return "knowledge"; }

int valid_enable(string usage) { return usage == "medical"; }

int valid_learn(object me)
{
        if ((int)me->query_skill("medical", 1) < 80)
                return notify_fail("��Ļ���ҽ������̫ǳ����"
                                   "�������µľ���ҩ��\n");

        if ((int)me->query_skill("medical", 1) < (int)me->query_skill("jueqing-yaoli", 1))
                return notify_fail("��Ļ���ҽ��ˮƽ���ޣ���"
                                   "�����ո���µľ���ҩ��\n");

        return 1;
}

