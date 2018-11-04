#include <ansi.h>
#include <music.h>

inherit ITEM;
inherit MI_QIN;

void create()
{
        set_name(NOR + YEL "̴ľ��" NOR, ({ "tanmu qin", "tanmu", "qin" }));
        set_weight(600);

	if (clonep())
		set_default_object(__FILE__);
	else {
                set("unit", "��");
                set("long", NOR + YEL "һ��̴ľ���Ƶ�ľ�٣��ŵ����¡�\n" NOR);
		set("value", 50);
		set("material", "wood");
	}
	setup();
}

void init()
{
        add_action("play_qin", "play");
}
