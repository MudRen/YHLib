#include <ansi.h>
 
inherit ITEM;

void create()
{
        set_name(YEL "����ҽ��ס��²�" NOR, ({ "miaojia jianpu", "miaojia", "jianpu", "pu", "book" }));
        set_weight(500);
        if (clonep())
                destruct(this_object());
        else {
                set("unit", "��");
                set("long", YEL "����һ����������ᣬ��Ƥ��Ȼ���ƣ���"
                            "����д�š���ҽ��ס��ĸ��֡�\n" NOR);
                set("value", 1);
                set("no_sell", "���硭��ҡ�����������˼��ҿɵ��ﲻ��");
                set("material", "paper");
                set("skill", ([
                        "name" : "sword",
                        "exp_required" : 300000,
                        "jing_cost"  : 120,
                        "difficulty" : 80,
                        "max_skill"  : 199,
                        "min_skill"  : 150
                ]));
        }
}
