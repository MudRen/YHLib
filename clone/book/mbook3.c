#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(YEL "����٢����ͼ��" NOR, ({ "medical book3", "medical", "book3" }));
        set_weight(500);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", YEL "��ҽ��٢������ҽ�飬�ں����ҽѧ��Ҫ��\n" NOR);
                set("value", 30000);
                set("material", "paper");
                set("skill",
                ([
                        "name" : "medical",
                        "jing_cost"  : 45,
                        "difficulty" : 40,
                        "max_skill"  : 79,
                        "min_skill"  : 50,
                ]) );
        }
}
