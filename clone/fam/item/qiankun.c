#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(HIG "Ǭ" HIW "��" HIY "ʯ" NOR, ({"qiankun shi", "qiankun", "shi"}));
        set_weight(3000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", HIW "����һ�龧Ө��͸�ı�ʯ��ʯ��⻪"
                            "��ת�����ƻ���һ�㡣\n" NOR);
                set("unit", "��");
                set("value", 30000);
                set("item_origin", 1);
                set("material_attrib", "stone");
                set("material_name", HIG "Ǭ" HIW "��" HIY "ʯ" NOR);
                set("can_make", ({ "����" }));
                set("power_point", 100);
        }
}

int query_autoload()
{
        return 1;
}

