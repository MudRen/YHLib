#include <ansi.h>
#include <music.h>

inherit ITEM;
inherit MI_XIAO;

void create()
{
        set_name(HIG "������������" NOR, ({ "qingyin xiao", "qingyin", "xiao" }));
        set_weight(600);

	if (clonep())
		set_default_object(__FILE__);
	else {
                set("unit", "��");
                set("long", HIG "һ�ѱ������ƵĶ���������������"
		    "�⡣�Ͽ̡�" HIB "����" HIG "����\n" NOR);
		set("value", 5000000);
		set("material", "stone");
	}
	setup();
}

void init()
{
        add_action("play_xiao", "play");
}
