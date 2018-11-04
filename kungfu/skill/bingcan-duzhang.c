// bingcan-duzhang.c  ���϶���

#include <ansi.h>

inherit SKILL;

mapping *action = ({
([      "action": "$N����¶�������Ц�ݣ�˫��Я����˪����ɨ$n",
        "dodge" : -30,
        "attack": 79,
        "parry" : -37,
        "dmage" : 52,
        "force" : 430,
        "damage_type": "����"
]),
([      "action": "$NͻȻ������ת��������$n��˫�Ʒ���������$n��$l",
        "dodge" : -22,
        "attack": 96,
        "parry" : -34,
        "dmage" : 67,
        "force" : 490,
        "damage_type": "����"
]),
([      "action": "$N�����Ϻ����������֣������ޱȵ�����$n��$l",
        "dodge" : -20,
        "attack": 113,
        "parry" : 10,
        "dmage" : 82,
        "force" : 530,
        "damage_type": "����"
]),
([      "action": "$N�����һЦ��˫�ƴ��������ĺ�������$n��$l",
        "dodge" : 28,
        "attack": 139,
        "parry" : 36,
        "dmage" : 95,
        "force" : 580,
        "damage_type": "����"
]),
([      "action": "$N����һ����Х���ۼ�ȫ�����������$n",
        "dodge" : 27,
        "attack": 161,
        "parry" : 21,
        "dmage" : 105,
        "force" : 640,
        "damage_type": "����"
]),
});

int valid_enable(string usage) { return usage=="strike" || usage=="parry"; }   

int valid_learn(object me)
{
        if ((int)me->query_skill("yijinjing", 1) < 0)
                return notify_fail("�����޵��ڹ��޷������϶��ơ�\n");

        if ((int)me->query_skill("force") < 200)
                return notify_fail("����ڹ���򲻹����޷������϶��ơ�\n");

        if ((int)me->query("max_neili") < 3000)
                return notify_fail("�������̫�����޷������϶��ơ�");

        if ((int)me->query_skill("strike", 1) < (int)me->query_skill("bingcan-duzhang", 1))
                return notify_fail("��Ļ����Ʒ�ˮƽ���ޣ��޷���������ı��϶��ơ�\n");

        if ((int)me->query_skill("yijinjing", 1) < (int)me->query_skill("bingcan-duzhang", 1))
                return notify_fail("����׽��ˮƽ���ޣ��޷���������ı��϶��ơ�\n");

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
        level   = (int) me->query_skill("bingcan-duzhang", 1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        if ((int)me->query("qi") < 40)
                return notify_fail("�������̫���ˡ�\n");

        if ((int)me->query("neili") < 30)
                return notify_fail("����������������϶��ơ�\n");

        if (me->query_skill("bingcan-duzhang", 1) < 50)
                me->receive_damage("qi", 100);
        else
                me->receive_damage("qi", 150);

        me->add("neili", -180);
        return 1;
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
        int lvl;
        int flvl;

        lvl  = me->query_skill("bingcan-duzhang", 1);
        flvl = me->query("jiali");
        if (lvl < 80 || flvl < 10 || ! damage_bonus)
                return;

        if (flvl * 2 + random(lvl) > victim->query_skill("force") &&
            victim->affect_by("bingcan_duzhang",
                              ([ "level" : flvl + random(flvl),
                                 "id"    : me->query("id"),
                                 "duration" : lvl / 100 + random(lvl / 10) ])))
        {
                return HIW "$n" HIW "ֻ��һ�󼫺����ĵ����𣬿���������$N" HIW "���ϵı��Ϻ�����\n" NOR;
        }
}

string perform_action_file(string action)
{
    return __DIR__"bingcan-duzhang/" + action;
}

