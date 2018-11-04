#include <ansi.h>
inherit SKILL;

mapping *action = ({
([      "action" :  "$N����$w����б�����������죬һʽ���쵶ʽ����Ϯ��$n$l",
        "force"  :  20,
        "dodge"  :  28,
        "damage" :  15,
	"lvl"    :  0,
        "damage_type":  "����",
        "skill_name"  : "�쵶ʽ",
]),
([      "action" :  "$N����$w��ת��̤����ǰ��һʽ���絶ʽ��������$n$l",
        "force"  :  40,
        "dodge"  :  24,
        "damage" :  20,
	"lvl"    :  25,
        "damage_type":  "����",
        "skill_name"  : "�絶ʽ",
]),
([     
        "action" :  "$Nŭ��һ��������Ծ��һʽ����ʽ����$w�����������ѵ�$n$l",
        "force"  :  60,
        "dodge"  :  24,
        "damage" :  18,
	"lvl"    :  50,
        "damage_type":  "����",
        "skill_name"  : "��ʽ",
]),
([      
        "action" :  "$N����$w����������һʽ��ƽ��ʽ����ƽƽ����$n",
        "force"  :  80, 
        "dodge"  :  30,
        "damage" :  25,
	"lvl"    :  75,
        "damage_type":  "����",
        "skill_name"  : "ƽ��ʽ",
]),
([      
        "action" : "$N��$w������ǰ���͵�������һʽ������ʽ��������$n$l",
        "force"  :  100,
        "dodge"  :  38,
        "damage" :  35,
	"lvl"    :  100,
        "damage_type":  "����",
        "skill_name"  : "����ʽ",
]),
});

int valid_learn(object me)
{
    	object ob; 

    	if (! (ob = me->query_temp("weapon"))
           || (string)ob->query("skill_type") != "blade")
        	return notify_fail("���������һ�ѵ����������������\n");

    	if ((int)me->query("max_neili") < 100)
        	return notify_fail("��Ŀǰ��������Ϊ������û�а취�����������\n");

    	if (me->query_skill("blade", 1) < 15)
		return notify_fail("��Ļ����������̫ǳ��û�а취�����������\n");

    	if (me->query_skill("blade", 1) < me->query_skill("tianjue-dao", 1))
		return notify_fail("��Ļ�������������ޣ��޷�������������������\n");

    	return 1;
}

int valid_enable(string usage)
{
    	return usage == "blade" || usage == "parry";
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

        level = (int) me->query_skill("tianjue-dao", 1);
        for (i = sizeof(action); i > 0; i--)
                if (level > action[i - 1]["lvl"])
                        return action[NewRandom(i, 20, level / 5)];
}

int practice_skill(object me)
{
    	object weapon;

        if (! objectp(weapon = me->query_temp("weapon"))
           || (string)weapon->query("skill_type") != "blade")
        	return notify_fail("��ʹ�õ��������ԡ�\n");

        if ((int)me->query("neili") < 40)
       	        return notify_fail("����������㣬û�а취�����������\n");

        if ((int)me->query("qi") < 50)
        	return notify_fail("����������������������\n");

        me->receive_damage("qi", 45);
        me->add("neili", -30);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"tianjue-dao/" + action;
}

