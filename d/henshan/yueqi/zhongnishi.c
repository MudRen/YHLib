#include <ansi.h>
#include <music.h>

inherit ITEM;
inherit MI_QIN;

void create()
{
        set_name(HIC "����ʽ�١��γ�" NOR, ({ "zhongni qin", "zhongni", "qin" }));
        set_weight(500);

	if (clonep())
		set_default_object(__FILE__);
	else {
                set("unit", "��");
  			   
                set("long", HIC "�����������������죬�������洹����\n"
                                "���޺��ȣ���ɫ���̣�΢���̹⣬����ʽ��\n"
                                "ΪԪ��������\n" NOR);
		set("value", 200000);
		set("material", "wood");
	     }
	setup();
}

void init()
{
        add_action("play_qin", "play");
}
