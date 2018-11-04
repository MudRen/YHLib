#include <ansi.h>
inherit SKILL;

mapping *action = ({
([      "action" :  "$N����$w�����ʹ̣�����������$n",
        "force"  :  80,
        "dodge"  :  28,
        "damage" :  20,
	"lvl"    :  0,
        "damage_type":  "����",
]),
([      "action" :  "$N����$w����һɨ��һʽ��������β��������������ɲ�Ǽ�$w�ѵ�$n$l",
        "force"  :  90,
        "dodge"  :  24,
        "damage" :  25,
	"lvl"    :  30,
        "damage_type":  "����",
]),
([     
        "action" :  "���ⲻ����$N���ط�ת����һʽ��꼻�һ�֡�����Ȼ��$w����$n$l",
        "force"  :  100,
        "dodge"  :  24,
        "damage" :  30,
	"lvl"    :  60,
        "damage_type":  "����",
]),
([      
        "action" :  "$N�������ˣ�һʽ����ˮ���ۡ���$w���������У�ȴб��һ��ָ��$n",
        "force"  :  120, 
        "dodge"  :  30,
        "damage" :  35,
	"lvl"    :  90,
        "damage_type":  "����",
]),
([      
        "action" : "$N����Ծ������$wһ�ᣬһʽ����ɨǧ�����������Ƿ���Ϯ��$n$l",
        "force"  :  140,
        "dodge"  :  40,
        "damage" :  40,
	"lvl"    :  120,
        "damage_type":  "����",
]),
});

int valid_learn(object me)
{
    	object ob; 

    	if (! (ob = me->query_temp("weapon"))
           || (string)ob->query("skill_type") != "sword")
        	return notify_fail("���������һ�ѽ�������������\n");

    	if ((int)me->query("max_neili") < 400)
        	return notify_fail("��Ŀǰ��������Ϊ������û�а취�����ǽ�����\n");

    	if (me->query_skill("force") < 100)
        	return notify_fail("����ڹ���Ϊ������û�а취�����ǽ�����\n");

    	if (me->query_skill("sword", 1) < 80)
		return notify_fail("��Ļ����������̫ǳ��û�а취�����ǽ�����\n");

    	if (me->query_skill("sword", 1) < me->query_skill("guxing-jian", 1))
		return notify_fail("��Ļ�������������ޣ��޷���������Ĺ��ǽ�����\n");

    	return 1;
}

int valid_enable(string usage)
{
    	return usage == "sword" || usage == "parry";
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

        level = (int) me->query_skill("guxing-jian", 1);
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

        if ((int)me->query("neili") < 40)
       	        return notify_fail("����������㣬û�а취��ϰ���ǽ�����\n");

        if ((int)me->query("qi") < 50)
        	return notify_fail("����������������ǽ�����\n");

        me->receive_damage("qi", 45);
        me->add("neili", -35);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"guxing-jian/" + action;
}

