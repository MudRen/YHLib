// File(/data/room/lala/yingke.c) of lala's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "����ӭ����");
	set ("long", @LONG
����������������޻�ӭ�Ӱ˷����͵ĵط����󷲿������ݼ���
�ڣ��ٲ��������ﺮ���𻰣��˾���Ľ֮�顣����ͨ��һ�����ң���
������ͬ����Ʒ����������֮���� 
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

        set("room_owner", "�޻�");
        set("room_name", "����");
        set("room_id", "lai");
        set("room_owner_id", "lala");
        set("room_position", "ɽ·");
}
