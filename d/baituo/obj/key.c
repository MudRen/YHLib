#include <ansi.h> 
inherit ITEM;

void create()
{
        set_name(NOR + YEL "钥匙" NOR, ({ "key" }));
        set_weight(100);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", YEL "这是一把普通的铜钥匙。\n" NOR);
                set("value", 0);
                set("material", "iron");
        }
}
