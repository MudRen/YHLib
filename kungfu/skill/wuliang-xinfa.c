// wuliang-xinfa.c �����ķ�

inherit FORCE;

int valid_enable(string usage)
{
            return usage == "force";
}

int valid_force(string force)
{
        return force == "dahai-wuliang" ||
               force == "lingjiu-xinfa" ||
               force == "bahuang-gong" ||
               force == "wudoumi-shengong";
}

int valid_learn(object me)
{
            return ::valid_learn(me);
}

int practice_skill(object me)
{
            return notify_fail("�����ķ�ֻ����ѧ(learn)�������������ȡ�\n");
}

string exert_function_file(string func)
{
            return __DIR__"wuliang-xinfa/" + func;
}
