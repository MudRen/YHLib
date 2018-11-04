inherit FORCE;

int valid_enable(string usage)
{
	return usage == "force";
}

int valid_force(string force)
{
        return force == "tianchi-neigong" ||
               force == "honghua-xinfa" ;
}

int query_neili_improve(object me)
{
    int lvl;

    lvl = (int)me->query_skill("zhanshen-xinjing", 1);
    return lvl * lvl * 15 * 20 / 100 / 200;
}

int valid_learn(object me)
{
        if ((int)me->query_skill("force", 1) < 100)
                return notify_fail("��Ļ����ڹ���򻹲�����\n");

        if (me->query("gender") == "����" && (int)me->query_skill("zhanshen-xinjing", 1) > 19)
                return notify_fail("���޸����ԣ����������������������ս���ľ���\n");

        if (me->query("con") < 30)
                return notify_fail("����������������޷�ѧϰս���ľ���\n");

        return ::valid_learn(me);
}

int practice_skill(object me)
{
        return notify_fail("ս���ľ�ֻ����ѧ(learn)�������������ȡ�\n");
}

string exert_function_file(string func)
{
        return __DIR__"zhanshen-xinjing/" + func;
}
