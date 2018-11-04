// xuantian-wujigong.c �����޼���

inherit FORCE;

int valid_enable(string usage) { return usage == "force"; }

int valid_force(string force)
{
        return force == "wuzheng-xinfa" ||
               force == "xuantian-wujigong" ||
               force == "riyue-xinfa";
}

int query_neili_improve(object me)
{
    int lvl;

    lvl = (int)me->query_skill("xuantian-wujigong", 1);
    return lvl * lvl * 15 * 12 / 100 / 200;
}

int valid_learn(object me)
{
        if ( me->query("gender") == "����" && (int)me->query_skill("xuantian-wujigong", 1) > 19)
                return notify_fail("���޸����ԣ���������������������������޼�����\n");

        if ((int)me->query_skill("force", 1) < 60)
                return notify_fail("��Ļ����ڹ���򻹲�����\n");

        return ::valid_learn(me);
}

int practice_skill(object me)
{
        return notify_fail("�����޼���ֻ����ѧ(learn)�������������ȡ�\n");
}

string exert_function_file(string func)
{
        return __DIR__"xuantian-wujigong/" + func;
}
