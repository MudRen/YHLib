inherit FORCE;

int valid_enable(string usage) { return usage == "force"; }

int valid_force(string force)
{
        return force == "wuliang-xinfa" ||
               force == "lingjiu-xinfa" ||
               force == "bahuang-gong" ||
               force == "wudoumi-shengong";
}

int query_neili_improve(object me)
{
    int lvl;

    lvl = (int)me->query_skill("dahai-wuliang", 1);
    return lvl * lvl * 15 * 7 / 100 / 200;
}

int valid_learn(object me)
{
        if ((int)me->query_skill("force", 1) < 50)
                return notify_fail("��Ļ����ڹ���򻹲�����\n");

        if (me->query("gender") == "����" && (int)me->query_skill("dahai-wuliang", 1) > 49)
                return notify_fail("���޸����ԣ���������������������Ĵ�������\n");

        return ::valid_learn(me);
}

int practice_skill(object me)
{
        return notify_fail("������ֻ����ѧ(learn)�������������ȡ�\n");
}

string exert_function_file(string func)
{
        return __DIR__"dahai-wuliang/" + func;
}
