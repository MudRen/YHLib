inherit ROOM;

void create()
{
	set("short", "ɽ·");
	set("long", @LONG
������ڤ���ɽ·��������ľ���ʣ����޳�Ⱥ��
LONG );
	set("exits", ([
		"northdown"    : __DIR__"xuanminggu",
		"southdown"    : __DIR__"shanlu2",
	]));

	set("outdoors", "xuanming");
	setup();
	replace_program(ROOM);
}

