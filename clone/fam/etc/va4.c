#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(HIW "����" NOR, ({ "zhen zhu", "zhen", "zhu" }));
        set_weight(1000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", HIW "����һ�Ż�Բ�����飬���ſ���"
                            "�����ü�Ǯ��\n");
                set("value", 100000);
                set("unit", "��");

        }
}
