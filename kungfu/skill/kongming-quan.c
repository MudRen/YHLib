#include <ansi.h>
inherit SKILL;

mapping *action = ({
([      "action": "$Nʹһ�С�����ס�ˡ���˫����ƮƮ�ع���$n$l",
        "force" : 250,
        "attack": 55,
        "dodge" : 70,
        "parry" : 60,
        "damage": 10,
        "lvl"   : 0,
        "damage_type": "����"
]),
([      "action": "$N����һƽ������һ�죬һ�С�����ʢ����ֱ��$n��$l",
        "force" : 270,
        "attack": 60,
        "dodge" : 80,
        "parry" : 80,
        "damage": 15,
        "lvl"   : 30,
        "damage_type": "����"
]),
([      "action": "$N������$nһת��˫������,һ�С��ղ�װˮ������$n$l",
        "force" : 300,
        "attack": 75,
        "dodge" : 100,
        "parry" : 100,
        "damage": 20,
        "lvl"   : 60,
        "damage_type": "����"
]),
([      "action": "$N����һ��������һ��,һ�С��黳���ȡ�����$n��$l",
        "force" : 320,
        "attack": 75,
        "dodge" : 110,
        "parry" : 100,
        "damage": 25,
        "lvl"   : 90,
        "damage_type": "����"
]),
([      "action": "$Nʹһ�С���ɽ�����$n��$l��Χ��$N��������Ӱ֮��",
        "force" : 340,
        "attack": 80,
        "dodge" : 130,
        "parry" : 120,
        "damage": 30,
        "lvl"   : 120,
        "damage_type": "����"
]),
([      "action": "$N��ɫһ����ʹ�������Ŀ�������Χ��$n��$l��������",
        "force" : 370,
        "attack": 85,
        "dodge" : 140,
        "parry" : 130,
        "damage": 40,
        "lvl"   : 150,
        "damage_type": "����"
]),
});

int valid_enable(string usage)
{
	return usage == "unarmed" || usage == "parry";
}

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("������ȭ������֡�\n");

	if ((int)me->query("max_neili") < 1500)
                return notify_fail("�������̫�����޷�������ȭ��\n");

        if ((int)me->query_skill("force") < 150)
                return notify_fail("����ڹ���򲻹����޷�������ȭ��\n");

        if ((int)me->query_skill("unarmed", 1) < 120)
                return notify_fail("��Ļ���ȭ�Ż�򲻹����޷�������ȭ��\n");

        if ((int)me->query_skill("unarmed", 1) < (int)me->query_skill("kongming-quan", 1))
                return notify_fail("��Ļ���ȭ��ˮƽ���ޣ��޷���������Ŀ���ȭ��\n");

	return 1;
}

string query_skill_name(int level)
{
        int i;
        for (i = sizeof(action) - 1; i >= 0; i--)
                if (level >= action[i - 1]["lvl"])
                        return action[i - 1]["skill_name"];
}

mapping query_action(object me, object weapon)
{
        int i, level;
        level = (int)me->query_skill("kongming-quan", 1);
        for (i = sizeof(action); i > 0; i--)
                if (level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level / 5)];
}

mixed valid_damage(object ob, object me, int damage, object weapon)
{
        mapping result;
        int ap, dp;

        if ((int)me->query_skill("kongming-quan", 1) < 100
           || ! living(me)
           || me->query_temp("weapon")
           || ob->query_temp("weapon"))
                return;

        ap = ob->query_skill("force");
        dp = me->query_skill("unarmed", 1) / 2 +
             me->query_skill("kongming-quan", 1);

        if (ap / 2 + random(ap) < dp)
        {
                result = ([ "damage": -damage ]);

                switch (random(2))
                {
                case 0:
                        result += (["msg" : HIG "$n" HIG "˫��һ��$N" + HIG
                                            "��ʱ�����Լ�������ȫȻ��ա�\n"
                                            NOR]);
                        break;
                case 1:
                        result += (["msg" : HIG "$n" HIG "����񵲣���$N" HIG 
                                            "ֻ�����Լ�ȫȻ��׽����$n" HIG "��"
                                            "������\n" NOR]);
                        break;
                default:
                        result += (["msg" : HIG "$n" HIG "������ȭ���Ҹ���"
                                            "$N" HIG "ֻ���������޴���ʹ��˵��"
                                            "�������ܡ�\n" NOR]);
                        break;
                }
                return result;
        }
}

int query_effect_parry(object attacker, object me)
{
        int lvl;

        if (me->query_temp("weapon"))
                return 0;

        lvl = me->query_skill("kongming-quan", 1);
        if (lvl < 80)  return 0;
        if (lvl < 200) return 50;
        if (lvl < 280) return 80;
        if (lvl < 350) return 100;
        return 120;
}

int practice_skill(object me)
{
	if ((int)me->query("qi") < 60)
		return notify_fail("�������̫���ˡ�\n");

	if ((int)me->query("neili") < 70)
                return notify_fail("������������ˡ�\n");

	me->receive_damage("qi", 50);
	me->add("neili", -60);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"kongming-quan/" + action;
}
