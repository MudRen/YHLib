inherit ITEM;
inherit F_LIQUID;

#include <ansi.h>

void create()
{
        set_name(HIY "��ˮ" NOR, ({"water","shui"}));
        set_weight(50);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "һ����ˮ��\n");
                set("unit", "��");
                set("value", 10);
                set("max_liquid", 4);
        }

        set("liquid", ([
    	        "type": "water",
                "name": "��ˮ",
                "remaining": 6,
                "drunk_supply": 20,
        ]));
}
