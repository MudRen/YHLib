// shenlong-xinfa.c �����ķ�

inherit FORCE;

int valid_enable(string usage) { return usage == "force"; }

int valid_force(string force)
{
	return force == "shedao-neigong";
}

int valid_learn(object me)
{
	if (me->query("gender") == "����" &&
        (int)me->query_skill("shenlong-xinfa", 1) > 49)
		return notify_fail("���޸����ԣ���������������������������ķ���\n");

	return ::valid_learn(me);
}

int practice_skill(object me)
{
    return notify_fail("�����ķ�ֻ��ͨ��ѧ���Ǵ�����(exert)�����������ȡ�\n");
}

string exert_function_file(string func)
{
    return __DIR__"shenlong-xinfa/" + func;
}
