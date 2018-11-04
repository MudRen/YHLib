// jiuqu-zhegufa.c �����۹Ƿ�
// Edit By Vin On 22/2/2001

#include <ansi.h>

inherit SKILL;

mapping *action = ({
([      "action": "$Nһ����ߣ����ƻ�צ����ָ�繳��ֱ��$n������ҪѨ",
        "force" : 130,
        "attack": 65,
        "dodge" : 5,
        "damage": 85,
        "parry" : 40,
        "lvl"   : 0,
        "damage_type" : "����"
]),
([      "action": "$N������Σ���������ֱ��������$n�ļ羮��Ѩ",
        "force" : 160,
        "attack": 72,
        "dodge" : 10,
        "damage": 92,
        "parry" : 42,
        "lvl"   : 30,
        "damage_type" : "����"
]),
([      "action": "$Nһ������ָ��������ò�ʩ������$n����·Ҫ��",
        "force" : 180,
        "attack": 81,
        "dodge" : 15,
        "parry" : 45,
        "damage": 130,
        "lvl"   : 60,
        "damage_type" : "����"
]),
([      "action": "$N����ӥץ�������߾٣�����΢΢�ζ���˫�ּ���$n���нڴ���",
        "force" : 230,
        "attack": 85,
        "dodge" : 20,
        "parry" : 46,
        "damage": 140,
        "lvl"   : 90,
        "damage_type" : "����"
]),
([      "action": "$N��ǰһ��������˷�����������Ӱ��һצͻ����ץ��$n���ؿ�",
        "force" : 240,
        "attack": 93,
        "dodge" : 25,
        "parry" : 54,
        "damage": 150,
        "lvl" : 120,
        "damage_type" : "����"
]),
([      "action": "$N���һ�������ֻ��ۣ�ȫ��ؽ�žž���죬����$n��$l",
        "force" : 270,
        "attack": 98,
        "dodge" : 30,
        "parry" : 58,
        "damage": 160,
        "lvl" : 150,
        "damage_type" : "����"
]),
([      "action": "$N����һչ��ʮָ���죬������հ������$n��ȫ��ҪѨ",
        "force" : 330,
        "attack": 101,
        "dodge" : 35,
        "parry" : 62,
        "damage": 170,
        "lvl" : 180,
        "damage_type" : "����"
]),
([      "action": "$N�������ţ���һ�������У�˫��ͬʱ����$n��ȫ�����",
        "force" : 380,
        "attack": 127,
        "dodge" : 50,
        "parry" : 65,
        "damage": 180,
        "lvl" : 210,
        "damage_type" : "����"
])
});

int valid_enable(string usage)
{
        return usage == "hand" || usage == "parry";
}

int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("�������۹Ƿ�������֡�\n");

        if ((int)me->query_skill("force") < 200)
                return notify_fail("����ڹ���򲻹����޷�ѧ�����۹Ƿ���\n");

        if ((int)me->query("max_neili") < 2800)
                return notify_fail("�������̫�����޷��������۹Ƿ���\n");

        if ((int)me->query_skill("hand", 1) < 180)
                return notify_fail("��Ļ����ַ���򲻹����޷�ѧ�����۹Ƿ���\n");

        if ((int)me->query_skill("hand", 1) < (int)me->query_skill("jiuqu-zhegufa", 1))
                return notify_fail("��Ļ����ַ�ˮƽ���ޣ��޷���������ľ����۹Ƿ���\n");

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
        level = (int) me->query_skill("jiuqu-zhegufa",1);
        for (i = sizeof(action); i > 0; i--)
                if (level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        if (me->query_temp("weapon") ||
            me->query_temp("secondary_weapon"))
                return notify_fail("�����۹Ƿ����������ϰ��\n");

        if ((int)me->query("qi") < 120)
                return notify_fail("�������̫���ˡ�\n");

        if ((int)me->query("neili") < 120)
                return notify_fail("������������������۹Ƿ���\n");

        me->receive_damage("qi", 100);
        me->add("neili", -100);
        return 1;
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
        string *limbs;
        string  limb;

        if (damage_bonus < 200) return 0;

        if (damage_bonus / 5 > victim->query_dex())
        {
                if (arrayp(limbs = victim->query("limbs")))
                        limb = limbs[random(sizeof(limbs))];
                else
                        limb = "����";

                victim->receive_wound("qi", (damage_bonus - 200) / 2);
                return HIR "$n" HIR "��һ���ɣ�ֻ��$N" HIR "���������Լ�" + limb +
                       "�ϣ�ֻ�������꡹һ�����죬�˴�������ʱӦ�����飡\n" NOR;
        }
}

string perform_action_file(string action)
{
        return __DIR__"jiuqu-zhegufa/" + action;
}
