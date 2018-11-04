// huntian-baojian.c ���챦�� ��׺�
// modified by Vin 2000

#include <ansi.h>

inherit FORCE;

int query_neili_improve(object me)
{
        int lvl;

        lvl = (int)me->query_skill("dian-canghai", 1);
        return lvl * lvl * 15 * 18 / 100 / 200;
}

int valid_force(string force)
{
        return 1;
}

mapping *action = ({
([  "action" : "$Nʩ��һ��" HIB "��׺�" NOR "֮��" HIB "������" NOR "����һ"
               "ȭ��Ȼ���������ƻֺ룬�������ȣ�ֱ��$n��$l",
    "dodge"  : -37,
    "attack" : 61,
    "parry"  : 14,
    "force"  : 381,
    "damage" : 31,
    "lvl"    : 0,
    "weapon" : HIB "��׺�����" NOR,
    "damage_type": "����"
]),
([  "action" : "$N����ǰ��һ��" HIB "��׺�" NOR "֮��" HIB "��Ԩ��" NOR
               "����˫����Ȼ��һ�����캮����ϯ��$nȫ��",
    "dodge"  : -38,
    "attack" : 80,
    "parry"  : 21,
    "force"  : 485,
    "damage" : 137,
    "lvl"    : 150,
    "weapon" : HIB "��׺�����" NOR,
    "damage_type": "����"
]),
([  "action" : "$N��Ȼʹ��" HIB "��׺�" NOR "��" HIB "������" NOR "����˫��"
               "���½����ͷ׹����������Ӱ��ʱ����$n",
    "dodge"  : -21,
    "attack" : 93,
    "parry"  : 13,
    "force"  : 451,
    "damage" : 141,
    "lvl"    : 150,
    "weapon" : HIB "��׺�����" NOR,
    "damage_type": "����"
]),
([  "action" : "$Nһ���޺ȣ����" HIB "��׺�" NOR "�ķ�֮��" HIB "������" NOR
               "����˫����������ˣ�һ�����������Ӿ������������$n",
    "dodge"  : -21,
    "attack" : 93,
    "parry"  : 13,
    "force"  : 451,
    "damage" : 141,
    "lvl"    : 200,
    "weapon" : HIB "��׺�����" NOR,
    "damage_type": "����"
]),
});

//string main_skill() { return "huntian-baojian"; }

int valid_enable(string usage) { return usage=="unarmed" ||  usage=="parry" ||  usage=="force"; }  

int valid_learn(object me)
{
        if (me->query_skill("huntian-baojian", 1) > 0)
                return notify_fail("���Ѿ������챦���񹦺�һ�������ٵ���ѧϰ��\n");

        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("����" HIB "��׺�" NOR "�ķ�������֡�\n");

        if ((int)me->query("con") < 35)
                return notify_fail("�����ӹ�̫�����޷���ϰ���챦���񹦡�\n");

        if ((int)me->query_skill("unarmed", 1) < 200)
                return notify_fail("���ȭ�Ż���޷�ѧϰ" HIB "��׺�" NOR "�ķ���\n");

        if ((int)me->query_skill("force", 1) < 200)
                return notify_fail("����ڹ�����޷�ѧϰ" HIB "��׺�" NOR "�ķ���\n");

        if ((int)me->query("max_neili") < 5000)
                return notify_fail("���������Ϊ̫��޷�ѧϰ" HIB "��׺�" NOR "�ķ���\n");

        if ((int)me->query_skill("xuan-huntun", 1) - 10 < (int)me->query_skill("dian-canghai", 1))
                return notify_fail("�������������" WHT "�����" NOR "�ķ���\n");

        return 1;
}

mapping query_action(object me, object weapon)
{
    return action[random(sizeof(action))];
}

int practice_skill(object me)
{
        return notify_fail( HIB "��׺�" NOR "�ķ�ֻ��ͨ���Ķ�" HIB "��׺��쾧" NOR "����ߡ�\n");
}


string perform_action_file(string action)
{
        return __DIR__"dian-canghai/perform/" + action;
}
string exert_function_file(string action)
{
        return __DIR__"dian-canghai/exert/" + action;
}
