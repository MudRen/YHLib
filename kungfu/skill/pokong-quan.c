#include <ansi.h>
inherit SKILL;

mapping *action = ({
([      "action" : "$Nʹһ�С��տ���Ҳ��������б����һȭ��$n��$l��ȥ",
        "force"  : 10,
        "dodge"  : 30,
        "parry"  : 25,       
        "lvl"    : 0,
        "damage_type" : "����",
        "skill_name"  : "�տ���Ҳ",
]),
([      "action" : "$Nʹһ�С��������ޡ������ֻӳ�������$n��$l",
        "force" : 25,
        "dodge" : 48,
        "parry" : 30,        
        "lvl"   : 10,
        "damage_type" : "����",
        "skill_name"  : "��������",
]),
([      "action" : "$N˫�ֻس������ط�ת��һʽ�����´��ҡ�������$n��$l",
        "force"  : 35,
        "dodge"  : 50,
        "parry"  : 45,        
        "lvl"    : 20,
        "damage_type" : "����",
        "skill_name"  : "���´���", 
]),
([      "action" : "$N˫�ַֿ������������һ�С�����ǧ�������ֻ�$n�����ź�$l",
        "force" : 42,
        "dodge" : 44,
        "parry" : 71,      
        "lvl"   : 30,
        "damage_type" : "����",
         "skill_name" : "����ǧ��",
]),
([      "action" : "$N����̤����������ǰ��һʽ��������Ϣ��������$n$l",
        "force"  : 50,
        "dodge"  : 55,
        "parry"  : 60,       
        "lvl"    : 42,
        "damage_type" : "����",
        "skill_name"  : "������Ϣ",
]),
([      "action" : "$N˫����Ȼ���գ�ͻȻ��ȭֱ����һʽ��ӥ�����ա���$n��$l��ȥ",
        "force"  : 60,
        "dodge"  : 60,
        "parry"  : 62,        
        "lvl"    : 55,
        "damage_type" : "����",
        "skill_name"  : "ӥ������",
]),
([      "action" : "$N�첽��ǰ��һ�С��������硹����ȭֱ��$n$l",
        "force"  : 70,
        "dodge"  : 54,
        "parry"  : 71,     
        "lvl"    : 65,
        "damage_type" : "����",
        "skill_name"  : "��������",
]),
([      "action" : "$Nȭ��������ȭ����Ȼ��죬һʽ�������ƿա�˫ȭ�ѵ�$n$l",
        "force"  : 80,
        "dodge"  : 76,
        "parry"  : 80,       
        "lvl"    : 80,
        "damage_type" : "����",
        "skill_name"  : "�����ƿ�",
]),
});

int valid_enable(string usage)
{
	return usage == "cuff" || usage == "parry";
}

int valid_combine(string combo)
{
        return combo == "guhong-zhang";
}

int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("���ƿ�ȭ��������֡�\n");

        if ((int)me->query_skill("force") < 30)
                return notify_fail("����ڹ���򲻹����޷�ѧ�ƿ�ȭ����\n");

        if ((int)me->query("max_neili") < 200)
                return notify_fail("���������Ϊ̫�����޷����ƿ�ȭ����\n");

        if ((int)me->query_skill("cuff", 1) < 20)
                return notify_fail("��Ļ���ȭ�����̫ǳ���޷����ƿ�ȭ����\n");

        if ((int)me->query_skill("cuff", 1) < (int)me->query_skill("pokong-quan", 1))
                return notify_fail("��Ļ���ȭ��ˮƽ���ޣ��޷�����������ƿ�ȭ����\n");

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
        level = (int) me->query_skill("pokong-quan", 1);
        for (i = sizeof(action); i > 0; i--)
            if (level > action[i-1]["lvl"])
                return action[NewRandom(i, 5, level / 5)];
}

int practice_skill(object me)
{
        if ((int)me->query("qi") < 60)
                return notify_fail("�������̫���ˡ�\n");

        if ((int)me->query("neili") < 50)
                return notify_fail("��������������ƿ�ȭ����\n");

        me->receive_damage("qi", 45);
        me->add("neili", -35);

        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"pokong-quan/" + action;
}
