#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(HIM "���" NOR, ({ "ma nao", "ma", "nao" }));
        set_weight(1000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", HIM "����һ���ϵ���解����ſ���"
                            "�����ü�Ǯ��\n");
                set("value", 120000);
                set("unit", "��");

        }
}
