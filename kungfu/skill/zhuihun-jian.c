// zhuihun-jian.c ׷�������

inherit SKILL;

mapping *action = ({
([      "action" : "$Nһ�С��޳���������$w�ƻ�������������������˷�������$n",
        "force"  : 110,
        "attack" : 35,
        "dodge"  : -20,
        "parry"  : -25,
        "damage" : 43,
        "lvl"    : 0,
        "skill_name" : "�޳�����",
        "damage_type" : "����"
]),
([      "action" : "$Nһ�С�ɷ�񵱵�����������ָ������$n��$n�������ֱܷ�$w����·",
        "force"  : 155,
        "attack" : 43,
        "dodge"  : -25,
        "parry"  : -34,
        "damage" : 51,
        "lvl"    : 20,
        "skill_name" : "ɷ�񵱵�",
        "damage_type" : "����"
]),
([      "action" : "$Nʹ����ӹҽ��ҩ����$w��һ������������һ�ɺ�������$n��$l",
        "force"  : 178,
        "attack" : 48,
        "dodge"  : -28,
        "parry"  : -24,
        "damage" : 62,
        "lvl"    : 40,
        "skill_name" : "ӹҽ��ҩ",
        "damage_type" : "����"
]),
([      "action" : "$N�������ϵ���������ָ��һ�С��йٷ�����������$w����һ�Ž���������$n��$l",
        "force"  : 211,
        "attack" : 53,
        "dodge"  : -22,
        "parry"  : -24,
        "damage" : 84,
        "lvl"    : 60,
        "skill_name" : "�йٷ���",
        "damage_type" : "����"
]),
([      "action" : "$Nһ�С��������š������Ծ����أ�����$w�ó�һ��ѩ�׵��ٲ���ɨ��$n��$l",
        "force"  : 238,
        "attack" : 69,
        "dodge"  : -28,
        "parry"  : -35,
        "damage" : 95,
        "lvl"    : 80,
        "skill_name" : "��������",
        "damage_type" : "����"
]),
([      "action" : "$N���Ȱ�����ף�$wƽָ��һ�С����Ͷ�桹������������ɫ�������Ĵ���$n��$l",
        "force"  : 268,
        "attack" : 73,
        "dodge"  : -38,
        "parry"  : -15,
        "damage" : 110,
        "lvl"    : 100,
        "skill_name" : "���Ͷ��",
        "damage_type" : "����"
]),
([      "action" : "$Nһ�С��������ġ���������ָ������$n��$n�������ֱܷ�$w����·",
        "force"  : 255,
        "attack" : 71,
        "dodge"  : -25,
        "parry"  : -24,
        "damage" : 108,
        "lvl"    : 120,
        "skill_name" : "��������",
        "damage_type" : "����"
]),
([      "action" : "$Nʹ�����������ʡ���$w��һ������������һ�ɺ�������$n��$l",
        "force"  : 270,
        "attack" : 78,
        "dodge"  : -18,
        "parry"  : -19,
        "damage" : 123,
        "lvl"    : 140,
        "skill_name" : "��������",
        "damage_type" : "����"
]),
([      "action" : "$N�������ϵ���������ָ��һ�С����Ź�����������$w����һ�Ž���������$n��$l",
        "force"  : 291,
        "attack" : 103,
        "dodge"  : -23,
        "parry"  : -28,
        "damage" : 141,
        "lvl"    : 160,
        "skill_name" : "���Ź���",
        "damage_type" : "����"
]),
([      "action" : "$Nһ�С�ţͷ¾�ס������Ծ����أ�����$w�ó�һ��ѩ�׵��ٲ���ɨ��$n��$l",
        "force"  : 283,
        "attack" : 91,
        "dodge"  : -22,
        "parry"  : -25,
        "damage" : 155,
        "lvl"    : 180,
        "skill_name" : "ţͷ¾��",
        "damage_type" : "����"
]),
([      "action" : "$N���Ȱ�����ף�$wƽָ��һ�С�Թ����㡹������������ɫ�������Ĵ���$n��$l",
        "force"  : 298,
        "attack" : 97,
        "dodge"  : -28,
        "parry"  : -37,
        "damage" : 158,
        "lvl"    : 200,
        "skill_name" : "Թ�����",
        "damage_type" : "����"
]),
([      "action" : "$Nһ�С��˹�������$w��$n��������裬��$n�ۻ����ң������ڰ����ͻȻͣס����$n��$l",
        "force"  : 328,
        "attack" : 118,
        "dodge"  : -25,
        "parry"  : -27,
        "damage" : 170,
        "lvl"    : 220,
        "skill_name" : "�˹���",
        "damage_type" : "����"
]),
});

int valid_enable(string usage) {return usage == "sword" || usage == "parry";}

int valid_learn(object me)
{
        if (me->query("character") != "�ĺ�����")
                return notify_fail("��ֻ��׷������������ޱȣ����޾���֮�٣���ѧҲ�ա�\n");

        if (me->query("dex") < 24)
                return notify_fail("���������̫��޷�ѧϰ׷���������\n");

        if ((int)me->query("max_neili") < 2500)
                return notify_fail("���������Ϊ������\n");

        if ((int)me->query_skill("force", 1) < 120)
                return notify_fail("��Ļ����ڹ����̫ǳ��\n");

        if ((int)me->query_skill("sword", 1) < 120)
                return notify_fail("��Ļ���������򲻹����޷�ѧϰ׷���������\n");

        if ((int)me->query_skill("sword", 1) < (int)me->query_skill("zhuihun-jian", 1))
                return notify_fail("��Ļ�������ˮƽ���ޣ��޷����������׷���������\n");

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
        level   = (int) me->query_skill("zhuihun-jian",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        object weapon;

        if (!objectp(weapon = me->query_temp("weapon")) ||
            (string)weapon->query("skill_type") != "sword")
                return notify_fail("��ʹ�õ��������ԡ�\n");

        if ((int)me->query("qi") < 60)
                return notify_fail("�������Ŀǰû�а취��ϰ׷���������\n");

        if ((int)me->query("neili") < 90)
                return notify_fail("��������������޷���ϰ׷���������\n");
        
        me->add("qi", -50);
        me->add("neili", -82);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"zhuihun-jian/" + action;
}

