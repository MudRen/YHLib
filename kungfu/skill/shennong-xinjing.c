// shennong-xinjing.c ��ũ�ľ�

inherit FORCE;

int valid_enable(string usage) { return usage == "force"; }

int valid_force(string force)
{
        return force == "shennong-xinjing" ||
               force == "yaogu-xinfa" ||
               force == "lengyue-shengong" ||
               force == "hujia-neigong" ||
               force == "danyang-tunafa" ||
               force == "miaojia-neigong" ;
}

int query_neili_improve(object me)
{
        int lvl;

        lvl = (int)me->query_skill("shennong-xinjing", 1);
                return lvl * lvl * 15 * 21 / 100 / 200;
}

int valid_learn(object me)
{
        if ( me->query("gender") == "����" && (int)me->query_skill("shennong-xinjing", 1) > 99)
	        return notify_fail("���޸����ԣ������������������������ũ�ľ���\n");

        if ((int)me->query_skill("force", 1) < 60)
	        return notify_fail("��Ļ����ڹ���򻹲�����\n");

	return ::valid_learn(me);
}

int practice_skill(object me)
{
	return notify_fail("��ũ�ľ�ֻ����ѧ(learn)�������������ȡ�\n");
}

string exert_function_file(string func)
{
	return __DIR__"shennong-xinjing/" + func;
}
