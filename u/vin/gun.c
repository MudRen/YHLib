#include <ansi.h>
#include <weapon.h>

inherit HAMMER;

void create()
{
        set_name(HIR "AK47" NOR, ({ "ak47" }));
        set_weight(5000);

        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "֧");
                set("long", HIR "ɱ�˹��ߣ�����˲��ɱ�ˡ�\n" NOR);
                set("value", 25000);
        }
        init_hammer(30);
        setup();
}
