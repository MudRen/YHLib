#include <ansi.h>
#include <weapon.h>
inherit BLADE;

void create()
{
        set_name( WHT "�ݹǵ�" NOR, ({ "blade" }));
        set_weight(300);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 30);
                set("material", "leather");
        }
        init_blade(250);
        setup();
}
void owner_is_killed()
{
        destruct(this_object());
} 
