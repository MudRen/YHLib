// ��ң����
#include <ansi.h>
inherit SKILL;

mapping *action = ({
([      "action" : "$Nһ�С���ҶƮƮ����$w�ƻ�������������������˷�������$n",
        "force"  : 110,
        "attack" : 35,
        "dodge"  : -20,
        "parry"  : -25,
        "damage" : 43,
        "lvl"    : 0,
        "skill_name" : "��ҶƮƮ",
        "damage_type" : "����"
]),
([      "action" : "$Nһ�С�ˮ�и�Ƽ����������ָ������$n��$n�������ֱܷ�$w����·",
        "force"  : 155,
        "attack" : 43,
        "dodge"  : -25,
        "parry"  : -34,
        "damage" : 51,
        "lvl"    : 20,
        "skill_name" : "�и�Ƽ",
        "damage_type" : "����"
]),
([      "action" : "$Nʹ����ƮȻֱȥ����$w��һ������������һ�ɺ�������$n��$l",
        "force"  : 178,
        "attack" : 48,
        "dodge"  : -28,
        "parry"  : -24,
        "damage" : 62,
        "lvl"    : 40,
        "skill_name" : "ƮȻֱȥ",
        "damage_type" : "����"
]),
([      "action" : "$N�������ϵ���������ָ��һ�С�ǧ�ﲻ���С�������$w����һ�Ž���������$n��$l",
        "force"  : 211,
        "attack" : 53,
        "dodge"  : -22,
        "parry"  : -24,
        "damage" : 84,
        "lvl"    : 60,
        "skill_name" : "ǧ�ﲻ����",
        "damage_type" : "����"
]),
([      "action" : "$Nһ�С�����Ĩ���������Ծ����أ�����$w�ó�һ��ѩ�׵��ٲ���ɨ��$n��$l",
        "force"  : 238,
        "attack" : 69,
        "dodge"  : -28,
        "parry"  : -35,
        "damage" : 95,
        "lvl"    : 80,
        "skill_name" : "����Ĩ��",
        "damage_type" : "����"
]),
([      "action" : "$N���Ȱ�����ף�$wƽָ��һ�С����˺�ȥ��������������ɫ�������Ĵ���$n��$l",
        "force"  : 268,
        "attack" : 73,
        "dodge"  : -38,
        "parry"  : -15,
        "damage" : 110,
        "lvl"    : 100,
        "skill_name" : "���˺�ȥ",
        "damage_type" : "����"
]),
([      "action" : "$Nһ�С����￴������������ָ������$n��$n�������ֱܷ�$w����·",
        "force"  : 255,
        "attack" : 71,
        "dodge"  : -25,
        "parry"  : -24,
        "damage" : 108,
        "lvl"    : 120,
        "skill_name" : "���￴��",
        "damage_type" : "����"
]),
([      "action" : "$Nʹ������ɽ�չȡ���$w��һ������������һ�ɺ�������$n��$l",
        "force"  : 270,
        "attack" : 78,
        "dodge"  : -18,
        "parry"  : -19,
        "damage" : 123,
        "lvl"    : 140,
        "skill_name" : "��ɽ�չ�",
        "damage_type" : "����"
]),
([      "action" : "$N�������ϵ���������ָ��һ�С�Ⱥ�ɾۻ᡹������$w����һ�Ž���������$n��$l",
        "force"  : 291,
        "attack" : 103,
        "dodge"  : -23,
        "parry"  : -28,
        "damage" : 141,
        "lvl"    : 160,
        "skill_name" : "Ⱥ�ɾۻ�",
        "damage_type" : "����"
]),
([      "action" : "$Nһ�С�ƮƮ�����������Ծ����أ�����$w�ó�һ��ѩ�׵��ٲ���ɨ��$n��$l",
        "force"  : 283,
        "attack" : 91,
        "dodge"  : -22,
        "parry"  : -25,
        "damage" : 155,
        "lvl"    : 180,
        "skill_name" : "ƮƮ����",
        "damage_type" : "����"
]),
([      "action" : "$N���Ȱ�����ף�$wƽָ��һ�С�ǧɽ��ˮ��������������ɫ�������Ĵ���$n��$l",
        "force"  : 300,
        "attack" : 97,
        "dodge"  : -28,
        "parry"  : -37,
        "damage" : 158,
        "lvl"    : 200,
        "skill_name" : "ǧɽ��ˮ",
        "damage_type" : "����"
]),
([      "action" : "$Nһ�С�ȥ���˼䡹��$w��$n��������裬��$n�ۻ����ң������ڰ����ͻȻͣס����$n��$l",
        "force"  : 328,
        "attack" : 118,
        "dodge"  : -25,
        "parry"  : -27,
        "damage" : 170,
        "lvl"    : 220,
        "skill_name" : "ȥ���˼�",
        "damage_type" : "����"
]),
});

int valid_enable(string usage) {return usage == "sword" || usage == "parry";}

int valid_learn(object me)
{
        if (me->query("int") < 30)
                return notify_fail("���������Բ��㣬�޷�������ң������\n");
 
        if ((int)me->query("max_neili") < 2500)
                return notify_fail("���������Ϊ�������޷�ѧϰ��ң������\n");

        if ((int)me->query_skill("force", 1) < 120)
                return notify_fail("��Ļ����ڹ����̫ǳ���޷�ѧϰ��ң������\n");

        if ((int)me->query_skill("dodge", 1) < 120)
                return notify_fail("��Ļ����ڹ����̫ǳ���޷�ѧϰ��ң������\n");

        if ((int)me->query_skill("sword", 1) < 120)
                return notify_fail("��Ļ���������򲻹����޷�ѧϰ��ң������\n");

        if ((int)me->query_skill("sword", 1) < (int)me->query_skill("xiaoyao-jian", 1))
                return notify_fail("��Ļ�������ˮƽ���ޣ��޷������������ң������\n");

        return 1;
}

string query_skill_name(int level)
{
        int i;
        for(i = sizeof(action)-1; i >= 0; i--)
                if(level >= action[i]["lvl"])
                        return action[i]["skill_name"];
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
        object weapon;

        int lvl = me->query_skill("xiaoyao-jian", 1);
        weapon = me->query_temp("weapon");      

        if (lvl < 130 || lvl / 2 + random(lvl) < (int)victim->query_skill("dodge", 1) ||
            me->query("neili") < 150 ||
            me->query_skill("dodge", 1) < 180 ||
            me->query_skill("force", 1) < 150 ||             
            victim->is_busy() )
                 return 0;

        message_vision(HIW "\n$N" HIW "����" + weapon->name() + HIW "��Ȼ��ת������ͻ"
                       "�֣�ɲ�Ǽ��ѽ�$n" HIW "��·ȫ��������\n" NOR, me, victim); 

        me->add("neili", -80);
        victim->start_busy(2 + random(lvl / 30));

        return 1;                         
}

mapping query_action(object me, object weapon)
{
        int i, level;
        level   = (int) me->query_skill("xiaoyao-jian",1);
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
                return notify_fail("�������Ŀǰû�а취��ϰ��ң������\n");

        if ((int)me->query("neili") < 90)
                return notify_fail("��������������޷���ϰ��ң������\n");
        
        me->add("qi", -50);
        me->add("neili", -82);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"xiaoyao-jian/" + action;
}

