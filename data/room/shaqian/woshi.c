// File(/data/room/shaqian/woshi.c) of shaqian's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "小院卧室");
	set ("long", @LONG
这是主人的卧室，收拾得井井有条。南窗下是一张大床，床边有
一个柜子，还有一个书架，上面放着一些书。整间屋子布置得非常朴
素，并不奢华。屋门在西首。 
LONG );

	setup();

        set("exits", ([
                "west" : __DIR__"dating",
        ]));

        create_door("west", "木门", "east", DOOR_CLOSED);
    
        set("sleep_room", 1);
        set("loving_room", 1);
        set("no_fight", 1);
    
        set("room_owner", "杀钱");
        set("room_name", "小院");
        set("room_id", "xyuan");
        set("room_position", "青石官道");
}
