#include <ansi.h>
inherit SKILL;

mapping *action = ({
([      "action" :  "$N����Ҵڣ�����$wͻȻ����$n$l������һ�С�ǧ�����֡�",
        "force"  :  45,
        "dodge"  :  20,
        "parry"  :  20,
        "attack" :  10,
        "damage" :  20,
	"lvl"    :  0,
        "damage_type" :  "����",
        "skill_name"  :  "ǧ������",
]),
([      "action" :  "$NԽ��Խ�ͣ�ͻȻ������$w���Ⱪ�ǣ�һ�С����·ת����Ȼʹ��\n"
                    "$nֻ����ǰ����ҫ�ۣ����ɵ�����һ��",
        "force"  :  90,
        "dodge"  :  26,
        "parry"  :  40,
        "attack" :  24,
        "damage" :  35,
	"lvl"    :  25,
        "damage_type" :  "����",
        "skill_name"  :  "���·ת",
]),
([     
        "action" :  "$N�Թ�Ϊ�أ��Խ�Ϊ�ˣ�����$wˢ��һ��������ɷ����$n$l��ȥ",
        "force"  :  110,
        "dodge"  :  35,
        "parry"  :  40,
        "attack" :  30,
        "damage" :  40,
	"lvl"    :  50,
        "damage_type":  "����",
        "skill_name":   "����ɷ�",
]),
([      
        "action" :  "$N��Хһ����$w��ֱ��$n$w����һ�������κ���ʽ������$Nȴʹ�ò�\n"
                    "�������������ʹ�������ǧɽĺѩ����һ�з��ӵ��˼���",
        "force"  :  120, 
        "dodge"  :  48,
        "parry"  :  45,
        "attack" :  35,
        "damage" :  48,
	"lvl"    :  75,
        "damage_type" :  "����",
        "skill_name"  :  "ǧɽĺѩ",
]),
([      
        "action" : "$N��$wһ�ӣ���Хһ�����ڿն���ʹ��һʽ�����ʽ������һ��������\n"
                   "����׼��$wֱָ$n$l,",
        "force"  :  130,
        "dodge"  :  56,
        "parry"  :  66,
        "attack" :  55,
        "damage" :  60,
	"lvl"    :  100,
        "damage_type" :  "����",
        "skill_name"  :  "���ʽ",
]),
});

int valid_learn(object me)
{
    	object ob; 

    	if (! (ob = me->query_temp("weapon"))
           || (string)ob->query("skill_type") != "sword")
        	return notify_fail("���������һ�ѽ�������������\n");

    	if ((int)me->query("max_neili") < 300)
        	return notify_fail("�������������û�а취������������\n");

    	if ((int)me->query_skill("force") < 100)
                return notify_fail("����ڹ����̫ǳ��\n");

    	if ((int)me->query_skill("sword", 1) < 60)
           	return notify_fail("��Ļ���������򲻹����޷�ѧϰ����������\n");

    	if (me->query_skill("sword", 1) < me->query_skill("jiuqu-jian", 1))
		return notify_fail("��Ļ�������������ޣ��޷���������ľ���������\n");

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

        level = (int) me->query_skill("jiuqu-jian", 1);
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

       if((int)me->query("neili") < 60 )
        	   return notify_fail("����������㣬û�а취��ϰ����������\n");

       if ((int)me->query("qi") < 65)
        	   return notify_fail("�����������������������\n");

       me->receive_damage("qi", 40);
       me->add("neili", -50);
       return 1;
}

string perform_action_file(string action)
{
        return __DIR__"jiuqu-jian/" + action;
}

