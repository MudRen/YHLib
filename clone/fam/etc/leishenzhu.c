inherit ITEM;
#include <ansi.h>

void create()
{
        set_name(HIM "������"  NOR, ({"leishen zhu", "leishen", "zhu"}));
        set_weight(300);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", HIM "һ��Բ�ε����飬͸���ѤĿ�Ĺ�â��\n" NOR);
                set("unit", "��");
                set("value", 9000);
                set("can_be_enchased", 1);
                set("magic/type", "lighting");
                set("magic/power", 55 + random(16));
        }
        setup();
}

int query_autoload()
{
        return 1;
}

