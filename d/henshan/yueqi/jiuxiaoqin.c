#include <ansi.h>
#include <music.h>

inherit ITEM;
inherit MI_QIN;

void create()
{
        set_name(MAG "�������塤�Ƴ�" NOR, ({ "jiuxiao qin", "jiuxiao", "qin" }));
        set_weight(600);

	if (clonep())
		set_default_object(__FILE__);
	else {
                set("unit", "��");
                set("long", MAG "������ʷ���ƾõĴ���֮�٣�ʢ�ƿ�Ԫ֮����\n"
                                "�������履�����������ᣬ������ɰ��֮  \n"
                                "ɫ���������ξ�ѣ�Ϊ����֮���ļ�Ʒ��\n" NOR);

		set("value", 400000);
		set("material", "wood");
	     }
	setup();
}

void init()
{
        add_action("play_qin", "play");
}
