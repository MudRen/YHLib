#include <ansi.h>
inherit ITEM;

inherit F_LIQUID;

void create()
{
        set_name(NOR + YEL "ţƤˮ��" NOR, ({ "shui dai", "shui", "dai" }));
        set_weight(5000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", NOR + YEL "����һ֧�ش�ŵ�ţƤˮ��������"
                            "�൱��������������������ԽɳĮ��\n" NOR);
                set("unit", "֧");
                set("value", 5000);
                set("max_liquid", 800);
        }
        set("liquid", ([
                "type"         : "water",
                "name"         : "��ˮ",
                "remaining"    : 300,
                "drunk_supply" : 300,
        ]));
}
