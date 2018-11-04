inherit SKILL;

mapping *action = ({
([      "action": "$N�߸߾���$w��ʩһ�С������������ݺݵ���$n��$l��ȥ",
        "force" : 110,
        "attack": 2,
        "dodge" : -5,
        "parry" : -7,
        "lvl"   : 0,
        "damage": 30,
        "skill_name" : "������",
        "damage_type": "����",
]),
([      "action": "$N�εض��𣬰����һ���������$wһʽ����ɽ��ɨ��$n",
        "force" : 130,
        "attack": 5,
        "dodge" : -11,
        "parry" : -5,
        "lvl"   : 40,
        "damage": 40,
        "skill_name" : "��ɽ",
        "damage_type": "����",
]),
([      "action": "$N����$w�趯��һ�С��������졹Ю������ײ��֮��������$n",
        "force" : 150,
        "attack": 8,
        "dodge" : -6,
        "parry" : -5,
        "lvl"   : 80,
        "damage": 45,
        "skill_name" : "��������",
        "damage_type": "����",
]),
([      "action": "$Nʩһ�С�������������$w������������������$n�ĸ�����λ",
        "force" : 160,
        "attack": 15,
        "dodge" : 0,
        "parry" : -3,
        "lvl"   : 100,
        "damage": 50,
        "skill_name" : "����",
        "damage_type": "����",
]),
([      "action": "$N�������$w��ʹ�����䶥��������$w���ն��£�����$n$l",
        "force" : 220,
        "attack": 22,
        "dodge" : -10,
        "parry" : -5,
        "lvl"   : 120,
        "damage": 75,
        "skill_name" : "�䶥",
        "damage_type": "����",
]),
});

int valid_enable(string usage)
{
	return usage == "hammer" || usage == "parry";
}

int valid_learn(object me)
{
        if ((int)me->query("max_neili") < 300)
                return notify_fail("���������Ϊ�����������������ϴ����ơ�\n");

        if ((int)me->query_skill("force") < 30)
                return notify_fail("����ڹ����̫ǳ�������������ϴ����ơ�\n");

        if ((int)me->query_skill("hammer", 1) < 20)
                return notify_fail("��Ļ������������������������ϴ����ơ�\n");

        if ((int)me->query_skill("hammer", 1) < (int)me->query_skill("dali-chu", 1))
                return notify_fail("��Ļ�������ˮƽ���ޣ��޷�������������ϴ����ơ�\n");

        return 1;
}

string query_skill_name(int level)
{
        int i;
        for (i = sizeof(action) - 1; i >= 0; i--)
                if (level >= action[i]["lvl"])
                        return action[i]["skill_name"];
}

mapping query_action(object me, object weapon)
{
        int i, level;
        level = (int) me->query_skill("dali-chu", 1);
        for (i = sizeof(action); i > 0; i--)
                if (level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level / 5)];
}

int practice_skill(object me)
{
        object weapon;

        if (! objectp(weapon = me->query_temp("weapon")) || 
            (string)weapon->query("skill_type") != "hammer")
                return notify_fail("��ʹ�õ��������ԡ�\n");

        if ((int)me->query("qi") < 40)
                return notify_fail("����������������������ϴ����ơ�\n");

        if ((int)me->query("neili") < 50)
                return notify_fail("����������������������ϴ����ơ�\n");

        me->receive_damage("qi", 35);
        me->add("neili", -40);

        return 1;
}

string perform_action_file(string action)
{
       return __DIR__"dali-chu/" + action;
}
