#include <ansi.h>
#include <music.h>

inherit ITEM;
inherit MI_QIN;

void create()
{
        set_name(HIY "̴ľ����" NOR, ({ "tanmu huqin", "qin", "huqin", "tanmu" }));
        set_weight(800);

	if (clonep())
		set_default_object(__FILE__);
	else {
                set("unit", "��");
                set("long", HIY "һ�Ѿ��µ�̴ľ���١�\n" NOR);
		set("value", 1000);
		set("material", "wood");
	}
	setup();
}

void init()
{
        add_action("play_qin", "play");
}
