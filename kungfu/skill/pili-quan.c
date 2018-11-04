inherit SKILL;

mapping *action = ({
([      "action": "$Nʹһ�С�����������˫ȭ�ɳ���Ϯ��$n$l",
        "force" : 130,
        "dodge" : 20,
        "parry" : 20,
        "attack": 15,
        "damage": 20,
        "lvl"   : 0,
        "skill_name" : "������",
        "damage_type": "����"
]),
([      "action": "$N����˫ȭ����������һ�С����׺䡹��ȭ�����죬Ϯ��$n$l",
        "force" : 185,
        "dodge" : 25,
        "parry" : 25,
        "attack": 17,
        "damage": 43,
        "lvl"   : 20,
        "skill_name" : "���׺�",
        "damage_type":  "����"
]),
([      "action": "$N����Ȧ���������⵱�أ����ֻ��ڳ��ϣ�һ�С���ؾ�������$n��",
        "force" : 220,
        "dodge" : 31,
        "parry" : 33,
        "attack": 21,
        "damage": 68,
        "lvl"   : 40,
        "skill_name" : "��ؾ�",
        "damage_type":  "����"
]),
});

int valid_enable(string usage) { return usage == "cuff" || usage == "parry"; }

int valid_combine(string combo)
{
        return combo == "feihua-zhang";
}

int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("��������������֡�\n");

        if ((int)me->query_skill("force") < 20)
                return notify_fail("����ڹ���򲻹����޷�ѧ������ȭ��\n");

        if ((int)me->query("max_neili") < 100)
                return notify_fail("�������̫�����޷���������ȭ��\n");

        if ((int)me->query_skill("cuff", 1) < 20)
                return notify_fail("��Ļ���ȭ�����̫ǳ��\n");

        if ((int)me->query_skill("cuff", 1) < (int)me->query_skill("pili-quan", 1))
                return notify_fail("��Ļ���ȭ��ˮƽ���ޣ��޷����������������ȭ��\n");

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
        level = (int) me->query_skill("pili-quan", 1);
        for (i = sizeof(action); i > 0; i--)
            if (level > action[i-1]["lvl"])
                return action[NewRandom(i, 5, level / 5)];
}

int practice_skill(object me)
{
        if ((int)me->query("qi") < 80)
                return notify_fail("�������̫���ˡ�\n");

        if ((int)me->query("neili") < 80)
                return notify_fail("�������������������ȭ��\n");

        me->receive_damage("qi", 55);
        me->add("neili", -45);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"pili-quan/" + action;
}
