#include <ansi.h>
#include <weapon.h>

inherit BLADE;

void create()
{
        set_name(RED "����»���" NOR, ({ "wugui ren", "ren", "blade", "dao" }) );
        set_weight(4000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 1200000);
                set("material", "steel");
        }
        init_blade(90);
        setup();
}
