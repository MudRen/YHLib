#include <ansi.h>
inherit SKILL;

mapping *action = ({
([      "action" : "$N�ҽ������������㣬һʽ" HIR "������֡�" NOR "��������һ��һ�ͣ�����$n��$l",
        "force" : 150,
        "dodge" : 5,
        "damage": 5,
        "lvl" : 0,
        "skill_name" : "�����",
        "damage_type" : "����"
]),
([      "action" : "$N�����̤��ȫ����ת��һ��" HIW "���з��ȡ�" NOR "������Я�����羢�͵�����$n��$l",
        "force" : 200,
        "dodge" : 10,
        "damage": 20,
        "lvl" : 20,
        "skill_name" : "�з���",
        "damage_type" : "����"
]),
([      "action" : "$N����Ʈ����������Ȼһ��" HIC "��ˮ��ץ��" NOR "��������������צӰһ��ץ��$n��$l",
        "force" : 200,
        "dodge" : 10,
        "damage": 20,
        "lvl" : 40,
        "skill_name" : "ˮ��ץ",
        "damage_type" : "ץ��"
]),
([      "action" : "$N˫�ִ󿪴��أ����߾٣�ʹһ��" HIY "��˸���ơ�" NOR "��˫�Ʊ��������������$n$l",
        "force" : 220,
        "dodge" : 15,
        "damage": 25,
        "lvl" : 60,
        "skill_name" : "˸����",
        "damage_type" : "����"
]),
([      "action" : "$N����Ȧ���������⵱�أ����ֻ��ڳ��ϣ�һ��" WHT "������ȭ��" NOR "��Х�Ŵ���$n��$l",
        "force" : 260,
        "dodge" : 20,
        "damage": 35,
        "lvl" : 80,
        "skill_name" : "����ȭ",
        "damage_type" : "����"
]),
([      "action" : "$N���������һ��" YEL "����ľָ��" NOR "������ǰ̽����쬡���һֱָ��$n��$l",
        "force" : 300,
        "dodge" : 25,
        "damage": 30,
        "lvl" : 100,
        "weapon" : "��ָ",
        "skill_name" : "��ľָ",
        "damage_type" : "����"
]),
([      "action" : "$N˫ȭ������һ��" RED "�������ܾ���" NOR "���г���磬�ó�������Ӱ������ǵ�Ϯ��$nȫ��",
        "force" : 320,
        "dodge" : 0,
        "damage": 40,
        "lvl" : 120,
        "skill_name" : "�����ܾ�",
        "damage_type" : "����"
]),
});

int valid_enable(string usage) { return usage=="unarmed" || usage=="parry"; }

int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("������ȭ������֡�\n");

        if ((int)me->query_skill("force") < 100)
                return notify_fail("����ڹ���򲻹����޷�ѧ����ȭ��\n");

        if ((int)me->query("max_neili") < 800)
                return notify_fail("�������̫�����޷�������ȭ��\n");

        if ((int)me->query_skill("unarmed", 1) < 100)
                return notify_fail("���ȭ�Ÿ������ޣ��޷��������ȭҪ�衣\n");

        if ((int)me->query_skill("unarmed", 1) < (int)me->query_skill("wuxing-quan", 1))
                return notify_fail("���ȭ�Ÿ�������㣬�޷��������������ȭ��\n");

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
        level   = (int) me->query_skill("wuxing-quan",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        if ((int)me->query("qi") < 60)
                return notify_fail("�������̫���ˡ�\n");

        if ((int)me->query("neili") < 70)
                return notify_fail("�����������������ȭ��\n");

        me->receive_damage("qi", 45);
        me->add("neili", -56);

        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"wuxing-quan/" + action;
}
