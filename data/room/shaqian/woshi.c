// File(/data/room/shaqian/woshi.c) of shaqian's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "СԺ����");
	set ("long", @LONG
�������˵����ң���ʰ�þ����������ϴ�����һ�Ŵ󴲣�������
һ�����ӣ�����һ����ܣ��������һЩ�顣�������Ӳ��õ÷ǳ���
�أ������ݻ������������ס� 
LONG );

	setup();

        set("exits", ([
                "west" : __DIR__"dating",
        ]));

        create_door("west", "ľ��", "east", DOOR_CLOSED);
    
        set("sleep_room", 1);
        set("loving_room", 1);
        set("no_fight", 1);
    
        set("room_owner", "ɱǮ");
        set("room_name", "СԺ");
        set("room_id", "xyuan");
        set("room_position", "��ʯ�ٵ�");
}
