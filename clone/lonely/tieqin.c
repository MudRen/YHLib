#include <weapon.h>
#include <music.h>
#include <ansi.h>

inherit SWORD;
inherit MI_QIN;

void create()
{
        set_name(WHT "���ٽ�" NOR,({ "tieqin jian", "tieqin", "jian", "qin" }) );
        set_weight(12000);
        if (clonep())
                destruct(this_object());
        else {
                set("long", WHT "һ�ߵ��й��ӻ��Ƶ����٣����ٵ�һ��¶��һ��������\n" NOR);
                set("unit", "��");
                set("value", 800000);
                set("no_sell", 1);
                set("material", "steel");
                set("wield_msg", WHT "$N" WHT "�����ӻ������ٵ��ټ������һ����"
                                 "���еĳ����������С�\n" NOR);
                set("unwield_msg", WHT "$N" WHT "΢΢һЦ�������е����ٽ��ջأ���"
                                 "��������ȥ��\n" NOR);
                set("stable", 100);
        }
        init_sword(110);
        setup();
}

void init()
{
        add_action("play_qin", "play");
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
        int n;

        if (me->query_skill_mapped("sword") != "kunlun-jian" ||
            me->query_skill("kunlun-jian", 1) < 100)
                return damage_bonus / 2;

        switch (random(12))
        {
        case 0:
                if (! victim->is_busy())
                victim->start_busy(me->query_skill("sword") / 12 + 2);
                return WHT "$N" WHT "һ���Ϻȣ�������Ȼ�����������٣����ٶ�ʱ����һ�ɼ����"
                       "������$n" WHT "ֻ��ͷ��Ŀѣ���������ʣ�\n" NOR;

        case 1:
                n = me->query_skill("sword");
                victim->receive_damage("qi", n * 3 / 4, me);
                victim->receive_wound("qi", n * 3 / 4, me);
                return WHT "$N" WHT "һ����ߣ��������ٽ�һ����ʱ��������һ������Я�ż�"
                       "�������ֱ��$n" WHT "��ȥ��\n" NOR;
        }
        return damage_bonus;
}
