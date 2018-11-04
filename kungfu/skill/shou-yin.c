// shou-yin.c ��ӡ(������)

#include <ansi.h>

inherit SKILL;

mapping *action = ({
([      "action" : "$Nʹ��һ�С���������ӡ����˫����׶��ֱֱ����$n��ǰ��",
        "force"    : 589,
        "attack"   : 285,
        "dodge"    : 167,
        "parry"    : 189,
        "damage"   : 303,
        "weapon"   : HIW "��ӡ" NOR,
        "damage_type" : "����",
]),
([      "action" : "$Nʹ��һ�С����ƹ���ӡ��������Ծ��˫���繴��ץ��$n��$l",
        "force"    : 621,
        "attack"   : 309,
        "dodge"    : 188,
        "parry"    : 197,
        "damage"   : 326,
        "weapon"   : HIW "��ӡ" NOR,
        "damage_type" : "����",
]),
([      "action" : "$Nʹ��һ�С�׼���ĸӡ����������ָ��ֱȡ$n��$l",
        "force"    : 642,
        "attack"   : 321,
        "dodge"    : 197,
        "parry"    : 203,
        "damage"   : 339,
        "weapon"   : HIW "��ӡ" NOR,
        "damage_type" : "����",
]),
([      "action" : "$Nʹ��һ�С���������ӡ����ŭ��һ����һ�Ƶ�ͷ����$n��$l",
        "force"    : 657,
        "attack"   : 335,
        "dodge"    : 215,
        "parry"    : 227,
        "damage"   : 356,
        "weapon"   : HIW "��ӡ" NOR,
        "damage_type" : "����",
]),
([      "action" : "$Nʹ��һ�С�ҩʦ�����ӡ�����ͳ���ǰ���Ƶ��������㿳��$n",
        "force"    : 673,
        "attack"   : 357,
        "dodge"    : 243,
        "parry"    : 236,
        "damage"   : 367,
        "weapon"   : HIW "��ӡ" NOR,
        "damage_type" : "����",
]),
([      "action" : "$Nʹ��һ�С����½��ӡ������������˫������ɨ��$n��$l",
        "force"    : 672,
        "attack"   : 371,
        "dodge"    : 265,
        "parry"    : 257,
        "damage"   : 386,
        "weapon"   : HIW "��ӡ" NOR,
        "damage_type" : "����",
]),
([      "action" : "$Nʹ��һ�С����ֽ��ӡ���������Ծ��˫��ǰ�������ץ��$n����"
                   "��",
        "force"    : 680,
        "attack"   : 398,
        "dodge"    : 297,
        "parry"    : 271,
        "damage"   : 403,
        "weapon"   : HIW "��ӡ" NOR,
        "damage_type" : "����",
]),
([      "action" : "$Nʹ��һ�С������ǻ�ӡ������ʱ��������������г���������Ӱ��"
                   "��$n",
        "force"    : 720,
        "attack"   : 435,
        "dodge"    : 315,
        "parry"    : 287,
        "damage"   : 436,
        "weapon"   : HIW "��ӡ" NOR,
        "damage_type" : "����",
]),
});

int double_attack() { return 1; }

int valid_enable(string usage) { return usage == "hand" || usage == "parry"; }

int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("����ӡ������֡�\n");

        if (me->query("int") < 36)
                return notify_fail("�������ӡ���ڼ��������⡣\n");

        if ((int)me->query_skill("martial-cognize", 1) < 300)
                return notify_fail("�����ѧ����̫�ͣ��޷���ϰ��ӡ��\n");

        if ((int)me->query("max_neili") < 5000)
                return notify_fail("�������������\n");

        if ((int)me->query_skill("force") < 350)
                return notify_fail("����ڹ����̫ǳ��\n");

        if ((int)me->query_skill("hand", 1) < 200)
                return notify_fail("��Ļ����ַ����̫ǳ��\n");

        if ((int)me->query_skill("hand", 1) < (int)me->query_skill("shou-yin",1))
                return notify_fail("��Ļ����ַ�ˮƽ���ޣ��޷������������ӡ��\n");

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
                  level   = (int) me->query_skill("shou-yin",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        object weapon;

        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("������ӡ��������֡�\n");

        if ((int)me->query("qi") < 350)
                return notify_fail("���������������������ӡ��\n");

        if ((int)me->query("neili") < 500)
                return notify_fail("���������������������ӡ��\n");

        me->receive_damage("qi", 300);
        me->add("neili", -300);
        return 1;
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
        if (damage_bonus < 100) return 0;

        if (damage_bonus / 5 > victim->query_str())
        {
                victim->receive_wound("qi", (damage_bonus - 100) / 2);
                return HIR "ֻ��" + victim->name() +
                       HIR "һ���ƺߣ�һ˫" NOR + HIW "��ӡ"
                       NOR + HIR "���ص�ӡ����ǰ�����ۡ�"
                       "�������һ�����Ѫ��\n" NOR;
        }
}

string perform_action_file(string action)
{
        return __DIR__"shou-yin/" + action;
}

