inherit SKILL;

mapping *action = ({
([      "action" : "$Nʹһ�С��׺���ա�������$w��ƮƮ����$n��$l��ȥ��",
        "force"  : 120,
        "dodge"  : 20,
        "parry"  : 14,
        "damage" : 25,
        "lvl"    : 0,
        "skill_name" : "�׺����",
        "damage_type": "����"
]),
([      "action" : "$N�������磬$w����һ�С�������硹���¶�������$n��$l",
        "force"  : 140,
        "dodge"  : 20,
        "parry"  : 15,
        "damage" : 20,
        "lvl"    : 20,
        "skill_name" : "�������",
        "damage_type": "����"
]),
([      "action" : "$N����һת��һ�С�����������$w������˸����������$n��$l",
        "force"  : 155,
        "dodge"  : 15,
        "parry"  : 16,
        "damage" : 25,
        "lvl"    : 40,
        "skill_name" : "��������",
        "damage_type": "����"
]),
([      "action" : "$N�趯$w��һ�С��ĳ���ң��Ѹ�����׵�����$n��$l",
        "force"  : 167,
        "dodge"  : 15,
        "parry"  : 18,
        "damage" : 35,
        "lvl"    : 60,
        "skill_name" : "�ĳ���ң",
        "damage_type": "����"
]),
([      "action" : "$N����$wһ�Σ�һ�С���ɽ���ɡ���$n��$lбб�̳�һ��",
        "force"  : 170,
        "dodge"  : 25,
        "parry"  : 21,
        "damage" : 25,
        "lvl"    : 80,
        "skill_name" : "��ɽ����",
        "damage_type": "����"
]),
([      "action" : "$N�ὣ���磬�������һ�С�����������ֱ��$n$l",
        "force"  : 174,
        "dodge"  : 25,
        "parry"  : 22,
        "damage" : 25,
        "lvl"    : 100,
        "skill_name" : "��������",
        "damage_type": "����"
]),
([      "action" : "$N����$w����һ�֣�һ�С��������������ֶ�׼$n$lһ����ȥ",
        "force"  : 189,
        "dodge"  : 15,
        "parry"  : 35,
        "damage" : 38,
        "lvl"    : 120,
        "skill_name" : "��������",
        "damage_type": "����"
]),
([      "action" : "$N�Ʋ�����ʹһ�С���ɽ��Ұ�����������ȫ����$n��$l",
        "force"  : 215,
        "dodge"  : 35,
        "parry" :  45,
        "damage" : 43,
        "lvl"    : 150,
        "skill_name" : "��ɽ��Ұ",
        "damage_type": "����"
]),
});


int valid_enable(string usage) { return usage == "sword" || usage == "parry"; }

int valid_learn(object me)
{
        if ((int)me->query("max_neili") < 100)
                return notify_fail("�������������\n");

        if ((int)me->query_skill("force") < 20)
                return notify_fail("����ڹ����̫ǳ��\n");

        if ((int)me->query_skill("sword", 1) < (int)me->query_skill("pomopima-jian", 1))
                return notify_fail("��Ļ�������ˮƽ���ޣ��޷������������ī���齣��\n");

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
        level = (int) me->query_skill("pomopima-jian", 1);
        for (i = sizeof(action); i > 0; i--)
                if (level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level / 5)];

}

int practice_skill(object me)
{
        object weapon;

        if (! objectp(weapon = me->query_temp("weapon")) ||
            (string)weapon->query("skill_type") != "sword")
                return notify_fail("��ʹ�õ��������ԡ�\n");

        if ((int)me->query("qi") < 60)
                return notify_fail("���������������ī���齣��\n");

        if ((int)me->query("neili") < 60)
                return notify_fail("���������������ī���齣��\n");

        me->receive_damage("qi", 55);
        me->add("neili", -55);

        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"pomopima-jian/" + action;
}
