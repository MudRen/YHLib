#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIG "������" NOR, ({"shexin zi", "shexing", "zi"}));
        set("unit", "��");
        set("long", HIG "����һ��ֲ��Ĺ�ʵ��\n" NOR);
        set("value", 10);
        set_weight(10);
        setup();
}
