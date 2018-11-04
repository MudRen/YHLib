inherit SKILL;

mapping *action = ({
([      "action": "$N�����ϲ����������ǣ�˫ȭ��������$n��$l",
        "force" : 80,
        "attack": 12,
        "parry" : 14,
        "dodge" : 5,
        "lvl"   : 0,
        "damage_type" : "����"
]),
([      "action": "$N�����̤��ȫ����ת������Ť�����ұ�˳���͵�ɨ��$n��$l",
        "force" : 100,
        "attack": 15,
        "parry" : 16,
        "dodge" : 10,
        "lvl"   : 8,
        "damage_type" : "����"
]),
([      "action": "$N������ǰһ�Σ����˫�ƣ�ָ���أ��͵���$n��$l��ȥ",
        "force" : 120,
        "attack": 18,
        "parry" : 19,
        "dodge" : 5,
        "lvl"   : 15,
        "damage_type" : "����"
]),
([      "action": "$N����һ�����ȣ����Ӷ�ʱ��ǰһ�㣬˫��˳���ĳ���������һ������$n",
        "force" : 170,
        "attack": 23,
        "parry" : 24,
        "dodge" : 10,
        "lvl"   : 42,
        "damage_type" : "����"
]),
([      "action": "$Nҡҡ�λΣ�ƫƫ��������˫ȭȴȭ����磬������$nͷ���أ�������Ҫ��",
        "force" : 200,
        "attack": 25,
        "parry" : 24,
        "dodge" : 5,
        "lvl"   : 50,
        "damage_type" : "����"
]),
([      "action": "$N�������ʣ���ȴ�������ᣬһ����ȣ����һ�ھ���������Юǧ��֮������$n",
        "force" : 210,
        "attack": 28,
        "parry" : 25,
        "dodge" : 10,
        "lvl"   : 58,
        "damage_type" : "����"
]),
});

int valid_enable(string usage)
{
        return usage == "cuff" || usage == "unarmed" || usage == "parry";
}

int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("����ȭ���������֡�\n");

        if ((int)me->query_skill("force") < 20)
                return notify_fail("����ڹ���򲻹����޷�ѧ��ȭ����\n");

        if ((int)me->query("max_neili") < 50)
                return notify_fail("�������̫�����޷�����ȭ����\n");

        if (me->query_skill("unarmed", 1) < me->query_skill("zuiquan-sanda", 1)
           && me->query_skill("cuff", 1) < me->query_skill("zuiquan-sanda", 1))
                return notify_fail("��ȭ����ȭ��������㣬�޷�������"
                                   "�����ȭ����\n");

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
        level = (int) me->query_skill("zuiquan-sanda", 1);
        for (i = sizeof(action); i > 0; i--)
                if (level > action[i - 1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        if (me->query_temp("weapon") ||
            me->query_temp("secondary_weapon"))
                return notify_fail("����������ϰ��\n");

        if ((int)me->query("qi") < 35)
                return notify_fail("�������̫���ˡ�\n");

        if ((int)me->query("neili") < 30)
                return notify_fail("������������ˡ�\n");

        me->receive_damage("qi", 25);
        me->add("neili", -20);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__ "zuiquan-sanda/" + action;
}
