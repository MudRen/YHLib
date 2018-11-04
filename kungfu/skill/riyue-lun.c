#include <ansi.h>;
inherit SKILL;

mapping *action = ({
([      "action" : "$Nʹһ�С������ơ����������е�$w��$n��$l��ȥ",
        "force"  : 120,
        "attack" : 27,
        "dodge"  : -10,
        "parry"  : 40,
        "lvl"    : 0,
        "damage" : 62,
        "damage_type" : "����",
        "skill_name"  : "������",
]),
([      "action" : "$Nʹһ�С���ɽ���ơ���˫��һ�����趯����$w��$n��$l��ɨ",
        "force"  : 160,
        "attack" : 38,
        "dodge"  : -20,
        "parry"  : 45,
        "lvl"    : 35,
        "damage" : 66,
        "damage_type" : "����",
        "skill_name"  : "��ɽ����",
]),
([      "action" : "$Nʹһ�С���΢�ơ����͵�һ�����������¶�������$n��$l",
        "force"  : 200,
        "attack" : 43,
        "dodge"  : -20,
        "parry"  : 47,
        "lvl"    : 70,
        "damage" : 70,
        "damage_type" : "����",
        "skill_name"  : "��΢��",
]),
([      "action" : "$Nʹһ�С������ơ����������֮��$wɨ��$n��$l",
        "force"  : 240,
        "attack" : 51,
        "dodge"  : 5,
        "parry"  : 50,
        "lvl"    : 100,
        "damage" : 75,
        "damage_type" : "����",
        "skill_name"  : "������",
]),
([      "action" : "$Nʹһ�С�Բ���ơ���$w������֮����ֱ��$n��$l",
        "force"  : 280,
        "attack" : 55,
        "dodge"  : -10,
        "parry"  : 55,
        "lvl"    : 120,
        "damage" : 80,
        "damage_type" : "����",
        "skill_name"  : "Բ����",
]),
([      "action" : "$NԾ���գ�ʹһ�С����ػ��ơ����߾�$w����$n��$l",
        "force"  : 320,
        "attack" : 61,
        "dodge"  : 10,
        "parry"  : 60,
        "lvl"    : 140,
        "damage" : 85,
        "damage_type" : "����",
        "skill_name"  : "���ػ���",
]),
([      "action" : "$Nʹһ�С�׽���ơ���б������$w����$n��$l",
        "force"  : 360,
        "attack" : 65,
        "dodge"  : -15,
        "parry"  : 68,
        "lvl"    : 150,
        "damage" : 95,
        "damage_type" : "����",
        "skill_name"  : "׽����",
]),
([      "action" : "$N��һ��������ʹ�����Լ��项��$wɨ��$n��ͷ��",
        "force"  : 400,
        "attack" : 70,
        "dodge"  : -20,
        "parry"  : 75,
        "lvl"    : 160,
        "damage" : 110,
        "damage_type" : "����",
        "skill_name"  : "�Լ���",
]),
});


int valid_enable(string usage)
{
	return usage == "hammer" || usage == "parry";
}

int valid_learn(object me)
{
        if (me->query("str") < 32)
                return notify_fail("�������������㣬�������������ַ���\n");

        if ((int)me->query("max_neili") < 1000)
                return notify_fail("�������������\n");

        if ((int)me->query_skill("force") < 150)
                return notify_fail("����ڹ����̫ǳ��\n");

        if ((int)me->query_skill("hammer", 1) < 100)
                return notify_fail("��Ļ��������������������������ַ���\n");

        if ((int)me->query_skill("hammer", 1) < (int)me->query_skill("riyue-lun", 1))
                return notify_fail("��Ļ�������ˮƽ���ޣ��޷���������������ַ���\n");

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
        level = (int) me->query_skill("riyue-lun",1);
        for (i = sizeof(action); i > 0; i--)
                if (level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level / 5)];
}

int practice_skill(object me)
{
        object weapon;

        if (! objectp(weapon = me->query_temp("weapon"))
           || (string)weapon->query("skill_type") != "hammer")
                return notify_fail("��ʹ�õ��������ԡ�\n");

        if ((int)me->query("qi") < 70)
                return notify_fail("������������������������ַ���\n");

        if ((int)me->query("neili") < 70)
                return notify_fail("������������������������ַ���\n");

        me->receive_damage("qi", 62);
        me->add("neili", -68);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"riyue-lun/" + action;
}
