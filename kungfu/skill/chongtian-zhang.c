// ��׫������Ʒ��������������佣�����

inherit SKILL;

mapping *action = ({
([      "action": "$N˫������һ�С��²�ժ���ơ���һ�ƻ���$n���ţ���һ��ȴ����$nС��",
        "force" : 185,
        "dodge" : 11,
        "parry" : 12,
        "attack": 9,
        "damage": 12,
        "lvl"   : 0,
        "skill_name" : "�²�ժ����",
        "damage_type": "����"
]),
([      "action": "$N˫�ƻ������Ī�⣬һ�С�ϴ�����б��¡���˲Ϣ֮������$n��������",
        "force" : 205,
        "dodge" : 18,
        "parry" : 17,
        "attack": 13,
        "damage": 17,
        "lvl"   : 30,
        "skill_name" : "ϴ�����б���",
        "damage_type": "����"
]),
([      "action": "$Nһ����Х������һ�ƣ�һ�С�����ת�����롹��ȥ����죬��$n�ͻ���ȥ",
        "force" : 217,
        "dodge" : 16,
        "parry" : 19,
        "attack": 17,
        "damage": 21,
        "lvl"   : 60,
        "skill_name" : "����ת������",
        "damage_type": "����"
]),
([      "action": "$N˫�ƽ����������ޣ�һ�С��ϲ��Ʊ�ժ�¡�������ת׾������$n��$l",
        "force" : 225,
        "dodge" : 24,
        "parry" : 21,
        "attack": 22,
        "damage": 33,
        "lvl"   : 90,
        "skill_name" : "�ϲ��Ʊ�ժ��",
        "damage_type": "����"
]),
([      "action": "$Nһ�С����ý��׺���᡹������һȭ���������ƽ���������ȭ˳�ƻ���$n��$l",
        "force" : 255,
        "dodge" : 24,
        "parry" : 28,
        "attack": 33,
        "damage": 41,
        "lvl"   : 120,
        "skill_name" : "���ý��׺����",
        "damage_type": "����"
]),
([      "action": "$N˫���뻮������˫�����ƣ�һ�С����������ر�������һ����ɽ������ֱ��$n",
        "force" : 267,
        "dodge" : 28,
        "parry" : 30,
        "attack": 36,
        "damage": 49,
        "lvl"   : 150,
        "skill_name" : "���������ر���",
        "damage_type": "����"
]),
});

int valid_enable(string usage) { return usage == "strike" || usage == "parry"; }

int valid_combine(string combo) { return combo == "panlong-zhao"; }

int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("���׺׳����Ʊ�����֡�\n");

        if ((int)me->query_skill("force") < 100)
                return notify_fail("����ڹ���򲻹����޷�ѧ�׺׳����ơ�\n");

        if ((int)me->query("max_neili") < 800)
                return notify_fail("�������̫�����޷����׺׳����ơ�\n");

        if ((int)me->query_skill("strike", 1) < 60)
                return notify_fail("��Ļ����Ʒ����̫ǳ��\n");

        if ((int)me->query_skill("strike", 1) < (int)me->query_skill("chongtian-zhang", 1))
                return notify_fail("��Ļ����Ʒ�ˮƽ���ޣ��޷���������İ׺׳����ơ�\n");

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
        level = (int) me->query_skill("chongtian-zhang", 1);
        for (i = sizeof(action); i > 0; i--)
            if (level > action[i-1]["lvl"])
                return action[NewRandom(i, 5, level / 5)];
}

int practice_skill(object me)
{
        if ((int)me->query("qi") < 80)
                return notify_fail("�������̫���ˡ�\n");

        if ((int)me->query("neili") < 100)
                return notify_fail("��������������׺׳����ơ�\n");

        me->receive_damage("qi", 55);
        me->add("neili", -90);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"chongtian-zhang/" + action;
}
