inherit ROOM;

void create()
{
	set("short", "ɽ·");
	set("long", @LONG
������ڤ���ɽ·��������ľ���ʣ����޳�Ⱥ��
LONG );
	set("exits", ([
		"northup"    : __DIR__"shanlu3",
                  "southeast"    : __DIR__"zulin1",
	]));

	set("outdoors", "xuanming");
	setup();
	replace_program(ROOM);
}

