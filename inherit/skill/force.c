// force.c

#include <ansi.h>

inherit SKILL;

int valid_learn(object me)
{
        if ((int)me->query_skill("force", 1) < 10)
                return notify_fail("��Ļ����ڹ���򲻹�������ѧϰ�����ڹ���\n");

        return 1;
}

// hit effect called by combatd
mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
        int damage;
        int me_fac;
        int victim_fac;
        int f;
        int m_lvl;
        int v_lvl;
        string skill;
        mixed result;

        skill = victim->query_skill_mapped("force");
        if (stringp(skill))
        {
                if (result = SKILL_D(skill)->valid_damage(me, victim, damage_bonus))
                        return result;
        }

        me_fac = (int)me->query("neili");
        if (me_fac > (int)me->query("max_neili"))
                me_fac = (int)me->query("max_neili");

        victim_fac = (int)victim->query("neili");
        if (victim_fac > (int)victim->query("max_neili"))
                victim_fac = (int)victim->query("max_neili");

        if ((int)me->query("combat_exp") < (int)victim->query("combat_exp") * 20)
                me->add("neili", -factor);

        damage = me_fac / 20 + factor - victim_fac / 24;

        if (damage < 0)
        {
                v_lvl = victim->query_skill("force");
                m_lvl = me->query_skill("force");
                if (! me->query_temp("weapon") &&
                    m_lvl + random(m_lvl / 3) < v_lvl)
                {
                        result = ([ "damage" : damage * 2 ]);
                        damage = -damage;
                        me->receive_damage("qi", damage * 4, victim);
                        me->receive_wound("qi", damage * 4, victim);
                        if (damage < 10)
                                result += ([ "msg" : HIY "$N" HIY "�ܵ�$n"
                                                     HIY "�����������ƺ�һ����\n" NOR ]);
                        else if (damage < 20)
                                result += ([ "msg" : YEL "$N" YEL "��$n"
                                                     YEL "���������𣬡��١���һ������������\n" NOR ]);
                        else if (damage < 40)
                                result += ([ "msg" : HIC "$N" HIC "��$n"
                                                     HIC "������һ���ؿ������ܵ�һ���ش�����������������\n" NOR ]);
                        else if (damage < 80)
                                result += ([ "msg" : HIR "$N" HIR "��$n"
                                                     HIR "������һ����ǰһ�ڣ��������ɳ�����\n" NOR ]);
                        else
                                result += ([ "msg" : RED "$N" RED "��$n"
                                                     RED "������һ��ֻ�����������ϣ���Ѫ�������������˹�ȥ��\n" NOR ]);
                        return result;
                }

                return damage;
        }

        damage -= victim->query_temp("apply/armor_vs_force");
        if (damage_bonus + damage < 0)
                return - damage_bonus;
        if ((f = random(me->query_skill("force"))) < damage)
                return f;

        return damage;
}

// can I exercise force?
int do_effect(object me)
{
        int lvl;
        int n;
        mapping skmap;
        string sk;

        if (! userp(me))
                // only user does effect
                return 0;

        n = 0;
        skmap = me->query_skills();
        if (! skmap || ! sizeof(skmap))
                return 0;

        foreach (sk in keys(skmap))
        {
                if (! SKILL_D(sk)->is_shaolin_skill())
                        continue;
                n += skmap[sk] * skmap[sk] / 100 * skmap[sk];
        }

        if (n < 10000)
                return 0;

        lvl = me->query_skill("buddhism", 1);
        lvl *= lvl * lvl / 25;

        if (me->query("family/family_name") == "������")
                lvl += lvl / 2;

        if (lvl < n * 9 / 10)
        {
                write(RED "��ֻ��������һ���ʹ����ȫ�޷�������Ϣ����"
                      "��ס���һ�����ƶ���ĺ����乶��¡�\n" NOR);
                message("vision", RED + me->name() + RED "��Ȼ���һ����"
                        "�ƶ���ĺ����乶��£�������ʹ��֮����\n" NOR,
                        environment(me), ({ me }));
                me->receive_damage("jing", 200 + random(200));
                me->receive_damage("qi", 400 + random(400));
                return 1;
        } else
        if (lvl < n)
        {
                write(HIR "��ֻ������Ϣһ�����ң���֫�ٺ���ʱ���䣬��"
                      "��ü�������������Ĳ�����\n" NOR);
                message("vision", HIR + me->name() + RED "������ס��"
                        "��������ü������΢΢������\n" NOR,
                        environment(me), ({ me }));
                me->receive_damage("jing", 100 + random(100));
                me->receive_damage("qi", 200 + random(200));
                return 1;
        } else
        if (lvl < n * 11 / 10)
        {
                write(HIY "������е��ķ����ң�������������"
                      "�٣�����������Щ���ѡ�\n" NOR);
        } else
        if (lvl < n * 13 / 10)
        {
                write(HIC "�������е������ĸо���\n" NOR);
        }
        return 0;
}

