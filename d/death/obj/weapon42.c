#include <ansi.h>
#include <weapon.h>

inherit BLADE;

void create()
{
        set_name(HIY "�����쵶" NOR, ({ "qiwang dao", "qiwang", "blade", "dao" }) );
        set_weight(4000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 300000);
                set("material", "steel");
        }
        init_blade(55);
        setup();
}
