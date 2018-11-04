#include <ansi.h>
inherit SKILL;

mapping *action = ({
([      "action": "$N����������һ�С���Ԫ�ơ�������$w���ñ�ֱ����׼$n���ظ�Ҫ����������",
        "force" : 180,
        "attack": 20,
        "dodge" : 2,
        "parry" : 1,
        "damage": 49,
        "lvl"   : 0,
        "skill_name" : "��Ԫ��",
        "damage_type": "����"
]),
([      "action": "$N����һת��һ�С��̽��ơ�������$w��������ڿ�һ���͵���$n��ͷ����",
        "force" : 200,
        "attack": 28,
        "dodge" : 3,
        "parry" : 5,
        "damage": 61,
        "lvl"   : 30,
        "skill_name" : "�̽���",
        "damage_type": "����"
]),
([      "action": "$N������ң�һ�С������ơ�������$w��������Ӱ����ɽ������ɨ��$nȫ��",
        "force" : 210,
        "attack": 35,
        "dodge" : 2,
        "parry" : 5,
        "damage": 73,
        "lvl"   : 60,
        "skill_name" : "������",
        "damage_type": "����"
]),
([      "action":"$N������ң�һ�С���ħ�ơ�������$w��������Ӱ����ɽ������ɨ��$nȫ��",
        "force" : 220,
        "attack": 41,
        "dodge" : 5,
        "parry" : 6,
        "damage": 84,
        "lvl"   : 90,
        "skill_name" : "��ħ��",
        "damage_type": "����"
]),
([      "action":"$N������ң�һ�С����ơ�������$w��������Ӱ����ɽ������ɨ��$nȫ��",
        "force" : 230,
        "attack": 47,
        "dodge" : 6,
        "parry" : 15,
        "damage": 95,
        "lvl"   : 120,
        "skill_name" : "����",
        "damage_type": "����"
]),
([      "action":"$N������ң�һ�С�¾���ơ�������$w��������Ӱ����ɽ������ɨ��$nȫ��",
        "force" : 240,
        "attack": 55,
        "dodge" : 12,
        "parry" : 20,
        "damage": 110,
        "lvl"   : 150,
        "skill_name":  "¾����",
        "damage_type": "����"
]),
([      "action":"$N������ң�һ�С��׺��ơ�������$w��������Ӱ����ɽ������ɨ��$nȫ��",
        "force" : 260,
        "attack": 61,
        "dodge" : 17,
        "parry" : 25,
        "damage": 130,
        "lvl"   : 180,
        "skill_name" : "�׺���",
        "damage_type": "����"
]),
([      "action":"$N������ң�һ�С������ơ�������$w��������Ӱ����ɽ������ɨ��$nȫ��",
        "force" : 290,
        "attack": 68,
        "dodge" : 20,
        "parry" : 35,
        "damage": 149,
        "lvl"   : 220,
        "skill_name" : "������",
        "damage_type": "����"
]),
});

int valid_enable(string usage)
{
	return usage == "whip" || usage == "parry";
}

int valid_learn(object me)
{
        object weapon;

        if (! objectp(weapon = me->query_temp("weapon")) ||
            (string)weapon->query("skill_type") != "whip")
                return notify_fail("���������һ�����Ӳ������޷���\n");

        if ((int)me->query("max_neili") < 800)
                return notify_fail("���������Ϊ���㣬�޷�����������������\n");

        if ((int)me->query_skill("force") < 120)
                return notify_fail("����ڹ����̫ǳ���޷�����������������\n");

        if ((int)me->query_skill("whip", 1) < 80)
                return notify_fail("��Ļ����޷����̫ǳ���޷�����������������\n");

        if ((int)me->query_skill("whip", 1) < (int)me->query_skill("panlong-suo", 1))
                return notify_fail("��Ļ����޷�ˮƽ���������޷����������������������\n");

        return 1;
}

string query_skill_name(int level)
{
        int i;
        for (i = sizeof(action)-1; i >= 0; i--)
                if(level >= action[i]["lvl"])
                        return action[i]["skill_name"];
}

mapping query_action(object me, object weapon)
{
        int i, level;
        level = (int) me->query_skill("panlong-suo",1);
        for(i = sizeof(action); i > 0; i--)
                if (level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        object weapon;

        if (! objectp(weapon = me->query_temp("weapon")) ||
            (string)weapon->query("skill_type") != "whip")
                return notify_fail("��ʹ�õ��������ԡ�\n");

        if ((int)me->query("qi") < 80)
                return notify_fail("�������������������������\n");

        if ((int)me->query("neili") < 90)
                return notify_fail("�������������������������\n");

        me->receive_damage("qi", 75);
        me->add("neili", -85);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"panlong-suo/" + action;
}
