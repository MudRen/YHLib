// File(/data/room/spooks/yanwu2.c) of spooks's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "ʱ�����������");
	set ("long", @LONG
����ʱ�����������������ʱ��Щ�����������ᣬ��һ�����֣�
���������������� 
LONG );

	set("exits", ([
                "east" : __DIR__"yishiting",
	]));

        set("objects", ([
                "/clone/weapon/zhubang" : 1,
                "/clone/weapon/zhujian" : 1,
                "/clone/weapon/mudao"   : 1,
        ]));

        set("no_sleep_room", 1);
        setup();

        set("room_owner", "��ʹ");
        set("room_name", "ʱ�����");
        set("room_id", "suidao");
        set("room_owner_id", "spooks");
        set("room_position", "��ʯ�ٵ�");
}
