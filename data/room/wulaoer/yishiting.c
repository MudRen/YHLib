// File(/data/room/wulaoer/yishiting.c) of wulaoer's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "������");
	set ("long", @LONG
�������ͳǱ��������϶�����Ҫ����������������֮��������
�в������Σ����������磬�����й�����������������ͨ����������
LONG );

	set("exits", ([
                "east"   : __DIR__"yanwu1",
                "west"   : __DIR__"yanwu2",
		"north"  : __DIR__"zhongting",
                "south"  : __DIR__"yingke",
	]));

        set("no_sleep_room", 1);
        setup();

        set("room_owner", "���϶�");
        set("room_name", "��ͳǱ�");
        set("room_id", "mud");
        set("room_owner_id", "wulaoer");
        set("room_position", "��ʯ�ٵ�");
}
