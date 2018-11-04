// jinwu-goufa.c ���ڹ���

#include <ansi.h>
inherit SKILL;

mapping *action = ({
([   "action" : "$N����$wһ����һʽ���������š��������ļ�����$n��$l",
     "force"  : 50,
     "attack" : 15,
     "dodge"  : 10,
     "parry"  : 25,
     "damage" : 10,
     "lvl"    : 0,
     "damage_type":  "����"
]),
([   "action" : "$N����ͻ������ʽ���䣬����$w��һ�����벻���ķ�λб����$n��$l",
     "force"  : 93,
     "attack" : 25,
     "dodge"  : 25,
     "parry"  : 30,
     "damage" : 5,
     "lvl"    : 10,
     "damage_type":  "����"
]),
([   "action" : "$Nһʽ����˿��ϵ�����������಻��������һ�����εĴ�����$n���ڵ���",
     "force"  : 135,
     "attack" : 33,
     "dodge"  : 22,
     "parry"  : 32,
     "damage" : 20,
     "lvl"    : 20,
     "damage_type":  "����"
]),
([   "action" : "$Nһ����Ц����������һʽ��������צ��������$w���裬�ó�ǧ�����ֱۣ���������$n",
     "force"  : 189,
     "attack" : 39,
     "dodge"  : 40,
     "parry"  : 35,
     "damage" : 35,
     "lvl"    : 30,
     "damage_type":  "����"
]),
([   "action" : "$N����һ���������ߣ�����$wȴٿ�Ĵ�Ҹ�´�����������$n��$l����һʽ����Ы���롹",
     "force"  : 221,
     "attack" : 43,
     "dodge"  : 60,
     "parry"  : 40,
     "damage" : 48,
     "lvl"    : 40,
     "damage_type":  "����"
]),
([   "action" : "$N�Ų����ģ����κ�����ǰ������һʽ���������¡�������$w���¶���ֱ��$n��С��",
     "force"  : 263,
     "attack" : 51,
     "dodge"  : 50,
     "parry"  : 45,
     "damage" : 63,
     "lvl"    : 70,
     "damage_type":  "����"
]),
([   "action" : "$N����һ�Σ�һʽ�����߲��󡹣�����$w�總��֮����������Ϣ�ش���$n������",
     "force"  : 285,
     "attack" : 62,
     "dodge"  : 40,
     "parry"  : 47,
     "damage" : 87,
     "lvl"    : 100,
     "damage_type":  "����"
]),
([   "action" : "$Nһ����Х�����γ������һʽ�����ű䡹������$w����Ȱ�����$nȫ��ŵ���Ѩ",
     "force"  : 291,
     "attack" : 71,
     "dodge"  : 30,
     "parry"  : 52,
     "damage" : 91,
     "lvl"    : 110,
     "damage_type":  "����"
]),
([   "action" : "$N�������ף�����$w�й�ֱ����һʽ���ڻ����Ρ���Ѹ���ޱȵ���$n��$l��ȥ",
     "force"  : 313,
     "attack" : 85,
     "dodge"  : 20,
     "parry"  : 54,
     "damage" : 95,
     "lvl"    : 130,
     "damage_type":  "����"
]),
([   "action" : "$N����һ�������ݡ������𡹣�$w���͸��һ��ǿ���ĺ�����������Ϯ��$n",
     "force"  : 328,
     "attack" : 88,
     "dodge"  : 30,
     "parry"  : 62,
     "damage" : 117,
     "lvl"    : 160,
     "damage_type":  "����"
]),
});

int valid_enable(string usage)
{
	return usage == "sword" || usage == "parry";
}

int valid_learn(object me)
{
        if ((int)me->query("max_neili") < 1200)
                return notify_fail("�������������\n");

        if ((int)me->query_skill("force") < 150)
                return notify_fail("����ڹ����̫ǳ��\n");

        if ((int)me->query_skill("sword", 1) < 100)
                return notify_fail("��Ļ���������򲻹����޷�ѧϰ���ڹ�����\n");

        if ((int)me->query_skill("sword", 1) < (int)me->query_skill("jinwu-goufa", 1))
                return notify_fail("��Ļ�������ˮƽ���ޣ��޷���������Ľ��ڹ�����\n");

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
        level   = (int) me->query_skill("jinwu-goufa",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        object weapon;

        if (!objectp(weapon = me->query_temp("weapon")) ||
            (string)weapon->query("skill_type") != "sword")
                return notify_fail("��ʹ�õ��������ԡ�\n");

        if ((int)me->query("qi") < 60)
                return notify_fail("�������Ŀǰû�а취��ϰ���ڹ�����\n");

        if ((int)me->query("neili") < 70)
                return notify_fail("��������������޷���ϰ���ڹ�����\n");
        
        me->add("qi", -50);
        me->add("neili", -62);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"jinwu-goufa/" + action;
}

