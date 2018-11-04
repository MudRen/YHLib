// dusha-zhang.c ��ɰ�� ҩ����
// Edit By Vin On 26/2/2001

#include <ansi.h>

inherit SKILL;

mapping *action = ({
([      "action": "$N˫�ֲ�ס�غ���������ֱ۹ؽڿ������죬����һ��������ž��һ�³�$n$l��ȥ",
        "force" : 80,
        "attack": 28,
        "dodge" : 10,
        "parry" : 5,
        "damage": 60,
        "lvl"   : 0,
        "damage_type": "����"
]),
([      "action": "$N���δ춯���������������ų�$n�������ƣ�һ�ƿ���һ�ƣ�һ������һ��",
        "force" : 130,
        "attack": 35,
        "dodge" : 10,
        "parry" : 10,
        "damage": 67,
        "lvl"   : 30,
        "damage_type": "����"
]),
([      "action": "$N���ر�צΪ�ƣ����Ӳ������ұ۶�����Ǳ��������һ�Ƴ�$n$l��ȥ",
        "force" : 170,
        "attack": 37,
        "dodge" : 20,
        "parry" : 25,
        "damage": 65,
        "lvl"   : 60,
        "damage_type": "����"
]),
([      "action": "$Nһ����Х������Ʈ�磬����������е�ֿ������$n����δ������������Ѹ���Ѽ�",
        "force" : 220,
        "attack": 42,
        "dodge" : 30,
        "parry" : 35,
        "damage": 73,
        "lvl"   : 90,
        "damage_type": "����"
]),
});

int valid_enable(string usage) { return usage == "strike" || usage == "parry"; }

int valid_combine(string combo) { return combo=="lansha-shou"; }

mapping query_action(object me, object weapon)
{
        int i, level;
        level = (int)me->query_skill("dusha-zhang", 1);
        for (i = sizeof(action); i > 0; i--)
                if (level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level / 5)];
}

int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("����ɰ�Ʊ�����֡�\n");

        if ((int)me->query_skill("force") < 100)
                return notify_fail("����ڹ���򲻹����޷�����ɰ�ơ�\n");

        if ((int)me->query("max_neili") < 450)
                return notify_fail("�������̫�����޷�����ɰ�ơ�\n");

        if (me->query_skill("strike", 1) < me->query_skill("dusha-zhang", 1))
                return notify_fail("��Ļ����Ʒ�ˮƽ���ޣ��޷���������Ķ�ɰ�ơ�\n");

        return 1;
}

int practice_skill(object me)
{
        if ((int)me->query("qi") < 60)
                return notify_fail("�������̫���ˣ�����Ϣһ�°ɡ�\n");

        if ((int)me->query("neili") < 70)
                return notify_fail("���������������ɰ�ơ�\n");

        if (me->query_skill("dusha-zhang", 1) < 50)
                me->receive_damage("qi", 30);
        else
                me->receive_damage("qi", 40);

        me->add("neili", -60);
        return 1;
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
        int lvl;
        int flvl;

        lvl  = me->query_skill("dusha-zhang", 1);
        flvl = me->query("jiali");
        if (lvl < 80 || flvl < 10 || ! damage_bonus)
                return;

        if (flvl * 2 + random(lvl) > victim->query_skill("force") &&
           victim->affect_by("sha_poison",
                ([ "level" : flvl + random(flvl),
                   "id"    : me->query("id"),
                   "duration" : lvl / 50 + random(lvl / 20) ])))
        {
                return WHT "$n" WHT "��Ȼ�е�һ��Ī���Ķ��ģ�ȫ��̱����Ƥ���ϡ�\n" NOR;
        }
}

string perform_action_file(string action)
{
        return __DIR__"dusha-zhang/" + action;
}

