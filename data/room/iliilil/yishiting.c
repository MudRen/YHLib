
#include <room.h>

inherit PRIVATE_ROOM;

void create()
{
	set("short", "������");
	set ("long", @LONG
�����Ѫ��ħ������ħ����������Ҫ����������������֮���������в�
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

        set("room_owner", "ħ������");
        set("room_name", "Ѫ��ħ��");
        set("room_id", "xhmg");
        set("room_owner_id", "iliilil");
        set("room_position", "ɽ·");
}
