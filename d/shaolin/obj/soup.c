inherit ITEM;
inherit F_LIQUID;

#include <ansi.h>

void create()
{
        set_name(GRN "��˷�˿��" NOR, ({"soup"}));
        set_weight(50);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "һ�������˱ǵ���˷�˿����\n");
                set("unit", "��");
                set("value", 160);
                set("max_liquid", 8);
        }

        set("liquid", ([
                "type": "water",
                "name": "��˷�˿��",
                "remaining": 12,
                "drunk_supply": 40,
        ]));
}
