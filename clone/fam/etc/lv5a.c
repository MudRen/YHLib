inherit ITEM;
#include <ansi.h>

void create()
{
        set_name(HIC "�����" NOR, ({"tiancan yu", "tiancan", "yu"}));
        set_weight(300);
        if (clonep())
                set_default_object(__FILE__);
        else {
         	set("long", HIC "����һ�龧Ө��͸�Ĺ�������ޱȡ�\n" NOR);
                set("unit", "��");
                set("value", 15000);
        }
        setup();
}

int query_autoload()
{
        return 1;
}

