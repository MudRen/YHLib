// ���վ��� shenzhaojing.c
// Editd By Vin On 26/4/2001

#include <ansi.h>
inherit FORCE;

int query_neili_improve(object me)
{
        int lvl;

        lvl = (int)me->query_skill("shenzhaojing", 1);
        return lvl * lvl * 15 * 18 / 100 / 200;
}

mapping *action = ({
([      "action" : "$NٿȻԾ��������һȭ����һȭ������Ӱ��ȥ�ƿ켫����$n���ؿڴ�ȥ",
        "dodge"  : 81,
        "force"  : 323,
        "attack" : 119,
        "parry"  : 94,
        "damage" : 68,
        "lvl"    : 0,
        "damage_type": "����" 
]), 
([      "action" : "$N˿��������ɫ������ƽ�죬�����������վ��񹦵ľ���������һ������$n",
        "dodge"  : 73,
        "force"  : 362,
        "attack" : 138,
        "parry"  : 51,
        "damage" : 73,
        "lvl"    : 200,
        "damage_type": "����"
]), 
([      "action" : "$N����΢΢һչ����Ȼ������$n��ǰ����Ȼ��˫����ʩ����$n���Ķ�ȥ",
        "dodge"  : 78,
        "force"  : 389,
        "attack" : 152,
        "parry"  : 53,
        "damage" : 87,
        "lvl"    : 220,
        "damage_type": "����"
]),
([      "action" : "$N�˺�һ����˫�ƻ��գ���ջ���һ��ԲȦ����ʱһ�����ȵ�����ֱӿ$n����",
        "dodge"  : 75,
        "force"  : 410,
        "attack" : 163,
        "parry"  : 67,
        "damage" : 93,
        "lvl"    : 250,
        "damage_type": "����"
]), 
});

int valid_enable(string usage)
{ 
        int lvl;
        lvl = (int)this_player()->query_skill("shenzhaojing", 1);

        if(lvl >= 180)    
                return usage == "force" || usage == "unarmed" || usage == "parry";
        else
                return usage == "force";
       
}

int valid_learn(object me)
{
        if ((int)me->query("str") < 32)
                return notify_fail("�����������������޷��������վ��񹦡�\n");

        if ((int)me->query("con") < 32)
                return notify_fail("����������������޷��������վ��񹦡�\n");

        if ( me->query("gender") == "����" && me->query("shenzhaojing", 1) > 29)
                return notify_fail("���޸����ԣ�������������������������վ��񹦡�\n");

        if ((int)me->query_skill("force", 1) < 200)
                return notify_fail("��Ļ����ڹ�����㣬����ѧ���վ��񹦡�\n");

        if ((int)me->query_skill("unarmed", 1) < 200)
                return notify_fail("��Ļ���ȭ�Ż���㣬����ѧ���վ��񹦡�\n");

        if ((int)me->query("max_neili", 1) < 4000)
                return notify_fail("���������Ϊ���㣬����ѧ���վ��񹦡�\n");

        if (me->query_skill("force", 1) < me->query_skill("shenzhaojing", 1))
                return notify_fail("��Ļ����ڹ�ˮƽ���������Զ������������վ��񹦡�\n");

        if (me->query_skill("unarmed", 1) < me->query_skill("shenzhaojing", 1))
                return notify_fail("��Ļ���ȭ��ˮƽ���������Զ������������վ��񹦡�\n");

        return ::valid_learn(me);
}

mapping query_action(object me, object weapon)
{
        int i, level;
        level = (int) me->query_skill("shenzhaojing", 1);
        for (i = sizeof(action); i > 0; i--)
                if (level > action[i-1]["lvl"])
                        return action[NewRandom(i, 50, level)];
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
        int lvl;

        lvl = me->query_skill("shenzhaojing", 1);

        if (damage_bonus < 160
           || lvl < 180
           || me->query("neili") < 300
           || me->query_temp("weapon")
           || me->query_temp("secondary_weapon")
           || me->query_skill_mapped("force") != "shenzhaojing"
           || me->query_skill_mapped("unarmed") != "shenzhaojing"
           || me->query_skill_prepared("unarmed") != "shenzhaojing")
                return 0;

        // ���վ��������еļ���������˺���ʹ������
        // ����max_hit �������书���Ǿ��޽��еģ�����
        // �����ֵļ����Լ��˺�ֵ�ּ������˺��������
        // ���书��������
        if (damage_bonus / 6 > victim->query_con())
        {
               	victim->receive_wound("qi", (damage_bonus - 100) / 3, me);
                victim->affect_by("shenzhao",
                               ([ "level" : me->query("jiali") + random(me->query("jiali")),
                                  "id"    : me->query("id"),
                                  "duration" : lvl / 100 + random(lvl / 10) ]));
               	return HIR "$n" HIR "һ���Һ���ȫ��������������"
                       "�����߹ǡ��۹ǡ��ȹ�ͬʱ���ۡ�\n" NOR;
        }
}

int practice_skill(object me)
{
        return notify_fail("���վ���ֻ����ѧ(learn)�������������ȡ�\n");
}

int difficult_level()
{
        return 400;
}

string perform_action_file(string action)
{
        return __DIR__"shenzhaojing/perform/" + action;
}

string exert_function_file(string action)
{
        return __DIR__"shenzhaojing/exert/" + action;
}
