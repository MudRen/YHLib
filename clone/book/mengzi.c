#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(WHT "�����ӡ�" NOR, ({ "mengzi book", "shu", "mengzi", "book" }));
        set_weight(300);

        if (clonep())
                set_default_object(__FILE__);
        else
        {
                set("unit", "��");
                set("long", WHT "�Ȿ������˵�����������������ۣ�����Ҿ����鼮��\n" NOR);
                set("value", 100);
                set("no_sell", "�⡭��ֵʲôǮ��\n");
                set("material", "paper");
                set("skill", ([
                        "name" : "literate",
                        "jing_cost"  :   100,
                        "difficulty" :   60,
                        "max_skill"  :   299,
                        "min_skill"  :   150,
                ]));
        }
}
