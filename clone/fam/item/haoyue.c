#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(NOR + HIY "��½�ɰ" NOR, ({"haoyue jinsha", "haoyue", "jinsha", "sha"}));
        set_weight(4000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", HIY "��ϫ֮���ɺ�Ԩ���ɳ��Ľ�ɰ��������������������ı��\n" NOR);
                set("unit", "��");
                set("value", 10000);
                set("item_origin", 1);
                set("material_attrib", "stone");
                set("material_name", NOR + HIY "��½�ɰ" NOR);
                set("can_make", ({ "����", "ͷ��", "����" }));
                set("power_point", 70);
        }
}

int query_autoload()
{
        return 1;
}

