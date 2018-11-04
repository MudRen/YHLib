#include <ansi.h>
inherit FORCE;

int query_neili_improve(object me)
{
        int lvl;

        lvl = (int)me->query_skill("hamagong", 1);
        return lvl * lvl * 15 * 18 / 100 / 200;
}

mapping *action = ({
([      "action" : "$N����������һ�ֳ�ס���棬���Ӻ�ͦ����һ����$n���ؿ���ȥ",
        "dodge"  : 35,
        "force"  : 310,
        "attack" : 103,
        "parry"  : 21,
        "damage" : 58,
        "lvl"    : 0,
        "damage_type": "����" 
]), 
([      "action" : "$N˫��΢��������ƽ�죬���������󡹦����������һ������$n",
        "dodge"  : 50,
        "force"  : 332,
        "attack" : 112,
        "parry"  : 37,
        "damage" : 61,
        "lvl"    : 180,
        "damage_type": "����"
]), 
([      "action" : "$N���۱�ס��������Ծ�����۾�Ҳ��������������$n���˳�ȥ",
        "dodge"  : 67,
        "force"  : 360,
        "attack" : 122,
        "parry"  : 53,
        "damage" : 72,
        "lvl"    : 220,
        "damage_type": "����"
]),
([      "action" : "$N�Ų�ҡ�ϣ���Ȼ˫��һ�ǣ����и��һ���кȣ���$n��Ȼ�Ƴ�",
        "dodge"  : 75,
        "force"  : 410,
        "attack" : 143,
        "parry"  : 67,
        "damage" : 81,
        "lvl"    : 240,
        "damage_type": "����"
]), 
});

int valid_enable(string usage)
{ 
        int lvl = (int)this_player()->query_skill("hamagong", 1);

        if (lvl >= 180)    
                return usage == "force" || usage == "unarmed" || usage == "parry";
        else
                return usage == "force";
       
}

int valid_learn(object me)
{
        if (me->query("character") == "��������"
           || me->query("character") == "������")
                return notify_fail("�����а��������󡹦�����쳣�����ƻ��˼���"
                                   "�����Ǳ���Ϊ�\n");

        if ((int)me->query("con") < 32)
                return notify_fail("����������������޷�������󡹦��\n");

        if ((int)me->query("dex") < 32)
                return notify_fail("��������̫��޷�������󡹦��\n");

        if (me->query("gender") == "����" && me->query("hamagong", 1) > 49)
                return notify_fail("���޸����ԣ���������������������ĸ�󡹦��\n");

        if ((int)me->query_skill("force", 1) < 150)
                return notify_fail("��Ļ����ڹ�����㣬��������󡹦��\n");

        if ((int)me->query_skill("unarmed", 1) < 150)
                return notify_fail("��Ļ���ȭ�Ż���㣬��������󡹦��\n");

        if ((int)me->query_skill("poison", 1) < 150)
                return notify_fail("��Ļ�����������㣬��������󡹦��\n");

        if ((int)me->query("max_neili", 1) < 2500)
                return notify_fail("�����ڵ�������Ϊ���㣬��������󡹦��\n");

        return ::valid_learn(me);
}

mapping query_action(object me, object weapon)
{
        int i, level;
        level = (int) me->query_skill("hamagong", 1);
        for (i = sizeof(action); i > 0; i--)
                if (level > action[i - 1]["lvl"])
                        return action[NewRandom(i, 5, level / 5)];
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
        int lvl;

        lvl = me->query_skill("hamagong", 1);

        if (damage_bonus < 150
           || lvl < 180
           || me->query("neili") < 300
           || me->query_temp("weapon")
           || me->query_temp("secondary_weapon")
           || me->query_skill_mapped("force") != "hamagong"
           || me->query_skill_mapped("unarmed") != "hamagong"
           || me->query_skill_prepared("unarmed") != "hamagong")
                return 0;

        if (damage_bonus / 6 > victim->query_con())
        {
                me->add("neili", -30);
                victim->receive_wound("qi", (damage_bonus - 90) / 3, me);
                return WHT "$n" WHT "Ӳ����$N" WHT "һ�ƣ���ʱȫ"
                       "��һ���������������һ����Ѫ��\n" NOR;
        }
}

int practice_skill(object me)
{
        return notify_fail("��󡹦ֻ����ѧ(learn)�������������ȡ�\n");
}

string perform_action_file(string action)
{
        return __DIR__"hamagong/perform/" + action;
}

string exert_function_file(string action)
{
        return __DIR__"hamagong/exert/" + action;
}
