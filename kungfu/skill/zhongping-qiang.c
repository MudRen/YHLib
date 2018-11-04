inherit SKILL;

mapping *action = ({
([      "action": "$N˫��һ�𣬾���ǰ�죬ʹ��һ�С���ƽ�޵С�������$wƽƽ����$n",
        "force" : 80,
        "dodge" : 3,
        "damage": 30,
        "attack": 10,
        "parry" : 25,
        "lvl"   : 0,
        "skill_name" : "��ƽ�޵�",
        "damage_type": "����"
]),
([      "action": "$N����$w������ת�������¶ף�����һ�С�ҹ��̽����������$n��ȥ",
        "force" : 100,
        "dodge" : 5,
        "damage": 40,
        "attack": 20,
        "parry" : 25,
        "lvl"   : 40,
        "skill_name" : "ҹ��̽��",
        "damage_type": "����"
]),
([      "action": "$N�߸߾���$w��ӭ�ն�������ǹ����һ�С����߳�������$n������ȥ",
        "force" : 110,
        "dodge" : 10,
        "damage": 44,
        "attack": 27,
        "parry" : 21,
        "lvl"   : 80,
        "skill_name" : "���߳���",
        "damage_type": "����"
]),
([      "action": "$Nʩ����������ת��������$wб����ȥ$n�ĺ��У�������������$n",
        "force" : 120,
        "dodge" : -5,
        "damage": 50,
        "attack": 30,
        "parry" : 35,
        "lvl"   : 120,
        "skill_name" : "������ת",
        "damage_type": "����"
]),
});

int valid_enable(string usage)
{
	return usage == "club" || usage == "parry";
}

int valid_learn(object me)
{
        object weapon;

        if (! objectp(weapon = me->query_temp("weapon"))
           || (string)weapon->query("skill_type") != "club")
                return notify_fail("���������һ�����Ӳ�������ƽǹ����\n");

        if ((int)me->query("max_neili") < 1000)
                return notify_fail("���������Ϊ���㣬û�а취����ƽǹ����\n");

        if ((int)me->query_skill("force") < 100)
                return notify_fail("����ڹ����̫ǳ��û�а취����ƽǹ����\n");

        if ((int)me->query_skill("club", 1) < 80)
                return notify_fail("��Ĺ����������㣬û�а취����ƽǹ����\n");

        if ((int)me->query_skill("club", 1) < (int)me->query_skill("zhongping-qiang", 1))
                return notify_fail("��Ļ�������ˮƽ�������޷������������ƽǹ����\n");

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
        level = (int) me->query_skill("zhongping-qiang", 1);
        for (i = sizeof(action); i > 0; i--)
                if (level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level / 5)];

}

int practice_skill(object me)
{
        object weapon;

        if (! objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "club")
                return notify_fail("��ʹ�õ��������ԡ�\n");

        if ((int)me->query("qi") < 50)
                return notify_fail("���������������ƽǹ����\n");

        if ((int)me->query("neili") < 50)
                return notify_fail("���������������ƽǹ����\n");

        me->receive_damage("qi", 20);
        me->add("neili", -20);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"zhongping-qiang/" + action;
}
