#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(NOR + YEL "���" NOR, ({ "jin kuai", "jin", "kuai" }));
        set_weight(2000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", NOR + YEL "����һ���ƳγεĽ�飬����"
                            "���������ü�Ǯ��\n");
                set("value", 150000);
                set("unit", "��");
        }
}
