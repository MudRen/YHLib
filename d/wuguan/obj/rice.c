inherit ITEM;
inherit F_FOOD;
#include <ansi.h>;

void create()
{
        set_name(HIW "С�׷�" NOR, ({ "rice" }));
        set_weight(280);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", HIW "һ���������С�׷���\n" NOR);
                set("unit", "��");
                set("value", 0);
                set("food_remaining", 15);
                set("food_supply", 10);
        }
}
