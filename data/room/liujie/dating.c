// File(/data/room/liujie/dating.c) of liujie's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "����������");
	set ("long", @LONG
�����������������ȥӭ�Ϳ��˵ĵط���������Щ���Σ�������
�������硣������������ȥ�ķ��䣬��һ��ľ�������š��ϱ��Ǵ��ţ�
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
    
        set("room_owner", "��ȥ");
        set("room_name", "������");
        set("room_id", "tingyu");
        set("room_position", "��ʯ�ٵ�");
}
