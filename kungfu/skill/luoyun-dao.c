#include <ansi.h>
inherit SKILL;

mapping *action = ({
([      "action" :  "$N����$wƽƽһ����һʽ���������ơ�������$n$l",
        "force"  :  80,
        "dodge"  :  28,
        "damage" :  20,
	"lvl"    :  0,
        "damage_type":  "����",
        "skill_name"  : "��������",
]),
([      "action" :  "$N����$w�Կն��£�һʽ������������������$n$l",
        "force"  :  90,
        "dodge"  :  24,
        "damage" :  25,
	"lvl"    :  30,
        "damage_type":  "����",
        "skill_name"  : "��������",
]),
([     
        "action" :  "������˸�䣬$N�ڿն��𣬰��ֱ�£�һʽ�����׺䶥��"
                    "������$w�Ѿ���$n$l",
        "force"  :  100,
        "dodge"  :  24,
        "damage" :  30,
	"lvl"    :  60,
        "damage_type":  "����",
        "skill_name"  : "���׺䶥",
]),
([      
        "action" :  "$N���Ų�æ��һʽ������������������$w��ת�������͵�"
                    "һ������$n$l",
        "force"  :  120, 
        "dodge"  :  30,
        "damage" :  35,
	"lvl"    :  90,
        "damage_type":  "����",
        "skill_name"  : "��������",
]),
([      
        "action" : "$N˫���յ���һʽ������Ⱥɽ��������$w���϶��£��糤��"
                   "����£�����$n$l",
        "force"  :  140,
        "dodge"  :  40,
        "damage" :  40,
	"lvl"    :  120,
        "damage_type":  "����",
        "skill_name"  : "����Ⱥɽ",
]),
});

int valid_learn(object me)
{
    	object ob; 

    	if (! (ob = me->query_temp("weapon"))
           || (string)ob->query("skill_type") != "blade")
        	return notify_fail("���������һ�ѽ����������Ƶ�����\n");

    	if ((int)me->query("max_neili") < 400)
        	return notify_fail("��Ŀǰ��������Ϊ������û�а취�����Ƶ�����\n");

    	if (me->query_skill("force") < 100)
        	return notify_fail("����ڹ���Ϊ������û�а취�����Ƶ�����\n");

    	if (me->query_skill("blade", 1) < 80)
		return notify_fail("��Ļ����������̫ǳ��û�а취�����Ƶ�����\n");

    	if (me->query_skill("blade", 1) < me->query_skill("luoyun-dao", 1))
		return notify_fail("��Ļ�������������ޣ��޷���������Ĺ��ǽ�����\n");

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

        level = (int) me->query_skill("luoyun-dao", 1);
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
       	        return notify_fail("����������㣬û�а취��ϰ���Ƶ�����\n");

        if ((int)me->query("qi") < 50)
        	return notify_fail("����������������Ƶ�����\n");

        me->receive_damage("qi", 45);
        me->add("neili", -35);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"luoyun-dao/" + action;
}

