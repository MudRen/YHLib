#include <ansi.h>

inherit ROOM;

int is_chat_room() { return 1; } 

void create()
{
        set("short",HIW "������" NOR);
	set("long", @LONG
�����ǡ���������־�������ң�����Կ���������豸ʮ����ȫ
�����������úõ����졣
LONG
	);

	set("exits", ([ 
                        "south" : __DIR__"fourroom",
        ]));

        set("objects", ([
                        "/clone/megazine/room/npc/ltxj" : 1,
        ]));

        set("no_fight",1);   
	setup();
}
