#include <weapon.h>
#include <ansi.h>

inherit SWORD;

void create()
{
        set_name(HIY "���߽�" NOR, ({ "jinshe jian", "jinshe", "jian" }) );
        set_weight(10000);
        if (clonep())
                destruct(this_object());
        else {
                set("long", HIY "ֻ���ǽ���״�������أ�������������һ������\n"
                                "�����ɣ���β���ɽ�������ͷ���ǽ��⣬������\n"
                                "���ֲ棬���Խ��⾹�����档�ǽ������ã���\n"
                                "���������ǳ��أ��������ǻƽ������������\n"
                                "������������һ��Ѫ�ۣ����������͵İ��⣬��\n"
                                "�ǹ��졣��\n" NOR);

                set("unit", "��");
                set("value", 800000);
                set("no_sell", 1);
                set("material", "steel");
                set("wield_msg", HIY "�ƿն��죬���߽��ѳ��ʣ�$N" HIY "ȫ�����쬵�ֻ�к������ˡ�\n" NOR); 
                set("unwield_msg", HIY "$N" HIY "��һ����߽����ʣ����ܺ���������\n" NOR);
                set("stable", 100);
        }
        init_sword(100);
        setup();
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
        int ap, dp;
        int n;

        ap = me->query_skill("sword");
        dp = victim->query_skill("dodge");

        if (me->query_skill_mapped("sword") != "jinshe-jian" ||
            me->query_skill("jinshe-jian", 1) < 100 ||
            ap / 2 + random(ap) < dp)
                return damage_bonus / 2;

        switch (random(3))
        {
        case 0:
                if (! victim->is_busy())
                      victim->start_busy(me->query_skill("sword") / 10 + 4);
                return HIY "$N" HIY "ŭ��һ�������߽���������һ�㣬�����ζ�������\n��������֮�⣬��"
                       "��$n" HIY "�����������Ӱ֮�¡�\n" NOR;

        case 1:
                n = me->query_skill("sword");
                victim->receive_damage("qi", n * 3 / 4, me);
                victim->receive_wound("qi", n * 3 / 4, me);
                return  HIY "$N" HIY "������𣬽��߽�������£��������߰���趯�ž���$n" HIY
                        "���������Ѩ��\n" NOR;

        }
        return damage_bonus;
}
