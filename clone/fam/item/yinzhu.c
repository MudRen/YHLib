#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(NOR + HIW "����˿" NOR, ({"yinzhu si", "yinzhu", "si"}));
        set_weight(800);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", HIW "��ѩɽ����������˿��ǿ�ͼ�̣���Ϊ���\n" NOR);
                set("unit", "��");
                set("value", 10000);
                set("item_origin", 1);
                set("material_attrib", "stone");
                set("material_name", NOR + HIW "����˿" NOR);
                set("can_make", ({ "����", "ս��", "����", "����", "ѥ��", "��" }));
                set("power_point", 70);
        }
}

int query_autoload()
{
        return 1;
}

