inherit ITEM;
#include <ansi.h>

void create()
{
        set_name(HIR "������" NOR, ({"binghuo zhu", "binghuo", "zhu"}));
        set_weight(300);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", HIR "ȭͷ��С��Բ�α��飬��������ֻ��������ȡ�\n" NOR);
                set("unit", "��");
                set("value", 9000);
                set("can_be_enchased", 1);
                set("magic/type", "fire");
                set("magic/power", 60 + random(11));
        }
        setup();
}

int query_autoload()
{
        return 1;
}

