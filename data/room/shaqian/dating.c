// File(/data/room/shaqian/dating.c) of shaqian's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "СԺ����");
	set ("long", @LONG
�����СԺ����ɱǮӭ�Ϳ��˵ĵط���������Щ���Σ���������
�����硣����������ɱǮ�ķ��䣬��һ��ľ�������š��ϱ��Ǵ��ţ�
��ȥ����Ժ�ӡ� 
LONG );

	setup();

	set("exits", ([
                "east"   : __DIR__"woshi",
		"north"  : __DIR__"houyuan",
	]));

        create_door("east", "ľ��", "west", DOOR_CLOSED);

        set("no_sleep_room", 1);

        set("KEY_DOOR", ([
                "exit" : "south",
                "room" : __DIR__"xiaoyuan",
        ]));
    
        set("room_owner", "ɱǮ");
        set("room_name", "СԺ");
        set("room_id", "xyuan");
        set("room_position", "��ʯ�ٵ�");
}
