#include <ansi.h>
 
inherit ITEM;

void create()
{
        set_name(HIY "�������������" NOR, ({ "mai jing", "mai", "jing", "book" }));
        set_weight(500);
        if (clonep())
                destruct(this_object());
        else {
                set("unit", "��");
                set("long", HIY "����һ����װ��ᣬ��ҳ��Ȼ���ƣ���"
                            "Ƥ��д�š����������������֡�\n" NOR);
                set("value", 1);
                set("no_sell", "���̵ģ��Ȿ����Ҳ����Ǯ��");
                set("material", "paper");
                set("skill", ([
                        "name" : "jingluo-xue",
                        "exp_required" : 10000,
                        "jing_cost"  : 80,
                        "difficulty" : 50,
                        "max_skill"  : 149,
                        "min_skill"  : 0
                ]));
        }
}
