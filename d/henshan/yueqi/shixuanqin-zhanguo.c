#include <ansi.h>
#include <music.h>

inherit ITEM;
inherit MI_QIN;

void create()
{
        set_name(YEL "ʮ�����١�ս��" NOR, ({ "shixuan qin", "shixuan", "qin" }));
        set_weight(700);

	if (clonep())
		set_default_object(__FILE__);
	else {
                set("unit", "��");
                set("long", YEL "���������ܿ������й������������������\n"
				"������ս��������Ĺ֮�У��ٳ�67���֣���\n" 
				"��������¡�\n" NOR);
		set("value", 100000);
		set("material", "wood");
	}
	setup();
}

void init()
{
        add_action("play_qin", "play");
}
