// huntian-baojian.c ���챦�� Ѫ��
// modified by Vin 2000

#include <ansi.h>

inherit FORCE;

int query_neili_improve(object me)
{
        int lvl;

        lvl = (int)me->query_skill("xue-qiongcang", 1);
        return lvl * lvl * 15 * 20 / 100 / 200;
}

int valid_force(string force)
{
        return 1;
}

mapping *action = ({
([  "action" : "$Nʩչ" HIR "Ѫ��" NOR "�ķ�֮��" HIR "Ѫ������" NOR "����"
               "��ʱ���ֳ�һ��Ѫ�������任�޶���ȫ����һ��Ѫ�⹥��$n",
    "dodge"  : 41,
    "attack" : 21,
    "parry"  : 9,
    "force"  : 261,
    "damage" : 33,
    "lvl"    : 0,
    "weapon" : HIR "Ѫ������" NOR,
    "damage_type": "����"
]),
([  "action" : "$N��Ȼʹ��" HIR "Ѫ��" NOR "֮��" HIR "�������" NOR "����˫��"
               "�߾ٹ�����һ���ƺȣ�ǧ���Ʒ�����ӿ��������ǵ�ϯ��$n",
    "dodge"  : -61,
    "attack" : 103,
    "parry"  : -41,
    "force"  : 373,
    "damage" : 191,
    "lvl"    : 150,
    "weapon" : HIR "Ѫ������" NOR,
    "damage_type": "����"
]),
([  "action" : "$Nʩ��һ��" HIR "Ѫ��" NOR "֮��" HIR "Ѫ��˺��" NOR "�������"
               "��Ծ��˫צЯ�����֮���ó�����Ѫ��Ϯ����ֱ��$n$l",
    "dodge"  : -72,
    "attack" : 139,
    "parry"  : -54,
    "force"  : 424,
    "damage" : 253,
    "lvl"    : 200,
    "weapon" : HIR "Ѫ������" NOR,
    "damage_type": "����"
]),
([  "action" : "$Nվ��������һ�����ȣ�ʩ��" HIR "Ѫ��" NOR "֮��" HIR "����޻�"
               NOR "������ʱ����Ѫ�������������Ѫ����ʱ����$n������˷�",
    "dodge"  : -67,
    "attack" : 198,
    "parry"  : -54,
    "force"  : 484,
    "damage" : 239,
    "lvl"    : 200,
    "weapon" : HIR "Ѫ������" NOR,
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
                return notify_fail("����" HIR "Ѫ��" NOR "�ķ�������֡�\n");

        if ((int)me->query("con") < 35)
                return notify_fail("�����ӹ�̫�����޷���ϰ���챦���񹦡�\n");

        if ((int)me->query_skill("unarmed", 1) < 240)
                return notify_fail("���ȭ�Ż���޷�ѧϰ" HIR "Ѫ��" NOR "�ķ���\n");

        if ((int)me->query_skill("force", 1) < 240)
                return notify_fail("����ڹ�����޷�ѧϰ" HIR "Ѫ��" NOR "�ķ���\n");

        if ((int)me->query("max_neili") < 7000)
                return notify_fail("���������Ϊ̫��޷�ѧϰ" HIR "Ѫ��" NOR "�ķ���\n");

        if ((int)me->query_skill("jin-chenxi", 1) - 10 < (int)me->query_skill("xue-qiongcang", 1))
                return notify_fail("�������������" HIY "����" NOR "�ķ���\n");

        return 1;
}

mapping query_action(object me, object weapon)
{
    return action[random(sizeof(action))];
}

int practice_skill(object me)
{
        return notify_fail( HIR "Ѫ��" NOR "�ķ�ֻ��ͨ���Ķ�" HIR "Ѫ��" NOR "�쾧" NOR "����ߡ�\n");
}


string perform_action_file(string action)
{
        return __DIR__"xue-qiongcang/perform/" + action;
}
string exert_function_file(string action)
{
        return __DIR__"xue-qiongcang/exert/" + action;
}
