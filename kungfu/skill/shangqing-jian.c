inherit SKILL;

mapping *action = ({
([      "action": "$Nʹһʽ����¥������������$w���Ӷ��£��ó�һ���¹����$n��$l",
        "force" : 90,
        "attack": 30,
        "dodge" : 10,
        "parry" : 25,
        "damage": 25,
        "lvl"   : 0,
        "skill_name" : "��¥����",
        "damage_type": "����"
]),
([      "action": "$N����ǰ��һ�С������뵡��������������ޣ�$w��������$n��$l",
        "force" : 140,
        "attack": 60,
        "dodge" : 25,
        "parry" : 25,
        "damage": 40,
        "lvl"   : 40,
        "skill_name" : "������",
        "damage_type": "����"
]),
([      "action": "$Nһʽ���������ơ�������Ʈ�����ߣ����͵ش���ǰ������$w����$n��$l",
        "force" : 180,
        "attack": 60,
        "dodge" : 25,
        "parry" : 28,
        "damage": 40,
        "lvl"   : 80,
        "skill_name" : "��������",
        "damage_type": "����"
]),
([      "action": "$N��������Ծ��һʽ�������ԡ������������������$n",
        "force" : 220,
        "attack": 75,
        "dodge" : 20,
        "parry" : 35,
        "damage": 60,
        "lvl"   : 120,
        "skill_name" : "������",
        "damage_type": "����"
]),
([      "action": "$N����$w��â���£�����������һʽ������һ̶������׼$n��$lֱֱ�̳�",
        "force" : 260,
        "attack": 90,
        "dodge" : 25,
        "parry" : 50,
        "damage": 70,
        "lvl"   : 160,
        "skill_name" : "����һ̶",
        "damage_type": "����"
]),
([      "action": "$N���һ����$w�Ƴ�����â����$n������һʽ�����ݽ𶥡�������$n��$l",
        "force" : 285,
        "attack": 97,
        "dodge" : 31,
        "parry" : 48,
        "damage": 73,
        "lvl"   : 200,
        "skill_name" : "���ݽ�",
        "damage_type": "����"
]),
});

int valid_enable(string usage) { return usage == "sword" || usage == "parry"; }

int valid_learn(object me)
{
        if ((int)me->query("max_neili") < 600)
                return notify_fail("���������Ϊ�������޷�ѧϰ���彣����\n");

        if ((int)me->query_skill("force", 1) < 50)
                return notify_fail("����ڹ����̫ǳ���޷�ѧϰ���彣����\n");

        if ((int)me->query_skill("sword", 1) < 60)
                return notify_fail("��Ļ����������̫ǳ���޷�ѧϰ���彣����\n");

        if ((int)me->query_skill("sword", 1) < (int)me->query_skill("shangqing-jian", 1))
                return notify_fail("��Ļ�������ˮƽ���ޣ��޷�������������彣����\n");

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
        level = (int) me->query_skill("shangqing-jian", 1);
        for (i = sizeof(action); i > 0; i--)
                if (level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level / 5)];
}

int practice_skill(object me)
{
        object weapon;

        if (!objectp(weapon = me->query_temp("weapon")) ||        
            (string)weapon->query("skill_type") != "sword")
                return notify_fail("��ʹ�õ��������ԡ�\n");

        if ((int)me->query("qi") < 120)
                return notify_fail("����������������彣����\n");

        if ((int)me->query("neili") < 80)
                return notify_fail("����������������彣����\n");

        me->receive_damage("qi", 100);
        me->add("neili", -55);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"shangqing-jian/" + action;
}
