#include <ansi.h>
#include <weapon.h>

inherit BLADE;

void create()
{
        set_name(HIC "�������" NOR, ({ "qingyu dao", "qingyu", "blade", "dao" }) );
        set_weight(4000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 1000000);
                set("material", "steel");
        }
        init_blade(80);
        setup();
}
