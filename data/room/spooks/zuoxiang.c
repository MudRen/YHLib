// File(/data/room/spooks/zuoxiang.c) of spooks's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "���᷿");
	set ("long", @LONG
����ʱ����������᷿���ǿ��˾�ס�ĵط�����Ȼ�����ݻ���ȴ
Ҳ���õ÷ǳ����ʡ�һ�Ŵ�����ɾ���û�ж������ƣ�����������
ʵ��ʹ���ڹ���ǡ���ô��� 
LONG );

	set("exits", ([
                "west" : __DIR__"zhongting",
	]));

        set("sleep_room", 1);
        set("no_fight", 1);
        set("outdoors", "suzhou");

        create_door("west", "ľ��", "east", DOOR_CLOSED);

        set("room_owner", "��ʹ");
        set("room_name", "ʱ�����");
        set("room_id", "suidao");
        set("room_owner_id", "spooks");
        set("room_position", "��ʯ�ٵ�");
}
