#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(NOR + CYN "����ʯ" NOR, ({"zhenlong shi", "zhenlong", "shi"}));
        set_weight(8000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", CYN "��˵��ʯ���������ʳ�������ס�������ã����Ѱ����\n" NOR);
                set("unit", "��");
                set("value", 9000);
                set("item_origin", 1);
                set("material_attrib", "stone");
                set("material_name", NOR + CYN "����ʯ" NOR);
                set("can_make", ({ "��", "��", "��", "�̱�", "��", "��", "��" }));
                set("power_point", 60);
        }
}

int query_autoload()
{
        return 1;
}

