#include <ansi.h>
 
inherit ITEM;

void create()
{
        set_name(HIR "��Ѫ������" NOR, ({ "xuedao jing", "xuedao", "jing", "book" }));
        set_weight(500);
        if (clonep())
                destruct(this_object());
        else {
                set("unit", "��");
                set("long", HIR "����һ����������ᣬ�����ϻ�Ȼд�š�Ѫ"
                            "�������������֡�\n" NOR);
                set("value", 1);
                set("no_sell", "Ѫ��Ѫ���������⡭�ò�����Ѫ���ŵĶ����ɣ�");
                set("material", "paper");
                set("skill", ([
                        "name" : "xuedao-dafa",
                        "exp_required" : 300000,
                        "jing_cost"  : 100,
                        "difficulty" : 80,
                        "max_skill"  : 179,
                        "min_skill"  : 10
                ]));
        }
}
