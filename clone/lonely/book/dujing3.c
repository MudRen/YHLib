#include <ansi.h> 
inherit ITEM;

void create()
{
        set_name(NOR + WHT "��������ƪ��" NOR, ({ "du jing3", "jing3", "book3" }));
        set_weight(500);
        if (clonep())
                destruct(this_object());
        else {
                set("unit", "��");
                set("long", WHT "����һ��������С�ᣬ����������嶾����"
                            "�е��ö��ķ��š�\n" NOR);
                set("value", 100);
                set("no_sell", "�ҡ��ҵ��졭���嶾�̵Ķ����㶼����������");
                set("material", "silk");
                set("skill", ([
                        "name"         : "wudu-qishu",
                        "exp_required" : 150000,
                        "jing_cost"    : 50,
                        "difficulty"   : 50,
                        "min_skill"    : 50,
                        "max_skill"    : 149,
                ]));
        }
}
