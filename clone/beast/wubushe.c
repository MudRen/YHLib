#include <ansi.h>
inherit SNAKE;

void create()
{
        set_name(HIG "�岽��" NOR, ({ "wubu she", "wubu", "she" }));
        set("long", HIG "�岽���Ǹ����ط����ߣ��ഫ�ж���·�岽���е��С�\n" NOR);

        set("age", 1);
        set("str", 15);
        set("dex", 40);
        set("max_qi", 700);
        set("max_ging", 700);
        set("combat_exp", 10000);

        set("snake_poison", ([
                "level"  : 50,
                "perhit" : 25,
                "remain" : 50,
                "maximum": 50,
                "supply" : 2,
        ]));

        set("power", 20);
        set("item1", "/clone/quarry/item/sherou");
        set("item2", "/clone/herb/shedan");

        set_temp("apply/dodge", 120);
        set_temp("apply/defense", 120);
        set_temp("apply/unarmed_damage", 80);
        set_temp("apply/armor", 120);

        setup();
}
