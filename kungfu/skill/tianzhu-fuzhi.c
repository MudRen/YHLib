// tianzhu-fuzhi.c ���÷�ָ

inherit SHAOLIN_SKILL;

mapping *action = ({
([      "action": "$N����̧�ۣ���ָ���˸���Ȧ�����������$n$l����������",
        "force" : 100,
        "attack": 10,
        "parry" : 15,
        "dodge" : -5,
        "lvl"   : 0,
        "damage_type" : "��Ѩ"
]),
([      "action": "$N�������У�������ָ��Ҹ���������$n��ǰ�����ҪѨ",
        "force" : 140,
        "attack": 15,
        "parry" : 18,
        "dodge" : -5,
        "lvl"   : 20,
        "damage_type" : "��Ѩ"
]),
([      "action": "$N����б�У����ְ��ƣ�������ָ��ʳָ��$n��$l�������",
        "force" : 170,
        "attack": 20,
        "parry" : 25,
        "dodge" : 5,
        "lvl"   : 40,
        "damage_type" : "��Ѩ"
]),
([      "action": "$N˫Ŀ΢����˫��ʮָ�û���ǧ�ٸ�ָӰ������$n��$l",
        "force" : 210,
        "attack": 28,
        "parry" : 30,
        "dodge" : 5,
        "damage": 10,
        "lvl"   : 60,
        "damage_type" : "��Ѩ"
]),
([      "action": "ֻ��$N���ƻ�ס�������бָ���죬���Ƶ���$n��$l",
        "force" : 250,
        "attack": 30,
        "parry" : 35,
        "dodge" : 15,
        "damage": 10,
        "lvl"   : 80,
        "damage_type" : "��Ѩ"
]),
});

string main_skill() { return "canhe-zhi"; }

int valid_enable(string usage) { return usage == "finger" ||  usage == "parry"; }

int valid_learn(object me)
{
        if ((int)me->query_skill("canhe-zhi", 1))
                return notify_fail("���ѽ�����ָ������κ�ָ�������ٷֿ���ϰ�ˡ�\n");

        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("�����÷�ָ������֡�\n");

        if ((int)me->query_skill("force") < 30)
                return notify_fail("����ڹ���򲻹����޷�ѧ���÷�ָ��\n");

        if ((int)me->query_skill("finger", 1) < 10)
                return notify_fail("��Ļ���ָ����򲻹����޷�ѧ���÷�ָ��\n");

        if ((int)me->query("max_neili") < 300)
                return notify_fail("�������̫�����޷������÷�ָ��\n");

        if (me->query_skill("finger", 1) < me->query_skill("tianzhu-fuzhi", 1))
                return notify_fail("��Ļ���ָ��̫��޷�������������÷�ָ��\n");

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
        level = (int) me->query_skill("tianzhu-fuzhi",1);
        for (i = sizeof(action); i > 0; i--)
                if (level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        if ((int)me->query_skill("canhe-zhi", 1))
                return notify_fail("���ѽ�����ָ������κ�ָ�������ٷֿ���ϰ�ˡ�\n");

        if ((int)me->query("qi") < 70)
                return notify_fail("�������̫���ˣ��޷������÷�ָ��\n");

        if ((int)me->query("neili") < 70)
                return notify_fail("��������������޷������÷�ָ��\n");

        me->receive_damage("qi", 55);
        me->add("neili", -51);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"tianzhu-fuzhi/" + action;
}
