#include <ansi.h>

inherit ITEM;
inherit F_LIQUID;

void create()
{
        set_name(WHT "�ִŴ���" NOR, ({"wan", "dawan", "cha"}));
        set_weight(50);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", WHT "һ�����ߴִŴ��롣\n" NOR);
                set("unit", "��");
                set("value", 0);
                set("max_liquid", 4);
        }

        set("liquid", ([
                "type": "tea",
                "name": "��ˮ",
                "remaining" : 4,
                "drunk_supply" : 0,
        ]));
}
