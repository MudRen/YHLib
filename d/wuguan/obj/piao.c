#include <ansi.h>
#include <weapon.h>
inherit HAMMER;

void create()
{
        set_name(HIG "ˮư" NOR, ({ "shui piao", "shui", "piao" }));
        set_weight(500);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", HIG "����һ�����Ϻ�«�������ɵ�ư����ͨ���յ��ճ���ũ��Ʒ��\n" NOR);
                set("value", 10);
                set("material", "steel");
                set("wield_msg", HIG "$N" HIG "�ó�һ��ˮư�������С�\n" NOR);
                set("unwield_msg", HIG "$N" HIG "�����е�ˮư�������ϡ�\n" NOR);
        }
        init_hammer(4);
        setup();
}
