#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(YEL "��ǧ�𷽡�" NOR, ({ "medical book4", "medical", "book4" }));
        set_weight(500);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", YEL "��˼��������ҽ�飬�������������ѧ˵��\n" NOR);
                set("value", 50000);
                set("material", "paper");
                set("skill",
                ([
                        "name" : "medical",
                        "jing_cost"  : 55,
                        "difficulty" : 45,
                        "max_skill"  : 119,
                        "min_skill"  : 80,
                ]));
        }
}
