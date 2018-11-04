//kuangfeng-jian ���콣

#include <ansi.h>

inherit SKILL;

mapping *action = ({
([      "action" : "$N����Ծ������$w��ӣ�ն��$n��",
        "force"  : 160,
        "attack" : 35,
        "parry"  : 40,
        "dodge"  : 80,
        "damage" : 125,
        "lvl"    : 0,
        "skill_name" : "��ƽ�˾�",
        "damage_type" : "����"
]),
([      "action" : "$N����$w�����������Σ���$n���ұ����ն��",
        "force"  : 180,
        "attack" : 55,
        "parry"  : 52,
        "dodge"  : 95,
        "damage" : 148,
        "lvl"    : 30,
        "skill_name" : "������ӿ",
        "damage_type" : "����"
]),
([      "action" : "$N����һ����ˢˢˢˢ�Ľ�����$n�أ������������Ĵ�����",
        "force"  : 220,
        "attack" : 81,
        "parry"  : 18,
        "dodge"  : 123,
        "damage" : 195,
        "lvl"    : 60,
        "skill_name" : "������",
        "damage_type" : "����"
]),
([      "action" : "$N����һ����Х��б����ǰ��$w����ֱ����Ѹ���ޱȣ�����$n��$l",
        "force"  : 280,
        "attack" : 108,
        "parry"  : 20,
        "dodge"  : 152,
        "damage" : 230,
        "lvl"    : 90,
        "skill_name" : "������ɢ",
        "damage_type" : "����"
]),
});

int valid_enable(string usage) { return usage == "sword" || usage == "parry"; } 

int valid_learn(object me)
{
        if ((int)me->query("max_neili") < 200)
                return notify_fail("���������Ϊ�������޷���ϰ���콣��\n");

        if ((int)me->query_skill("dodge", 1) < 90)
                return notify_fail("��Ļ����Ṧ���̫ǳ���޷���ϰ���콣��\n");

        if ((int)me->query_dex() < 28)
                return notify_fail("��������������޷���ϰ���콣��\n");

        if ((int)me->query_skill("sword", 1) < (int)me->query_skill("kuangfeng-jian", 1))
	        return notify_fail("��Ļ�������ˮƽ���ޣ��޷���������Ŀ��콣��\n");

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

        level = (int) me->query_skill("kuangfeng-jian",1);
        for (i = sizeof(action); i > 0; i--)
    	        if (level > action[i - 1]["lvl"])
                        return action[NewRandom(i, 20, level / 5)];
}

int practice_skill(object me)
{
        object weapon;

        if (! objectp(weapon = me->query_temp("weapon")) ||
            (string)weapon->query("skill_type") != "sword")
                return notify_fail("��ʹ�õ��������ԡ�\n");

        if ((int)me->query("qi") < 65)
                return notify_fail("����������������콣��\n");

        if ((int)me->query("neili") < 40)
                return notify_fail("����������������콣��\n");

        me->receive_damage("qi", 60);
        me->add("neili", -36);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"kuangfeng-jian/" + action;
}
