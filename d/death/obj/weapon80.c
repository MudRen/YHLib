#include <ansi.h>
#include <weapon.h>

inherit SWORD;

void create()
{
        set_name(HIW "���ǽ�" NOR, ({ "guxing jian", "guxing", "jian", "sword" }) );
        set_weight(4000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 300000);
                set("material", "steel");
        }
        init_sword(50);
        setup();
}
