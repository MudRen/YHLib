inherit SKILL;

mapping *action = ({
([      "action" : "$Nһ�С�ǧ��������������ƽ�ƻ��ƶ�������Ȼ����$n��$l",
        "force"  : 33,
        "dodge"  : 5,
        "parry"  : 2,
        "attack" : 2,
        "damage" : 1,
        "lvl"    : 0,
        "skill_name" : "ǧ������",
        "damage_type": "����"
]),
([      "action" : "$Nʹһ�С����ò���������ֻ���һ��Ȧ�ӣ����ֻ���$n��ȥ",
        "force"  : 45,
        "dodge"  : 18,
        "parry"  : 17,
        "attack" : 6,
        "damage" : 4,
        "lvl"    : 20,
        "skill_name" : "���ò��",
        "damage_type": "����"
]),
([      "action" : "$N�����ɹ����ƣ�ʹһ�С�����ǧ���������Ƶ�ʱ��ɨ$n��$l",
        "force"  : 51,
        "dodge"  : 16,
        "parry"  : 19,
        "attack" : 11,
        "damage" : 7,
        "lvl"    : 40,
        "skill_name" : "����ǧ��",
        "damage_type": "����"
]),
([      "action" : "$N˫�ֻ�����˫���ַ��ĳ���ʹһ�С�����˷�������$n������",
        "force"  : 62,
        "dodge"  : 24,
        "parry"  : 21,
        "attack" : 15,
        "damage" : 9,
        "lvl"    : 60,
        "skill_name" : "����˷�",
        "damage_type": "����"
]),
});

int valid_enable(string usage)
{
        return usage == "strike" || usage == "parry";
}

int valid_combine(string combo)
{
        return combo == "jueming-tui";
}

int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("��ͭ���Ʒ�������֡�\n");

        if ((int)me->query_skill("force") < 15)
                return notify_fail("����ڹ���򲻹����޷�ѧͭ���Ʒ���\n");

        if ((int)me->query("max_neili") < 100)
                return notify_fail("���������Ϊ̫�����޷���ͭ���Ʒ���\n");

        if ((int)me->query_skill("strike", 1) < (int)me->query_skill("tongchui-zhang", 1))
                return notify_fail("��Ļ����Ʒ�����㣬�޷����������ͭ���Ʒ���\n");

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
        level = (int) me->query_skill("tongchui-zhang", 1);
        for (i = sizeof(action); i > 0; i--)
            if (level > action[i-1]["lvl"])
                return action[NewRandom(i, 5, level / 5)];
}

int practice_skill(object me)
{
        if ((int)me->query("qi") < 60)
                return notify_fail("����������������Ϣһ�������ɡ�\n");

        if ((int)me->query("neili") < 50)
                return notify_fail("�������������ͭ���Ʒ���\n");

        me->receive_damage("qi", 48);
        me->add("neili", -42);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"tongchui-zhang/" + action;
}
