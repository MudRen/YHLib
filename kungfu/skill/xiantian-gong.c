#include <ansi.h>
inherit FORCE;

int query_neili_improve(object me)
{
        int lvl;

        lvl = (int)me->query_skill("xiantian-gong", 1);
        return lvl * lvl * 15 * 22 / 100 / 200;
}

int valid_force(string force)
{
        return force == "quanzhen-xinfa" ||
               force == "xuanmen-neigong";
}

mapping *action = ({
([      "action" : "$N����һ�����˾����칦��������Х����$n��$l����ȥ",
        "dodge"  : 87,
        "force"  : 430,
        "attack" : 163,
        "parry"  : 81,
        "damage" : 83,
        "damage_type": "����" 
]), 
([      "action" : "$N����ƽ�죬�����������칦�ľ������͵�����$n��$l",
        "dodge"  : 85,
        "force"  : 440,
        "attack" : 147,
        "parry"  : 77,
        "damage" : 81,
        "damage_type": "����"
]), 
([      "action" : "$N����һչ�����ƻ�ס�����������й�ֱ��������$n$l",
        "dodge"  : 75,
        "force"  : 450,
        "attack" : 182,
        "parry"  : 67,
        "damage" : 93,
        "damage_type": "����"
]),
([      "action" : "$N��ת����������˫�ƻ�Ȧ����ʱһ�����ȵ�����ֱϮ$n",
        "dodge"  : 87,
        "force"  : 480,
        "attack" : 183,
        "parry"  : 85,
        "damage" : 105,
        "damage_type": "����"
]), 
});

int valid_enable(string usage)
{ 
        int lvl;
        lvl = (int)this_player()->query_skill("xiantian-gong", 1);

        if (lvl >= 180)    
                return usage == "force" || usage == "unarmed" || usage == "parry";
        else
                return usage == "force";
       
}

int valid_learn(object me)
{
        if (me->query("character") != "��������"
           && me->query("character") != "��ʿ��˫")
                return notify_fail("��ֻ�����칦����ֺ룬���Լ��������ƺ���������\n");

        if ((int)me->query("int") < 34)
                return notify_fail("����������Բ��㣬��������������칦��\n");

        if ((int)me->query("con") < 34)
                return notify_fail("�����������������޷�������������칦��\n");

        if ( me->query("gender") == "����" && me->query("xiantian-gong", 1) > 29)
                return notify_fail("���޸����ԣ�������������������������칦��\n");

        if ((int)me->query_skill("taoism", 1) < 200)
                return notify_fail("��Ե�ѧ�ķ�����ⲻ��������������칦��\n");

        if ((int)me->query_skill("force", 1) < 200)
                return notify_fail("��Ļ����ڹ�����㣬����������칦��\n");

        if ((int)me->query_skill("unarmed", 1) < 200)
                return notify_fail("��Ļ���ȭ�Ż���㣬����������칦��\n");

        if ((int)me->query("max_neili", 1) < 4000)
                return notify_fail("���������Ϊ���㣬����������칦��\n");

        if (me->query_skill("taoism", 1) < 320
           && me->query_skill("taoism", 1) < me->query_skill("xiantian-gong", 1))
                return notify_fail("��Ե�ѧ�ķ�����ⲻ�������Զ������������칦��\n");

        if (me->query_skill("force", 1) < me->query_skill("xiantian-gong", 1))
                return notify_fail("��Ļ����ڹ�ˮƽ���������Զ������������칦��\n");

        if (me->query_skill("unarmed", 1) < me->query_skill("xiantian-gong", 1))
                return notify_fail("��Ļ���ȭ��ˮƽ���������Զ������������칦��\n");

        return ::valid_learn(me);
}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
        int lvl;

        lvl = me->query_skill("xiantian-gong", 1);

        if (damage_bonus < 150
           || lvl < 180
           || me->query("neili") < 300
           || me->query_temp("weapon")
           || me->query_temp("secondary_weapon")
           || me->query_skill_mapped("force") != "xiantian-gong"
           || me->query_skill_mapped("unarmed") != "xiantian-gong"
           || me->query_skill_prepared("unarmed") != "xiantian-gong")
                return 0;

        if (damage_bonus / 6 > victim->query_con())
        {
                me->add("neili", -30);
                victim->receive_wound("qi", (damage_bonus - 100) / 3, me);
                return HIW "$N" HIW "���칦��Ǳ�������˳�����ͻȻ��$n"
                       HIW "ֻ�к���һ�����һ����Ѫ��\n" NOR;
        }
}

int practice_skill(object me)
{
        return notify_fail("���칦ֻ����ѧ(learn)�����������ȡ�\n");
}

int difficult_level()
{
        return 500;
}

string perform_action_file(string action)
{
        return __DIR__"xiantian-gong/perform/" + action;
}

string exert_function_file(string action)
{
        return __DIR__"xiantian-gong/exert/" + action;
}
