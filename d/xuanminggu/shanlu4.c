inherit ROOM;

void create()
{
	set("short", "ɽ·");
	set("long", @LONG
������ڤ���ɽ·��������ľ���ʣ����޳�Ⱥ��
LONG );
	set("exits", ([
		"northup"      : __DIR__"xuanmingfeng",
		"southeast"    : __DIR__"xuanminggu",
	]));

	set("outdoors", "xuanming");
	setup();
	replace_program(ROOM);
}

