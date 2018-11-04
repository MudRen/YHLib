#include <ansi.h>;
inherit SKILL;

mapping *action = ({
([      "action" : "$Nһ�С������Ϧ�����������ƶ��������ֵ�������$w�����������������$n$l��ȥ",
        "skill_name" : "�����Ϧ",
        "force" : 320,
        "attack": 27,
        "dodge" : -10,
        "parry" : 40,
        "lvl"   : 0,
        "damage": 62,
        "damage_type" : "����",
]),
([      "action" : "$N������$w���ϰ�գ�Ծ��һ������$w�ϣ���ʽ���紵��ɢ����������׹�أ�ֱ��$n",
        "skill_name" : "�紵��ɢ",
        "force" : 260,
        "attack": 38,
        "dodge" : -20,
        "parry" : 45,
        "lvl"   : 40,
        "damage": 66,
        "damage_type" : "����",
]),
([      "action" : "ƾ������һ��ѩ�׵Ĺ�Ļ�������˸��$wЮ�����꽻�ӡ������Ͼ�������$N���зɳ�����$n��$l",
        "skill_name" : "���꽻��",
        "force" : 300,
        "attack": 43,
        "dodge" : -20,
        "parry" : 47,
        "lvl"   : 80,
        "damage": 70,
        "damage_type" : "����",
]),
([      "action" : "$N˫�ۿıգ�ȫ������ȴ���ھ����������������$w���⡸�˷���ӿ�����ƶ��£���$n����ѹ��",
        "skill_name" : "�˷���ӿ",
        "force" : 340,
        "attack": 51,
        "dodge" : 5,
        "parry" : 50,
        "lvl"   : 120,
        "damage": 75,
        "damage_type" : "����",
]),
([      "action" : "$N˫�ֻ�Ȧ����Ļ����һ�����£���$P���֣��⡸�����׶����ľ�������$w����ɽ����֮�Ʒ�������",
        "skill_name" : "�����׶�",
        "force" : 380,
        "attack": 55,
        "dodge" : -10,
        "parry" : 55,
        "lvl"   : 160,
        "damage": 80,
        "damage_type" : "����",
]),
});


int valid_enable(string usage) { return usage == "hammer" || usage == "parry"; }

int valid_learn(object me)
{
        if ((int)me->query("max_neili") < 800)
                return notify_fail("�������������\n");

        if ((int)me->query_skill("force") < 120)
                return notify_fail("����ڹ����̫ǳ��\n");

        if ((int)me->query_skill("hammer", 1) < (int)me->query_skill("fenglei-panfa", 1))
                return notify_fail("��Ļ�������ˮƽ���ޣ��޷���������ķ����̷���\n");

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
        level = (int) me->query_skill("fenglei-panfa",1);
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
                return notify_fail("������������������˷����̷���\n");

        if ((int)me->query("neili") < 100)
                return notify_fail("������������������˷����̷���\n");

        me->receive_damage("qi", 90);
        me->add("neili", -90);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"fenglei-panfa/" + action;
}
