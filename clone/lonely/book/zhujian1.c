#include <ansi.h>
 
inherit ITEM;

void create()
{
        set_name(GRN "���" NOR, ({ "zhu jian", "zhu", "jian" }));
        set_weight(500);
        if (clonep())
                destruct(this_object());
        else {
                set("unit", "��");
                set("long", GRN "һ��ǳ��¾ɵ���򣬵������������ã��������"
                            "������д\n����С�֣�Ҳ��֪��ʲô���ݡ�\n" NOR);
                set("value", 1);
                set("no_sell", "�����ߣ�ʲô�����⣿");
                set("material", "bamboo");
                set("skill", ([
                        "name" : "leiting-fu",
                        "exp_required" : 1000000,
                        "jing_cost"  : 100,
                        "difficulty" : 100,
                        "max_skill"  : 299,
                        "min_skill"  : 0,
                        "need" : ([ "muslim" : 200 ]),
                ]));
        }
}
