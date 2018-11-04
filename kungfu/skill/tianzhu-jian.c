#include <ansi.h>
inherit SKILL;

mapping *action = ({
([      "action" :  "$N����Ծ��ͦ������$n$l������һ�С���ɽ�˼䡹",
        "force"  :  45,
        "dodge"  :  18,
        "parry"  :  20,
        "attack" :  10,
        "damage" :  20,
	"lvl"    :  0,
        "damage_type" : "����",
        "skill_name"  : "��ɽ�˼�"
]),
([      "action" :  "$N�����ڽ�����Ȼֱ����һ�С�һ�����졹��Ȼʹ����$wֱָ$n$l",
        "force"  :  90,
        "dodge"  :  25,
        "parry"  :  40,
        "attack" :  24,
        "damage" :  35,
	"lvl"    :  25,
        "damage_type" : "����",
        "skill_name"  : "һ������"
]),
([     
        "action" :  "$N����ͻ�䣬Ʈ��������һʽ�������������$n$l��ȥ",
        "force"  :  110,
        "dodge"  :  30,
        "parry"  :  40,
        "attack" :  30,
        "damage" :  40,
	"lvl"    :  50,
        "damage_type" : "����",
        "skill_name"  : "��������"
]),
([      
        "action" :  "$N��Хһ����$wһ����һʽ�����ڳ��硹��գ�ۼ�$w�ѵ�$n$l",
        "force"  :  120, 
        "dodge"  :  45,
        "parry"  :  45,
        "attack" :  35,
        "damage" :  48,
	"lvl"    :  75,
        "damage_type" : "����",
        "skill_name"  : "���ڳ���"
]),
([      
        "action" : "$N̤ǰ�벽������$w��Ӱ��ã�����$n$l��ȥ������һ�С�����������",
        "force"  :  160,
        "dodge"  :  80,
        "parry"  :  60,
        "attack" :  55,
        "damage" :  60,
	"lvl"    :  100,
        "damage_type" : "����",
        "skill_name"  : "��������"
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
   
        if ((int)me->query("max_neili") < 300)
        	return notify_fail("�������������û�а취������������\n");

        if ((int)me->query_skill("force") < 100)
                return notify_fail("����ڹ����̫ǳ��\n");

        if ((int)me->query_skill("sword", 1) < 60)
           	return notify_fail("��Ļ���������򲻹����޷�ѧϰ����������\n");

        if (me->query_skill("sword", 1) < me->query_skill("tianzhu-jian", 1))
		return notify_fail("��Ļ�������������ޣ��޷��������������������\n");

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

        level = (int) me->query_skill("tianzhu-jian", 1);
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

       if ((int)me->query("neili") < 60)
        	   return notify_fail("����������㣬û�а취��ϰ����������\n");

       if ((int)me->query("qi") < 65)
        	   return notify_fail("�����������������������\n");

       me->receive_damage("qi", 40);
       me->add("neili", -50);
       return 1;
}

string perform_action_file(string action)
{
        return __DIR__"tianzhu-jian/" + action;
}
