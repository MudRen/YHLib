#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(HIW "��ʯ" NOR, ({ "zuan shi", "zuan", "shi" }));
        set_weight(1000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", HIW "����һ���ϵ���ʯ�����ſ���"
                            "�����ü�Ǯ��\n");
                set("value", 200000);
                set("unit", "��");
        }
}
