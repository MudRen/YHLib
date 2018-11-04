inherit FORCE;

int valid_enable(string usage)
{
        return usage == "force";
}

int query_neili_improve(object me)
{
        int lvl;

        lvl = (int)me->query_skill("changsheng-jue", 1);
        return lvl * lvl * 15 * 22 / 100 / 200;
}

int valid_force(string force)
{
        return 1;
}

int valid_learn(object me)
{
        int lvl = (int)me->query_skill("changsheng-jue", 1);

        if (me->query("character") != "������")
                return notify_fail("�����а��룺�ⲻ���ǵ��������Ŀھ����ˣ�������ʲô�񹦣�\n");

        if (me->query("int") < 35)
                return notify_fail("����ó��������ڼ��������⡣\n");

        if (me->query("con") < 31)
                return notify_fail("������ĸ����޷�������������\n");

        if ((int)me->query_skill("martial-cognize", 1) < 300)
                return notify_fail("�����ѧ����û�а취������еľ�����塣\n");

        return ::valid_learn(me);
}

int practice_skill(object me)
{
        return notify_fail("������ֻ����ѧ(learn)�������������ȡ�\n");
}

string exert_function_file(string func)
{
        return __DIR__"changsheng-jue/" + func;
}

