// File(/data/room/wulaoer/yingke.c) of wulaoer's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "��ͳǱ�ӭ����");
	set ("long", @LONG
��������ͳǱ����������϶�ӭ�Ӱ˷����͵ĵط����󷲿�����
�ݼ����϶����ٲ��������ﺮ���𻰣��˾���Ľ֮�顣����ͨ��һ��
���ң���������ͬ����Ʒ����������֮���� 
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

        set("room_owner", "���϶�");
        set("room_name", "��ͳǱ�");
        set("room_id", "mud");
        set("room_owner_id", "wulaoer");
        set("room_position", "��ʯ�ٵ�");
}
