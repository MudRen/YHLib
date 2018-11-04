#include <ansi.h>

inherit SKILL;

mapping *action = ({
([      "action" : "$Nʹһ�С����֡���˫�ֻ��˸���Ȧ������$n��$l",
        "force"  : 37,
        "dodge"  : 35,
        "parry"  : 38,
        "attack" : 5,
        "damage" : 1,
        "lvl" : 0,
        "skill_name"  : "����",
        "damage_type" : "����"
]),
([      "action" : "$Nʹһ�С����ޡ��������������£���������ӳ�������$n��$l",
        "force"  : 48,
        "dodge"  : 51,
        "parry"  : 53,
        "attack" : 7,
        "damage" : 2,
        "lvl" : 10,
        "skill_name"  : "����",
        "damage_type" : "����"
]),
([      "action" : "$N���ֻ��գ������ɹ����ƣ���������ʹһ�С�ӡ�ơ�����$n��$l��ȥ",
        "force"  : 62,
        "dodge"  : 45,
        "parry"  : 57,
        "attack" : 9,
        "damage" : 3,
        "lvl" : 20,
        "skill_name"  : "ӡ��",
        "damage_type" : "����"
]),
([      "action" : "$N˫�ֻ������������ϣ��������£�ʹһ�С��ֱޡ����ֻ�$n�����ź�$l",
        "force"  : 74,
        "dodge"  : 53,
        "parry"  : 62,
        "attack" : 11,
        "damage" : 5,
        "lvl" : 30,
        "skill_name"  : "�ֱ�",
        "damage_type" : "����"
]),
([      "action" : "$N��������ǰ���£�����΢ת������һ����Ȧ��ʹһ�С�ˤ���֡�������$n��$l",
        "force"  : 92,
        "dodge"  : 76,
        "parry"  : 88,
        "attack" : 15,
        "damage" : 8,
        "lvl" : 50,
        "skill_name"  : "ˤ����",
        "damage_type" : "����"
]),
([      "action" : "$N�������������������ںϣ�ʹһ�С����Ƽ��ա�����$n��$l��ȥ",
        "force"  : 120,
        "dodge"  : 81,
        "parry"  : 97,
        "attack" : 19,
        "damage" : 11,
        "lvl" : 70,
        "skill_name"  : "���Ƽ���",
        "damage_type" : "����"
]),
([      "action" : "$N���ֱ��ƺ�����ǰ����ȭ�����´�����һ�С�����ȭ��������$n��$l",
        "force"  : 152,
        "dodge"  : 95,
        "parry"  : 108,
        "attack" : 21,
        "damage" : 14,
        "lvl" : 100,
        "skill_name"  : "����ȭ",
        "damage_type" : "����"
]),
([      "action" : "$N���ǰ̤�벽������ʹһ�С������롹��ָ������$n��$l��ȥ",
        "force"  : 183,
        "dodge"  : 105,
        "parry"  : 113,
        "attack" : 31,
        "damage" : 17,
        "lvl" : 130,
        "skill_name"  : "������",
        "damage_type" : "����"
]),
([      "action" : "$N�С��������������һ���������������Ͼ�����Ʋ������$n��$l��ȥ",
        "force"  : 212,
        "dodge"  : 115,
        "parry"  : 138,
        "attack" : 39,
        "damage" : 21,
        "lvl" : 160,
        "skill_name"  : "������",
        "damage_type" : "����"
]),
});

int valid_enable(string usage) { return usage == "unarmed" || usage == "parry"; }

int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("���޼�����ȭ������֡�\n");

        if ((int)me->query_skill("force") < 100)
                return notify_fail("����ڹ���򲻹����޷�ѧ�޼�����ȭ��\n");

        if ((int)me->query("max_neili") < 800)
                return notify_fail("�������̫�����޷����޼�����ȭ��\n");

        if ((int)me->query_skill("unarmed", 1) < 60)
                return notify_fail("��Ļ���ȭ�Ż�򲻹����޷�ѧ�޼�����ȭ��\n");

        if ((int)me->query_skill("unarmed", 1) < (int)me->query_skill("xuangong-quan", 1))
                return notify_fail("��Ļ���ȭ��ˮƽ���ޣ��޷�����������޼�����ȭ��\n");

        return 1;
}

string query_skill_name(int level)
{
        int i;
        for (i = sizeof(action)-1; i >= 0; i--)
                if (level >= action[i]["lvl"])
                        return action[i]["skill_name"];
}

mapping query_action(object me, object weapon)
{
        int i, level;
        level = (int) me->query_skill("xuangong-quan", 1);
        for (i = sizeof(action); i > 0; i--)
                if (level > action[i - 1]["lvl"])
                        return action[NewRandom(i, 5, level / 5)];
}

int practice_skill(object me)
{
        if ((int)me->query("qi") < 60)
                return notify_fail("�������̫���ˡ�\n");

        if ((int)me->query("neili") < 60)
                return notify_fail("��������������޼�����ȭ��\n");

        me->receive_damage("qi", 40);
        me->add("neili", -50);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"xuangong-quan/" + action;
}
