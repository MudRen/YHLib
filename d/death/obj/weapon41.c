#include <ansi.h>
#include <weapon.h>

inherit BLADE;

void create()
{
        set_name(CYN "����" NOR, ({ "chanyi dao", "chanyi", "blade", "dao" }) );
        set_weight(4000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 250000);
                set("material", "steel");
        }
        init_blade(50);
        setup();
}
