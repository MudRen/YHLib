// Room: /u/wfoxd/chuchangshi.c
inherit ROOM;

void create()
{
	set("short", "���ķ�ɽׯС�����ҡ�");
	set("long", @LONG
����ɽׯ��һ��С�����ң����������һЩû�õ�С�����ġ�
LONG
	);
	set("exits", ([ 
       		"south" : __DIR__"wroom",
	]));
	setup();
	replace_program(ROOM);
}
