// File(/data/room/lala/chashi.c) of lala's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "����");
	set ("long", @LONG
��һ������С�ɵĲ��ң������Եþ��¡�������һ�輸��������
������������Ů�������������˵ķԸ�(tea)�� 
LONG );

	set("exits", ([
		"west"  : __DIR__"yingke",
	]));

        set("objects", ([
                "/d/room/roomnpc/teagirl" : 2,
        ]));

        create_door("west", "ľ��", "east", DOOR_CLOSED);

        set("no_sleep_room", 1);
        setup();

        set("room_owner", "�޻�");
        set("room_name", "����");
        set("room_id", "lai");
        set("room_owner_id", "lala");
        set("room_position", "ɽ·");
}
