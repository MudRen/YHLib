#include <ansi.h>
#include <weapon.h>

inherit BLADE;

void create()
{
        set_name(HIY "������" NOR, ({ "jinyang dao", "jinyang", "blade", "dao" }) );
        set_weight(4000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 1400000);
                set("material", "steel");
        }
        init_blade(120);
        setup();
}
