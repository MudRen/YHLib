#include <ansi.h>
inherit SKILL;

mapping *action = ({
([      "action" : "$Nʹһ�С�����������������б����һ����$n��$l��ȥ",
        "force"  : 10,
        "dodge"  : 30,
        "parry"  : 25,       
        "lvl"    : 0,
        "damage_type" : "����",
        "skill_name"  : "��������",
]),
([      "action" : "$Nʹһ�С��󽭶�ȥ�������ֻӳ�������$n��$l",
        "force" : 25,
        "dodge" : 48,
        "parry" : 30,        
        "lvl"   : 10,
        "damage_type" : "����",
        "skill_name"  : "�󽭶�ȥ",
]),
([      "action" : "$N˫�ֻس������ط�ת��һʽ�������޻���������$n��$l",
        "force"  : 35,
        "dodge"  : 50,
        "parry"  : 45,        
        "lvl"    : 20,
        "damage_type" : "����",
        "skill_name"  : "�����޻�", 
]),
([      "action" : "$N˫�ַֿ������������һ�С�ˮ���ݡ����ֻ�$n�����ź�$l",
        "force" : 42,
        "dodge" : 44,
        "parry" : 71,      
        "lvl"   : 30,
        "damage_type" : "����",
         "skill_name" : "ˮ����",
]),
([      "action" : "$N����̤����������ǰ��һʽ�����಻����������$n$l",
        "force"  : 50,
        "dodge"  : 55,
        "parry"  : 60,       
        "lvl"    : 42,
        "damage_type" : "����",
        "skill_name"  : "���಻��",
]),
([      "action" : "$N˫����Ȼ���գ�ͻȻ����ֱ����һʽ�����컨�꡹��$n��$l��ȥ",
        "force"  : 60,
        "dodge"  : 60,
        "parry"  : 62,        
        "lvl"    : 55,
        "damage_type" : "����",
        "skill_name"  : "���컨��",
]),
([      "action" : "$N�첽��ǰ��һ�С����⽿�ӡ�������ֱ��$n$l",
        "force"  : 70,
        "dodge"  : 54,
        "parry"  : 71,     
        "lvl"    : 65,
        "damage_type" : "����",
        "skill_name"  : "���⽿��",
]),
([      "action" : "$N�Ʒ�������������Ȼ��죬һʽ������һ����˫���ѵ�$n$l",
        "force"  : 80,
        "dodge"  : 76,
        "parry"  : 80,       
        "lvl"    : 80,
        "damage_type" : "����",
        "skill_name"  : "����һ��",
]),
});

int valid_enable(string usage)
{
	return usage == "strike" || usage == "parry";
}

int valid_combine(string combo)
{
        return combo == "songshan-quan";
}

int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("����ɽ�Ʒ�������֡�\n");

        if ((int)me->query_skill("force") < 30)
                return notify_fail("����ڹ���򲻹����޷�ѧ��ɽ�Ʒ���\n");

        if ((int)me->query("max_neili") < 200)
                return notify_fail("���������Ϊ̫�����޷�����ɽ�Ʒ���\n");

        if ((int)me->query_skill("strike", 1) < 20)
                return notify_fail("��Ļ����Ʒ����̫ǳ���޷�����ɽ�Ʒ���\n");

        if ((int)me->query_skill("strike", 1) < (int)me->query_skill("songshan-zhang", 1))
                return notify_fail("��Ļ����Ʒ�ˮƽ���ޣ��޷������������ɽ�Ʒ���\n");

        return 1;
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
        level = (int) me->query_skill("songshan-zhang", 1);
        for (i = sizeof(action); i > 0; i--)
            if (level > action[i-1]["lvl"])
                return action[NewRandom(i, 5, level / 5)];
}

int practice_skill(object me)
{
        if ((int)me->query("qi") < 60)
                return notify_fail("�������̫���ˡ�\n");

        if ((int)me->query("neili") < 50)
                return notify_fail("���������������ɽ�Ʒ���\n");

        me->receive_damage("qi", 45);
        me->add("neili", -35);

        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"songshan-zhang/" + action;
}
