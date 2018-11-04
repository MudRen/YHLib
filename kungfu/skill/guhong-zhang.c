#include <ansi.h>
inherit SKILL;

mapping *action = ({
([      "action" : "$Nʹһ�С�����ֱ�¡�������һ������$n��$l��ȥ",
        "force"  : 55,
	"attack" : 4,
        "dodge"  : 30,
        "parry"  : 25,       
        "damage" : 20, 
        "lvl"    : 0,
        "damage_type" : "����",
        "skill_name"  : "����ֱ��",
]),
([      "action" : "$Nʹһ�С�����Ⱥɽ��������б��������$n��$l",
        "force"  : 68,
	"attack" : 6,
        "dodge"  : 48,
        "parry"  : 30,        
        "damage" : 30, 
        "lvl"    : 25,
        "damage_type" : "����",
        "skill_name"  : "����Ⱥɽ",
]),
([      "action" : "$N˫�ִ��磬һʽ���������᡹��������񣬻���$n��$l",
        "force"  : 78,
	"attack" : 10,
        "dodge"  : 50,
        "parry"  : 60,        
        "damage" : 38, 
        "lvl"    : 50,
        "damage_type" : "����",
        "skill_name"  : "��������", 
]),
([      "action" : "$N˫��΢̧�����������һ�С�ˮ��̽�¡����ѽ�$n$l����",
        "force"  : 86,
	"attack" : 12,
        "dodge"  : 44,
        "parry"  : 71,      
        "damage" : 45, 
        "lvl"    : 70,
        "damage_type" : "����",
         "skill_name" : "ˮ��̽��",
]),
([      "action" : "$N˫�Ʒ��ڣ��Ʒ�������һʽ������ϸ�꡹��ƮȻ����������$n$l",
        "force"  : 100,
	"attack" : 15,
        "dodge"  : 55,
        "parry"  : 60,       
        "damage" : 50, 
        "lvl"    : 90,
        "damage_type" : "����",
        "skill_name"  : "����ϸ��",
]),
([      "action" : "$N˫���ĳ���һʽ��˫�����¡����Ʒ�һ��һ������$n��$l��ȥ",
        "force"  : 125,
	"attack" : 15,
        "dodge"  : 60,
        "parry"  : 55, 
        "damage" : 55,        
        "lvl"    : 100,
        "damage_type" : "����",
        "skill_name"  : "˫������",
]),
([      "action" : "$N�첽��ǰ�������죬һ�С������Ҷ�����Ʒ��ѵ�$n$l",
        "force"  : 140,
	"attack" : 18,
        "dodge"  : 80,
        "parry"  : 71, 
        "damage" : 63,     
        "lvl"    : 110,
        "damage_type" : "����",
        "skill_name"  : "�����Ҷ",
]),
([      "action" : "$N˫���´�������������������Ȼ�ӿ죬�ƹ��ǹ���һʽ���˺��º衹\n"
                   "ʹ����˫���ѵ�$n$l",
        "force"  : 155,
	"attack" : 25,
        "dodge"  : 76,
        "parry"  : 80,   
        "damage" : 80,    
        "lvl"    : 120,
        "damage_type" : "����",
        "skill_name"  : "�˺��º�",
]),
});

int valid_enable(string usage)
{
	return usage == "strike" || usage == "parry";
}

int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("���º��Ʒ�������֡�\n");

        if ((int)me->query_skill("force") < 40)
                return notify_fail("����ڹ���򲻹����޷�ѧ�º��Ʒ���\n");

        if ((int)me->query("max_neili") < 120)
                return notify_fail("�������̫�����޷����º��Ʒ���\n");

        if ((int)me->query_skill("strike", 1) < 30)
                return notify_fail("��Ļ����Ʒ����̫ǳ��\n");

        if ((int)me->query_skill("strike", 1) < (int)me->query_skill("guhong-zhang", 1))
                return notify_fail("��Ļ����Ʒ�ˮƽ���ޣ��޷���������Ĺº��Ʒ���\n");

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
        level = (int) me->query_skill("guhong-zhang", 1);
        for (i = sizeof(action); i > 0; i--)
            if (level > action[i-1]["lvl"])
                return action[NewRandom(i, 5, level / 5)];
}

int practice_skill(object me)
{
        if ((int)me->query("qi") < 50)
                return notify_fail("�������̫���ˡ�\n");

        if ((int)me->query("neili") < 50)
                return notify_fail("��������������º��Ʒ���\n");

        me->receive_damage("qi", 45);
        me->add("neili", -40);

        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"guhong-zhang/" + action;
}
