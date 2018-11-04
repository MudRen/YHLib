inherit FORCE;

int valid_enable(string usage) { return usage == "force"; }

int valid_force(string force)
{
        return force == "tiezhang-xinfa" ||
               force == "tianlei-shengong" ||
               force == "wuqing-xinfa" ||
               force == "bingxin-jue";
}

int query_neili_improve(object me)
{
        int lvl;

        lvl = (int)me->query_skill("tianlei-shengong", 1);
        return lvl * lvl * 15 * 10 / 100 / 200;
}

int valid_learn(object me)
{
        int lvl = (int)me->query_skill("tianlei-shengong", 1);

        if ((int)me->query_skill("force", 1) < 70)
                return notify_fail("��Ļ����ڹ���򻹲�����\n");

        if ( me->query("gender") == "����" && lvl > 49)
                return notify_fail("���޸����ԣ���������������������������񹦡�\n");

        return ::valid_learn(me);
}

int practice_skill(object me)
{
	return notify_fail("������ֻ����ѧ(learn)�������������ȡ�\n");
}

string exert_function_file(string func)
{
	return __DIR__"tianlei-shengong/" + func;
}
