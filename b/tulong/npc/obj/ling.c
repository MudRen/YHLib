#include <weapon.h>
#include <ansi.h>

inherit SWORD;

void create()
{
        set_name(NOR + CYN "������" NOR, ({ "bintie ling", "bintie", "ling" }));
        set_weight(1500);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "֧");
                set("value", 300);
                set("material", "steel");
        }
        init_sword(10);
        setup();
}

