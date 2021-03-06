// File(/data/room/liujie/dating.c) of liujie's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "听雨轩大厅");
	set ("long", @LONG
这就是听雨轩主人区去迎送客人的地方。正中有些桌椅，侧面是
两扇屏风。东首是主人区去的房间，有一扇木门虚掩着。南边是大门，
出去就是院子。 
LONG );

	setup();

	set("exits", ([
                "east"   : __DIR__"woshi",
		"north"  : __DIR__"houyuan",
	]));

        create_door("east", "木门", "west", DOOR_CLOSED);

        set("no_sleep_room", 1);

        set("KEY_DOOR", ([
                "exit" : "south",
                "room" : __DIR__"xiaoyuan",
        ]));
    
        set("room_owner", "区去");
        set("room_name", "听雨轩");
        set("room_id", "tingyu");
        set("room_position", "青石官道");
}
