#include <ansi.h>

inherit COMBINED_ITEM;

void create()
{
        set_name(NOR + WHT "��Ƥ" NOR, ({ "yang pi", "yang", "pi" }));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", NOR + WHT "���Ƥë��ë�ʹ⻬��\n" NOR);
                set("base_unit", "��");
                set("base_value", 800);
                set("base_weight", 400);
        }
        setup();
        set_amount(1);
}
