#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(HIG "��ʯ" NOR, ({ "yu shi", "yu", "shi" }));
        set_weight(1000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", HIG "����һ���ϵȱ������ſ���"
                            "�����ü�Ǯ��\n");
                set("value", 160000);
                set("unit", "��");

        }
}
