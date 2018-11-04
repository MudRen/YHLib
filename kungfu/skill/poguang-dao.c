#include <ansi.h>
inherit SKILL;

mapping *action = ({
([      "action" : "$N����$w��ն�����һʽ���ƿ�ʽ����$w�ѵ�$n$l",
        "force"  : 90,
        "dodge"  : 21,
        "parry"  : 25,
        "attack" : 10,
        "damage" : 22,
	"lvl"    : 0,
        "damage_type" : "����",
        "skill_name"  : "�ƿ�ʽ",
]),
([      "action" : "$N����$wƽƽ�ӳ���һʽ�����ʽ����$w����$n$l ",
        "force"  : 100,
        "dodge"  : 24,
        "parry"  : 28,
        "attack" : 12,
        "damage" : 25,
	"lvl"    : 25,
        "damage_type" : "����",
        "skill_name"  : "���ʽ",
]),
([      "action" : "$N����Ծ��ʩ��һʽ�����ʽ����$w����һ���ѵ�$n$l",
        "force"  : 120,
        "dodge"  : 25,
        "parry"  : 31,
        "attack" : 13,
        "damage" : 38,
	"lvl"    : 50,
        "damage_type" : "����",
        "skill_name"  : "���ʽ",
]),
([      "action" : "$N�ڿն���һʽ������ʽ��������$wֱ����$n$l",
        "force"  : 140, 
        "dodge"  : 25,
        "parry"  : 35,
        "attack" : 15,
        "damage" : 50,
	"lvl"    : 75,
        "damage_type" : "����",
        "skill_name"  : "����ʽ",
]),
([      "action" : "$N�����ת��ʩ��һʽ������ʽ����$w���Ѷ�����Ϯ��$n$l",
        "force"  : 160,
        "dodge"  : 27,
        "parry"  : 38,
        "attack" : 18,
        "damage" : 63,
	"lvl"    : 100,
        "damage_type" : "����",
        "skill_name"  : "����ʽ",
]),
([      "action" : "$Nŭ��һ��������$w���費����һʽ�����ʽ������������$w����$n",
        "force"  : 180,
        "dodge"  : 30,
        "parry"  : 40,
        "attack" : 20,
        "damage" : 80,
	"lvl"    : 120,
        "damage_type" : "����",
        "skill_name"  : "���ʽ",
]),
});

int valid_learn(object me)
{
        object ob;

        if (! (ob = me->query_temp("weapon"))
           || (string)ob->query("skill_type") != "blade")
                return notify_fail("���������һ�ѽ��������ƹ⵶����\n");

        if ((int)me->query("max_neili") < 800)
                return notify_fail("���������Ϊ�������޷�ѧϰ�ƹ⵶����\n");

        if ((int)me->query_skill("force") < 120)
                return notify_fail("����ڹ����̫ǳ���޷�ѧϰ�ƹ⵶����\n");

        if ((int)me->query_skill("blade", 1) < 100)
                return notify_fail("��Ļ���������򲻹����޷�ѧϰ�ƹ⵶����\n");

        if (me->query_skill("blade", 1) < me->query_skill("poguang-dao", 1))
		return notify_fail("��Ļ�������������ޣ��޷�����������ƹ⵶����\n");

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

        level = (int) me->query_skill("poguang-dao", 1);
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
        	   return notify_fail("����������㣬û�а취��ϰ�ƹ⵶����\n");

       if ((int)me->query("qi") < 55)
        	   return notify_fail("��������������ƹ⵶����\n");

       me->receive_damage("qi", 40);
       me->add("neili", -50);

       return 1;
}

string perform_action_file(string action)
{
        return __DIR__"poguang-dao/" + action;
}

