#include <ansi.h>
inherit ITEM;

inherit F_LIQUID;

void create()
{
        set_name(HIW "�}��" NOR, ({ "god cup", "god", "cup" }));
        set_weight(1000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", HIW "���y���Ƶ��}�����ƺ������u���Ãr�X��\n" NOR);
                set("unit", "�b");
                set("value", 500000);
                set("max_liquid", 100);
        }
        set("liquid", ([
                "type"        : "water",
                "name"        : HIW "�}ˮ" NOR,
                "remaining"   : 100,
                "drunk_supply": 100,
        ]));
}

int query_autoload()
{
        return 1;
}