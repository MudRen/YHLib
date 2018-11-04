#include <ansi.h>
inherit SKILL;

mapping *action = ({
([      "action": "$Nһָ�������һ�С������ಫ���й�ֱ����ָ����$nѹ�ô���������",
        "force" : 41,
        "attack": 1,
        "parry" : 3,
        "dodge" : 5,
        "damage": 1,
        "lvl"   : 0,
        "damage_type" : "��Ѩ",
        "skill_name"  : "�����ಫ"
]),
([      "action": "$N���β�����һ�С�����������������$n��һ��ԥ��$N����ָ�Ѵ����Լ�",
        "force" : 49,
        "attack": 3,
        "parry" : 4,
        "dodge" : 7,
        "damage": 2,
        "lvl"   : 10,
        "damage_type" : "��Ѩ",
        "skill_name"  : "��������"
]),
([      "action": "ֻ��$Nһת������һʽ�����������һָ��в�´���������$n��$l",
        "force" : 55,
        "attack": 6,
        "parry" : 7,
        "dodge" : 5,
        "damage": 4,
        "lvl"   : 20,
        "damage_type" : "��Ѩ",
        "skill_name"  : "��������"
]),
([      "action": "ֻ��$Nһ�С��������졹��ʮָ�紩������һ�����·��ɣ�ȫȫ����$n",   
        "force" : 71,
        "attack": 5,
        "parry" : 11,
        "dodge" : 19,
        "damage": 4,
        "lvl"   : 30,
        "damage_type" : "��Ѩ",
        "skill_name"  : "��������"
]),
([      "action": "ֻ��$N���΢Ц�����ֶ�����һ�С�ң�۲׺�����$n�پ�һ��ָ��ֱ�˶���",
        "force" : 90,
        "attack": 8,
        "parry" : 12,
        "dodge" : 10,
        "damage": 7,
        "lvl"   : 40,
        "damage_type" : "��Ѩ",
        "skill_name"  : "ң�۲׺�"
]),
([      "action": "����$Nһ����߳��һ�С��׺�һ�ڡ������ֻ��˸��뻡��ʳָ��������$n",
        "force" : 110,
        "attack": 12,
        "parry" : 23,
        "dodge" : 25,
        "damage": 9,
        "lvl"   : 50,
        "damage_type" : "��Ѩ",
        "skill_name"  : "�׺�һ��"
]),
});

int valid_enable(string usage) { return usage == "finger" ||  usage == "parry"; }

int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("������ָ��������֡�\n");

        if ((int)me->query_skill("force") < 10)
                return notify_fail("����ڹ���򲻹����޷�ѧ����ָ����\n");

        if ((int)me->query_skill("finger", 1) < 10)
                return notify_fail("���ָ����򲻹����޷�ѧ����ָ����\n");

        if ((int)me->query("max_neili") < 50)
                return notify_fail("���������Ϊ̫�����޷�������ָ����\n");

        if (me->query_skill("finger", 1) < me->query_skill("canglang-zhi", 1))
                return notify_fail("��Ļ���ָ��̫��޷���������Ĳ���ָ����\n");

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
        level = (int)me->query_skill("canglang-zhi", 1);
        for (i = sizeof(action); i > 0; i--)
                if (level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        if ((int)me->query("qi") < 30)
                return notify_fail("�������̫���ˣ��޷�������ָ����\n");

        if ((int)me->query("neili") < 40)
                return notify_fail("��������������޷�������ָ����\n");

        me->receive_damage("qi", 25);
        me->add("neili", -35);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"canglang-zhi/" + action;
}
