#include <ansi.h>
inherit ITEM;

int is_bag() { return 1; }

void create()
{
        set_name(NOR + WHT "����" NOR, ({ "bag" }));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ��������\n");
                set("value", 0);
        }
        setup();
}
