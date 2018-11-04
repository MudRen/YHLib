#include <ansi.h>

inherit SKILL;

mapping *action = ({
([      "action" : "$N����һ�һ�С��޿ײ��롹������$w���ñ�ֱ����׼$n"
                   "��ͷ����",
        "force"  : 90,
        "attack" : 13,
        "dodge"  : 10,
        "parry"  : 10,
        "damage" : 20,
        "lvl" : 0,
        "skill_name" : "�޿ײ���",
        "damage_type":  "����"
]),
([      "action" : "$N����һת��һ�С�����������������$w��������ڿ�һ��"
                   "���͵ػ���$n",
        "force"  : 130,
        "attack" : 24,
        "dodge"  : 28,
        "parry"  : 15,
        "damage" : 36,
        "lvl" : 30,
        "skill_name" : "��������",
        "damage_type":  "����"
]),
([      "action" : "$N৵�һ�����ޣ�һ�С�������Ϊ��������$w���ñ�ֱ������"
                   "$n$l",
        "force"  : 170,
        "attack" : 35,
        "dodge"  : 36,
        "parry"  : 21,
        "damage" : 55,
        "lvl" : 60,
        "skill_name" : "������Ϊ",
        "damage_type":  "����"
]),
([      "action" : "$N������ң�һ�С�������ӿ��������$w��������Ӱ����ɽ��"
                   "����ɨ��$nȫ��",
        "force"  : 200,
        "attack" : 40,
        "dodge"  : 50,
        "parry"  : 30,
        "damage" : 64,
        "lvl" : 90,
        "skill_name" : "������ӿ",
        "damage_type":  "����"
]),
([      "action" : "$N��������һ�С������ơ�������$w��һ��ͭ����ֱ����$n",
        "force"  : 220,
        "attack" : 50,
        "dodge"  : 66,
        "parry"  : 38,
        "damage" : 80,
        "lvl" : 120,
        "skill_name" : "������",
        "damage_type":  "����"
]),
([      "action" : "$N����һ�ӣ�һ�С����ܹ��ݡ�������$wֱ����$n����",
        "force"  : 260,
        "attack" : 56,
        "dodge"  : 80,
        "parry"  : 32,
        "damage" : 98,
        "lvl" : 150,
        "skill_name" : "���ܹ���",
        "damage_type":  "����"
]),
([      "action" : "$N�߸�Ծ��һ�С���Ӱ���١�������$w��ֱ��$n��ͷ����",
        "force"  : 300,
        "attack" : 70,
        "dodge"  : 110,
        "parry"  : 40,
        "damage" : 130,
        "lvl" : 200,
        "skill_name" : "��Ӱ����",
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

        if (me->query("character") != "�ĺ�����") 
                return notify_fail("�����������ֱ���Ҫ�ĺ��������ҿ���������û�������\n"); 

        if ( !objectp(weapon = me->query_temp("weapon"))
        || ( string)weapon->query("skill_type") != "whip" )
                return notify_fail("���������һ�����Ӳ��������������֡�\n");

        if( (int)me->query("max_neili") < 800 )
                return notify_fail("����������㣬û�а취�����������֡�\n");

        if ((int)me->query_skill("force") < 120)
                return notify_fail("����ڹ����̫ǳ��û�а취�����������֡�\n");

        if ((int)me->query_skill("whip", 1) < 100)
                return notify_fail("��Ļ����޷����̫ǳ��û�а취�����������֡�\n");

        if ((int)me->query_skill("whip", 1) < (int)me->query_skill("sanwu-shou", 1))
                return notify_fail("��Ļ����޷�ˮƽ���ޣ��޷����������û�а취�����������֡�\n");

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
        level   = (int) me->query_skill("sanwu-shou",1);
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
                return notify_fail("����������������������֡�\n");

        if ((int)me->query("neili") < 70)
                return notify_fail("����������������������֡�\n");

        me->receive_damage("qi", 55);
        me->add("neili", -60);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"sanwu-shou/" + action;
}
