#include <ansi.h>
#include <music.h>

inherit ITEM;
inherit MI_XIAO;

void create()
{
        set_name(GRN "��ͨ����" NOR, ({ "zhu xiao", "zhu", "xiao" }));
        set_weight(600);

	if (clonep())
		set_default_object(__FILE__);
	else {
                set("unit", "��");
                set("long", GRN "һ�Ѵ������ƵĶ������ǳ���ͨ��\n" NOR);
		set("value", 200);
		set("material", "bamboo");
	}
	setup();
}

void init()
{
        add_action("play_xiao", "play");
}
