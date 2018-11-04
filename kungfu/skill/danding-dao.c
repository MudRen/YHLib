inherit SKILL;

mapping *action = ({
([      "action": "$N����$wбָ��һ�С�ɳŸ�Ӳ���������һ�٣�һ����$n��$l��ȥ",
        "force" : 20,
        "dodge" : 10,
        "parry" : 25,
        "damage": 5,
        "lvl"   : 0,
        "skill_name"  : "ɳŸ�Ӳ�",
        "damage_type" : "����"
]),
([      "action": "$Nһ�С�ƽɳ���㡹����������㣬$wһ��һ�գ�ƽ�л���$n�ľ���",
        "force" : 30,
        "dodge" : 30,
        "parry" : 40,
        "damage": 10,
        "lvl"   : 20,
        "skill_name"  : "ƽɳ����",
        "damage_type" : "����"
]),
([      "action": "$Nչ���鲽������Ծ�䣬һ�С��������֡�������һ������ն��$n",
        "force" : 40,
        "dodge" : 35,
        "parry" : 45,
        "damage": 15,
        "lvl"   : 40,
        "skill_name"  : "��������",
        "damage_type" : "����"
]),
([      "action": "$Nһ�С����ֿ�ѡ���$w�󿪴��أ����϶��»���һ���󻡣���ֱ����$n",
        "force" : 60,
        "dodge" : 45,
        "parry" : 45,
        "damage": 20,
        "lvl"   : 60,
        "skill_name"  : "���ֿ��",
        "damage_type" : "����"
]),
([      "action": "$N����$wһ����һ�С���Ů���󡹣�˫�ֳ����������У�����$n���ؿ�",
        "force" : 80,
        "dodge" : 50,
        "parry" : 55,
        "damage": 25,
        "lvl"   : 80,
        "skill_name"  : "��Ů����",
        "damage_type" : "����"
]),
([      "action": "$N����$w��ʹ��һ�С����б��¡����������ã����ҿ�����������$n",
        "force" : 90,
        "dodge" : 65,
        "parry" : 55,
        "damage": 30,
        "lvl"   : 100,
        "skill_name"  : "���б���",
        "damage_type" : "����"
]),
([      "action": "$Nһ�С�����Ҷ�������Ծ����أ�$w˳����ǰ��Ю��������$n��$l",
        "force" : 120,
        "dodge" : 75,
        "parry" : 85,
        "damage": 35,
        "lvl"   : 120,
        "skill_name"  : "����Ҷ",
        "damage_type" : "����"
]),
([      "action": "$N����פ�أ�һ�С�������ˮ�����ӳ�һƬ�����ĵ�Ӱ����$n��ȫ��ӿȥ",
        "force" : 140,
        "dodge" : 90,
        "parry" : 90,
        "damage": 40,
        "lvl"   : 140,
        "skill_name"  : "������ˮ",
        "damage_type" : "����"
]),
});


int valid_enable(string usage)
{
	return usage == "blade" || usage == "parry";
}

int valid_learn(object me)
{
        if ((int)me->query("max_neili") < 200)
                return notify_fail("���������Ϊ������\n");

        if ((int)me->query_skill("force") < 50)
                return notify_fail("����ڹ����̫ǳ��\n");

        if ((int)me->query_skill("blade", 1) < (int)me->query_skill("danding-dao", 1))
                return notify_fail("��Ļ�������ˮƽ���ޣ��޷���������ĵ��ֵ�����\n");

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
        level = (int) me->query_skill("danding-dao", 1);
        for (i = sizeof(action); i > 0; i--)
                if (level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        object weapon;

        if (! objectp(weapon = me->query_temp("weapon")) ||
            (string)weapon->query("skill_type") != "blade")
                return notify_fail("��ʹ�õ��������ԡ�\n");

        if ((int)me->query("qi") < 60)
                return notify_fail("����������������ֵ�����\n");

        if ((int)me->query("neili") < 60)
                return notify_fail("����������������ֵ�����\n");

        me->receive_damage("qi", 45);
        me->add("neili", -43);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"danding-dao/" + action;
}
