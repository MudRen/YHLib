#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(YEL "���ټ��ա�" NOR, ({ "literate book2", "literate", "book2" }));
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);                                   
        else
        { 
               set("unit", "��");
                set("long", YEL "�����˱ض��İټ��ա�\n" NOR);
                set("value", 5000);
                set("material", "paper");
                set("skill",
                ([
                        "name": "literate",
                        "jing_cost":    25,
                        "difficulty":   20,
                        "max_skill":    49,
                        "min_skill":    30,
                ]) );
        }
}
