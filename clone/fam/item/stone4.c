#include <ansi.h>
#include "stone.h"

void create()
{
        set_name(HIM "��ʯ" NOR, ({ "hui shi", "hui", "shi" }));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("base_unit", "��");
                set("base_value", 180000);
                set("base_weight", 100);
        }
        setup();
}

