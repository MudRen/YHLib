inherit SKILL;

mapping *action = ({
([      "action": "$N��һ��������΢��������һ����һ�С�è�ڡ���һȭֱͱ$n��$l",
        "force" : 30,
        "dodge" : 5,
        "parry" : 7,
        "attack": 4,
        "damage": 4,
        "lvl"   : 0,
        "skill_name" : "è��",
        "damage_type": "����"
]),
([      "action": "$N����һЦ����ȭ�������ϣ���ȭƽƽ������һ�С��ù������������$n",
        "force" : 45,
        "dodge" : 18,
        "parry" : 17,
        "attack": 6,
        "damage": 6,
        "lvl"   : 20,
        "skill_name" : "�ù�",
        "damage_type": "����"
]),
([      "action": "$N��$nһ����ȣ�ʹһ�С�ӥ��������ȭ�������漴��ȭ���ϣ�������������$n��$l",
        "force" : 57,
        "dodge" : 16,
        "parry" : 19,
        "attack": 7,
        "damage": 11,
        "lvl"   : 40,
        "skill_name" : "ӥ��",
        "damage_type": "����"
]),
([      "action": "$N�ƺ�һ����˫ȭ���Ϸֿ���һ�ǡ����ӷ�����ȭ�����ߣ�����ͬʱ����$n��$l",
        "force" : 65,
        "dodge" : 24,
        "parry" : 21,
        "attack": 9,
        "damage": 14,
        "lvl"   : 60,
        "skill_name" : "���ӷ���",
        "damage_type": "����"
]),
([      "action": "$Nʩ����ϸ���ɡ���һ�����һȭ��մ����ȭ��ֱ��$n��$l",
        "force" : 85,
        "dodge" : 24,
        "parry" : 28,
        "attack": 13,
        "damage": 19,
        "lvl"   : 80,
        "skill_name" : "ϸ����",
        "damage_type": "����"
]),
([      "action": "$Nһ����Х��˫ȭ���������һ�С����ӽš���ȭ���ܲ�$n��ǰ������",
        "force" : 97,
        "dodge" : 28,
        "parry" : 30,
        "attack": 16,
        "damage": 21,
        "lvl"   : 100,
        "skill_name" : "���ӽ�",
        "damage_type": "����"
]),
([      "action": "$Nŭ��һ������շ���һʽ�������项��˫ȭ�Ӹ����£����봷��$n",
        "force" : 115,
        "dodge" : 24,
        "parry" : 21,
        "attack": 17,
        "damage": 24,
        "lvl"   : 120,
        "skill_name" : "������",
        "damage_type": "����"
]),
});

int valid_enable(string usage) { return usage == "unarmed" || usage == "cuff" || usage == "parry"; }

string main_skill() { return "baihua-cuoquan"; }

int valid_learn(object me)
{
        if (me->query_skill("baihua-cuoquan", 1) > 0)
                return notify_fail("���Ѿ������˰ٻ���ȭ�������ٵ���ѧϰ�ˡ�\n");

        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("������ȭ������֡�\n");

        if ((int)me->query_skill("force") < 30)
                return notify_fail("����ڹ���򲻹����޷�ѧ����ȭ��\n");

        if ((int)me->query("max_neili") < 100)
                return notify_fail("�������̫�����޷�������ȭ��\n");

        if ((int)me->query_skill("unarmed", 1) < 20)
                return notify_fail("��Ļ���ȭ�Ż��̫ǳ��\n");

        if ((int)me->query_skill("unarmed", 1) < (int)me->query_skill("liuhe-quan", 1))
                return notify_fail("��Ļ���ȭ��ˮƽ���ޣ��޷��������������ȭ��\n");

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
        level = (int) me->query_skill("liuhe-quan", 1);
        for (i = sizeof(action); i > 0; i--)
            if (level > action[i-1]["lvl"])
                return action[NewRandom(i, 5, level / 5)];
}

int practice_skill(object me)
{
        if( (int)me->query("qi") < 100 )
                return notify_fail("����������������Ϣһ�������ɡ�\n");

        if( (int)me->query("neili") < 80 )
                return notify_fail("������������ˡ�\n");

        me->receive_damage("qi", 80);
        me->add("neili", -50);

        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"liuhe-quan/" + action;
}
