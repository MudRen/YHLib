inherit SKILL;

mapping *action = ({
([      "action" : "$N��̤���Է�λ������$w���ƣ�����������$n��ȥ",
        "force"  : 145,
        "attack" : 35,
        "dodge"  : 30,
        "parry"  : 12,
        "lvl"    : 0,
        "damage" : 12,
        "damage_type" : "����",
]),
([      "action" : "$N�������¶��ϻ��˸��뻡��$wһ��һ�գ�ƽ�л���$n�ľ���",
        "force"  : 153,
        "attack" : 42,
        "dodge"  : 40,
        "parry"  : 15,
        "lvl"    : 20,
        "damage" : 18,
        "damage_type" : "����",
]),
([      "action" : "$N��̤���Է�λ��б����ǰ����$w��������һ��ѹ��$n",
        "force"  : 168,
        "attack" : 51,
        "dodge"  : 45,
        "parry"  : 17,
        "lvl"    : 40,
        "damage" : 24,
        "damage_type" : "����",
]),
([      "action" : "$Nת��Ƕ��λ�����ס�λ��$w������б����$n��ȥ",
        "force"  : 187,
        "attack" : 55,
        "dodge"  : 55,
        "parry"  : 21,
        "lvl"    : 60,
        "damage" : 35,
        "damage_type" : "����",
]),
([      "action" : "$N����$w��ת��Ծ��һ���׹�����$n���ؿ�",
        "force"  : 201,
        "attack" : 55,
        "dodge"  : 27,
        "parry"  : 32,
        "lvl"    : 80,
        "damage" : 35,
        "damage_type" : "����",
]),
([      "action" : "$N����$w���������ã����ҿ�����������$n",
        "force"  : 227,
        "attack" : 70,
        "dodge"  : 30,
        "parry"  : 35,
        "lvl"    : 100,
        "damage" : 40,
        "damage_type" : "����",
]),
([      "action" : "$N���Ծ����أ�$w˳����ǰ��Ю��������$n��$l",
        "force"  : 260,
        "attack" : 80,
        "dodge"  : 45,
        "parry"  : 35,
        "lvl"    : 120,
        "damage" : 46,
        "damage_type" : "����",
]),
});

int valid_enable(string usage) { return usage == "blade" || usage == "parry"; }

int valid_learn(object me)
{
        if ((int)me->query("max_neili") < 350)
                return notify_fail("�������������\n");

        if ((int)me->query_skill("force") < 50)
                return notify_fail("��Ļ����ڹ����̫ǳ��\n");

        if ((int)me->query_skill("blade", 1) < (int)me->query_skill("shangjia-dao", 1))
                return notify_fail("��Ļ�������������ޣ��޷�����������̼ҵ�����\n");

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
        level = (int) me->query_skill("shangjia-dao", 1);
        for (i = sizeof(action); i > 0; i--)
                if (level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level / 5)];
}

int practice_skill(object me)
{
        object weapon;

        if (! objectp(weapon = me->query_temp("weapon")) ||
            (string)weapon->query("skill_type") != "blade")
                return notify_fail("��ʹ�õ��������ԡ�\n");

        if ((int)me->query("qi") < 60)
                return notify_fail("��������������̼ҵ�����\n");

        if ((int)me->query("neili") < 40)
                return notify_fail("��������������̼ҵ�����\n");

        me->receive_damage("qi", 50);
        me->add("neili", -35);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"shangjia-dao/" + action;
}
