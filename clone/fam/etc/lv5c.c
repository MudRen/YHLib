inherit ITEM;
#include <ansi.h>

void create()
{
        set_name(YEL "���̼" NOR, ({"tiangang tan", "tiangang", "tan"}));
        set_weight(300);
        if (clonep())
                set_default_object(__FILE__);
        else {
         	set("long", YEL "����ڼ������ĵ���̿���������������\n" NOR);
                set("unit", "��");
                set("value", 15000);
        }
        setup();
}

int query_autoload()
{
        return 1;
}

