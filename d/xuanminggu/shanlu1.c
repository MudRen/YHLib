inherit ROOM;

void create()
{
	set("short", "ɽ·");
	set("long", @LONG
������ڤ���ɽ·��������ľ���ʣ����޳�Ⱥ��
LONG );
	set("exits", ([
		"southeast"  : __DIR__"shanjiao",
                  "northwest"  : __DIR__"xiaolu2",
	]));

	set("outdoors", "xuanming");
	setup();
	replace_program(ROOM);
}

