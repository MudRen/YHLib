#include <weapon.h>
#include <ansi.h>
inherit WHIP;

void create()
{
        set_name(HIY "���Ǵ�" NOR, ({ "liuxing chui", "liuxing", "chui" }));
        set_weight(4500);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", HIY "һ��������������Ǵ���\n" NOR);
                set("value", 2000);
                set("material", "leather");
        }
        init_whip(40);
        setup();
}
