#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(YEL "���Ƶ��ھ���" NOR, ({ "medical book2", "medical", "book2" }));
        set_weight(500);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", YEL "�Ƶ��ھ�����������������ҽ�顣\n" NOR);
                set("value", 10000);
                set("material", "paper");
                set("skill",
                ([
                        "name" : "medical",
                        "jing_cost"  : 25,
                        "difficulty" : 30,
                        "max_skill"  : 49,
                        "min_skill"  : 30,
                ]) );
        }
}
