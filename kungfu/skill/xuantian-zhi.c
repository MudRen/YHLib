// xuantian-zhi.c - ����ָ

#include <ansi.h>
inherit SKILL;

mapping *action = ({
([      "action" : "$N��ָ�ӳ���һʽ���������ߡ���ָ��Я������֮������$n����Ե",
        "force" : 100,
        "attack": 10,
        "parry" : 15,
        "dodge" : -5,
        "lvl"   : 0,
        "skill_name" : "��������",
        "damage_type" : "����"
]),
([      "action" : "$Nȫ��֮������ָ����ʱָ��������һ�㺮˪��һʽ��ǧ����⡹ָ��$n����ǰ",
        "force" : 140,
        "attack": 15,
        "parry" : 18,
        "dodge" : -5,
        "lvl"   : 20,
        "skill_name" : "ǧ�����",
        "damage_type" : "����"
]),
([      "action" : "$N�����������Ѩ������һʽ������ѩƮ����ָ��Я������֮����$n��$l����",
        "force" : 170,
        "attack": 20,
        "parry" : 25,
        "dodge" : 5,
        "lvl"   : 40,
        "skill_name" : "����ѩƮ",
        "damage_type" : "����"
]),
([      "action" : "$N˫Ŀŭ�ӣ�һʽ�����պ�������˫ָЯ������֮������$n����ҪѨ",
        "force" : 210,
        "attack": 28,
        "parry" : 30,
        "dodge" : 5,
        "damage": 10,
        "lvl"   : 60,
        "skill_name" : "���պ���",
        "damage_type" : "����"
]),
([      "action" : "$N���������ʮָ�濪��һʽ�����Ӷ��������������������֮��������$n",
        "force" : 250,
        "attack": 30,
        "parry" : 35,
        "dodge" : 15,
        "damage": 10,
        "lvl"   : 80,
        "skill_name" : "���Ӷ���",
        "damage_type" : "����"
]),
([      "action" : "$N˫ָ�ų�����������֮���ľ�����һʽ������ѩ�衹����$n��ȫ��",
        "force" : 280,
        "attack": 45,
        "parry" : 40,
        "dodge" : 20,
        "damage": 15,
        "lvl"   : 100,
        "skill_name" : "����ѩ��",
        "damage_type" : "����"
]),
([      "action": "$N˫�Ʒ��ɣ�һʽ��������������ָ�˱ų���������������������$n��ȫ��",
        "force" : 310,
        "attack": 50,
        "parry" : 48,
        "dodge" : 25,
        "damage": 20,
        "lvl"   : 130,
        "skill_name" : "��������",
        "damage_type" : "����"
]),
([      "action": "$Nһʽ�����ر�ԭ������ָ���У�һ����������ٱ�ĺ�����������$n��$l��ȥ",
        "force" : 370,
        "attack": 60,
        "parry" : 55,
        "dodge" : 30,
        "damage": 30,
        "lvl"   : 160,
        "skill_name" : "���ر�ԭ",
        "damage_type" : "����"
]),
([      "action": "$Nһʽ���캮�ض�����˫��ʳָ���棬ָ�����һ�ƺ���������$n��$l",
        "force" : 400,
        "attack": 68,
        "parry" : 60,
        "dodge" : 35,
        "damage": 40,
        "lvl"   : 190,
        "skill_name" : "�캮�ض�",
        "damage_type" : "����"
]),
([      "action": "$N����������ǰ��һʽ����ż����������ʳָ��סĴָ���������$nһ��",
        "force" : 440,
        "attack": 75,
        "parry" : 66,
        "dodge" : 50,
        "damage": 10,
        "lvl"   : 220,
        "skill_name" : "��ż��",
        "damage_type" : "����"
])
});

int valid_enable(string usage) { return usage == "finger" || usage == "parry"; }

int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("������ָ������֡�\n");

        if ((int)me->query_skill("force") < 100)
                return notify_fail("����ڹ���򲻹����޷�ѧ����ָ��\n");

        if ((int)me->query("max_neili") < 1500)
                return notify_fail("�������̫�����޷�������ָ��\n");

        if ((int)me->query_skill("finger", 1) < 80)
                return notify_fail("��Ļ���ָ����򲻹����޷�������ָ��\n");

        if ((int)me->query_skill("finger", 1) < (int)me->query_skill("xuantian-zhi", 1))
                return notify_fail("��Ļ���ָ��ˮƽ���ޣ��޷��������������ָ��\n");

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
        level = (int) me->query_skill("xuantian-zhi",1);
        for (i = sizeof(action); i > 0; i--)
                if (level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        if (me->query_temp("weapon") ||
            me->query_temp("secondary_weapon"))
                return notify_fail("����������ϰ��\n");

        if ((int)me->query("qi") < 70)
                return notify_fail("�������̫���ˡ�\n");

        if ((int)me->query("neili") < 80)
                return notify_fail("�����������������ָ��\n");

        me->receive_damage("qi", 60);
        me->add("neili", -70);
        return 1;
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
        int lvl;
        int flvl;

        lvl  = me->query_skill("xuantian-zhi", 1);
        flvl = me->query("jiali");
        if (lvl < 100 || flvl < 20 || ! damage_bonus)
                return;

        if (flvl * 2 + random(lvl) > victim->query_skill("force") &&
            victim->affect_by("xuantian_zhi",
                              ([ "level" : flvl + random(flvl),
                                 "id"    : me->query("id"),
                                 "duration" : lvl / 50 + random(lvl / 20) ])))
        {
                return HIW "$n" HIW "ֻ�о�����֮�����ģ�ȫ��̱����Ƥ���ϣ����Ӿ�������һ�㺮˪��\n" NOR;
        }
}

string perform_action_file(string action)
{
        return __DIR__"xuantian-zhi/" + action;
}
