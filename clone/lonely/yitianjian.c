#include <weapon.h>
#include <ansi.h>

inherit SWORD;

void create()
{
        set_name(NOR + WHT "���콣" NOR, ({ "yitian jian", "yitian", "jian", "sword" }) );
        set_weight(10000);
        if (clonep())
                destruct(this_object());
        else {
                set("long", NOR + WHT "�������������������������Ƶ����콣��\n"
                            "�ഫ���в��п����Ĵ����ܡ�\n" NOR);
                set("unit", "��");
                set("value", 800000);
                set("no_sell", "�ҵ��졭�㡭��֪������ɶô������Ҳ����������");
                set("material", "steel");
                set("wield_msg", HIW "ֻ����ಡ���һ���ƿ����죬�ų����µ�һ"
                             "��������콣�ѱ�$N" HIW "�������С�\n" NOR);
                set("unwield_msg", HIW "$N" HIW "�����콣������䣬����ֽ���"
                             "�ų���â��\n"NOR);
                set("stable", 100);
        }
        init_sword(250);
        setup();
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
        victim->receive_damage("qi", me->query("str") * 4, me);
        victim->receive_wound("qi", me->query("str") * 4, me);
        return WHT "���콣Я�Ŵ̹Ƿ���������ʣ�$n"
               WHT "ֻ��ȫ��������һ˿˿���Ž���ӿ����\n" NOR;
}

