#include <ansi.h>
#include <music.h>

inherit ITEM;
inherit MI_QIN;

void create()
{
        set_name(WHT "������������į" NOR, ({ "jimo qin", "jimo", "qin" }));
        set_weight(1000);

	if (clonep())
		set_default_object(__FILE__);
	else {
                set("unit", "��");
                set("long", WHT "����ͨ�巺�����⣬ҫ�۶�"
				"Ŀ���Ͽ̡�" HIY "��į" WHT "����\n" NOR);
		set("value", 5000000);
		set("material", "wood");
	}
	setup();
}

void init()
{
        add_action("play_qin", "play");
}
