#include <weapon.h>
#include <ansi.h>

inherit WHIP;

void create()
{
        set_name(HIY "��������" NOR, ({ "chilong jinsuo", "chilong", "jinsuo", "suo", "whip" }) );
        set_weight(2800);
        if (clonep())
                destruct(this_object());
        else {
                set("long", HIY "һ���ɳ���������ĳ�������������һ��СС�ġ�"
                            HIR "��" HIY "���֡�\n" NOR);
                set("unit", "��");
                set("value", 800000);
                set("no_sell", "�⡭���ⲻ�����ҵ��죬�����������㶼���ǣ�");
                set("material", "steel");
                set("wield_msg", HIY "$N" HIY "��쬡���һ����������һ�������"
                                 "������˸�Ȧ�ӡ�\n" NOR);
                set("unwield_msg", HIY "$N" HIY "��Цһ���������г��������̺ã�"
                                 "�Ż����䡣\n" NOR);
                set("stable", 100);
        }
        init_whip(100);
        setup();
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
        int n;
        int my_exp, ob_exp;

        if (me->query_skill_mapped("whip") != "panlong-suo" ||
            me->query_skill("panlong-suo", 1) < 100)
                return damage_bonus / 2;

        switch (random(10))
        {
        case 0:
                if (! victim->is_busy())
                victim->start_busy(me->query_skill("whip") / 12 + 1);
                return HIY "$N" HIY "���г�������һ����������ʱ����һ����⣬"
                       "���������$n" HIY "��ǰҪѨ��\n" NOR;

        case 1:
                n = me->query_skill("whip");
                victim->receive_damage("qi", n * 2 / 3, me);
                victim->receive_wound("qi", n * 2 / 3, me);
                return HIY "ֻ��$N" HIY "�������󣬳���������ʱ����ͬ����һ��"
                       "����$n" HIY "��ɨ��ȥ��\n" NOR;
        }
        return damage_bonus;
}
