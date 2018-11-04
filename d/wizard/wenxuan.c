// /d/wizard/guest_room.c

#include <room.h>
#include <ansi.h>

inherit ROOM;

int is_chat_room() { return 1; }

void create()
{
	set("short", HIG "��ѡ������" NOR);
	set("long", @LONG
����������﷢���ת�����£��类��ʦѡ�ý����ǳ�����
ע����ֹ�����������������ࡢ���׵����ݡ�
LONG );

	set("exits", ([
		"east"    :  __DIR__"herodoor",           
        ]));

	set("no_fight", 1);

	setup();
	"/clone/board/wenxuan_b"->foo();
        replace_program(ROOM);
}

