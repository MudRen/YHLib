// Room: /u/wfoxd/chuchangshi.c
inherit ROOM;

void create()
{
	set("short", "【幽风山庄小储藏室】");
	set("long", @LONG
这是山庄的一个小储藏室，室用来存放一些没用的小东西的。
LONG
	);
	set("exits", ([ 
       		"south" : __DIR__"wroom",
	]));
	setup();
	replace_program(ROOM);
}
