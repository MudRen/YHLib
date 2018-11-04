#include <weapon.h>
#include <ansi.h>

inherit SWORD;

void create()
{
        set_name(NOR + WHT "ī��" NOR, ({ "mo jian", "mo", "jian" }) );
        set_weight(14000);
        if (clonep())
                destruct(this_object());
        else {
                set("long", WHT "һ��ͨ��ī�ڵĳ���������͸������Ĺ���\n" NOR);
                set("unit", "��");
                set("value", 800000);
                set("no_sell", 1);
                set("material", "steel");
                set("wield_msg", WHT "ֻ��$N" WHT "��������һ���������Ѷ���һ��ͨ"
                                 "��ī�ڵĳ�����\n" NOR);
                set("unwield_msg", WHT "$N" WHT "΢΢һЦ�������е�ī�ڳ��������"
                                 "�䡣\n" NOR);
                set("stable", 100);
        }
        init_sword(90);
        setup();
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
        int n;

        if (me->query_skill_mapped("sword") != "shangqing-jian" ||
            me->query_skill("shangqing-jian", 1) < 100)
                return damage_bonus / 2;

        switch (random(12))
        {
        case 0:
                if (! victim->is_busy())
                victim->start_busy(me->query_skill("sword") / 12 + 1);
                return WHT "$N" WHT "��תī�����������������佣������ʱ�������䣬����$n"
                       WHT "���ֲ�����\n" NOR;

        case 1:
                n = me->query_skill("sword");
                victim->receive_damage("qi", n * 3 / 4, me);
                victim->receive_wound("qi", n * 3 / 4, me);
                return WHT "$N" WHT "һ����ߣ�����ī���й�ֱ������ʱһ��������ī�������"
                       "�����������$n" WHT "��\n" NOR;
        }
        return damage_bonus;
}
