#include <ansi.h>

inherit SKILL;

mapping *action = ({
([      "action": "$N�ݲ���ǰ������$wбб�̳���Ҳ��֪�����η���$n��ȫ�޷��м�",
        "force" : 72,
        "attack": 41,
        "parry" : 40,
        "dodge" : 31,
        "damage": 14,
        "lvl"   : 0,
        "damage_type" : "����"
]),
([      "action": "$N�˺����ߣ�����$w�͵ķ���ݳ����Ƶл��ȣ�����$n��$l",
        "force" : 94,
        "attack": 52,
        "parry" : 41,
        "dodge" : 42,
        "damage": 25,
        "lvl"   : 20,
        "damage_type" : "����"
]),
([      "action": "$N���е�$w��$nֱֱ��ȥ, �⿴�ƺ�ƽ����һ�о�Ȼ���ž޴��ɱ��",
        "force" : 115,
        "attack": 58,
        "parry" : 45,
        "dodge" : 43,
        "damage": 36,
        "lvl"   : 40,
        "damage_type" : "����"
]),
([      "action": "$Nһ����ȣ�����$w����������ó�����â���Ƶ�$n��������",
        "force" : 127,
        "attack": 61,
        "parry" : 48,
        "dodge" : 48,
        "damage": 45,
        "lvl"   : 60,
        "damage_type" : "����"
]),
([      "action": "$N����$w��â��˸��������â�еݳ�ɱ�ţ���ȫ����$n����֮��",
        "force" : 139,
        "attack": 68,
        "parry" : 51,
        "dodge" : 50,
        "damage": 52,
        "lvl"   : 80,
        "damage_type" : "����"
]),
([      "action": "$N����$wбб�̳�������ʵʵ������$n���ܣ���ȫ������$n����·",
        "force" : 152,
        "attack": 71,
        "parry" : 55,
        "dodge" : 55,
        "damage": 58,
        "lvl"   : 100,
        "damage_type" : "����"
]),
([      "action": "$N����ڵ���һ����𣬰���е��ǧ���ǣ��ִ�$n����Ҫ��",
        "force" : 173,
        "attack": 78,
        "parry" : 60,
        "dodge" : 62,
        "damage": 65,
        "lvl"   : 120,
        "damage_type" : "����"
]),
([      "action": "$N����Ծ������$w�����������˸�Ľ���������������£���$n������",
        "force" : 185,
        "attack": 81,
        "parry" : 64,
        "dodge" : 65,
        "damage": 78,
        "lvl"   : 140,
        "damage_type" : "����"
]),
([      "action": "$N���лζ�����������$w�����������������Ѹ���ޱȵĺ�������$n",
        "force" : 210,
        "attack": 94,
        "parry" : 68,
        "dodge" : 75,
        "damage": 91,
        "lvl"   : 160,
        "damage_type" : "����"
]),
([      "action": "$N�����������$w����ʱ�ó���㽣â, ���ɽ����ӽ�â�еݳ���ֱ֪����$n",
        "force" : 223,
        "attack": 104,
        "parry" : 70,
        "dodge" : 78,
        "damage": 102,
        "lvl"   : 180,
        "damage_type" : "����"
]),
([      "action": "$N����$wңָ���죬��â���²�������Ȼ�佣â���ǣ���׼$n��$lֱ���ȥ",
        "force" : 238,
        "attack": 115,
        "parry" : 72,
        "dodge" : 85,
        "damage": 118,
        "lvl"   : 200,
        "damage_type" : "����"
]),
([      "action": "$Nһ���޺ȣ����������ŷ���ֻ��$w���������һ��ǿ��Ľ���ϯ��$nȫ��",
        "force" : 280,
        "attack": 124,
        "parry" : 72,
        "dodge" : 85,
        "damage": 140,
        "lvl"   : 220,
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
                return notify_fail("���������Ϊ�������޷�ѧϰԭʼ������\n");

        if ((int)me->query_skill("force", 1) < 100)
                return notify_fail("����ڹ���򲻹����޷�ѧϰԭʼ������\n");

        if ((int)me->query_skill("sword", 1) < 100)
                return notify_fail("��Ļ���������򲻹����޷�ѧϰԭʼ������\n");

        if ((int)me->query_skill("sword", 1) < (int)me->query_skill("yuanshi-jian", 1))
                return notify_fail("��Ļ�������ˮƽ���ޣ��޷����������ԭʼ������\n");

        if ((int)me->query_skill("force", 1) < (int)me->query_skill("yuanshi-jian", 1))
                return notify_fail("��Ļ����ڹ�ˮƽ���ޣ��޷����������ԭʼ������\n");

        return 1;
}

mapping query_action(object me, object weapon)
{
        int i, level;
        level = (int) me->query_skill("yuanshi-jian", 1);
        for (i = sizeof(action); i > 0; i--)
                if (level > action[i - 1]["lvl"])
                        return action[NewRandom(i, 20, level / 5)];
}

int practice_skill(object me)
{
        object weapon;
        if (! objectp(weapon = me->query_temp("weapon"))
           || (string)weapon->query("skill_type") != "sword")
                return notify_fail("��ʹ�õ��������ԡ�\n");

        if ((int)me->query("qi") < 60)
                return notify_fail("�������������ԭʼ������\n");

        if ((int)me->query("neili") < 100)
                return notify_fail("�������������ԭʼ������\n");

        me->receive_damage("qi", 50);
        me->add("neili", -100);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"yuanshi-jian/" + action;
}
