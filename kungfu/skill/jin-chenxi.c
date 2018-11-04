// huntian-baojian.c ���챦�� ����
// modified by Vin 2000

#include <ansi.h>

inherit FORCE;

int query_neili_improve(object me)
{
        int lvl;

        lvl = (int)me->query_skill("jin-chenxi", 1);
        return lvl * lvl * 15 * 20 / 100 / 200;
}

int valid_force(string force)
{
        return 1;
}

mapping *action = ({
([  "action" : "$Nʩչ" HIY "����" NOR "�ķ�֮��" HIY "������ѩ" NOR "����"
               "һȭ����$n���ţ���Ȼ��צ���ó�һ���������$n$l",
    "dodge"  : -29,
    "attack" : 51,
    "parry"  : 4,
    "force"  : 284,
    "damage" : 58,
    "lvl"    : 0,
    "weapon" : HIY "��������" NOR,
    "damage_type": "ץ��"
]),
([  "action" : "$N��Ȼʹ��" HIY "����" NOR "֮��" HIY "ʮ����һ" NOR "����˫��"
               "����ʹ��������ǵصĹ���$n",
    "dodge"  : -21,
    "attack" : 93,
    "parry"  : 13,
    "force"  : 303,
    "damage" : 161,
    "lvl"    : 150,
    "weapon" : HIY "��������" NOR,
    "damage_type": "����"
]),
([  "action" : "$Nʩ��һ��" HIY "����" NOR "֮��" HIY "��������" NOR "����˫��"
               "��׶��Я�����ޱ��������ھ���Ȼ�����ֱ��$n��$l",
    "dodge"  : -12,
    "attack" : 98,
    "parry"  : 54,
    "force"  : 384,
    "damage" : 233,
    "lvl"    : 200,
    "weapon" : HIY "��������" NOR,
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
                return notify_fail("����" HIY "����" NOR "�ķ�������֡�\n");

        if ((int)me->query("con") < 35)
                return notify_fail("�����ӹ�̫�����޷���ϰ���챦���񹦡�\n");

        if ((int)me->query_skill("unarmed", 1) < 220)
                return notify_fail("���ȭ�Ż���޷�ѧϰ" HIY "����" NOR "�ķ���\n");

        if ((int)me->query_skill("force", 1) < 220)
                return notify_fail("����ڹ�����޷�ѧϰ" HIY "����" NOR "�ķ���\n");

        if ((int)me->query("max_neili") < 6000)
                return notify_fail("���������Ϊ̫��޷�ѧϰ" HIY "����" NOR "�ķ���\n");

        if ((int)me->query_skill("dian-canghai", 1) - 10 < (int)me->query_skill("jin-chenxi", 1))
                return notify_fail("�������������" HIB "��׺�" NOR "�ķ���\n");

        return 1;
}

mapping query_action(object me, object weapon)
{
    return action[random(sizeof(action))];
}

int practice_skill(object me)
{
        return notify_fail( HIY "����" NOR "�ķ�ֻ��ͨ���Ķ�" HIY "�����쾧" NOR "����ߡ�\n");
}


string perform_action_file(string action)
{
        return __DIR__"jin-chenxi/perform/" + action;
}
string exert_function_file(string action)
{
        return __DIR__"jin-chenxi/exert/" + action;
}
