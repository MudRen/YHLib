#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(NOR + CYN "����ʯ" NOR, ({"handan shi", "handan", "shi"}));
        set_weight(1000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", CYN "����һ��ͨ���ںڵ�ʯͷ�����ִ������⻬��\n" NOR);
                set("unit", "��");
                set("value", 8000);
                set("item_origin", 1);
                set("material_attrib", "stone");
                set("material_name", NOR + CYN "����ʯ" NOR);
                set("can_make", ({ "ָ��" }));
                set("power_point", 50);
        }
}

int query_autoload()
{
        return 1;
}

