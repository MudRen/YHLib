#include <weapon.h>
#include <ansi.h>

inherit HAMMER;

void create()
{
        set_name(CYN "������" NOR,({ "tie qipan", "tie", "qipan", "pan" }) );
        set_weight(10000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", CYN "һ�����������ɵ����̣��ǳ����ء�\n" NOR);
                set("unit", "��");
                set("value", 3000);
                set("no_sell", 1);
                set("material", "steel");
                set("stable", 80);
        }
        init_hammer(40);
        setup();
}

