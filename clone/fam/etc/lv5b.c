inherit ITEM;
#include <ansi.h>

void create()
{
        set_name(HIC "������" NOR, ({"qingyu ya", "qingyu", "ya"}));
        set_weight(300);
        if (clonep())
                set_default_object(__FILE__);
        else {
         	set("long", HIC "����һ��С�����解���ν��ֵ���ǡ�\n" NOR);
                set("unit", "ֻ");
                set("value", 15000);
        }
        setup();
}

int query_autoload()
{
        return 1;
}

