#include <ansi.h>; 
inherit ITEM;

void create()
{
        set_name(WHT "�������澭���ر�" NOR, ({ "zhenjing taben", "taben",
                                                "zhenjing", "jing" }));
        set_weight(500);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("no_sell", "����Ǯ����ˣ���Ҳ������Ǯ��");
                set("long", WHT "����һ����Ƭ���������������������С�֡�\n" NOR);
                set("material", "paper");
                set("skill", ([
                        "name":        "force",
                        "exp_required" : 100000,
                        "jing_cost"    : 80,
                        "difficulty"   : 50,
                        "max_skill"    : 199,
                        "min_skill"    : 100
                ]));
        }
}
