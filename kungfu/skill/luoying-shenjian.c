#include <ansi.h>

inherit SKILL;

mapping *action = ({
([      "action" : "$Nʹһ�С���Ӣ�ͷס�����������Ʈ������$w�ó���㽣������$n",
        "force"  : 100,
        "parry"  : 15,
        "damage" : 40,
        "lvl"    : 0,
        "skill_name"  : "��Ӣ�ͷ�",
        "damage_type" : "����"
]),
([      "action" : "$Nһʽ�������һ�����������$n����һ�Σ�����$w�������佣������$n",
        "force"  : 150,
        "parry"  : 20,
        "damage" : 50,
        "lvl"    : 20,
        "skill_name"  : "�����һ�",
        "damage_type" : "����"
]),
([      "action" : "$N����һת������$w����һָ��һʽ���������꡹�ó����콣Ӱ����$n$l",
        "force"  : 180,
        "dodge"  : 20,
        "damage" : 60,
        "lvl"    : 40,
        "skill_name"  : "��������",
        "damage_type" : "����"
]),
([      "action" : "$N����ƮȻ������Ȼһʽ�����Ƿɻ���������$w�������޴���$n��$l",
        "force"  : 210,
        "dodge"  : 30,
        "damage" : 70,
        "lvl"    : 60,
        "skill_name"  : "���Ƿɻ�",
        "damage_type" : "����"
]),
([      "action" : "$N�������࣬һ�С������䡹����$w���һ����������$n��$l",
        "force"  : 250,
        "dodge"  : 35,
        "damage" : 80,
        "lvl"    : 80,
        "skill_name"  : "������",
        "damage_type" : "����"
]),
([      "action" : "$Nһ�����ʹ�������컨�꡹������$w�ó����컨�꣬Ѹ����������$n��$l",
        "force"  : 280,
        "dodge"  : 35,
        "damage" : 90,
        "lvl"    : 100,
        "skill_name"  : "���컨��",
        "damage_type" : "����"
]),
([      "action" : "$N��̾һ��������$w����һ����һʽ���仨���⡹��$w��ʱƮȻ����$n��$l",
        "force"  : 300,
        "dodge"  : 30,
        "damage" : 110,
        "lvl"    : 120,
        "skill_name": "�仨����",
        "damage_type": "����"
]),
});

int valid_enable(string usage)
{
        return usage == "sword" || usage == "parry";
}

int valid_learn(object me)
{
        object ob;

        if (! objectp(ob = me->query_temp("weapon"))
           || (string)ob->query("skill_type") != "sword")
                return notify_fail("���������һ�ѽ�����ѧϰ������\n");

        if ((int)me->query_skill("force") < 30)
                return notify_fail("����ڹ���򲻹�����������Ӣ�񽣡�\n");

        if ((int)me->query("max_neili") < 250)
                return notify_fail("���������Ϊ��������������Ӣ�񽣡�\n");

        if ((int)me->query_skill("sword", 1) < (int)me->query_skill("luoying-shenjian", 1))
                return notify_fail("��Ļ�������ˮƽ���ޣ��޷������������Ӣ�񽣡�\n");

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
        int i, level;

        level = (int)me->query_skill("luoying-shenjian", 1);
        for (i = sizeof(action); i > 0; i--)
                if (level > action[i - 1]["lvl"])
                        return action[NewRandom(i, 20, level / 5)];
}

int practice_skill(object me)
{
        object ob;

        if ((int)me->query("qi") < 50)
                return notify_fail("�������̫�ͣ�û�а취��ϰ��Ӣ�񽣡�\n");

        if ((int)me->query("neili") < 35)
                return notify_fail("�������������û�а취��ϰ��Ӣ�񽣡�\n");

        if (! objectp(ob = me->query_temp("weapon"))
           || (string)ob->query("skill_type") != "sword")
                return notify_fail("���������һ�ѽ�����ϰ��������\n");

        me->receive_damage("qi", 45);
        me->add("neili", -41);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"luoying-shenjian/" + action;
}

