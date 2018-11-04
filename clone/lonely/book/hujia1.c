#include <ansi.h>
 
inherit ITEM;

void create()
{
        set_name(WHT "������ȭ����" NOR, ({ "hujia quanjing", "hujia", "quanjing", "jing", "book" }));
        set_weight(500);
        if (clonep())
                destruct(this_object());
        else {
                set("unit", "��");
                set("long", WHT "����һ����������ᣬ��Ƥ��Ȼ���ƣ���"
                            "�����Ѿ���һ����ʷ�ˡ�\n" NOR);
                set("value", 1);
                set("no_sell", "���̵ģ��Ȿ����Ҳ����Ǯ��");
                set("material", "paper");
                set("skill", ([
                        "name" : "hujia-quan",
                        "exp_required" : 10000,
                        "jing_cost"  : 100,
                        "difficulty" : 40,
                        "max_skill"  : 119,
                        "min_skill"  : 0
                ]));
        }
}
