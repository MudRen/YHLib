
#include <room.h>

inherit PRIVATE_ROOM;

void create()
{
	set("short", "������");
	set ("long", @LONG
�����Ǭ����������������Ҫ����������������֮���������в�
�����Σ����������磬�����й�����������������ͨ����������
LONG );

	set("exits", ([
                "east"   : __DIR__"yanwu1",
                "west"   : __DIR__"yanwu2",
		"north"  : __DIR__"zhongting",
                "south"  : __DIR__"yingke",
	]));

        set("no_sleep_room", 1);
        setup();

        set("room_owner", "����");
        set("room_name", "Ǭ����");
        set("room_id", "qiankun");
        set("room_owner_id", "mong");
        set("room_position", "��ʯ���");
}
