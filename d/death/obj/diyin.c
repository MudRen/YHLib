#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(RED "����Ѫ��" NOR, ({ "diyin xuemai", "diyin", " xuemai"}));
        set_weight(700);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", RED "һ������Ŀ�ʯ,ɢ��������Ѫ�⡣\n" NOR);
                set("unit", "��");
                set("value", 20000);
        }
}
