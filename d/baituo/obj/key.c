#include <ansi.h> 
inherit ITEM;

void create()
{
        set_name(NOR + YEL "Կ��" NOR, ({ "key" }));
        set_weight(100);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", YEL "����һ����ͨ��ͭԿ�ס�\n" NOR);
                set("value", 0);
                set("material", "iron");
        }
}
