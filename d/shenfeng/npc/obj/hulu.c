#include <ansi.h>

inherit ITEM;
inherit F_LIQUID;

void create()
{
        set_name(YEL "�ƺ�«" NOR, ({ "jiu hulu", "hulu", "jiu" }));
        set_weight(700);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "һ������װ�ƵĴ��«����Ƥ��ƣ�������װ�ü���ơ�\n");
                set("unit", "��");
                set("value", 100);
                set("max_liquid", 15);
        }
        set("liquid", ([
                "type": "alcohol",
                "name": "�׾�",
                "remaining": 15,
                "drunk_apply": 3,
        ]));
}
