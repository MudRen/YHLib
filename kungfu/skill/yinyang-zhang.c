#include <ansi.h>
inherit SKILL;

mapping *action = ({
([  "action": "$Nʹ��һ�С�ɽ���֡���������ɣ�����ֱ��$n��$l",
    "force" : 60,
    "attack": 25,
    "dodge" : 10,
    "parry" : 16,
    "damage": 15,
    "lvl"   : 0,
    "skill_name" : "ɽ����" ,
    "damage_type" : "����"
]),
([  "action": "$Nʹ��һ�С�ǧ���С���˫�Ƽ��������������������Ʒ�ֱ��$n��$l",
    "force" : 80,
    "attack": 55,
    "dodge" : 15,
    "parry" : 19,
    "damage": 25,
    "lvl"   : 20,
    "skill_name" : "ǧ����" ,
    "damage_type" : "����"
]),
([  "action": "$N��Ȼһ����Х��һ�С����굶����˫����Ȼ���£�ֱ��$n��Ҫ��",
    "force" : 100,
    "attack": 45,
    "dodge" : 20,
    "parry" : 18,
    "damage": 50,
    "lvl"   : 40,
    "skill_name" : "���굶" ,
    "damage_type" : "����"
]),
([  "action": "$N�������죬˫�ۺ�Ȼ�������ߣ�һ�С�����ơ�ֱֱ����$n��$l",
    "force" : 130,
    "attack": 40,
    "dodge" : 20,
    "parry" : 23,
    "damage": 65,
    "lvl"   : 80,
    "skill_name" : "�����" ,
    "damage_type" : "����"
]),
([  "action": "$Nʩչ��һ�С�����֡���˫���ͷ��ĳ�����Ȼ��˫������$n��ǰ",
    "force" : 150,
    "attack": 61,
    "dodge" : 32,
    "parry" : 35,
    "damage": 80,
    "lvl"   : 120,
    "skill_name" : "�����" ,
    "damage_type" : "����"
]),
});

int valid_enable(string usage)
{
        return usage == "strike" || usage == "parry";
}

int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
            return notify_fail("�������Ʊ�����֡�\n");

        if ((int)me->query("max_neili") < 200)
            return notify_fail("���������Ϊ̫ǳ���޷���ϰ�����ơ�\n");

        if ((int)me->query_skill("strike", 1) < 30)
            return notify_fail("��Ļ����Ʒ�̫��޷���������ơ�\n");

        if ((int)me->query_skill("strike", 1) < (int)me->query_skill("yinyang-zhang", 1))
            return notify_fail("��Ļ����Ʒ���򲻹����޷���������������ơ�\n");

        return 1;
}

string query_skill_name(int level)
{
        int i;
        for (i = sizeof(action); i > 0; i--)
                if (level >= action[i-1]["lvl"])
                        return action[i-1]["skill_name"];
}

mapping query_action(object me, object weapon)
{
        int i, level;
        level = (int) me->query_skill("yinyang-zhang", 1);
        for (i = sizeof(action); i > 0; i--)
                if (level > action[i-1]["lvl"])
                        return action[NewRandom(i, 5, level / 5)];
}

int practice_skill(object me)
{
        if ((int)me->query("qi") < 80)
                return notify_fail("�������̫���ˡ�\n");

        if ((int)me->query("neili") < 80)
                return notify_fail("�������������\n");

        me->receive_damage("qi", 45);
        me->add("neili", -48);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"yinyang-zhang/" + action;
}

