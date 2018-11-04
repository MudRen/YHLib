
inherit FORCE;
#include <ansi.h>

int valid_enable(string usage) { return usage == "force"; }

int query_neili_improve(object me)
{
        int lvl;

        lvl = (int)me->query_skill("shenghuo-shengong", 1);
        return lvl * lvl * 15 * 16 / 100 / 200;
}

int valid_force(string force)
{
    return (force == "shenghuo-xinfa");
}

int valid_learn(object me)
{
        if (me->query("int") < 32)
                return notify_fail("���������Բ������޷�����ʥ���񹦡�\n");

        if ((int)me->query_skill("force", 1) < 180)
                return notify_fail("��Ļ����ڹ���򻹲�����������ѧϰʥ���񹦡�\n");

        return ::valid_learn(me);
}

int practice_skill(object me)
{
        return notify_fail("ʥ����ֻ����ѧ(learn)�������������ȡ�\n");
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
        int lvl, i;
        int flvl, attack_time;
        object weapon;

        lvl  = me->query_skill("shenghuo-shengong", 1);
        flvl = me->query_skill("shenghuo-ling");

        if (lvl < 140 || ! damage_bonus ||
            me->query_skill_mapped("force") != "shenghuo-shengong" ||
            me->query_skill_mapped("sword") != "shenghuo-ling" ||
            ! objectp(weapon = me->query_temp("weapon")) ||
            (string)weapon->query("skill_type") != "sword" ||
            flvl < 140 ||
            me->query_temp("shenghuo-ling/hit") ||
            me->query("neili") < 200)
                return 0;

        attack_time = (int)(me->query_skill("shenghuo-ling", 1) / 40);

        if (attack_time > 8)
                attack_time = 8;


        if (lvl / 2 + random(lvl) > victim->query_skill("force", 1) &&
            ! me->query_temp("shenghuo-ling/max_hit") )
        {
                 message_vision(HIR "\nɲ�Ǽ�$N" HIR "����Ȼ�ӿ죬���������������ʽ�����ޱ�"
                                "����$n" HIR "������ĥ��\n" NOR, me, victim);

                    
                 me->start_busy(1+ random(attack_time));
                 me->add("neili", -attack_time * 20);
                 me->add_temp("shenghuo-ling/hit", 1);
                 for (i = 0; i < attack_time; i++)
                 {
                       if (! me->is_fighting(victim))
                                 break;

                       COMBAT_D->do_attack(me, victim, weapon, 0);
                 }
                 me->delete_temp("shenghuo-ling/hit");
               
                 return 1;                
        }            
 
}

string exert_function_file(string func)
{
        return __DIR__"shenghuo-shengong/" + func;
}

