inherit FORCE;

int valid_enable(string usage) 
{ 
        return usage == "force"; 
}

int valid_force(string force)
{
        return force == "yunv-xinjing" ||
               force == "quanzhen-xinfa";
}

int valid_learn(object me)
{
            return ::valid_learn(me);
}

int practice_skill(object me)
{
        return notify_fail("���ľ�ֻ����ѧ(learn)�����������ȡ�\n");
}

string exert_function_file(string func)
{
            return __DIR__"suxin-jue/" + func;
}
