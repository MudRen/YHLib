#include <ansi.h>
#include <armor.h>

inherit HEAD;

void create()
{
        set_name("Ò»°ÙÁã°Ë¿Å" RED "ÑªÉ«²Ôñ·" NOR, ({ "q" }) );
        set_weight(50);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("value", 200000);
                set("unit", "¿é");
                set("can_be_enchased", 1);
                set("magic/type", "magic");
                set("magic/power", 50000);
                set("armor_prop/per", 8);
        }
        setup();
}

