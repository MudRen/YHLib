#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIW "���ǫF֮��" NOR, ({ "unicorn horn", "unicorn", "horn" }));
        set_weight(1000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", HIW "���ǫF�Ľǣ��ƺ������u���Ãr�X��\n" NOR);
                set("unit", "��");
                set("value", 700000);
        }
        setup();
}
