#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(YEL "�����־���" NOR, ({ "literate book1", "literate", "book1" }));
        set_weight(500);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", YEL "�����˱ض������־���\n" NOR);
                set("value", 1000);
                set("material", "paper");
                set("skill",
                ([
                        "name": "literate",
                        "jing_cost":    15,
                        "difficulty":   25,
                        "max_skill":    29,
                        "min_skill":    10,
                ]) );
        }
}
