#include <ansi.h>
#include <weapon.h>

inherit WHIP;

void create()
{
        set_name(HIW "����˿" NOR, ({ "chanhun si", "si", "chanhun", "whip" }) );
        set_weight(4000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 230000);
                set("material", "steel");
        }
        init_whip(50);
        setup();
}
