//jingzhong-bafa ���а˷�

#include <ansi.h>
inherit SKILL;

mapping *action = ({
([      "action" : "$N��������������$w���ƣ�һ�С�������������������$nl������ȥ",
        "force"  : 232,
        "attack" : 157,
        "dodge"  : 123,
        "parry"  : 221,
        "damage" : 389,
        "damage_type" : "����",
]),
([      "action" : "$Nһ�С�ɳŸ�Ӳ������������¶��ϻ��˸��뻡��$wһ��һ�գ�ƽ�л���$n�ľ���",
        "force"  : 285,
        "attack" : 183,
        "dodge"  : 123,
        "parry"  : 221,
        "damage" : 421,
        "damage_type" : "����",
]),
([      "action" : "$Nʹ��һ�С���������������$w��������һ��ѹ��$n",
        "force"  : 297,
        "attack" : 179,
        "dodge"  : 123,
        "parry"  : 221,
        "damage" : 435,
        "damage_type" : "����",
]),
([      "action" : "$Nһ�С��������ȡ���$w������б����$n��ȥ",
        "force"  : 334,
        "attack" : 191,
        "dodge"  : 123,
        "parry"  : 221,
        "damage" : 451,
        "damage_type" : "����",
]),
([      "action" : "$N����$w��ת��Ծ��һ�С���´��ʡ���һ���׹�����$n���ؿ�",
        "force"  : 382,
        "attack" : 207,
        "dodge"  : 121,
        "parry"  : 211,
        "damage" : 479,
        "damage_type" : "����",
]),
([      "action" : "$N����$w��ʹ��һ�С��׺���᡹���������ã����ҿ�����������$n",
        "force"  : 397,
        "attack" : 223,
        "dodge"  : 123,
        "parry"  : 221,
        "damage" : 483,
        "damage_type" : "����",
]),
([      "action" : "$Nһ�С�������ů�������Ծ����أ�$w˳����ǰ��Ю��������$n��$l",
        "force"  : 421,
        "attack" : 257,
        "dodge"  : 133,
        "parry"  : 213,
        "damage" : 534,
        "damage_type" : "����",
]),
([      "action" : "$N���ʹһ�С��˷��ص�������ʱ�����������䵶��������˷�ӿ��$nȫ��",
        "force"  : 423,
        "attack" : 271,
        "dodge"  : 173,
        "parry"  : 221,
        "damage" : 589,
        "damage_type" : "����",
]),
});

int valid_enable(string usage) { return usage == "blade" || usage == "parry"; }

int valid_learn(object me)
{
        if (me->query("character") != "������")
                return notify_fail("�����а��룺�ߣ����ֵ���û����·����������ã�\n");

        if (me->query("int") < 36)
                return notify_fail("����þ��а˷����ڼ��������⡣\n");

        if ((int)me->query_skill("martial-cognize", 1) < 300)
                return notify_fail("�����ѧ����û�а취��⾮�а˷��ľ�����塣\n");

        if ((int)me->query("max_neili") < 5000)
                return notify_fail("����������㣬û�а취�����а˷�������Щ���������ɡ�\n");

        if ((int)me->query_skill("blade", 1) < 250)
                return notify_fail("��Ļ����������̫ǳ��û�а취�����а˷���\n");

        if ((int)me->query_skill("force") < 350)
                return notify_fail("����ڹ����̫ǳ��û�а취�����а˷���\n");

        if ((int)me->query_skill("blade", 1) < (int)me->query_skill("jingzhong-bafa", 1))
                return notify_fail("��Ļ�������ˮƽ���������޷���������ľ��а˷���\n");

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
        level   = (int) me->query_skill("jingzhong-bafa", 1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        object weapon;

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "blade")
                return notify_fail("��ʹ�õ��������ԡ�\n");

        if ((int)me->query("qi") < 500)
                return notify_fail("������������������˾��а˷���\n");

        if ((int)me->query("neili") < 500)
                return notify_fail("������������������˾��а˷���\n");

        me->receive_damage("qi", 300);
        me->add("neili", -300);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"jingzhong-bafa/" + action;
}

