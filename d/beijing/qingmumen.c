#include <room.h>
inherit ROOM;

void create()
{
	set("short", "��ľ��");
	set("long", @LONG
��δ���š�
LONG );
        set("exits", ([
		"north" : __DIR__"yangliu3",
	]));
	replace_program(ROOM);
}

