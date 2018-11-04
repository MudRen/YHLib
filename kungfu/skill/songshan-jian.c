#include <ansi.h>
inherit SKILL;

mapping *action = ({
([      "action" :  "$N����$w����б�̣��������죬ֱָ$n$l",
        "force"  :  45,
        "dodge"  :  28,
        "damage" :  5,
	"lvl"    :  0,
        "damage_type":  "����",
]),
([      "action" :  "$N����$w��ת��̤����ǰ��һ������$n$l",
        "force"  :  60,
        "dodge"  :  24,
        "damage" :  8,
	"lvl"    :  30,
        "damage_type":  "����",
]),
([     
        "action" :  "����������$Nŭ��һ��������Ծ��$w�����������ѵ�$n$l",
        "force"  :  80,
        "dodge"  :  24,
        "damage" :  15,
	"lvl"    :  60,
        "damage_type":  "����",
]),
([      
        "action" :  "$N����$w����һ�����ߣ������Ž����ջأ�ȴƽƽһ������$n$l",
        "force"  :  100, 
        "dodge"  :  30,
        "damage" :  25,
	"lvl"    :  80,
        "damage_type":  "����",
]),
([      
        "action" : "$N���Ų�æ���͵�����$w�����̳����������磬ֱָ$n$l",
        "force"  :  110,
        "dodge"  :  38,
        "damage" :  30,
	"lvl"    :  100,
        "damage_type":  "����",
]),
});

int valid_learn(object me)
{
    	object ob; 

    	if (! (ob = me->query_temp("weapon"))
           || (string)ob->query("skill_type") != "sword")
        	return notify_fail("���������һ�ѽ�������������\n");

    	if ((int)me->query("max_neili") < 100)
        	return notify_fail("��Ŀǰ��������Ϊ������û�а취����ɽ������\n");

    	if (me->query_skill("sword", 1) < 15)
		return notify_fail("��Ļ����������̫ǳ��û�а취����ɽ������\n");

    	if (me->query_skill("sword", 1) < me->query_skill("songshan-jian", 1))
		return notify_fail("��Ļ�������������ޣ��޷���������ľ��齣����\n");

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

        level = (int) me->query_skill("songshan-jian", 1);
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
       	        return notify_fail("����������㣬û�а취��ϰ��ɽ������\n");

        if ((int)me->query("qi") < 50)
        	return notify_fail("���������������ɽ������\n");

        me->receive_damage("qi", 45);
        me->add("neili", -30);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"songshan-jian/" + action;
}

