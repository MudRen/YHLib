#include <ansi.h>
 
inherit ITEM;

void create()
{
        set_name(HIY "�����Ҿ�������" NOR, ({ "emei jiuyang", "emei", "jiuyang", "book" }));
        set_weight(500);
        if (clonep())
                destruct(this_object());
        else {
                set("unit", "��");
                set("long", HIG "����һ�������Ĳ��ӣ������Ѿ��е㿪ʼ���á�\n" NOR);
                set("value", 1);
                set("no_sell", "�Ȿ�������Լ����Űɡ�");
                set("material", "paper");
                set("skill", ([
                        "name"       : "emei-jiuyang",
                        "jing_cost"  : 100,
                        "difficulty" : 200,
                        "max_skill"  : 180,
                        "min_skill"  : 0
                ]));
        }
}
