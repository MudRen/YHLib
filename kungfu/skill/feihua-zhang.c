inherit SKILL;

mapping *action = ({
([      "action": "$Nʹһ�С���ѩʽ����һ��ֱ����Ϯ��$n$l",
        "force" : 60,
        "dodge" : 20,
        "parry" : 20,
        "attack": 15,
        "damage": 20,
        "lvl"   : 0,
        "skill_name" : "��ѩʽ",
        "damage_type": "����"
]),
([      "action": "$N����˫�������һ�С��仨ʽ�����Ʒ��������$n����",
        "force" : 85,
        "dodge" : 25,
        "parry" : 25,
        "attack": 17,
        "damage": 43,
        "lvl"   : 20,
        "skill_name" : "�仨ʽ",
        "damage_type":  "����"
]),
([      "action": "$N���ֻ�����ԣ�����һȦ��һ�С�ǧ���򻯡���$n��$l�ĳ�",
        "force" : 155,
        "dodge" : 31,
        "parry" : 33,
        "attack": 21,
        "damage": 68,
        "lvl"   : 40,
        "skill_name" : "ǧ����",
        "damage_type":  "����"
]),
});

int valid_enable(string usage) { return usage == "strike" || usage == "parry"; }

int valid_combine(string combo)
{
        return combo == "piaofeng-quan";
}

int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("���ɻ��Ʒ�������֡�\n");

        if ((int)me->query_skill("force") < 30)
                return notify_fail("����ڹ���򲻹����޷�ѧ�ɻ��Ʒ���\n");

        if ((int)me->query("max_neili") < 100)
                return notify_fail("�������̫�����޷����ɻ��Ʒ���\n");

        if ((int)me->query_skill("strike", 1) < 20)
                return notify_fail("��Ļ����Ʒ����̫ǳ��\n");

        if ((int)me->query_skill("strike", 1) < (int)me->query_skill("feihua-zhang", 1))
                return notify_fail("��Ļ����Ʒ�ˮƽ���ޣ��޷���������ķɻ��Ʒ���\n");

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
        level = (int) me->query_skill("feihua-zhang", 1);
        for (i = sizeof(action); i > 0; i--)
            if (level > action[i-1]["lvl"])
                return action[NewRandom(i, 5, level / 5)];
}

int practice_skill(object me)
{
        if ((int)me->query("qi") < 80)
                return notify_fail("�������̫���ˡ�\n");

        if ((int)me->query("neili") < 80)
                return notify_fail("��������������ɻ��Ʒ���\n");

        me->receive_damage("qi", 55);
        me->add("neili", -45);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"feihua-zhang/" + action;
}
