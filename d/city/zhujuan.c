#include <room.h>
#include <ansi.h>
inherit ROOM;

int is_chat_room()
{
	return 1;
}

void create()
{
        set("short", NOR + WHT "��Ȧ" NOR);
        set("long", @LONG
������һ����������Ȧ�����Ϲ���һ������(paizi)��
LONG);
        set("no_fight", 1);
        set("no_sleep_room",1);
        set("item_desc", ([
                "paizi" : WHT "���һ�𷢴�������̶���������硣\n" NOR,
        ]));
        set("exits", ([
                "up"   : __DIR__"kedian",
        ]));

        setup();
        
        replace_program(ROOM);
}

