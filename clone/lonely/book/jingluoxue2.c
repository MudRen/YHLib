#include <ansi.h>
 
inherit ITEM;

void create()
{
        set_name(HIW "����ȧ��������" NOR, ({ "yuquan jing", "yuquan", "jing", "book" }));
        set_weight(500);
        if (clonep())
                destruct(this_object());
        else {
                set("unit", "��");
                set("long", HIW "����һ����װ��ᣬ��ҳ��Ȼ���ƣ���"
                            "Ƥ��д�š���ȧ������������֡�\n" NOR);
                set("value", 1);
                set("no_sell", "���̵ģ��Ȿ����Ҳ����Ǯ��");
                set("material", "paper");
                set("skill", ([
                        "name" : "jingluo-xue",
                        "exp_required" : 600000,
                        "jing_cost"  : 90,
                        "difficulty" : 65,
                        "max_skill"  : 200,
                        "min_skill"  : 149
                ]));
        }
}
