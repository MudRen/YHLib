inherit FORCE;

int valid_enable(string usage)
{
            return usage == "force";
}

int valid_learn(object me)
{
            return ::valid_learn(me);
}

int valid_force(string force)
{
        return force == "zihui-xinfa";
}


int practice_skill(object me)
{
            return notify_fail("Ľ���ķ�ֻ����ѧ(learn)�������������ȡ�\n");
}
