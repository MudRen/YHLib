#include <ansi.h>

inherit SKILL;

mapping *action = ({
([   "action" : "$N��¶΢Ц��һ�С����Ƽ��ա�������$wһ�������Ⱪ��������$n��$l",
     "force"  : 50,
     "attack" : 15,
     "dodge"  : 10,
     "parry"  : 25,
     "damage" : 10,
     "lvl"    : 0,
     "skill_name" : "���Ƽ���",
     "damage_type":  "����"
]),
([   "action" : "$Nһ�С�����ָ·��������ͻ�������ж��䣬����$w�Ӻ�б����$n��$l",
     "force"  : 70,
     "attack" : 21,
     "dodge"  : 25,
     "parry"  : 30,
     "damage" : 15,
     "lvl"    : 20,
     "skill_name" : "����ָ·",
     "damage_type":  "����"
]),
([   "action" : "$N�������ߣ�һ�С��ܹ����İ塹�����׸������������$w��Ȼ���ϣ�����$n��$l",
     "force"  : 75,
     "attack" : 23,
     "dodge"  : 22,
     "parry"  : 32,
     "damage" : 20,
     "lvl"    : 40,
     "skill_name" : "�ܹ����İ�",
     "damage_type":  "����"
]),
([   "action" : "$N����һ�Σ����Ӷ��ϣ�ʹһ�С����ﳯ����������$w����һ������׼$n��������",
     "force"  : 90,
     "attack" : 29,
     "dodge"  : 10,
     "parry"  : 25,
     "damage" : 21,
     "lvl"    : 60,
     "skill_name" : "���ﳯ��",
     "damage_type":  "����"
]),
([   "action" : "$N����һչ��ʩչ�������Ӵ������Ӱ���棬����$w����$n��$l��ȥ",
     "force"  : 103,
     "attack" : 31,
     "dodge"  : 13,
     "parry"  : 22,
     "damage" : 23,
     "lvl"    : 80,
     "skill_name" : "���Ӵ���",
     "damage_type":  "����"
]),
([   "action" : "$Nһ�С��ɺ��׻�����������ӣ�����$w����б������ֱָ$n��$l",
     "force"  : 125,
     "attack" : 35,
     "dodge"  : 15,
     "parry"  : 25,
     "damage" : 28,
     "lvl"    : 100,
     "skill_name" : "�ɺ��׻�",
     "damage_type":  "����"
]),
([   "action" : "$N΢΢һ��ת��һ�С��Ź��ϵ���¿��������$wȴ�������´���������$n��$l",
     "force"  : 133,
     "attack" : 42,
     "dodge"  : 11,
     "parry"  : 27,
     "damage" : 33,
     "lvl"    : 120,
     "skill_name" : "�Ź��ϵ���¿",
     "damage_type":  "����"
]),
([   "action" : "$N��ɫ΢�䣬һ�С��������������ȡ������ж�ʱ��������ޱȣ�����$w���������$n",
     "force"  : 151,
     "attack" : 47,
     "dodge"  : 13,
     "parry"  : 32,
     "damage" : 36,
     "lvl"    : 140,
     "skill_name" : "��������������",
     "damage_type":  "����"
]),
([   "action" : "$N�������ף�����һ�С��������«ϵ����������$w�й�ֱ����Ѹ���ޱȵ���$n��ȥ",
     "force"  : 165,
     "attack" : 53,
     "dodge"  : 20,
     "parry"  : 34,
     "damage" : 43,
     "lvl"    : 160,
     "skill_name" : "�������«ϵ��",
     "damage_type":  "����"
]),
});

int valid_enable(string usage) {return usage == "sword" || usage == "parry";}

int valid_learn(object me)
{
        if ((int)me->query("max_neili") < 200)
                return notify_fail("�������������\n");

        if ((int)me->query_skill("force") < 20)
                return notify_fail("����ڹ����̫ǳ��\n");

        if ((int)me->query_skill("sword", 1) < 10)
                return notify_fail("��Ļ���������򲻹����޷�ѧϰ���ɽ�����\n");

        if ((int)me->query_skill("sword", 1) < (int)me->query_skill("baxian-jian", 1))
                return notify_fail("��Ļ�������ˮƽ���ޣ��޷���������İ��ɽ�����\n");

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
        level   = (int) me->query_skill("baxian-jian",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level / 5)];
}

int practice_skill(object me)
{
        object weapon;

        if ( ! objectp(weapon = me->query_temp("weapon")) ||
            (string)weapon->query("skill_type") != "sword")
                return notify_fail("��ʹ�õ��������ԡ�\n");

        if ((int)me->query("qi") < 50)
                return notify_fail("�������Ŀǰû�а취��ϰ���ɽ�����\n");

        if ((int)me->query("neili") < 50)
                return notify_fail("��������������޷���ϰ���ɽ�����\n");
        
        me->add("qi", -43);
        me->add("neili", -44);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"baxian-jian/" + action;
}