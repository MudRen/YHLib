inherit FORCE;

int valid_enable(string usage)
{
        return usage == "force";
}

int query_neili_improve(object me)
{
        int lvl;

        lvl = (int)me->query_skill("bingxin-jue", 1);
        return lvl * lvl * 15 * 18 / 100 / 200;
}

int valid_force(string force)
{
        return 1;
}

int valid_learn(object me)
{
        if ( me->query("gender") == "����" && (int)me->query("bingxin-jue", 1) > 99)
                return notify_fail("���޸����ԣ���������������������ı��ľ���\n");

        if (me->query("int") < 26)
                return notify_fail("����ñ��ľ�����ޱȣ�һʱ������ᡣ\n");

        if ((int)me->query_skill("force", 1) < 100)
                return notify_fail("��Ļ����ڹ���򻹲�����������ѧϰ���ľ���\n");

        return ::valid_learn(me);
}

int practice_skill(object me)
{
        return notify_fail("���ľ�ֻ����ѧ(learn)�������������ȡ�\n");
}

string exert_function_file(string func)
{
        return __DIR__"bingxin-jue/" + func;
}

