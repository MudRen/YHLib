#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(NOR + MAG "�Ͻ��" NOR, ({"zijin kuang", "zijin", "kuang"}));
        set_weight(1800);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", MAG "����һ�鼫Ϊ�������Ͻ��ʯ��������������ֵ���ǡ�\n" NOR);
                set("unit", "��");
                set("value", 8000);
                set("item_origin", 1);
                set("material_attrib", "stone");
                set("material_name", NOR + MAG "�Ͻ��" NOR);
                set("can_make", ({ "����", "ͷ��", "����" }));
                set("power_point", 50);
        }
}

int query_autoload()
{
        return 1;
}

