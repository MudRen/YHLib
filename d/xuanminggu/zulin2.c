inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
������ڤ��ɽ����һƬ�����֣��Ĵ������ӳ�����ﻨ�㡣
�˴���֮������ڴ���ɫ���ѣ����ӵ�������Ϣ�˱Ƕ�����ʵ��
�����侲˼֮���ء�
LONG );
	set("exits", ([
		"eastdown"  : __DIR__"zulin1",
	]));

        set("objects", ([
                 "/kungfu/class/xuanming/he" : 1,
        ]));

	set("outdoors", "xuanming");
	setup();
	replace_program(ROOM);
}

