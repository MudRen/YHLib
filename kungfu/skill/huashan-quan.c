inherit SKILL;

mapping *action = ({
([      "action": "$Nʹһ�С�����Ǭ��������ȭ����ȭ֮�״�������׼$n$l��Ȼ��ȥ",
        "force" : 50,
        "dodge" : 20,
        "parry" : 20,
        "attack": 15,
        "damage": 20,
        "lvl"   : 0,
        "skill_name" : "����Ǭ��",
        "damage_type": "����"
]),
([      "action": "$N��ȭͻȻ�ſ���ȭ�����ƣ�һ�С����￴��������$n��$l�к���ȥ",
        "force" : 65,
        "dodge" : 25,
        "parry" : 25,
        "attack": 17,
        "damage": 23,
        "lvl"   : 20,
        "skill_name" : "���￴��",
        "damage_type":  "����"
]),
([      "action": "$N���ֻ�����ԣ�����һȦ��һ�С������������$n��$l����",
        "force" : 85,
        "dodge" : 31,
        "parry" : 33,
        "attack": 21,
        "damage": 28,
        "lvl"   : 40,
        "skill_name" : "�������",
        "damage_type":  "����"
]),
([      "action": "$N����һ������ȭ���һ�У���ȭʹ����÷��ŪӰ������$n$l",
        "force" : 110,
        "dodge" : 42,
        "parry" : 45,
        "attack": 35,
        "damage": 33,
        "lvl"   : 60,
        "skill_name" : "÷��ŪӰ",
        "damage_type":  "����"
]),
});

int valid_enable(string usage) { return usage == "cuff" || usage == "parry"; }

int valid_combine(string combo)
{
        return combo == "huashan-zhang";
}

int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("����ɽȭ��������֡�\n");

        if ((int)me->query_skill("force") < 30)
                return notify_fail("����ڹ���򲻹����޷�ѧ��ɽȭ����\n");

        if ((int)me->query_skill("cuff", 1) < 20)
                return notify_fail("��Ļ���ȭ�����̫ǳ��\n");

        if ((int)me->query_skill("cuff", 1) < (int)me->query_skill("huashan-quan", 1))
                return notify_fail("��Ļ���ȭ��ˮƽ���ޣ��޷���������Ļ�ɽȭ����\n");

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
        level = (int) me->query_skill("huashan-quan", 1);
        for (i = sizeof(action); i > 0; i--)
            if (level > action[i-1]["lvl"])
                return action[NewRandom(i, 5, level / 5)];
}

int practice_skill(object me)
{
        if ((int)me->query("qi") < 80)
                return notify_fail("�������̫���ˡ�\n");

        if ((int)me->query("neili") < 80)
                return notify_fail("���������������ɽȭ����\n");

        me->receive_damage("qi", 55);
        me->add("neili", -45);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"huashan-quan/" + action;
}
