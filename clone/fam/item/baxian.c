#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(NOR + HIW "����ʯ" NOR, ({"baxian shi", "baxian", "shi"}));
        set_weight(1000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", HIW "����һ�龧Ө��͸����ʯ���⻪���󣬴��ֱ�����\n" NOR);
                set("unit", "��");
                set("value", 10000);
                set("item_origin", 1);
                set("material_attrib", "stone");
                set("material_name", NOR + HIW "����ʯ" NOR);
                set("can_make", ({ "ָ��" }));
                set("power_point", 70);
        }
}

int query_autoload()
{
        return 1;
}

