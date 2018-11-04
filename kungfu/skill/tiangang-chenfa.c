#include <ansi.h>
inherit SKILL;

mapping *action = ({
([      "action": "$N����Ծ��һ�С���ڷ��ǡ�������$w���¶��ϣ�����$n������",
        "force" : 100,
        "dodge" : 0,
        "damage": 20,
        "lvl"   : 15,
        "skill_name" : "��ڷ���",
        "damage_type":  "����"
]),
([      "action": "$Nһ�С��ǹ��Ŀ��������$w�ڿ�һ��ֱ����$n��$l��ȥ",
        "force" : 110,
        "dodge" : -10,
        "damage": 30,
        "lvl"   : 20,
        "skill_name" : "�ǹ��Ŀ",
        "damage_type":  "����"
]),
([      "action": "$Nһ�С�ҡ�⻻λ��������$w�ڿ�һ��һ�����죬�͵���$n��ͷ����",
        "force" : 120,
        "dodge" : -15,
        "damage": 40,
        "lvl"   : 40,
        "skill_name" : "ҡ�⻻λ",
        "damage_type":  "����"
]),
([      "action": "$N̤��һ��������$w����ͣ����һ�С����Ǿ��¡���ɨ��$n��$l",
        "force" : 130,
        "dodge" : -30,
        "damage": 60,
        "lvl"   : 50,
        "skill_name" : "���Ǿ���",
        "damage_type":  "����"
]),
([      "action": "$N���һ�С��������ɡ�������$w������ϴ�գ�����Ϸ�𣬷ֵ�$n����",
        "force" : 150,
        "dodge" : -35,
        "damage": 70,
        "lvl"   : 60,
        "skill_name" : "��������",
        "damage_type":  "����"
]),
([      "action": "$N��ǰ����������$wȦת��磬һ�С��������������$nǰ��",
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
                return notify_fail("����ڹ����̫ǳ���޷����������\n");

        if ((int)me->query("max_neili") < 200)
                return notify_fail("���������Ϊ̫�����޷����������\n");

        if ((int)me->query_skill("whip") < 20)
                return notify_fail("��Ļ����޷��ȼ�̫�ͣ��޷�ѧ�������\n");

        if ((int)me->query_skill("whip", 1) < (int)me->query_skill("tiangang-chenfa", 1))
                return notify_fail("��Ļ����޷�ˮƽ���ޣ��޷�����������������\n");

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

        level = (int) me->query_skill("tiangang-chenfa", 1);
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
                return notify_fail("��������������������\n");

        if ((int)me->query("neili") < 45)
                return notify_fail("��������������������\n");

        me->receive_damage("qi", 30);
        me->add("neili", -39);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"tiangang-chenfa/" + action;
}
