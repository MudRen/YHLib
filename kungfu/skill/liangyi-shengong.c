inherit FORCE;

int valid_enable(string usage) { return usage == "force"; }

int valid_force(string force)
{
        return force == "kunlun-xinfa" ||
               force == "liangyi-shengong";
}

int query_neili_improve(object me)
{
        int lvl;

        lvl = (int)me->query_skill("liangyi-shengong", 1);
        return lvl * lvl * 15 * 14 / 100 / 200;
}

int valid_learn(object me)
{
        int lvl = (int)me->query_skill("liangyi-shengong", 1);

        if ((int)me->query_skill("force", 1) < 60)
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
	return __DIR__"liangyi-shengong/" + func;
}
