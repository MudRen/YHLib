#include <ansi.h>
 
inherit ITEM;

void create()
{
        set_name(HIR "�����÷�ָ��" NOR, ({ "tianzhu zhi", "tianzhu", "zhi", "book" }));
        set_weight(500);
        if (clonep())
                destruct(this_object());
        else {
                set("unit", "��");
                set("long", HIY "����һ����������ᣬ��Ƥ����ȥ���£�����"
                            "���³�д�ģ�������д�š����÷�ָ���ĸ��֡�\n" NOR);
                set("value", 1);
                set("no_sell", 1);
                set("material", "paper");
                set("skill", ([
                        "name":       "tianzhu-fuzhi",
                        "exp_required" : 100000,
                        "jing_cost":  60,
                        "difficulty": 50,
                        "max_skill":  1,
                        "min_skill":  0
                ]));
        }
}
