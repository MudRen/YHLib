#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(YEL "����̨��Ҫ��" NOR, ({ "medical book6", "medical", "book6" }));
        set_weight(500);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", YEL "����������ҽѧ���䣬�����˸���������֢�����Ʒ�����\n" NOR);
                set("value", 5000);
                set("material", "paper");
                set("skill",
                ([
                        "name" : "medical",
                        "jing_cost"  : 80,
                        "difficulty" : 60,
                        "max_skill"  : 179,
                        "min_skill"  : 150,
                ]) );
        }
}
