#include <ansi.h>
 
inherit ITEM;

void create()
{
        set_name(HIG "���" NOR, ({ "zhu jian", "zhu", "jian" }));
        set_weight(500);
        if (clonep())
                destruct(this_object());
        else {
                set("unit", "��");
                set("long", HIG "һ��Ө��ɫ����򣬿����������Ѿ���Ϊ��Զ�ˡ���"
                            "��������\n����д����С�֣�Ҳ��֪��ʲô���ݡ�\n" NOR);
                set("value", 1);
                set("no_sell", "�����ߣ�ʲô�����⣿");
                set("material", "bamboo");
                set("skill", ([
                        "name" : "zhanshen-xinjing",
                        "exp_required" : 1500000,
                        "jing_cost"  : 120,
                        "difficulty" : 120,
                        "max_skill"  : 179,
                        "min_skill"  : 0,
                        "need" : ([ "muslim" : 250,
                                    "literate" : 250 ]),
                ]));
        }
}
