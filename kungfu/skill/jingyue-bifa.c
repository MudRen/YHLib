
inherit SKILL;

mapping *action = ({
([      "action":"$Nһ�С�����ʽ��������$w������$n������Ѩ",
        "force" : 90,
        "attack": 15,
        "dodge" : -10,
        "parry" : 20,
        "damage": 25,
        "lvl"   : 0,
        "skill_name" : "����ʽ",
        "damage_type" : "����"
]),
([      "action":"$N��������һ�С����ʽ����$w���������£���$n�׺�Ѩ��ȥ",
        "force" : 110,
        "attack": 30,
        "dodge" : 10,
        "parry" : 30,
        "damage": 30,
        "lvl"   : 40,
        "skill_name" : "���ʽ",
        "damage_type" : "����"
]),
([      "action":"$N��ǰ����һ��������$wʹ��������ʽ��������$n�ĵز�Ѩ",
        "force" : 130,
        "attack": 40,
        "dodge" : 5,
        "parry" : 32,
        "damage": 35,
        "lvl"   : 60,
        "skill_name" : "����ʽ",
        "damage_type" : "����"
]),
([      "action":"$N���е�$w������ҵ�һ�Σ�ʹ������ѩʽ�����ź����������$n������Ѩ",
        "force" : 150,
        "attack": 50,
        "dodge" : 5,
        "parry" : 35,
        "damage": 40,
        "lvl"   : 80,
        "skill_name" : "��ѩʽ",
        "damage_type" : "����"
]),
([      "action":"$N����Ծ��һʽ�����ʽ�������������Ӱ��$w��$n�����ȥ",
        "force" : 170,
        "attack": 60,
        "dodge" : 10,
        "parry" : 45,
        "damage": 50,
        "lvl"   : 100,
        "skill_name" : "���ʽ",
        "damage_type" : "����"
]),
([      "action":"$N�������У�$w�Ƴ�����ѩ���ʷ棬�ӳ�������ʽ����һ�ʿ���һ�ʵع���$n",
        "force" : 180,
        "attack": 65,
        "dodge" : 5,
        "parry" : 50,
        "damage": 60,
        "lvl"   : 120,
        "skill_name" : "����ʽ",
        "damage_type" : "����"
]),
});


int valid_enable(string usage) { return (usage == "dagger") || (usage == "parry"); }

int valid_learn(object me)
{
        object ob;

        if ((int)me->query("max_neili") < 100)
                return notify_fail("���������Ϊ������\n");

        if (! (ob = me->query_temp("weapon"))
        ||  (string)ob->query("skill_type") != "dagger" )
                return notify_fail("���������һ����Ӧ����������ѧϰ���±ʷ���\n");

        if ((int)me->query_skill("dagger", 1) < (int)me->query_skill("jingyue-bifa", 1))
                return notify_fail("��Ļ����̱�ˮƽ���ޣ��޷���������ľ��±ʷ���\n");

    return 1;
}

string query_skill_name(int level)
{
        int i;

        for(i = sizeof(action) - 1; i >= 0; i--)
                if(level >= action[i]["lvl"])
                        return action[i]["skill_name"];
}

mapping query_action(object me, object weapon)
{
        int i, level;

        level = (int) me->query_skill("jingyue-bifa", 1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        object weapon;

        if (! objectp(weapon = me->query_temp("weapon")) ||
            (string)weapon->query("skill_type") != "dagger")
                return notify_fail("�����ֵ������޷���ϰ���±ʷ���\n");

        if ((int)me->query("qi") < 50)
                return notify_fail("����������������±ʷ���\n");

        if ((int)me->query("neili") < 50)
                return notify_fail("����������������±ʷ���\n");

        me->receive_damage("qi", 45);
        me->add("neili", -42);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"jingyue-bifa/" + action;
}
