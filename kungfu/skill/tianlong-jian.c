inherit SKILL;

mapping *action = ({
([      "action": "$N��ǰб��һ����һ�С���Ծ���š�������$wֱ��$n�ĺ�",
        "force" : 126,
        "parry" : 3,
        "dodge" : 5,
        "damage": 21,
        "lvl"   : 0,
        "skill_name" : "��Ծ����",
        "damage_type":  "����"
]),
([      "action": "$N����ǰ��һ�С����Գ��֡��������������ޣ�$w��������$n��$l��ȥ",
        "force" : 149,
        "parry" : 13,
        "dodge" : 10,
        "damage": 25,
        "lvl"   : 20,
        "skill_name" : "���Գ���",
        "damage_type":  "����"
]),
([      "action": "$Nһʽ�����Ƴ��ա�������Ʈ�����ߣ��˷�����������$wңҡָ��$n��$l",
        "force" : 167,
        "parry" : 12,
        "dodge" : 15,
        "damage": 31,
        "lvl"   : 40,
        "skill_name" : "���Ƴ���",
        "damage_type":  "����"
]),
([      "action": "$N��������Ծ��һʽ������̽צ����������ˮ��һкǧ�����$nȫ��",
        "force" : 187,
        "parry" : 23,
        "dodge" : 19,
        "damage": 45,
        "lvl"   : 60,
        "skill_name" : "����̽צ",
        "damage_type":  "����"
]),
([      "action":"$N����ǰ��һ�С�������ա��������������ޣ�$w��������$n��$l��ȥ",
        "force" : 197,
        "parry" : 31,
        "dodge" : 27,
        "damage": 56,
        "lvl"   : 90,
        "skill_name" : "�������",
        "damage_type":  "����"
]),
([      "action":"$N����$w�й�ֱ����һʽ��������衹��������Ϣ�ض�׼$n��$l�̳�һ��",
        "force" : 218,
        "parry" : 49,
        "dodge" : 35,
        "damage": 63,
        "lvl"   : 120,
        "skill_name" : "�������",
        "damage_type":  "����"
]),
([      "action":"$N����$wһ����һʽ�����������������ƶ�ʱ������Ϣ�ػ���$n$l��ȥ",
        "force" : 239,
        "parry" : 52,
        "dodge" : 45,
        "damage": 72,
        "lvl"   : 150,
        "skill_name" : "��������",
        "damage_type":  "����"
]),
});

int valid_enable(string usage) { return usage == "sword" || usage == "parry"; }

int valid_learn(object me)
{
        if (me->query_skill("force") < 70)
                return notify_fail("����ڹ���򲻹�������ѧϰ����������\n");

        if (me->query_skill("sword", 1) < 40)
                return notify_fail("��Ļ���������򲻹�������ѧϰ����������\n");

        if (me->query("max_neili") < 500)
                return notify_fail("�����������������ѧϰ����������\n");

        if ((int)me->query_skill("sword", 1) < (int)me->query_skill("tianlong-jian", 1))
                return notify_fail("��Ļ�������ˮƽ���ޣ��޷��������������������\n");

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
        level = (int) me->query_skill("tianlong-jian",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        object weapon;

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
                return notify_fail("��ʹ�õ��������ԡ�\n");

        if ((int)me->query("qi") < 60)
                return notify_fail("�����������������������\n");

        if ((int)me->query("neili") < 60)
                return notify_fail("�����������������������\n");

        me->receive_damage("qi", 52);
        me->add("neili", -53);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"tianlong-jian/" + action;
}
