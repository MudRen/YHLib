//shunv-jian ��Ů����
//modify by rcwiz 2003

#include <ansi.h>

inherit SKILL;

mapping *action = ({
([      "action" : "$N����һ��������$w���Ⱪ�ǣ�ָ��$n$l",
        "force"  : 130,
        "attack" : 35,
        "parry"  : 20,
        "dodge"  : 40,
        "damage" : 100,
        "lvl"    : 0,
        "damage_type" : "����"
]),
([      "action" : "$N����$w��תб�̣��������д��գ�ָ��$n$l",
        "force"  : 150,
        "attack" : 45,
        "parry"  : 52,
        "dodge"  : 55,
        "damage" : 118,
        "lvl"    : 30,
        "damage_type" : "����"
]),
([      "action" : "$Nһ�����⣬���ƶ��죬����$wն��$n",
        "force"  : 190,
        "attack" : 81,
        "parry"  : 18,
        "dodge"  : 103,
        "damage" : 155,
        "lvl"    : 60,
        "damage_type" : "����"
]),
([      "action" : "$N����һ�ڣ�����ͻ�֣�����$wһ�˷���������$n$l",
        "force"  : 250,
        "attack" : 108,
        "parry"  : 20,
        "dodge"  : 122,
        "damage" : 200,
        "lvl"    : 90,
        "damage_type" : "����"
]),
});

int valid_enable(string usage) { return usage == "sword" || usage == "parry"; } 

int valid_learn(object me)
{
        if ((int)me->query("max_neili") < 100)
                return notify_fail("���������Ϊ�������޷���ϰ��Ů������\n");

        if ((int)me->query_skill("dodge", 1) < 40)
                return notify_fail("��Ļ����Ṧ���̫ǳ���޷���ϰ��Ů������\n");

        if ((int)me->query_dex() < 24)
                return notify_fail("��������������޷���ϰ��Ů������\n");

        if ((int)me->query_skill("sword", 1) < (int)me->query_skill("shunv-jian", 1))
	        return notify_fail("��Ļ�������ˮƽ���ޣ��޷������������Ů������\n");

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

        level = (int) me->query_skill("shunv-jian",1);
        for (i = sizeof(action); i > 0; i--)
    	        if (level > action[i - 1]["lvl"])
                        return action[NewRandom(i, 20, level / 5)];
}

int practice_skill(object me)
{
        object weapon;

        if (! objectp(weapon = me->query_temp("weapon")) ||
            (string)weapon->query("skill_type") != "sword")
                return notify_fail("��ʹ�õ��������ԡ�\n");

        if ((int)me->query("qi") < 45)
                return notify_fail("�������������\n");

        if ((int)me->query("neili") < 38)
                return notify_fail("�������������\n");

        me->receive_damage("qi", 40);
        me->add("neili", -34);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"shunv-jian/" + action;
}
