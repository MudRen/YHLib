inherit SKILL;

mapping *action = ({
([      "action": "$N����$wбָ��һ�С�������ɱ�ơ�������һ�٣�һ����$n��$l��ȥ",
        "force" : 72,
        "dodge" : 10,
        "parry" : 25,
        "attack": 16,
        "damage": 15,
        "lvl"   : 0,
        "skill_name"  : "������ɱ��",
        "damage_type" : "����"
]),
([      "action": "$Nһ�С���ͼ��ذ�ơ�����������㣬$wһ��һ�գ�ƽ�л���$n�ľ���",
        "force" : 90,
        "dodge" : 30,
        "parry" : 40,
        "attack": 24,
        "damage": 21,
        "lvl"   : 20,
        "skill_name"  : "��ͼ��ذ��",
        "damage_type" : "����"
]),
([      "action": "$Nչ���鲽������Ծ�䣬һ�С��²���ɽ�ơ�������һ������ն��$n",
        "force" : 124,
        "dodge" : 35,
        "parry" : 45,
        "attack": 29,
        "damage": 35,
        "lvl"   : 40,
        "skill_name"  : "�²���ɽ��",
        "damage_type" : "����"
]),
([      "action": "$Nһ�С�¾����ħ�ơ���$w�󿪴��أ����϶��»���һ���󻡣���ֱ����$n",
        "force" : 136,
        "dodge" : 45,
        "parry" : 45,
        "attack": 34,
        "damage": 52,
        "lvl"   : 60,
        "skill_name"  : "¾����ħ��",
        "damage_type" : "����"
]),
([      "action": "$N����$wһ����һ�С��������ơ���˫�ֳ����������У�����$n���ؿ�",
        "force" : 158,
        "dodge" : 50,
        "parry" : 55,
        "attack": 37,
        "damage": 65,
        "lvl"   : 80,
        "skill_name"  : "��������",
        "damage_type" : "����"
]),
([      "action": "$N����$w��ʹ��һ�С����²ص��ơ����������ã����ҿ�����������$n",
        "force" : 169,
        "dodge" : 65,
        "parry" : 55,
        "attack": 46,
        "damage": 73,
        "lvl"   : 100,
        "skill_name"  : "���²ص���",
        "damage_type" : "����"
]),
([      "action": "$Nһ�С�����͹���ơ������Ծ����أ�$w˳����ǰ��Ю��������$n��$l",
        "force" : 210,
        "dodge" : 75,
        "parry" : 85,
        "attack": 55,
        "damage": 85,
        "lvl"   : 130,
        "skill_name"  : "����͹����",
        "damage_type" : "����"
]),
([      "action": "$N����פ�أ�һ�С�����߱��ơ����ӳ�һƬ�����ĵ�Ӱ����$n��ȫ��ӿȥ",
        "force" : 240,
        "dodge" : 90,
        "parry" : 90,
        "attack": 76,
        "damage": 104,
        "lvl"   : 160,
        "skill_name"  : "����߱���",
        "damage_type" : "����"
]),
([      "action": "$N����ʩ��һ�С�ʮ��ת�����ơ���$w��ʱ����������ҫ�ĵ�â����$nȫ��",
        "force" : 240,
        "dodge" : 90,
        "parry" : 90,
        "attack": 76,
        "damage": 104,
        "lvl"   : 200,
        "skill_name"  : "ʮ��ת������",
        "damage_type" : "����"
]),
});


int valid_enable(string usage)
{
	return usage == "blade" || usage == "parry";
}

int valid_learn(object me)
{
        if ((int)me->query("max_neili") < 500)
                return notify_fail("���������Ϊ������\n");

        if ((int)me->query_skill("force") < 80)
                return notify_fail("����ڹ����̫ǳ��\n");

        if ((int)me->query_skill("blade", 1) < 50)
                return notify_fail("��Ļ����������̫ǳ��\n");

        if ((int)me->query_skill("blade", 1) < (int)me->query_skill("shiying-lianhuan", 1))
                return notify_fail("��Ļ�������ˮƽ���ޣ��޷����������߱ӥ��������\n");

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
        level = (int) me->query_skill("shiying-lianhuan", 1);
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
                return notify_fail("�������������߱ӥ��������\n");

        if ((int)me->query("neili") < 60)
                return notify_fail("�������������߱ӥ��������\n");

        me->receive_damage("qi", 55);
        me->add("neili", -53);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"shiying-lianhuan/" + action;
}
