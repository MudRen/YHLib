inherit ITEM;
#include <ansi.h>

void create()
{
        set_name(HIB "������" NOR, ({"qinglong ya", "qinglong", "ya"}));
        set_weight(300);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", HIB "ͨ�������ĵ�����״���壬��˵���������ݡ�\n" NOR);
                set("unit", "��");
                set("value", 50000);
                set("can_be_enchased", 1);
                set("magic/type", "magic");
                set("magic/power", 35 + random(16));
        }
        setup();
}

int query_autoload()
{
        return 1;
}

