inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
������ڤ��ɽ����һƬ�����֣��Ĵ������ӳ�����ﻨ�㡣
LONG );
	set("exits", ([
		"eastdown"  : __DIR__"xiaolu3",
		"westup"    : __DIR__"zulin2",
                "northwest" : __DIR__"shanlu2",
	]));

        set("objects", ([
                 "/kungfu/class/xuanming/wuwang" : 1,
        ]));

	set("outdoors", "xuanming");
	setup();
	replace_program(ROOM);
}

