inherit ITEM;
inherit F_LIQUID;
#include <ansi.h>
void create()
{
        set_name(GRN"�ִ���"NOR, ({"wan"}));
        set_weight(50);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "һ���������ڵ��ࡣ\n");
                set("unit", "��");
                set("value", 20);
                set("max_liquid", 20);
    }

    set("liquid", ([
        "type": "water",
        "name": "����",
        "remaining": 20,
        "drunk_supply": 40,
    ]));
}

