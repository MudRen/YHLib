#include <ansi.h> 
inherit ITEM;

void create()
{
        set_name(YEL "��������ƪ��" NOR, ({ "du jing2", "jing2", "book2" }));
        set_weight(500);
        if (clonep())
                destruct(this_object());
        else {
                set("unit", "��");
                set("long", YEL "����һ��������С�ᣬ������������ļ���"
                            "�˸����ö��ķ��š�\n" NOR);
                set("value", 100);
                set("no_sell", "�ҡ��ҵ��졭���嶾�̵Ķ����㶼����������");
                set("material", "silk");
                set("skill", ([
                        "name"         : "poison",
                        "exp_required" : 100000,
                        "jing_cost"    : 50,
                        "difficulty"   : 50,
                        "min_skill"    : 50,
                        "max_skill"    : 119,
                ]));
        }
}
