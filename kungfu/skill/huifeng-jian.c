inherit SKILL;

mapping *action = ({
([      "skill_name" : "���Ϯ��",
        "action": "$N���⽣â������һ�С����Ϯ�¡�������$w�����´󿪴��أ�һ��\n"
                  "��������$n��$l",
        "force" : 125,
        "attack": 23,
        "dodge" : 5,
        "damage": 42,
        "lvl"   : 0,
        "damage_type" : "����"
]),
([      "skill_name" : "Ʈѩ����",
        "action": "$N����Ȧת��ʩһ�С�Ʈѩ���ơ�������$wƽչ�´̣�һ�����Ữ��\n"
                  "$n��$l",
        "force" : 172,
        "attack": 31,
        "dodge" : 10,
        "damage": 59,
        "lvl"   : 20,
        "damage_type" : "����"
]),
([      "skill_name" : "ǧ�徺��",
        "action": "ֻ��$N��������������������������$w�͵�ʹ��һʽ��ǧ�徺�㡹\n"
                  "����$n��$l",
        "force" : 185,
        "attack": 39,
        "dodge" : 10,
        "damage": 73,
        "lvl"   : 40,
        "damage_type" : "����"
]),
([      "skill_name" : "��������",
        "action": "$N������ָ��������ת��һ�С��������ڡ�ֱȡ$n��$l",
        "force" : 197,
        "attack": 45,
        "dodge" : 10,
        "damage": 75,
        "lvl"   : 60,
        "damage_type" : "����"
]),
([      "skill_name" : "��������",
        "action": "$N��â���£��������ߣ�����$wʹ��һʽ����������������������\n"
                  "�Ƿ�������$n��$l",
        "force" : 212,
        "attack": 44,
        "dodge" : 10,
        "damage": 96,
        "lvl"   : 90,
        "damage_type" : "����"
]),
([      "skill_name" : "������ɳ",
        "action": "$N�����ƽ���������ʵ��׷ɣ��ó�����ǹ⣬����$w��Ȼʹ����\n"
                  "ʽ��������ɳ��ԾԾ����Ʈ��$n��$l",
        "force" : 230,
        "attack": 47,
        "dodge" : 15,
        "damage": 123,
        "lvl"   : 100,
        "damage_type" : "����"
]),
([      "skill_name" : "��������",
        "action": "$N�ӽ��ֻ�����������ǰԾ��������$wһʽ���������Ρ���������\n"
                  "��֮�ƣ�����$n��$l",
        "force" : 250,
        "attack": 51,
        "dodge" : 15,
        "lvl"   : 110,
        "damage": 125,
        "damage_type" : "����"
]),
([      "skill_name" : "��غ���",
        "action": "$N�˲������ֽ�ָ��ת������һŤ������$wһ�ǡ���غ��衹����\n"
                  "���ϴ���$n��$l",
        "force" : 275,
        "attack": 65,
        "dodge" : 25,
        "damage": 130,
        "lvl"   : 120,
        "damage_type" : "����"
]),
});

int valid_enable(string usage)
{
	return usage == "sword" || usage == "parry";
}

int valid_learn(object me)
{
        if ((int)me->query("max_neili") < 1200)
                return notify_fail("���������Ϊ������\n");

        if ((int)me->query_skill("force", 1) < 100)
                return notify_fail("����ڹ����̫ǳ��\n");

        if ((int)me->query_skill("sword", 1) < 100)
                return notify_fail("��Ļ����������̫ǳ��\n");

        if (me->query_skill("sword", 1) < me->query_skill("huifeng-jian"))
                return notify_fail("��Ļ�������ˮƽ���ޣ��޷���������Ļط��������\n");

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

        level = (int) me->query_skill("huifeng-jian", 1);
        for (i = sizeof(action); i > 0; i--)
                if (level > action[i-1]["lvl"])
                       return action[NewRandom(i, 20, level/5)];

}

int practice_skill(object me)
{
        object weapon;

        if (! objectp(weapon = me->query_temp("weapon")) ||
            (string)weapon->query("skill_type") != "sword")
                return notify_fail("��ʹ�õ��������ԡ�\n");

        if ((int)me->query("qi") < 60)
                return notify_fail("��������������ط��������\n");

        if ((int)me->query("neili") < 60)
                return notify_fail("��������������ط��������\n");

        me->receive_damage("qi", 45);
        me->add("neili", -58);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"huifeng-jian/" + action;
}
