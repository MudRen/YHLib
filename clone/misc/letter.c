#include <ansi.h>
inherit ITEM;

int is_letter() { return 1; }

void create()
{
        set_name(NOR + WHT "�ż�" NOR, ({ "letter" }));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ���ż���\n");
                set("value", 0);
        }
        setup();
}
