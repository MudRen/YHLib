#include <ansi.h>

inherit FORCE;

int query_neili_improve(object me)
{
        int lvl;

        lvl = (int)me->query_skill("huntian-baojian", 1);
        return lvl * lvl * 15 * 50 / 100 / 200;
}

mapping *action = ({
([  "action" : "$Nʩ��һ��" HIB "��׺�" NOR "֮��" HIB "������" NOR "����һ"
               "ȭ��Ȼ���������ƻֺ룬�������ȣ�ֱ��$n��$l",
    "dodge"  : 137,
    "attack" : 161,
    "parry"  : 114,
    "force"  : 481,
    "damage" : 131,
    "weapon" : HIB "��׺�����" NOR,
    "damage_type": "����"
]),
([  "action" : "$N����ǰ��һ��" HIB "��׺�" NOR "֮��" HIB "��Ԩ��" NOR
               "����˫����Ȼ��һ�����캮����ϯ��$nȫ��",
    "dodge"  : 138,
    "attack" : 180,
    "parry"  : 121,
    "force"  : 485,
    "damage" : 137,
    "weapon" : HIB "��׺�����" NOR,
    "damage_type": "����"
]),
([  "action" : "$N��Ȼʹ��" HIB "��׺�" NOR "��" HIB "������" NOR "����˫��"
               "���½����ͷ׹����������Ӱ��ʱ����$n",
    "dodge"  : 121,
    "attack" : 193,
    "parry"  : 113,
    "force"  : 451,
    "damage" : 241,
    "weapon" : HIB "��׺�����" NOR,
    "damage_type": "����"
]),
([  "action" : "$Nһ���޺ȣ����" HIB "��׺�" NOR "�ķ�֮��" HIB "������" NOR
               "����˫����������ˣ�һ�����������Ӿ������������$n",
    "dodge"  : 121,
    "attack" : 193,
    "parry"  : 113,
    "force"  : 451,
    "damage" : 241,
    "weapon" : HIB "��׺�����" NOR,
    "damage_type": "����"
]),
([  "action" : "$Nʩչ" HIR "Ѫ��" NOR "�ķ�֮��" HIR "Ѫ������" NOR "����"
               "��ʱ���ֳ�һ��Ѫ�������任�޶���ȫ����һ��Ѫ�⹥��$n",
    "dodge"  : 241,
    "attack" : 221,
    "parry"  : 209,
    "force"  : 261,
    "damage" : 233,
    "weapon" : HIR "Ѫ������" NOR,
    "damage_type": "����"
]),
([  "action" : "$N��Ȼʹ��" HIR "Ѫ��" NOR "֮��" HIR "�������" NOR "����˫��"
               "�߾ٹ�����һ���ƺȣ�ǧ���Ʒ�����ӿ��������ǵ�ϯ��$n",
    "dodge"  : 261,
    "attack" : 103,
    "parry"  : 241,
    "force"  : 373,
    "damage" : 391,
    "weapon" : HIR "Ѫ������" NOR,
    "damage_type": "����"
]),
([  "action" : "$Nʩ��һ��" HIR "Ѫ��" NOR "֮��" HIR "Ѫ��˺��" NOR "�������"
               "��Ծ��˫צЯ�����֮���ó�����Ѫ��Ϯ����ֱ��$n$l",
    "dodge"  : 272,
    "attack" : 239,
    "parry"  : 254,
    "force"  : 424,
    "damage" : 353,
    "weapon" : HIR "Ѫ������" NOR,
    "damage_type": "����"
]),
([  "action" : "$Nվ��������һ�����ȣ�ʩ��" HIR "Ѫ��" NOR "֮��" HIR "����޻�"
               NOR "������ʱ����Ѫ�������������Ѫ����ʱ����$n������˷�",
    "dodge"  : 267,
    "attack" : 298,
    "parry"  : 254,
    "force"  : 484,
    "damage" : 339,
    "weapon" : HIR "Ѫ������" NOR,
    "damage_type": "����"
]),
([  "action" : "$Nʩչ" HIY "����" NOR "�ķ�֮��" HIY "������ѩ" NOR "����"
               "һȭ����$n���ţ���Ȼ��צ���ó�һ���������$n$l",
    "dodge"  : 329,
    "attack" : 251,
    "parry"  : 304,
    "force"  : 884,
    "damage" : 358,
    "weapon" : HIY "��������" NOR,
    "damage_type": "����"
]),
([  "action" : "$N��Ȼʹ��" HIY "����" NOR "֮��" HIY "ʮ����һ" NOR "����˫��"
               "����ʹ��������ǵصĹ���$n",
    "dodge"  : 321,
    "attack" : 393,
    "parry"  : 513,
    "force"  : 703,
    "damage" : 461,
    "weapon" : HIY "��������" NOR,
    "damage_type": "����"
]),
([  "action" : "$Nʩ��һ��" HIY "����" NOR "֮��" HIY "��������" NOR "����˫��"
               "��׶��Я�����ޱ��������ھ���Ȼ�����ֱ��$n��$l",
    "dodge"  : 312,
    "attack" : 398,
    "parry"  : 454,
    "force"  : 884,
    "damage" : 433,
    "weapon" : HIY "��������" NOR,
    "damage_type": "����"
]),
});

int valid_enable(string usage)
{
        return usage == "force" || usage == "unarmed" || usage == "parry";
}

int valid_force(string force) { return 1; }

int double_attack() { return 1; }

mapping query_action(object me)
{
        return action[random(sizeof(action))];
}

int valid_learn(object me)
{
        return notify_fail("%��������%������������*#��\n");
}

int practice_skill(object me)
{
        return notify_fail("%��������%������������*#��\n");
}

int difficult_level()
{
        return 9000;
}

string perform_action_file(string action)
{
        return __DIR__"huntian-baojian/perform/" + action;
}

string exert_function_file(string action)
{
        return __DIR__"huntian-baojian/exert/" + action;
}
