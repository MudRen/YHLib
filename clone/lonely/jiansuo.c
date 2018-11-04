#include <weapon.h>
#include <ansi.h>

inherit WHIP;

void create()
{
        set_name(HIW "��������" NOR,({ "jiandun zhusuo", "jiandun", "zhusuo",
                                       "suo", "whip" }) );
        set_weight(1000);
        if (clonep())
                destruct(this_object());
        else {
                set("long", HIW "һ��ͨ�����׵ĳ�������ͷ��ϵ��һ������\n" NOR);
                set("unit", "��");
                set("value", 800000);
                set("no_sell", 1);
                set("material", "steel");
                set("wield_msg", HIW "$N" HIW "������ȡ��һ������ɫ�ĳ�������ž"
                                 "������ճ����һ�¡�\n" NOR);
                set("unwield_msg", HIW "$N" HIW "΢΢һЦ�������н��������̺ã�"
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

        if (me->query_skill_mapped("whip") != "jiandun-zhusuo" ||
            me->query_skill("jiandun-zhusuo", 1) < 100)
                return damage_bonus / 2;

        switch (random(10))
        {
        case 0:
                if (! victim->is_busy())
                victim->start_busy(me->query_skill("whip") / 10 + 1);
                return HIW "$N" HIW "���н�������һ����������ʱ����һ����â��"
                       "��ͷ����ֱ��$n" HIW "��ǰҪѨ��\n" NOR;

        case 1:
                n = me->query_skill("whip");
                victim->receive_damage("qi", n * 2 / 3, me);
                victim->receive_wound("qi", n * 2 / 3, me);
                return HIW "ֻ��$N" HIW "�������󣬱����á�쬡���һ����������"
                       "����������һ�㣬ֱϮ$n" HIW "��ȥ��\n" NOR;
        }
        return damage_bonus;
}
