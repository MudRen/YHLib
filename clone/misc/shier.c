// shier.c ʳ��

#include <ansi.h>

inherit COMBINED_ITEM;

void create()
{
        set_name("ʳ��", ({ "shi er", "shi", "er" }));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "�������˳��õ��ն���\n");
                set("base_unit", "��");
                set("base_weight", 50);
                set("base_value", 10);
                set("no_sell", "��ɶ�����ֲ����ԣ�Ҫ��Щ����������");
                set("unit", "Щ");
        }
        set_amount(1);
        setup();
}
