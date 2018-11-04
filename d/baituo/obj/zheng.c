// zheng.c

#include <ansi.h>
#include <music.h>

inherit ITEM;
inherit MI_ZHENG;

void create()
{
        set_name(NOR + YEL "����" NOR, ({ "gu zheng", "gu", "zheng" }));
        set_weight(300);

	if (clonep())
		set_default_object(__FILE__);
	else {
                set("unit", "̨");
                set("long", YEL "����һ̨����ȥ��Щ�¾ɵĹ��ݡ�\n" NOR);
		set("value", 50);
		set("material", "wood");
	}
	setup();
}

void init()
{
        add_action("play_zheng", "play");
}
