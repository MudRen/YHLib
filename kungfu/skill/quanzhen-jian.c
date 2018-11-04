inherit SKILL;

mapping *action = ({
([      "action":"$Nʹһʽ��̽��������������$w�������Һ�ɨ����$n��$l",
        "force" : 70,
        "attack": 10,
        "dodge" : 10,
        "damage": 13,
        "lvl" : 0,
        "skill_name" : "̽������",
        "damage_type":  "����"
]),
([      "action":"$N̤��һ�������ɨҶ��������$w���������һ����������$n��$l",
        "force" : 74,
        "attack": 15,
        "dodge" : 20,
        "damage": 19,
        "lvl" : 10,
        "skill_name" : "�ɨҶ",
        "damage_type":  "����"
]),
([      "action":"$N����$wһ����һ�С�˳ˮ���ۡ���ббһ�������ó�������$n��$l",
        "force" : 85,
        "attack": 20,
        "dodge" : 25,
        "damage": 21,
        "lvl" : 20,
        "skill_name" : "˳ˮ����",
        "damage_type":  "����"
]),
([      "action":"$N����$w����������Ȧ��һʽ���ǳڵ�������һ���������$n��$l",
        "force" : 118,
        "attack": 25,
        "dodge" : 30,
        "damage": 28,
        "lvl" : 40,
        "skill_name" : "�ǳڵ���",
        "damage_type":  "����"
]),
([      "action":"$Nһʽ���׺����᡹��������չ������$w����$n��$l",
        "force" : 130,
        "attack": 30,
        "dodge" : 35,
        "damage": 32,
        "lvl" : 60,
        "skill_name" : "�׺�����",
        "damage_type":  "����"
]),
([      "action":"$N����$wбָ���죬һʽ������Į��������׼$n��$lбб����",
        "force" : 150,
        "attack": 33,
        "dodge" : 45,
        "damage": 39,
        "lvl" : 80,
        "skill_name" : "����Į��",
        "damage_type":  "����"
]),
([      "action":"$Nһʽ�������仨�������󼱶�������������⣬����$n��$l",
        "force" : 170,
        "attack": 36,
        "dodge" : 42,
        "damage": 48,
        "lvl" : 100,
        "skill_name" : "�����仨",
        "damage_type":  "����"
]),
([      "action":"$Nһʽ����Ʒ��̨����$w��ն�������缲�������$n���ؿ�",
        "force" : 193,
        "attack": 40,
        "dodge" : 55,
        "damage": 54,
        "lvl" : 120,
        "skill_name" : "��Ʒ��̨",
        "damage_type":  "����"
]),
([      "action":"$Nʹһʽ��������ء�������$w������$n���ؿڣ������ɵ�",
        "force" : 220,
        "attack": 45,
        "dodge" : 55,
        "damage": 63,
        "lvl" : 140,
        "skill_name" : "�������",
        "damage_type":  "����"
]),
([      "action":"$N����$w����һ�������Ļ��ߣ�����$n��$l��ȴ��һ�С���ʷ������",
        "force" : 240,
        "attack": 50,
        "dodge" : 58,
        "damage": 75,
        "lvl" : 160,
        "skill_name" : "��ʷ����",
        "damage_type":  "����"
]),
([      "action":"$N�ؽ����أ�ʹһʽ��������项���������$w��$n����",
        "force" : 280,
        "attack": 55,
        "dodge" : 65,
        "damage": 88,
        "lvl" : 180,
        "skill_name" : "�������",
        "damage_type":  "����"
]),
([      "action":"$N��������һʽ�������߶�����$w�Ӳ���˼��ĽǶȴ���$n",
        "force" : 340,
        "attack": 57,
        "dodge" : 62,
        "damage": 103,
        "lvl" : 200,
        "skill_name" : "�����߶�",
        "damage_type":  "����"
]),
([      "action":"$Nһʽ���ϵ紩�ơ���$wͻȻ���������һƬ���Χ��$nȫ��",
        "force" : 370,
        "attack": 60,
        "dodge" : 66,
        "damage": 135,
        "lvl" : 220,
        "skill_name" : "�ϵ紩��",
        "damage_type":  "����"
])
});

int valid_enable(string usage)
{
	return usage == "sword" || usage == "parry";
}

int valid_learn(object me)
{
        if ((int)me->query_skill("force") < 150)
                return notify_fail("����ڹ�����㣬�޷�ѧϰȫ�潣����\n");

        if (me->query("max_neili") < 1000)
                return notify_fail("���������Ϊ̫��޷�ѧϰȫ�潣����\n");

        if (me->query_skill("sword", 1) < 100)
                return notify_fail("��Ļ���������Ϊ�������޷�ѧϰȫ�潣����\n");

        if (me->query_skill("sword", 1) < me->query_skill("quanzhen-jian", 1))
                return notify_fail("��Ļ�������ˮƽ���ޣ��޷����������ȫ�潣����\n");

        return 1;
}

string query_skill_name(int level)
{
        int i;
        for(i = sizeof(action)-1; i >= 0; i--)
                if(level >= action[i]["lvl"])
                        return action[i]["skill_name"];
}

mapping query_action(object me, object weapon)
{
        int i, level;
        level = (int) me->query_skill("quanzhen-jian",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        object weapon;

        if (! objectp(weapon = me->query_temp("weapon")) ||
            (string)weapon->query("skill_type") != "sword")
                return notify_fail("��ʹ�õ��������ԡ�\n");

        if ((int)me->query("qi") < 60)
                return notify_fail("�������������ȫ�潣����\n");

        if ((int)me->query("neili") < 60)
                return notify_fail("�������������ȫ�潣����\n");

        me->receive_damage("qi", 55);
        me->add("neili", -53);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"quanzhen-jian/" + action;
}
