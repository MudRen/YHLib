#include <ansi.h>
inherit SKILL;

mapping *action = ({
([
        "action" : "$N����$w��ಡ��صݳ���ͻȻ�������һ������������һ�С�ܽ�ػ�����\n"
                   "��֪�����䣬$w�Ѿ���$n��$l��ȥ",
        "force"  : 45,
        "dodge"  : 18,
        "parry"  : 20,
        "attack" : 10,
        "damage" : 20,
	"lvl"    : 0,
        "damage_type" : "����",
        "skill_name"  : "ܽ�ػ���"
]),
([      "action" :  "$N����$wһ������������֮������$n�۾���ȥ������$w�ڰ�·����һת\n"
                    "����$n$l��ȥ������ܽ�ؽ����еġ�������л��",
        "force"  :  90,
        "dodge"  :  28,
        "parry"  :  40,
        "attack" :  24,
        "damage" :  35,
	"lvl"    :  25,
        "damage_type" : "����",
        "skill_name"  : "������л"
]),
([
        "action" : "$N�����Է�������·������$wˢ��һ����Ȫ��ܽ�ء�����$n$l��ȥ",
        "force"  : 110,
        "dodge"  : 32,
        "parry"  : 40,
        "attack" : 30,
        "damage" : 40,
	"lvl"    : 50,
        "damage_type" : "����",
        "skill_name"  : "Ȫ��ܽ��"
]),
([
        "action" : "$N����$wٿ�ش̳������ƴ����ػأ�������ã�����һ�С��������硹����\n"
                   "$n$l��ȥ",
        "force"  : 120, 
        "dodge"  : 50,
        "parry"  : 42,
        "attack" : 35,
        "damage" : 48,
	"lvl"    : 75,
        "damage_type" : "����",
        "skill_name"  : "��������"
]),
([
        "action" : "$N����$wٿ�ش̳�����������֮���£������޶�������׽��������һ��\n"
                   "���軨�׷�ָ��$n$l",
        "force"  : 150,
        "dodge"  : 75,
        "parry"  : 60,
        "attack" : 55,
        "damage" : 60,
	"lvl"    : 100,
        "damage_type" : "����",
        "skill_name"  : "�軨�׷�"
]),
([
        "action" : "$N����Ծ��һʽ��ܽ�س�ˮ��$w����һ�������Ӱ���д���$n��$l",
        "force"  : 180,
        "dodge"  : 85,
        "parry"  : 68,
        "attack" : 65,
        "damage" : 70,
	"lvl"    : 120,
        "damage_type" : "����",
        "skill_name"  : "ܽ�س�ˮ"
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
        	return notify_fail("�������������û�а취��ܽ�ؽ�����\n");

        if ((int)me->query_skill("force") < 100)
                return notify_fail("����ڹ����̫ǳ��\n");

        if ((int)me->query_skill("sword", 1) < 60)
           	return notify_fail("��Ļ���������򲻹����޷�ѧϰܽ�ؽ�����\n");

        if (me->query_skill("sword", 1) < me->query_skill("furong-jian", 1))
		return notify_fail("��Ļ�������������ޣ��޷����������ܽ�ؽ�����\n");

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

        level = (int) me->query_skill("furong-jian", 1);
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
        	   return notify_fail("����������㣬û�а취��ϰܽ�ؽ�����\n");

       if ((int)me->query("qi") < 65)
        	   return notify_fail("�������������ܽ�ؽ�����\n");

       me->receive_damage("qi", 40);
       me->add("neili", -50);
       return 1;
}

string perform_action_file(string action)
{
        return __DIR__"furong-jian/" + action;
}

