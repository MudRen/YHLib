#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIR "����ʫѡ����" NOR, ({ "tangshi xuanji", "tangshi", "xuanji", "book" }));
        set_weight(500);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", HIR "һ����������������ʫѡ��\n" NOR);
                set("value", 500);
                set("material", "paper");
                set("skill",
                ([
                        "name" : "literate",
                        "jing_cost" : 5,
                        "difficulty" : 10,
                        "max_skill" : 9,
                        "min_skill" : 0,
                ]) );
        }
}
