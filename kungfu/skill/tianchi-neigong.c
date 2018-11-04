inherit FORCE;

int valid_enable(string usage)
{
	return usage == "force";
}

int valid_force(string force)
{
        return force == "zhanshen-xinjing" ||
               force == "honghua-xinfa" ;
}

int query_neili_improve(object me)
{
    int lvl;

    lvl = (int)me->query_skill("tianchi-neigong", 1);
    return lvl * lvl * 15 * 6 / 100 / 200;
}

int valid_learn(object me)
{
        if ((int)me->query_skill("force", 1) < 60)
                return notify_fail("��Ļ����ڹ���򻹲�����\n");

        if (me->query("gender") == "����" && (int)me->query_skill("tianchi-neigong", 1) > 49)
                return notify_fail("���޸����ԣ��������������������������ڹ���\n");

        return ::valid_learn(me);
}

int practice_skill(object me)
{
        return notify_fail("����ڹ�ֻ����ѧ(learn)�������������ȡ�\n");
}

string exert_function_file(string func)
{
        return __DIR__"tianchi-neigong/" + func;
}
