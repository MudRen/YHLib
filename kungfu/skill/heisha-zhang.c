#include <ansi.h>
inherit SKILL;

mapping *action = ({
([      "action" : "$N��ǰһ����˫�ƶ�Ȼ����������˿˿�������$n��$l",
        "force" : 100,
        "attack": 25,
        "dodge" : 15,
        "parry" : 20,
        "damage": 10,
        "damage_type" : "����"
]),
([      "action" : "$N���ƻ��أ��������Ĵ��ż���֮������$n��$l",
        "force" : 130,
        "attack": 30,
        "dodge" : 10,
        "parry" : 15,
        "damage": 20,
        "damage_type" : "����"
]),
([      "action" : "$N˫���ĳ��������磬��Ȼ����������Ϣ������$n��$l",
        "force" : 180,
        "attack": 50,
        "dodge" : 20,
        "parry" : 30,
        "damage": 30,
        "damage_type" : "����"
]),
([      "action" : "$N�ֽ�һ��������һԾ�����ƿ�����������$n��$l",
        "force" : 210,
        "attack": 65,
        "dodge" : 25,
        "parry" : 20,
        "damage": 35,
        "damage_type" : "����"
]),
([      "action" : "$N��Цһ����˫��һ�����ƺ�Ȼ�������߻���$n��$l",
        "force" : 210,
        "attack": 65,
        "dodge" : 25,
        "parry" : 20,
        "damage": 35,
        "damage_type" : "����"
]),
([      "action" : "$N���μ��Σ�һԾ����$n��ǰ�����ƴ��ų��캮������$n��$l",
        "force" : 210,
        "attack": 65,
        "dodge" : 25,
        "parry" : 20,
        "damage": 35,
        "damage_type" : "����"
]),
([      "action" : "$N���쳤Х��˫���Ʒ���ǧ�Ų����ĺ���������$n��$l",
        "force" : 210,
        "attack": 65,
        "dodge" : 25,
        "parry" : 20,
        "damage": 35,
        "damage_type" : "����"
]),
([      "action" : "$N����Ȼһ�䣬��Ӱǧ����ã���$n�޷�����",
        "force" : 250,
        "attack": 45,
        "dodge" : 15,
        "parry" : 20,
        "damage": 25,
        "damage_type" : "����"
]),
([      "action" : "$N����һ����Х��˫��Я������ű���ֱֱ����$n",
        "force" : 330,
        "attack": 35,
        "dodge" : 25,
        "parry" : 20,
        "damage": 15,
        "damage_type" : "����"
])
});

int valid_enable(string usage) { return usage == "strike" || usage == "parry"; }

int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("����ɰ�Ʊ�����֡�\n");

        if ((int)me->query_skill("force") < 30)
                return notify_fail("����ڹ���򲻹����޷���ϰ��ɰ�ơ�\n");

        if ((int)me->query("max_neili") < 500)
                return notify_fail("�������̫�����޷���ϰ��ɰ�ơ�\n");

        if ((int)me->query_skill("strike", 1) < (int)me->query_skill("heisha-zhang", 1))
                return notify_fail("��Ļ����Ʒ�ˮƽ���ޣ��޷���������ĺ�ɰ�ơ�\n");

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
        level   = (int) me->query_skill("heisha-zhang",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        if ((int)me->query("qi") < 50)
                return notify_fail("�������̫���ˡ�\n");

        if ((int)me->query("neili") < 70)
                return notify_fail("���������������ɰ�ơ�\n");

        me->receive_damage("qi", 40);
        me->add("neili", -60);
        return 1;
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
        int lvl;
        int flvl;

        lvl  = me->query_skill("heisha-zhang", 1);
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
        return __DIR__"heisha-zhang/" + action;
}
