inherit SKILL;

mapping *action = ({
([      "action": "$N���⽣â������һ�С���������������$w�󿪴��أ���âֱ��$n��$l",
        "force" : 98,
        "attack": 13,
        "dodge" : 2,
        "parry" : 3,
        "damage": 41,
        "lvl"   : 0,
        "skill_name"  : "������",
        "damage_type" : "����"
]),
([      "action": "$N��â���£�����$wһ�С����������������������ֱ����$n��$l",
        "force" : 132,
        "attack": 19,
        "dodge" : 3,
        "parry" : 4,
        "damage": 58,
        "lvl"  : 30,
        "skill_name"  : "������",
        "damage_type" : "����"
]),
([      "action": "$Nһʽ���̹ǽ����������ƽ���������ʵ��׷ɣ��ó�����ǹ�Ʈ��$n",
        "force" : 163,
        "attack": 23,
        "dodge" : 9,
        "parry" : 10,
        "damage": 77,
        "lvl"   : 60,
        "skill_name"  : "�̹ǽ�",
        "damage_type" : "����"
]),
([      "action": "$N�ӽ��ֻ�����������ǰԾ����$wһʽ�����񽣡�����������֮�ƣ�����$n",
        "force" : 190,
        "attack": 31,
        "dodge" : 11,
        "parry" : 13,
        "damage": 85,
        "lvl"   : 100,
        "skill_name"  : "����",
        "damage_type" : "����"
]),
([      "action": "$N���ֽ�ָ��ת������һŤ������$wһ�ǡ��ٳ��������¶��ϴ���$n��$l",
        "force" : 225,
        "attack": 35,
        "dodge" : 5,
        "parry" : 7,
        "damage": 93,
        "lvl"   : 150,
        "skill_name"  : "�ٳ���",
        "damage_type" : "����"
]),
});

int valid_enable(string usage)
{
        return usage == "sword" || usage == "parry";
}

int valid_learn(object me)
{
        if ((int)me->query("max_neili") < 1000)
                return notify_fail("���������Ϊ���㡣\n");

        if ((int)me->query_skill("force", 1) < 100)
                return notify_fail("����ڹ����̫ǳ��\n");

        if ((int)me->query_skill("sword", 1) < 80)
                return notify_fail("��Ļ����������̫ǳ��\n");

        if (me->query_skill("sword", 1) < me->query_skill("pichen-jian"))
                return notify_fail("��Ļ�������ˮƽ���ޣ��޷���������ıٳ�������\n");

        return 1;
}

string query_skill_name(int level)
{
        int i;
        for (i = sizeof(action)-1; i >= 0; i--)
                if (level >= action[i]["lvl"])
                        return action[i]["skill_name"];
}

mapping query_action(object me, object weapon)
{
        int i, level;

        level = (int) me->query_skill("pichen-jian", 1);
        for (i = sizeof(action); i > 0; i--)
                if (level > action[i-1]["lvl"])
                       return action[NewRandom(i, 20, level/5)];

}

int practice_skill(object me)
{
        object weapon;

        if (! objectp(weapon = me->query_temp("weapon")) ||
            (string)weapon->query("skill_type") != "sword")
                return notify_fail("��ʹ�õ��������ԡ�\n");

        if ((int)me->query("qi") < 60)
                return notify_fail("��������������ٳ�������\n");

        if ((int)me->query("neili") < 60)
                return notify_fail("��������������ٳ�������\n");

        me->receive_damage("qi", 50);
        me->add("neili", -55);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"pichen-jian/" + action;
}
