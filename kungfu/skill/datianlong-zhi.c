// datianlong-zhi.c ������ָ

#include <ansi.h>
inherit SKILL;

mapping *action = ({
([      "action": "$Nһָ�������һ�С�������š��й�ֱ����ָ����$nѹ�ô���������",
        "force" : 90,
        "dodge" : 5,
        "damage": 15,
        "lvl"   : 0,
        "weapon"      : "����ָ��",
        "damage_type" : "����",
        "skill_name"  : "�������"
]),
([      "action": "$N���β�����һ�С������Ợ��������$n��һ��ԥ��$N����ָ�Ѵ����Լ�",
        "force" : 140,
        "attack": 5,
        "parry" : 5,
        "dodge" : 5,
        "damage": 20,
        "lvl"   : 40,
        "weapon"      : "������ָ",
        "damage_type" : "����",
        "skill_name"  : "�����Ợ"
]),
([      "action": "ֻ��$Nһת������һʽ���������֡���һָ��в�´���������$n��$l",
        "force" : 155,
        "attack": 10,
        "parry" : 7,
        "dodge" : 5,
        "damage": 30,
        "lvl"   : 40,
        "weapon"      : "������ָ",
        "damage_type" : "����",
        "skill_name"  : "��������"
]),
([      "action": "ֻ��$Nһ�С������ĺ�����ʮָ�紩������һ�����·��ɣ�ȫȫ����$n",   
        "force" : 170,
        "attack": 20,
        "parry" : 11,
        "dodge" : 9,
        "damage": 40,
        "lvl"   : 60,
        "damage_type" : "��Ѩ",
        "skill_name"  : "�����ĺ�"
]),
([      "action": "ֻ��$N���΢Ц�����ֶ�����һ�С��������ԡ���$n�پ�һ��ָ��ֱ�˶���",
        "force" : 190,
        "attack": 30,
        "parry" : 12,
        "dodge" : 10,
        "damage": 50,
        "lvl"   : 80,
        "weapon"      : "����ָ��",
        "damage_type" : "����",
        "skill_name"  : "��������"
]),
([      "action": "����$Nһ����߳��һ�С����������������ֻ��˸��뻡��ʳָ��������$n",
        "force" : 250,
        "attack": 40,
        "parry" : 23,
        "dodge" : 25,
        "damage": 57,
        "lvl"   : 100,
        "weapon"      : "����ʳָ",
        "damage_type" : "����",
        "skill_name"  : "��������"
]),
});

string main_skill() { return "canhe-zhi"; }

int valid_enable(string usage) { return usage == "finger" ||  usage == "parry"; }

int valid_learn(object me)
{
        if ((int)me->query_skill("canhe-zhi", 1))
                return notify_fail("���ѽ�����ָ������κ�ָ�������ٷֿ���ϰ�ˡ�\n");

        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("��������ָ������֡�\n");

        if ((int)me->query_skill("force") < 120)
                return notify_fail("����ڹ���򲻹����޷�ѧ������ָ��\n");

        if ((int)me->query_skill("finger", 1) < 80)
                return notify_fail("��Ļ���ָ����򲻹����޷�ѧ������ָ��\n");

        if ((int)me->query("max_neili") < 1200)
                return notify_fail("�������̫�����޷���������ָ��\n");

        if (me->query_skill("finger", 1) < me->query_skill("datianlong-zhi", 1))
                return notify_fail("��Ļ���ָ��̫��޷���������Ĵ�����ָ��\n");

        return 1;
}

string query_skill_name(int level)
{
        int i;
        for(i = sizeof(action) - 1; i >= 0; i--)
                if (level >= action[i]["lvl"])
                        return action[i]["skill_name"];
}

mapping query_action(object me, object weapon)
{
        int i, level;
        level = (int)me->query_skill("datianlong-zhi", 1);
        for (i = sizeof(action); i > 0; i--)
                if (level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        if ((int)me->query_skill("canhe-zhi", 1))
                return notify_fail("���ѽ�����ָ������κ�ָ�������ٷֿ���ϰ�ˡ�\n");

        if ((int)me->query("qi") < 70)
                return notify_fail("�������̫���ˣ��޷���������ָ��\n");

        if ((int)me->query("neili") < 70)
                return notify_fail("��������������޷���������ָ��\n");

        me->receive_damage("qi", 55);
        me->add("neili", -51);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"datianlong-zhi/" + action;
}
