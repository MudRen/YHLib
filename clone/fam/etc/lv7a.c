inherit ITEM;
#include <ansi.h>

void create()
{
        set_name(HIW "��" HIR "��" HIY "��" HIG "��" HIM "��" NOR, ({"wucai zhu", "wucai", "zhu"}));
        set_weight(300);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", HIM "���������ı��飬������������ɫ��â��\n" NOR);
                set("unit", "��");
                set("value", 50000);
                set("can_be_enchased", 1);
                set("magic/type", "lighting");
                set("magic/power", 35 + random(16));

        }
        setup();
}

int query_autoload()
{
        return 1;
}

