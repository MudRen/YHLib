#include <weapon.h>
#include <ansi.h>

inherit HAMMER;

void create()
{
        set_name(NOR + WHT "��ʯͷ" NOR, ({ "stone" }));
        set_weight(16000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", NOR + WHT "һ�����Բ������ʯͷ��\n" NOR);
                set("value", 0);
                set("material", "stone");
        }
        init_hammer(10);
        setup();
}

