inherit FORCE;

int valid_enable(string usage) { return usage == "force"; }

int valid_force(string force)
{
        return force == "riyue-xinfa" ||
               force == "xixing-dafa" ||
               force == "yijinjing" ||
               force == "kuihua-mogong";
}

int query_neili_improve(object me)
{
        int lvl;

        lvl = (int)me->query_skill("tianhuan-shenjue", 1);
        return lvl * lvl * 15 * 8 / 100 / 200;
}

int valid_learn(object me)
{
        int lvl = (int)me->query_skill("tianhuan-shenjue", 1);

        if ((int)me->query_skill("force", 1) < 50)
                return notify_fail("��Ļ����ڹ���򻹲�����\n");

        // ��Ϊ��������̵��ڹ������Զ����Ե�ѧϰ���Ʒſ�
        if (me->query("gender") == "����" && lvl > 99)
                return notify_fail("���޸����ԣ������������������������������\n");

        return ::valid_learn(me);
}

int practice_skill(object me)
{
	return notify_fail("������ֻ����ѧ(learn)�������������ȡ�\n");
}

string exert_function_file(string func)
{
	return __DIR__"tianhuan-shenjue/" + func;
}
