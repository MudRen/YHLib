#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(NOR + MAG "������" NOR, ({"zixiao jue", "zixiao", "jue"}));
        set_weight(500);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", MAG "���Լ�ǿ�ĳ�У����л��в������˿��\n" NOR);
                set("unit", "��");
                set("value", 8000);
                set("item_origin", 1);
                set("material_attrib", "stone");
                set("material_name", NOR + MAG "������" NOR);
                set("can_make", ({ "ս��", "����", "����", "ѥ��" }));
                set("power_point", 50);
        }
}

int query_autoload()
{
        return 1;
}

