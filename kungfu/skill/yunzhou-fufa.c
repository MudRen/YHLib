#include <ansi.h>

inherit SKILL;

mapping *action = ({
([      "action": "$N����΢̧��һ�С��������������$w��ֱ����$n",
        "force" : 45,
        "dodge" : 35,
        "parry" : 12,
        "damage": 15,
        "lvl"   : 0,
        "damage_type": "����"
]),
([      "action": "$N����һת������$w��������ڿ�һ���͵���$n��ͷ����",
        "force" : 80,
        "dodge" : 28,
        "parry" : 15,
        "damage": 30,
        "lvl"   : 30,
        "damage_type": "����"
]),
([      "action": "$Nһ����Х������$w����ú������죬�糤�����Ϯ��$nȫ��",
        "force" : 116,
        "dodge" : 43,
        "parry" : 29,
        "damage": 51,
        "lvl"   : 50,
        "damage_type": "����"
]),
([      "action":"$N�����䣬������ң�����$w��������ֻ��$n$l",
        "force" : 180,
        "dodge" : 55,
        "parry" : 33,
        "damage": 60,
        "lvl"   : 80,
        "damage_type": "����"
]),
([      "action":"$N����һԾ����$w�����������ƿն��£�����$n",
        "force" : 210,
        "dodge" : 65,
        "parry" : 36,
        "damage": 80,
        "lvl"   : 110,
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
                return notify_fail("���������һ�����Ӳ��������������\n");

        if ((int)me->query("max_neili") < 400)
                return notify_fail("����������㣬û�а취���������������Щ���������ɡ�\n");

        if ((int)me->query_skill("force") < 80)
                return notify_fail("����ڹ����̫ǳ��û�а취�����������\n");

        if ((int)me->query_skill("whip", 1) < 20)
                return notify_fail("��Ļ����޷����̫ǳ��û�а취�����������\n");

        if ((int)me->query_skill("whip", 1) < (int)me->query_skill("yunzhou-fufa", 1))
                return notify_fail("��Ļ����޷�ˮƽ���������޷�������������������\n");

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
        level = (int) me->query_skill("yunzhou-fufa", 1);
        for (i = sizeof(action); i > 0; i--)
                if (level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level / 5)];
}

int practice_skill(object me)
{
        object weapon;

        if (! objectp(weapon = me->query_temp("weapon")) ||
            (string)weapon->query("skill_type") != "whip")
                return notify_fail("��ʹ�õ��������ԡ�\n");

        if ((int)me->query("qi") < 40)
                return notify_fail("����������������������\n");

        if ((int)me->query("neili") < 50)
                return notify_fail("����������������������\n");

        me->receive_damage("qi", 35);
        me->add("neili", -40);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"yunzhou-fufa/" + action;
}
