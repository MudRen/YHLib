#include <weapon.h>
#include <ansi.h>

inherit SWORD;

void create()
{
        set_name(HIY "������" NOR, ({ "tenglong jian", "tenglong", "jian", "sword" }) );
        set_weight(5800);
        if (clonep())
                destruct(this_object());
        else {
                set("long", HIY "һ�������ĳ���������������ˮ������������⡣\n" NOR);
                set("unit", "��");
                set("value", 800000);
                set("no_sell", "���š��⽣���ǿںý����������Ǯ���ÿ����ҿ�"
                                 "�������˰ɡ�");
                set("material", "steel");
                set("wield_msg", HIY "$N" HIY "৵ĳ��һ�������������У���"
                                 "����⵴�����������ˡ�\n" NOR);
                set("unwield_msg", HIY "$N" HIY "��������������������������"
                                 "������䡣\n" NOR);
                set("stable", 100);
        }
        init_sword(120);
        setup();
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
        int n;
        int my_exp, ob_exp;

        if (me->query_skill("sword") < 160)
                return damage_bonus / 2;

        if (me->query_skill_mapped("sword") != "miaojia-jian" &&
            me->query_skill_mapped("sword") != "tianlong-jian")
                return damage_bonus / 2;

        switch (random(12))
        {
        case 0:
                if (! victim->is_busy())
                victim->start_busy(me->query_skill("sword") / 16 + 2);
                return HIY "$N" HIY "����������һ���������㽣�⣬��ʱ��$n"
                       HIY "����������\n" NOR;

        case 1:
                n = me->query_skill("sword");
                victim->receive_damage("qi", n * 3 / 4, me);
                victim->receive_wound("qi", n * 3 / 4, me);
                return HIY "ֻ�����ƿ������죬$N" HIY "�����������ת��������"
                       "$n" HIY "����������\n" NOR;
        }
        return damage_bonus;
}
