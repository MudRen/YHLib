#include <ansi.h>
 
inherit ITEM;

void create()
{
        set_name(HIM "������ָ��" NOR, ({ "lianhua zhi", "lianhua", "zhi", "book" }));
        set_weight(500);
        if (clonep())
                destruct(this_object());
        else {
                set("unit", "��");
                set("long", YEL "����һ����������ᣬ��Ƥ��Ȼ���ƣ���"
                            "����д�š�����ָ�������֡�\n" NOR);
                set("value", 1);
                set("no_sell", 1);
                set("material", "paper");
                set("skill", ([
                        "name":       "lianhua-zhi",
                        "exp_required" : 100000,
                        "jing_cost":  60,
                        "difficulty": 50,
                        "max_skill":  1,
                        "min_skill":  0
                ]));
        }
}
