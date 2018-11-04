#include <ansi.h>
inherit SKILL;

string *xue_name = ({ 
"�͹�Ѩ", "����Ѩ", "����Ѩ", "��ԪѨ", "����Ѩ", "�м�Ѩ", "�н�Ѩ", "��ͻѨ", "�ٻ�Ѩ",
"����Ѩ", "����Ѩ", "���Ѩ", "�Ϲ�Ѩ", "��ԨѨ", "�쾮Ѩ", "��ȪѨ", "����Ѩ", "����Ѩ", });

mapping *action_finger = ({
([      "action" : "$N��ָ���˸���Ȧ��һʽ�������ѵء����϶��»���$n��ȫ��",
        "force" : 440,
        "attack": 100,
        "parry" : 50,
        "dodge" : 75,
        "damage": 131,
        "skill_name" : "�����ѵ�",
        "damage_type" : "����"
]),
([      "action" : "$N���ƻ��أ�һ�С��������ơ�����ָ��������ָ��$n�Ķ�ͷ",
        "force" : 410,
        "attack": 90,
        "parry" : 65,
        "dodge" : 90,
        "damage": 103,
        "skill_name" : "��������",
        "damage_type" : "����"
]),
([      "action" : "$N˫�������һʽ��ǧ����ָ������ʱһ��������$n��$l��",
        "force" : 420,
        "attack": 110,
        "parry" : 65,
        "dodge" : 85,
        "damage": 121,
        "skill_name" : "ǧ����ָ",
        "damage_type" : "����"
]),
([      "action" : "$N����һ̾��һ�С���ָ��������˫�ֻó�����ָӰ������$n��$l",
        "force" : 400,
        "attack": 100,
        "parry" : 70,
        "dodge" : 95,
        "damage": 98,
        "skill_name" : "��ָ����",
        "damage_type" : "����"
]),
([      "action" : "$Nһʽ��Цָ���ϡ���������ʽ����ָ����һ��ָ�����$n��$l",
        "force" : 430,
        "attack": 95,
        "parry" : 45,
        "dodge" : 100,
        "damage": 105,
        "skill_name" : "Цָ����",
        "damage_type" : "����"
]),
([      "action" : "$Nʩչ��һ�С�����һָ�����ȫ��������һָ����$n��$l",
        "force" : 450,
        "attack": 105,
        "parry" : 65,
        "dodge" : 90,
        "damage": 130,
        "skill_name" : "����һָ",
        "damage_type" : "����"
]),
});

int valid_enable(string usage)
{
        return usage == "finger" ||
               usage == "parry" ||
               usage == "throwing";
}

int valid_learn(object me)
{
        if ((int)me->query("dex") < 34)
                return notify_fail("������������㣬�޷�������ָ��ͨ��\n");

        if ((int)me->query_skill("force", 1) < 150)
                return notify_fail("����ڹ���򲻹����޷�������ָ��ͨ��\n");

        if ((int)me->query("max_neili") < 2000)
                return notify_fail("���������Ϊ̫�����޷�������ָ��ͨ��\n");

        if ((int)me->query_skill("finger", 1) < 150)
                return notify_fail("��Ļ���ָ����򲻹����޷�ѧ��ָ��ͨ��\n");

        if ((int)me->query_skill("finger", 1) < (int)me->query_skill("tanzhi-shentong", 1))
                return notify_fail("��Ļ���ָ��ˮƽ���ޣ��޷���������ĵ�ָ��ͨ��\n");

        return 1;
}

string query_skill_name(int level)
{
        return action_finger[random(sizeof(action_finger))]["skill_name"];
}

mapping query_action(object me, object weapon)
{
        return action_finger[random(sizeof(action_finger))];
}

int practice_skill(object me)
{
        if ((int)me->query("qi") < 80)
                return notify_fail("���������������Ϣһ�������ɡ�\n");

        if ((int)me->query("neili") < 80)
                return notify_fail("���������������ָ��ͨ��\n");

        me->receive_damage("qi", 68);
        me->add("neili", -67);
        return 1;
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
        string name, weapon;
        name = xue_name[random(sizeof(xue_name))];

        if (damage_bonus < 150
           || me->query("neili") < 800
	   || me->query_skill("tanzhi-shentong", 1) < 100
	   || me->query_skill("jingluo-xue", 1) < 100
           || victim->is_busy())
                return 0;

        victim->start_busy(2);
        victim->receive_wound("qi", (damage_bonus - 100) / 4, me);

        if (victim->query("neili") <= (damage_bonus / 4 + 50))
                victim->set("neili", 0);
        else
                victim->add("neili", -damage_bonus / 4);

        return HIR "ֻ����쬡���һ����$n" HIR "��$N" HIR "��յ������ָ������" NOR +
               HIY + name + NOR + HIR "��ȫ���ʱһ�����顣\n" NOR;
}

string perform_action_file(string action)
{
        return __DIR__"tanzhi-shentong/" + action;
}
