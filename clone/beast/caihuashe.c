#include <ansi.h>
inherit SNAKE;

void create()
{
        set_name(HIC "�˻���" NOR, ({ "caihua she", "caihua", "she" }));
        set("long", HIC "����һֻ�����ĵĲ˻��ߣ�ͷ������Բ�Ρ�\n" NOR);

        set("age", 1);
        set("str", 15);
        set("dex", 16);
	set("max_qi", 200);
	set("max_jing", 200);
        set("combat_exp", 1000);

        set("power", 8);
        set("item1", "/clone/quarry/item/sherou");
        set("item2", "/clone/herb/shedan");

        set_temp("apply/dodge", 80);
        set_temp("apply/defense", 80);
        set_temp("apply/unarmed_damage", 50);

        setup();
}
