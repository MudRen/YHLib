#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIC "�����项" NOR, ({ "luo shu", "luo", "shu" }));
        set_weight(500);
        if (clonep())
                destruct(this_object());
        else {
                set("unit", "��");
                set("long", HIY "����һ���ñ���д�ɵ��顣������ֹ�׭��"
                            HIC "����" HIY "������Ƥ��Ȼ\n���ƣ������Ѿ�"
                            "����ܾ��ˡ�\n" NOR);
                set("value", 1);
                set("no_sell", "�ţ����õ�����ɶ�����⣿");
                set("material", "silk");
                set("skill", ([
                        "name" : "count",
                        "exp_required" : 1000000,
                        "jing_cost"  : 120,
                        "difficulty" : 120,
                        "max_skill"  : 299,
                        "min_skill"  : 200,
                        "need" : ([ "literate" : 300 ]),
                ]));
        }
}
