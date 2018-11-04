#include <ansi.h>

inherit SKILL;

mapping *action = ({
([      "action": "$N����һ�һ�С���Ыצ��������$w���ñ�ֱ��ֱ��$n��˫��",
        "force" : 100,
        "dodge" : 12,
        "parry" : 10,
        "damage": 5,
        "lvl"   : 0,
        "damage_type": "����"
]),
([      "action": "$N������ң�һ�С�Ыβ����������$w��������Ӱ����ɨ$n����",
        "force" : 130,
        "dodge" : 17,
        "parry" : 15,
        "damage": 10,
        "lvl"   : 20,
        "damage_type": "����"
]),
([      "action": "$N��������һ�С���Ыʴ�¡�������$w��һ��ͭ����ֱ��$n�ز�",
        "force" : 150,
        "dodge" : 21,
        "parry" : 19,
        "damage": 13,
        "lvl"   : 40,
        "damage_type": "����"
]),
([      "action": "$N����һ�ӣ�һ�С�����Ы�С�������$wֱ����$n����",
        "force" : 175,
        "dodge" : 32,
        "parry" : 27,
        "damage": 18,
        "lvl"   : 60,
        "damage_type": "����"
]),
([      "action": "$N�߸�Ծ��һ�С���Ы���롹������$w��ֱ��$n��ͷ����",
        "force" : 225,
        "dodge" : 42,
        "parry" : 37,
        "damage": 35,
        "lvl"   : 80,
        "damage_type": "����"
]),
});

int valid_enable(string usage) { return (usage == "whip") || (usage == "parry"); }

int valid_learn(object me)
{
        object weapon;

        if ( !objectp(weapon = me->query_temp("weapon"))
        || ( string)weapon->query("skill_type") != "whip" )
                return notify_fail("���������һ�����Ӳ�����ϰЫβ�ޡ�\n");

        if( (int)me->query("max_neili") < 400 )
                return notify_fail("����������㣬û�а취��ϰЫβ�ޡ�\n");

        if ((int)me->query_skill("force") < 80)
                return notify_fail("����ڹ����̫ǳ��\n");

        if ((int)me->query_skill("whip", 1) < 20)
                return notify_fail("��Ļ����޷����̫ǳ��\n");

        if ((int)me->query_skill("whip", 1) < (int)me->query_skill("xiewei-bian", 1))
                return notify_fail("��Ļ����޷�ˮƽ���ޣ��޷����������Ыβ�ޡ�\n");

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
        level   = (int) me->query_skill("xiewei-bian", 1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        object weapon;

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "whip")
                return notify_fail("��ʹ�õ��������ԡ�\n");

        if ((int)me->query("qi") < 60)
                return notify_fail("�������������Ыβ�ޡ�\n");

        if ((int)me->query("neili") < 60)
                return notify_fail("�������������Ыβ�ޡ�\n");

        me->receive_damage("qi", 50);
        me->add("neili", -50);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"xiewei-bian/" + action;
}
