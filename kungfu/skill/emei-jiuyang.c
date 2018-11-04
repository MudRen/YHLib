inherit FORCE;

mapping *action = ({
([  "action": "$N�����Ҿ������˾��ڱۣ�һ�������ն����������һ�����ȵĻ�â",
    "lvl"   : 0,
    "damage_type" : "����"
]),
([  "action": "$N�粽��ǰ������΢΢һչ��˫�ƶ�׼$n$lһ������",
    "lvl"   : 0,
    "damage_type" : "����"
]),
});

string main_skill() { return "jiuyang-shengong"; }

int valid_enable(string usage)
{
        return usage == "force";
}

int query_neili_improve(object me)
{
        int lvl;

        lvl = (int)me->query_skill("emei-jiuyang", 1);
        return lvl * lvl * 15 * 15 / 100 / 200;
}

mapping query_action(object me, object weapon)
{
        int i, level;
        level = (int) me->query_skill("emei-jiuyang",1);
        for (i = sizeof(action); i > 0; i--)
                if (level > action[i-1]["lvl"])
                        return action[random(i)];
}

int valid_force(string force)
{
        return 1;
}

int valid_learn(object me)
{
        if ((int)me->query_skill("yinyang-shiertian", 1))
                return notify_fail("���ѽ��������ڻ��ͨ���ϳ�������֮����ǿ"
                                   "���书�������ٷֿ�ѧϰ�ˡ�\n");

        if ((int)me->query_skill("jiuyang-shengong", 1))
                return notify_fail("���ѽ����־�����ȫ���ڻ��ͨ�������ٷֿ�"
                                   "ѧϰ�ˡ�\n");

        if ( me->query("gender") == "����" && (int)me->query("emei-jiuyang", 1) > 9)
                return notify_fail("���޸����ԣ���������������������Ķ��Ҿ�"
                                   "���񹦡�\n");

        if (me->query("con") < 34)
                return notify_fail("�����������������޷��������Ҿ����񹦡�\n");

        if ((int)me->query_skill("force", 1) < 100)
            return notify_fail("����ڹ�̫��޷�ѧϰ���Ҿ����񹦡�\n");

        if ((int)me->query("max_neili") < 1200)
            return notify_fail("���������Ϊ̫ǳ���޷�ѧϰ���Ҿ����񹦡�\n");

        return ::valid_learn(me);
}

int practice_skill(object me)
{
        return notify_fail("���Ҿ�����ֻ����ѧ(learn)�������������ȡ�\n");
}

string exert_function_file(string func)
{
        return __DIR__"jiuyang-sub/" + func;
}
