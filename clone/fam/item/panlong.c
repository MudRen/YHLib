#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(NOR + HIW "��������˿" NOR, ({"yinjiao si", "yinjiao", "si"}));
        set_weight(3800);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", HIW "����������������������ؽ������ƶ��ɣ�����������\n" NOR);
                set("unit", "��");
                set("value", 9000);
                set("item_origin", 1);
                set("material_attrib", "stone");
                set("material_name", NOR + HIW "��������˿" NOR);
                set("can_make", ({ "����", "ͷ��", "����" }));
                set("power_point", 60);
        }
}

int query_autoload()
{
        return 1;
}

