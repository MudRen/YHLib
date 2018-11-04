#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�����ǹ���ׯ������һ�����¸����������æ��æȥ����
������������ĳ����ˡ�������ҳ���Ҫ(serve)Щ�Եġ�
LONG);
	set("resource/water", 1);
	set("exits", ([
		"south" : __DIR__"huayuan",
	]));
	set("ricewater", 5);
	setup();
}

void init()
{
        add_action("do_serve", "serve");
}

int do_serve()
{
	object me, food, water;
	me = this_player();

	if (me->query("family/family_name") != "�һ���")
		return notify_fail(CYN "��������㲻���һ������ӣ���"
                                   "����ȡʳ�\n" NOR);

        if (present("zongzi", me) || present("tea", me))
		return notify_fail(CYN "����������������ã����˷�ʳ"
                                   "�\n" NOR);

	if (query("ricewater") > 0)
	{
		message_vision(CYN "����������Ӧ���ݸ�$N" CYN "һ����"
                               "���һ�����ӡ�\n" NOR, me);

		food = new(__DIR__"obj/zongzi");
		water = new("/d/wudang/obj/xiangcha");
		food->move(me);
		water->move(me);
		add("ricewater", -1);
	}
	else
		message_vision(CYN "�����$N" CYN "Ǹ�������ˣ��Եĺ�"
                               "�Ķ�û�ˡ�\n" NOR, me);
	return 1;
}
