inherit SNAKE;
#include <ansi.h>

void create()
{
        set_name(HIG "����" NOR, ({ "mang she", "mang", "she" }));
        set("long", HIG "����һֻ����ֱ�������ų���о�Ĵ����ߡ�\n" NOR);

        set("age", 6);
        set("str", 50);
        set("dex", 20);
        set("con", 50);
	set("max_qi", 5000);
	set("max_jing", 5000);
        set("neili", 3000);
        set("max_neili", 3000);
        set("combat_exp", 300000);

        set("power", 45);
        set("item1", "/clone/quarry/item/sherou");
        set("item2", "/clone/quarry/item/shepi");

        set_temp("apply/force", 200);
        set_temp("apply/parry", 200);
        set_temp("apply/dodge", 200);
        set_temp("apply/attack", 180);
        set_temp("apply/defense", 180);
        set_temp("apply/unarmed_damage", 220);
        set_temp("apply/armor", 220);

        setup();
}