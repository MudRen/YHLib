inherit FORCE;

int valid_enable(string usage)
{
        return usage == "force";
}

int query_neili_improve(object me)
{
        int lvl;

        lvl = (int)me->query_skill("guoshi-xinfa", 1);
        return lvl * lvl * 15 * 2 / 100 / 200;
}

int valid_force(string force)
{
        return 1;
}

int valid_learn(object me)
{
        if (me->query("gender") == "����" && (int)me->query_skill("guoshi-xinfa", 1) > 49)
                return notify_fail("���޸����ԣ���������������������Ĺ����ķ���\n");

        if ((int)me->query_skill("force", 1) < 10)
                return notify_fail("��Ļ����ڹ���򻹲�����������ѧϰ�����ķ���\n");

        return ::valid_learn(me);
}

int practice_skill(object me)
{
        return notify_fail("�����ķ�ֻ����ѧ(learn)�������������ȡ�\n");
}

string exert_function_file(string func)
{
        return __DIR__"guoshi-xinfa/" + func;
}

