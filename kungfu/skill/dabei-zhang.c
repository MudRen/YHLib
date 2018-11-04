#include <ansi.h>
inherit SKILL;

mapping *action = ({
([      "action" : "$N���μ��Σ�ʩ�����ơ�" HIG "������" NOR "�������ƴ����й�֮������$n",
        "force" : 180,
        "attack": 23,
        "dodge" : 25,
        "parry" : 17,
        "damage": 19,
        "lvl"   : 0,
        "skill_name"  : "������",
        "damage_type" : "����"
]),
([      "action" : "$Nһ�С�" HIG "��Ԩ��" NOR "����˫��б������ǧ���ƺ���������˷�ϯ��$n",
        "force" : 240,
        "attack": 41,
        "dodge" : 25,
        "parry" : 27,
        "damage": 25,
        "lvl"   : 30,
        "skill_name"  : "��Ԩ��",
        "damage_type" : "����"
]),
([      "action" : "$Nƽ��Ϊ��ʩչ��" HIG "������" NOR "�����ó�һ�����͵��ƾ�쫷�����$n",
        "force" : 330,
        "attack": 58,
        "dodge" : 36,
        "parry" : 35,
        "damage": 39,
        "lvl"   : 60,
        "skill_name"  : "������",
        "damage_type" : "����"
]),
([      "action" : "$N��ת���ƶ�Ȼʩһ�С�" HIG "�����" NOR "������ע���ƣ�����$n������ȥ",
        "force" : 410,
        "attack": 96,
        "dodge" : 81,
        "parry" : 62,
        "damage": 53,
        "lvl"   : 90,
        "skill_name"  : "�����",
        "damage_type" : "����"
]),
([      "action" : "$N����һ�����ӳ�һ���ޱ��������ƾ�ֱն$n�����ǡ�" HIG "������" NOR "��",
        "force" : 460,
        "attack": 125,
        "dodge" : 35,
        "parry" : 47,
        "damage": 78,
        "lvl"   : 120,
        "skill_name"  : "������",
        "damage_type" : "����"
]),
([      "action" : "$Nʩ����" HIG "������" NOR "����˫��������һ����Ȧ��������Ȧ��ֱӿ$n",
        "force" : 520,
        "attack": 110,
        "dodge" : 45,
        "parry" : 40,
        "damage": 85,
        "lvl"   : 150,
        "skill_name"  : "������",
        "damage_type" : "����"
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

        if ((int)me->query_skill("force") < 240)
                return notify_fail("����ڹ���򲻹����޷���ϰ�����ơ�\n");

        if ((int)me->query("max_neili") < 2500)
                return notify_fail("�������̫�����޷���ϰ�����ơ�\n");

        if ((int)me->query_skill("strike", 1) < 180)
                return notify_fail("��Ļ����Ʒ���򲻹����޷���ϰ�����ơ�\n");

        if ((int)me->query_skill("strike", 1) < (int)me->query_skill("dabei-zhang", 1))
                return notify_fail("��Ļ����Ʒ�ˮƽ���ޣ��޷���������Ĵ����ơ�\n");

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
        return action[random(sizeof(action))];
}

int practice_skill(object me)
{
        if ((int)me->query("qi") < 100)
                return notify_fail("�������̫���ˡ�\n");

        if ((int)me->query("neili") < 100)
                return notify_fail("������������������ơ�\n");

        me->receive_damage("qi", 80);
        me->add("neili", -80);
        return 1;
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
        if (damage_bonus < 100)
                return 0;

        if (random(me->query_skill("force")) > victim->query_skill("force") / 2)
        {
                victim->receive_wound("qi", (damage_bonus - 100) / 2, me);
                return HIW "ֻ����������һ����$N" HIW "�Ʒ滮������ʱ��$n"
                       HIW "Ӳ��������������\n" NOR;
        }
}

string perform_action_file(string action)
{
        return __DIR__"dabei-zhang/" + action;
}
