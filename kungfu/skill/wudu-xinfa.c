// wudu-xinfa.c �嶾�ķ�

inherit FORCE;

int valid_enable(string usage)
{
	    return usage == "force";
}

int valid_force(string force)
{
        return force == "hamagong" ||
               force == "xiuluo-yinshagong" ||
               force == "shunxi-qianli";
}

int valid_learn(object me)
{
	    return ::valid_learn(me);
}

int practice_skill(object me)
{
	    return notify_fail("�嶾�ķ�ֻ����ѧ(learn)�������������ȡ�\n");
}

string exert_function_file(string func)
{
	    return __DIR__"wudu-xinfa/" + func;
}
