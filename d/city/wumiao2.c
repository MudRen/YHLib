#include <room.h>
inherit ROOM;


void create()
{
	set("short", "�����¥");
	set("long", @LONG
������������Ķ�¥�����﹩�������ɵĳ������ƺ�����
���ܣ�����������������Ӣ��������
LONG);

	set("no_fight", 1);
	set("no_steal", 1);
	set("no_beg", 1);
	set("no_sleep_room", 1);

	set("exits", ([
		"down" : __DIR__"wumiao",
	]));
	setup();

        replace_program(ROOM);
}
