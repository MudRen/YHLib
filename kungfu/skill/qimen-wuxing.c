// qimen-wuxing

inherit SKILL;

void create() { seteuid(getuid()); }

string type() { return "knowledge"; }

int valid_learn(object me)
{
        if ((int)me->query_skill("mathematics", 1) < 200)
                return notify_fail("�������֪ʶ̫��޷�����������еİ��\n");

        if ((int)me->query_skill("mathematics", 1) < (int)me->query_skill("qimen-wuxing", 1))
                return notify_fail("�������֪ʶ���ޣ��޷�������µ��������С�\n");

        return 1;
}

int practice_skill(object me)
{
	return notify_fail("���������ܿ�ѧ(learn)����ߡ�\n");
}
