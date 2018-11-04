#include <ansi.h>
inherit SKILL;

mapping *action = ({
([      "action" : "$Nʹһ�С��������������һ������$n��$l��ȥ",
        "force"  : 90,
	"attack" : 4,
        "dodge"  : 30,
        "parry"  : 25,       
        "damage" : 25, 
        "lvl"    : 0,
        "damage_type" : "����",
        "skill_name"  : "��������",
]),
([      "action" : "$Nʹһ�С������������������͵�����$n��$l",
        "force"  : 110,
	"attack" : 6,
        "dodge"  : 48,
        "parry"  : 30,        
        "damage" : 40, 
        "lvl"    : 25,
        "damage_type" : "����",
        "skill_name"  : "��������",
]),
([      "action" : "$N˫Ŀ΢�գ�һʽ���������ߡ���������񣬻���$n��$l",
        "force"  : 120,
	"attack" : 10,
        "dodge"  : 50,
        "parry"  : 60,        
        "damage" : 48, 
        "lvl"    : 50,
        "damage_type" : "����",
        "skill_name"  : "��������", 
]),
([      "action" : "$N˫��΢̧�����������һ�С�ˮ���ݡ����ѽ�$n$l����",
        "force"  : 150,
	"attack" : 12,
        "dodge"  : 44,
        "parry"  : 71,      
        "damage" : 55, 
        "lvl"    : 70,
        "damage_type" : "����",
         "skill_name" : "ˮ����",
]),
([      "action" : "$N˫�Ʒ��ڣ�ȴ��ֹͣ��һʽ������ѩƮ����ƮȻ����������$n$l",
        "force"  : 180,
	"attack" : 15,
        "dodge"  : 55,
        "parry"  : 60,       
        "damage" : 60, 
        "lvl"    : 90,
        "damage_type" : "����",
        "skill_name"  : "����ѩƮ",
]),
([      "action" : "$N����ֱ�����ھ�ʮ�㣬һʽ�������޼������Ʒ�һ��һ������$n��$l��ȥ",
        "force"  : 210,
	"attack" : 15,
        "dodge"  : 60,
        "parry"  : 62, 
        "damage" : 70,        
        "lvl"    : 100,
        "damage_type" : "����",
        "skill_name"  : "�����޼�",
]),
([      "action" : "$N�첽̤����˫�ư����˾���һ�С�����ѩ�ء����Ʒ��ѵ�$n$l",
        "force"  : 240,
	"attack" : 18,
        "dodge"  : 80,
        "parry"  : 71, 
        "damage" : 80,     
        "lvl"    : 110,
        "damage_type" : "����",
        "skill_name"  : "����ѩ��",
]),
([      "action" : "$N���ƺ�������$n����ͻȻ�ջأ�����������б����һ�С�"
                   "�캮�ض�������$n$l",
        "force"  : 280,
	"attack" : 25,
        "dodge"  : 76,
        "parry"  : 80,   
        "damage" : 90,    
        "lvl"    : 120,
        "damage_type" : "����",
        "skill_name"  : "�캮�ض�",
]),
});

int valid_enable(string usage)
{
	return usage == "strike" || usage == "parry";
}

int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("�������Ʊ�����֡�\n");

        if ((int)me->query_skill("force") < 120)
                return notify_fail("����ڹ���򲻹����޷�ѧ�����ơ�\n");

        if ((int)me->query("max_neili") < 600)
                return notify_fail("�������̫�����޷��������ơ�\n");

        if ((int)me->query_skill("strike", 1) < 100)
                return notify_fail("��Ļ����Ʒ����̫ǳ��\n");

        if ((int)me->query_skill("strike", 1) < (int)me->query_skill("hanbing-zhang", 1))
                return notify_fail("��Ļ����Ʒ�ˮƽ���ޣ��޷���������ĺ����ơ�\n");

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
        level = (int) me->query_skill("hanbing-zhang", 1);
        for (i = sizeof(action); i > 0; i--)
            if (level > action[i-1]["lvl"])
                return action[NewRandom(i, 5, level / 5)];
}

int practice_skill(object me)
{
        if ((int)me->query("qi") < 80)
                return notify_fail("�������̫���ˡ�\n");

        if ((int)me->query("neili") < 70)
                return notify_fail("������������������ơ�\n");

        me->receive_damage("qi", 65);
        me->add("neili", -60);

        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"hanbing-zhang/" + action;
}
