#include <ansi.h>
inherit FORCE;

int query_neili_improve(object me)
{
        int lvl;

        lvl = (int)me->query_skill("longxiang-gong", 1);
        return lvl * lvl * 15 * 18 / 100 / 200;
}

mapping *action = ({
([      "action" : "$N����һ�����˾������������������Х����$n��$l����ȥ",
        "dodge"  : 37,
        "force"  : 430,
        "attack" : 173,
        "parry"  : 41,
        "damage" : 133,
        "damage_type": "����" 
]), 
([      "action" : "$N��ȭ���ƣ�������������������ľ������͵�����$n��$l",
        "dodge"  : 35,
        "force"  : 440,
        "attack" : 177,
        "parry"  : 47,
        "damage" : 121,
        "damage_type": "����"
]), 
([      "action" : "$N����������˫ȭͬʱ���������������������$n$l����ȥ",
        "dodge"  : 37,
        "force"  : 450,
        "attack" : 182,
        "parry"  : 46,
        "damage" : 123,
        "damage_type": "����"
]),
([      "action" : "$N���������������˫ȭƽ�ƣ���ʱһ���������ֱϮ$n",
        "dodge"  : 27,
        "force"  : 480,
        "attack" : 183,
        "parry"  : 35,
        "damage" : 145,
        "damage_type": "����"
]), 
});

int valid_enable(string usage)
{ 
        int lvl;
        lvl = (int)this_player()->query_skill("longxiang-gong", 1);

        if (lvl >= 150)
                return usage == "force" ||
                       usage == "parry" ||
                       usage == "unarmed";

        else if (lvl >= 30)
                return usage == "force";

        else
                return usage == "";
}

int valid_learn(object me)
{
        int lvl, layer;

        lvl = me->query_skill("longxiang-gong", 1);
        layer = lvl / 30;

        if (layer > 13) layer = 13;

        if ((int)me->query("str") < 36)
                return notify_fail("������������������޷����������������\n");

        if ((int)me->query("con") < 30)
                return notify_fail("�����������������޷����������������\n");

        if (me->query("gender") == "����" && layer >= 1)
                return notify_fail("���޸����ԣ������������޷����������������\n");

        if ((int)me->query_skill("lamaism", 1) < 100)
                return notify_fail("��������ķ���ⲻ����������������������\n");

        if ((int)me->query_skill("force", 1) < 100)
                return notify_fail("��Ļ����ڹ�����㣬������������������\n");

        if ((int)me->query("max_neili", 1) < 1000)
                return notify_fail("���������Ϊ���㣬������������������\n");

        if (me->query_skill("force", 1) < lvl)
                return notify_fail("��Ļ����ڹ�ˮƽ�������������������������������\n");

        if ((int)me->query("max_neili", 1) < layer * 500)
                return notify_fail("���������Ϊ�������������������������������\n");

        if (me->query_skill("lamaism", 1) < layer * 25)
                return notify_fail("��������ķ���ⲻ�����������������������������\n");

        if (me->query_skill("unarmed", 1) < lvl && layer >= 5)
                return notify_fail("��Ļ���ȭ��ˮƽ�������������������������������\n");

        return ::valid_learn(me);
}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
        int lvl, layer;

        lvl = me->query_skill("longxiang-gong", 1);
        layer = lvl / 30;

        if (layer > 13) layer = 13;

        if (damage_bonus < 130
           || layer < 6
           || me->query("neili") < 500
           || me->query_temp("weapon")
           || me->query_temp("secondary_weapon")
           || me->query_skill_mapped("force") != "longxiang-gong"
           || me->query_skill_mapped("unarmed") != "longxiang-gong"
           || me->query_skill_prepared("unarmed") != "longxiang-gong"
           || damage_bonus / 6 < victim->query_con()
           || random(10) < 5)
                return 0;

        if (layer >= 10 && random(2) == 1)
        {
                me->add("neili", -80);
                victim->receive_wound("qi", (damage_bonus - 50) / 3, me);
                return HIY "$N" HIY "ȭ��֮�Ͼ��̲��š�" HIR "ʮ��ʮ��"
                       HIY "��֮��������壬�ݻ���$n" HIY "����Ԫ��\n" NOR;
        } else
        {
                me->add("neili", -50);
                victim->receive_wound("qi", (damage_bonus - 100) / 3, me);
                return HIY "$N" HIY "˫ȭ���������������" + chinese_number(layer) +
                       "�㹦����$n" HIY "�����������һ����Ѫ��\n" NOR;
        }
}

int practice_skill(object me)
{
        return notify_fail("���������ֻ����ѧ(learn)�����������ȡ�\n");
}

void skill_improved(object me)
{
        int lvl, layer;

        lvl = me->query_skill("longxiang-gong", 1);
        layer = lvl / 30;

        if ((lvl % 30) == 0 && layer > 13)
        {
                tell_object(me, HIY "�������������ֽ���һ�㡣\n" NOR);
        } else
        if ((lvl % 30) == 0)
        {
                tell_object(me, HIY "�������˵�" + chinese_number(layer) +
                                "��������������\n" NOR);
        }
}

int difficult_level()
{
        return 600;
}

string perform_action_file(string action)
{
        return __DIR__"longxiang-gong/perform/" + action;
}

string exert_function_file(string action)
{
        return __DIR__"longxiang-gong/exert/" + action;
}
