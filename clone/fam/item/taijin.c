#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(NOR + YEL "�ѽ���" NOR, ({"taijin zhu", "taijin", "zhu"}));
        set_weight(500);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", YEL "ǧ��һ����������ȡ��������֮��������������\n" NOR);
                set("unit", "��");
                set("value", 8000);
                set("item_origin", 1);
                set("material_attrib", "stone");
                set("material_name", NOR + YEL "�ѽ���" NOR);
                set("can_make", ({ "��", "��", "��", "��" }));
                set("power_point", 50);
        }
}

int query_autoload()
{
        return 1;
}

