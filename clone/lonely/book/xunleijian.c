#include <ansi.h>
 
inherit ITEM;

void create()
{
        set_name(WHT "��Ѹ�׽�����" NOR, ({ "xunlei jianjing", "jianjing", "xunlei", "jing", "book" }));
        set_weight(500);
        if (clonep())
                destruct(this_object());
        else {
                set("unit", "��");
                set("long", WHT "����һ����������ᣬ��Ƥ��Ȼ��"
                            "�ƣ��������Ѿ���һ����ʷ�ˡ�\n" NOR);
                set("value", 1);
                set("no_sell", "�Ȿ�������Լ����Űɡ�");
                set("material", "paper");
                set("skill", ([
                        "name":       "xunlei-jian",
                        "jing_cost":  100,
                        "difficulty": 30,
                        "max_skill":  119,
                        "min_skill":  0
                ]));
        }
}
