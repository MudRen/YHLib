inherit SKILL;

string type() { return "knowledge"; }

int valid_enable(string usage) { return usage == "medical"; }

int valid_learn(object me)
{
        if ((int)me->query_skill("medical", 1) < 100)
                return notify_fail("��Ļ���ҽ������̫ǳ����"
                                   "�������µı�������\n");

        if ((int)me->query_skill("medical", 1) < (int)me->query_skill("xingxiu-qishu", 1))
                return notify_fail("��Ļ���ҽ��ˮƽ���ޣ���"
                                   "�����ո���µı�������\n");

        if ((int)me->query_skill("bencao-changshi", 1) < (int)me->query_skill("bencao-shuli", 1))
                return notify_fail("��ı��ݳ�ʶˮƽ���ޣ���"
                                   "�����ո���µı�������\n");

        return 1;
}

