// File(/data/room/spooks/jusuo.c) of spooks's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "����");
	set ("long", @LONG
�����ʱ��������˽�ʹ��Ϣ������ĵط���¥�Ͼ������˵���
�ң����������鷿�� 
LONG );

	set("exits", ([
		"up"   : __DIR__"woshi",
                "west" : __DIR__"shufang",
	]));

        set("no_sleep_room", 1);
        setup();

        set("KEY_DOOR", ([
                "exit" : "east",
                "room" : __DIR__"huayuan",
        ]));
    
        set("room_owner", "��ʹ");
        set("room_name", "ʱ�����");
        set("room_id", "suidao");
        set("room_owner_id", "spooks");
        set("room_position", "��ʯ�ٵ�");
}
