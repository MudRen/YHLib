#include <ansi.h>
 
inherit ITEM;

void create()
{
        set_name(YEL "����ҽ��ס��ϲ�" NOR, ({ "miaojia jianpu", "miaojia", "jianpu", "pu", "book" }));
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
                        "name":       "suqin-beijian",
                        "exp_required" : 10000,
                        "jing_cost":  100,
                        "difficulty": 40,
                        "max_skill":  119,
                        "min_skill":  0
                ]));
        }
}
