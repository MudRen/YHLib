#include <ansi.h>;
inherit SKILL;

mapping *action = ({
([      "action" : "$N���ֵ�������$w��һ�С���ɽ�������������������$n$l��ȥ",
        "skill_name" : "��ɽ",
        "force" : 320,
        "attack": 27,
        "dodge" : -30,
        "parry" : -34,
        "lvl"   : 0,
        "damage": 62,
        "damage_type" : "����",
]),
([      "action" : "$N������$w����һ���뻡��һʽ����������������׹�أ�ֱ��$n",
        "skill_name" : "����",
        "force" : 460,
        "attack": 38,
        "dodge" : -27,
        "parry" : -45,
        "lvl"   : 40,
        "damage": 66,
        "damage_type" : "����",
]),
([      "action" : "ͻȻ��$N����$wЮ�����Ͼ�����һ�С����졹ʩ�����ɿ���$n��ȥ",
        "skill_name" : "����",
        "force" : 500,
        "attack": 43,
        "dodge" : -25,
        "parry" : -47,
        "lvl"   : 80,
        "damage": 70,
        "damage_type" : "����",
]),
([      "action" : "$N��Ŀ��ȣ�ʩһ�С��ֺ�����$w�ھ����ƶ�֮�£���$n����ѹ��",
        "skill_name" : "�ֺ�",
        "force" : 540,
        "attack": 51,
        "dodge" : -45,
        "parry" : -50,
        "lvl"   : 120,
        "damage": 75,
        "damage_type" : "����",
]),
([      "action" : "$N����$w�����ơ����项�ľ�������ͬ��ɽ�����㳯$n��������",
        "skill_name" : "����",
        "force" : 580,
        "attack": 55,
        "dodge" : -20,
        "parry" : -25,
        "lvl"   : 160,
        "damage": 80,
        "damage_type" : "����",
]),
([      "action" : "$N�߾�$w�����ơ����ġ��ľ�������ͬ��ɽ�����㳯$n��������",
        "skill_name" : "����",
        "force" : 620,
        "attack": 65,
        "dodge" : -40,
        "parry" : -35,
        "lvl"   : 180,
        "damage": 98,
        "damage_type" : "����",
]),
([      "action" : "$N��ת$w�����ơ��˼����ľ�������ͬ��ɽ�����㳯$n��������",
        "skill_name" : "�˼�",
        "force" : 640,
        "attack": 69,
        "dodge" : -62,
        "parry" : -33,
        "lvl"   : 200,
        "damage": 104,
        "damage_type" : "����",
]),
});


int valid_enable(string usage) { return usage == "hammer" || usage == "parry"; }

int valid_learn(object me)
{
        if (me->query("str") < 32)
                return notify_fail("������������������޷������̹����ơ�\n");

        if ((int)me->query("max_neili") < 2000)
                return notify_fail("���������Ϊ̫ǳ���޷������̹����ơ�\n");

        if ((int)me->query_skill("force") < 180)
                return notify_fail("����ڹ����̫ǳ���޷������̹����ơ�\n");

        if ((int)me->query_skill("hammer", 1) < 80)
                return notify_fail("��Ļ����������̫ǳ���޷������̹����ơ�\n");

        if ((int)me->query_skill("hammer", 1) < (int)me->query_skill("pangu-qishi", 1))
                return notify_fail("��Ļ�������ˮƽ���ޣ��޷�����������̹����ơ�\n");

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
        level = (int) me->query_skill("pangu-qishi",1);
        for (i = sizeof(action); i > 0; i--)
                if (level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level / 5)];
}

int practice_skill(object me)
{
        object weapon;

        if (! objectp(weapon = me->query_temp("weapon")) ||
            (string)weapon->query("skill_type") != "hammer")
                return notify_fail("��ʹ�õ��������ԡ�\n");

        if ((int)me->query("qi") < 100)
                return notify_fail("��������������������̹����ơ�\n");

        if ((int)me->query("neili") < 100)
                return notify_fail("��������������������̹����ơ�\n");

        me->receive_damage("qi", 90);
        me->add("neili", -90);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"pangu-qishi/" + action;
}
