#include <ansi.h>
inherit SKILL;

mapping *action = ({
([      "action" : "$N����$w�������ಡ�������$wб��$n$l������һ�С��������ʡ�",
        "force"  : 70,
        "dodge"  : 38,
        "parry"  : 25,
        "attack" : 15,
        "damage" : 20,
	"lvl"    : 0,
        "damage_type" : "����",
        "skill_name"  : "��������",
]),
([      "action" : "$N$w��ת������$n��$l��ȥ��һʽ��������ԡ���Ȼʹ��",
        "force"  : 85,
        "dodge"  : 45,
        "parry"  : 40,
        "attack" : 28,
        "damage" : 30,
	"lvl"    : 25,
        "damage_type" : "����",
        "skill_name"  : "�������",
]),
([     
        "action" : "$N����$w�����̳�����������������������$n�����ţ��ʺ���$l��ȥ",
        "force"  : 120,
        "dodge"  : 55,
        "parry"  : 45,
        "attack" : 40,
        "damage" : 38,
	"lvl"    : 50,
        "damage_type" : "����",
        "skill_name"  : "��������",
]),
([      
        "action" : "$N��Хһ����һ�С�����ǵء���$w���һ���������������䣬����$n",
        "force"  : 150, 
        "dodge"  : 65,
        "parry"  : 50,
        "attack" : 45,
        "damage" : 45,
	"lvl"    : 75,
        "damage_type" : "����",
        "skill_name"  : "����ǵ�",
]),
([      
        "action" : "$N�����������Ȼһ���̳�����ƫ���У�һ�С�ʯ��������ֱָ$n$l",
        "force"  : 180,
        "dodge"  : 80,
        "parry"  : 60,
        "attack" : 55,
        "damage" : 60,
	"lvl"    : 100,
        "damage_type" : "����",
        "skill_name"  : "ʯ������",
]),
});

string main_skill()
{
	return "wushen-jian";
}

int valid_learn(object me)
{
    	object ob;

        if (me->query_skill("wushen-jian", 1) > 0)
                return notify_fail("���������ϳ��˺�ɽ���񽣣������ٵ���ѧϰ��\n");

    	if (! (ob = me->query_temp("weapon"))
           || (string)ob->query("skill_type") != "sword")
        	return notify_fail("���������һ�ѽ�������������\n");

        if ((int)me->query("max_neili") < 400)
        	return notify_fail("�������������û�а취��ʯ�޽�����\n");

        if ((int)me->query_skill("force") < 100)
                return notify_fail("����ڹ����̫ǳ��\n");

        if ((int)me->query_skill("sword", 1) < 60)
           	return notify_fail("��Ļ���������򲻹����޷�ѧϰʯ�޽�����\n");

        if (me->query_skill("sword", 1) < me->query_skill("shilin-jian", 1))
		return notify_fail("��Ļ�������������ޣ��޷����������ʯ�޽�����\n");

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

        level = (int) me->query_skill("shilin-jian", 1);
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

       if((int)me->query("neili") < 60 )
        	   return notify_fail("����������㣬û�а취��ϰʯ�޽�����\n");

       if ((int)me->query("qi") < 65)
        	   return notify_fail("�������������ʯ�޽�����\n");

       me->receive_damage("qi", 45);
       me->add("neili", -55);
       return 1;
}

string perform_action_file(string action)
{
        return __DIR__"shilin-jian/" + action;
}
