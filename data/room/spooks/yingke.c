// File(/data/room/spooks/yingke.c) of spooks's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "ʱ�����ӭ����");
	set ("long", @LONG
������ʱ����������˽�ʹӭ�Ӱ˷����͵ĵط����󷲿�������
����ʹ���ٲ��������ﺮ���𻰣��˾���Ľ֮�顣����ͨ��һ�����ң�
��������ͬ����Ʒ����������֮���� 
LONG );

	set("exits", ([
		"north"  : __DIR__"yishiting",
                "south"  : __DIR__"zoudao",
                "east"   : __DIR__"chashi",
	]));

        create_door("east", "ľ��", "west", DOOR_CLOSED);

        set("objects", ([
                "/d/room/roomnpc/yahuan" : 2,
        ]));

        set("no_sleep_room", 1);
        setup();

        set("room_owner", "��ʹ");
        set("room_name", "ʱ�����");
        set("room_id", "suidao");
        set("room_owner_id", "spooks");
        set("room_position", "��ʯ�ٵ�");
}
