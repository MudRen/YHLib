#include <ansi.h>
#include <music.h>

inherit ITEM;
inherit MI_QIN;

void create()
{
        set_name(RED "��ľ���١�����" NOR, ({ "hongmu huqin", "qin", "huqin", "hongmu" }));
        set_weight(800);

	if (clonep())
		set_default_object(__FILE__);
	else {
                set("unit", "��");
                set("long", RED "һ�Ѿ��µĺ�ľ���٣�����⻬��΢����⡣\n" NOR);
		set("value", 2000);
		set("material", "wood");
	}
	setup();
}

void init()
{
        add_action("play_qin", "play");
}
