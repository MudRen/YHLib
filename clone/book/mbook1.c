#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(YEL "�����ݸ�Ŀ��" NOR, ({ "medical book1", "medical", "book1" }));
        set_weight(500);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", YEL "���ݸ�Ŀ����������������ҽ�顣\n" NOR);
                set("value", 8000);
                set("material", "paper");
                set("skill",
                ([
                        "name" : "medical",
                        "jing_cost"  : 15,
                        "difficulty" : 20,
                        "max_skill"  : 29,
                        "min_skill"  : 0,
                ]) );
        }
}
