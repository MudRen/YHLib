#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(WHT "������" NOR, ({"zhang panzi"}));
        set_weight(3);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", WHT "һ���ո��ù��������ӡ�\n" NOR);
                set("value", 1);
        }
        setup();
}
