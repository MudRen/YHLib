#include <ansi.h>
 
inherit ITEM;

void create()
{
        set_name(WHT "�����ҵ��ס�" NOR, ({ "hujia daopu", "hujia", "daopu", "pu", "book" }));
        set_weight(500);
        if (clonep())
                destruct(this_object());
        else {
                set("unit", "��");
                set("long", WHT "����һ����������ᣬ��Ƥ��Ȼ���ƣ���"
                            "����д�š����ҵ��ס��ĸ��֡�\n" NOR);
                set("value", 1);
                set("no_sell", "���̵ģ��Ȿ����Ҳ����Ǯ��");
                set("material", "paper");
                set("skill", ([
                        "name" : "blade",
                        "exp_required" : 30000,
                        "jing_cost"  : 120,
                        "difficulty" : 70,
                        "max_skill"  : 179,
                        "min_skill"  : 0
                ]));
        }
}
