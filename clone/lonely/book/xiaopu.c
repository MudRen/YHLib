#include <ansi.h>
 
inherit ITEM;

void create()
{
        set_name(HIG "�����ס�" NOR, ({ "xiao pu", "xiao", "pu", "shu", "book" }));
        set_weight(500);
        if (clonep())
                destruct(this_object());
        else {
                set("unit", "��");
                set("long", HIG "����һ�����������ף�������һЩ����ķ�����\n" NOR);
                set("value", 1);
                set("no_sell", "�Ȿ�������Լ����Űɡ�");
                set("material", "paper");
                set("skill", ([
                        "name"       : "chuixiao-jifa",
                        "jing_cost"  : 30,
                        "difficulty" : 30,
                        "max_skill"  : 149,
                        "min_skill"  : 0
                ]));
        }
}
