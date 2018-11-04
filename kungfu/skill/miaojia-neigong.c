inherit FORCE;

int valid_enable(string usage) { return usage == "force"; }

int query_neili_improve(object me)
{
    int lvl;

    lvl = (int)me->query_skill("miaojia-neigong", 1);
    return lvl * lvl * 15 * 4 / 100 / 200;
}

int valid_learn(object me)
{
        int lvl = (int)me->query_skill("miaojia-neigong", 1);

        if ( me->query("gender") == "����" && lvl > 49)
                return notify_fail("���޸����ԣ��������������������������ڹ���\n");

        return ::valid_learn(me);
}

int practice_skill(object me)
{
    return notify_fail("����ڹ�ֻ����ѧ(learn)�������������ȡ�\n");
}

string exert_function_file(string func)
{
    return __DIR__"miaojia-neigong/" + func;
}
