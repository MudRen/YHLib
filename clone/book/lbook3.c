#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(YEL "��ǧ���ġ�" NOR, ({ "literate book3", "literate", "book3" }));
        set_weight(500);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", YEL "�����˱ض���ǧ���ġ�\n" NOR);
                set("value", 20000);
                set("material", "paper");
                set("skill",
                ([
                        "name": "literate",
                        "jing_cost":    20,
                        "difficulty":   20,
                        "max_skill":    99,
                        "min_skill":    50,
                ]) );
        }
}

