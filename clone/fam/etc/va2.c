#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(HIC "���" NOR, ({ "fei cui", "fei", "cui" }));
        set_weight(1000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", HIC "����һ���ϵ���䣬���ſ���"
                            "�����ü�Ǯ��\n");
                set("value", 180000);
                set("unit", "��");
        }
}
