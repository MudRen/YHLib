#include <ansi.h>
inherit SKILL;

mapping *action = ({
([      "action": "$N����Ծ��һ�С����չ�᡹������$w���¶��ϣ�����$n������",
        "force" : 100,
        "dodge" : 0,
        "damage": 20,
        "lvl"   : 15,
        "skill_name" : "���չ��",
        "damage_type":  "����"
]),
([      "action": "$Nһ�С��ʷ����ࡹ������$w�ڿ�һ��ֱ����$n��$l��ȥ",
        "force" : 110,
        "dodge" : -10,
        "damage": 30,
        "lvl"   : 20,
        "skill_name" : "�ʷ�����",
        "damage_type":  "����"
]),
([      "action": "$Nһ�С��������������$w�ڿ�һ��һ�����죬�͵���$n��ͷ����",
        "force" : 120,
        "dodge" : -15,
        "damage": 40,
        "lvl"   : 40,
        "skill_name" : "�����",
        "damage_type":  "����"
]),
([      "action": "$N̤��һ��������$w����ͣ����һ�С�����Ϸ���ɨ��$n��$l",
        "force" : 130,
        "dodge" : -30,
        "damage": 60,
        "lvl"   : 50,
        "skill_name" : "����Ϸ��",
        "damage_type":  "����"
]),
([      "action": "$N���һ�С����ɷ��衹������$w������ϴ�գ�����Ϸ�𣬷ֵ�$n����",
        "force" : 150,
        "dodge" : -35,
        "damage": 70,
        "lvl"   : 60,
        "skill_name" : "���ɷ���",
        "damage_type":  "����"
]),
([      "action": "$N��ǰ����������$wȦת��磬һ�С�������项������$nǰ��",
        "force" : 170,
        "dodge" : -40,
        "damage": 85,
        "lvl"   : 75,
        "skill_name" : "�������",
        "damage_type":  "����"
])
});

int valid_enable(string usage)
{
	return usage == "whip" || usage == "parry";
}

int valid_learn(object me)
{
        object weapon;

        if (! objectp(weapon = me->query_temp("weapon"))
           || (string)weapon->query("skill_type") != "whip")
                return notify_fail("���������һ�����޲������޷���\n");

        if ((int)me->query_skill("force") < 30)
                return notify_fail("����ڹ����̫ǳ���޷����ɷ�޷���\n");

        if ((int)me->query("max_neili") < 200)
                return notify_fail("���������Ϊ̫�����޷����ɷ�޷���\n");

        if ((int)me->query_skill("whip") < 20)
                return notify_fail("��Ļ����޷��ȼ�̫�ͣ��޷�ѧ�ɷ�޷���\n");

        if ((int)me->query_skill("whip", 1) < (int)me->query_skill("feifeng-bian", 1))
                return notify_fail("��Ļ����޷�ˮƽ���ޣ��޷���������ķɷ�޷���\n");

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

        level = (int) me->query_skill("feifeng-bian", 1);
        for (i = sizeof(action); i > 0; i--)
                if (level > action[i - 1]["lvl"])
                        return action[NewRandom(i, 20, level / 5)];
}

int practice_skill(object me)
{
        object weapon;

        if (! objectp(weapon = me->query_temp("weapon")) ||
            (string)weapon->query("skill_type") != "whip")
                return notify_fail("��ʹ�õ��������ԡ�\n");

        if ((int)me->query("qi") < 50)
                return notify_fail("��������������ɷ�޷���\n");

        if ((int)me->query("neili") < 45)
                return notify_fail("��������������ɷ�޷���\n");

        me->receive_damage("qi", 30);
        me->add("neili", -39);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"feifeng-bian/" + action;
}
