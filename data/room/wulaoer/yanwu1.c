// File(/data/room/wulaoer/yanwu1.c) of wulaoer's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "泥巴城堡演武厅");
	set ("long", @LONG
这是泥巴城堡的演武厅，有时有些江湖朋友来会，想一试身手，
就在这里比武较量。 
LONG );

	set("exits", ([
                "west" : __DIR__"yishiting",
	]));

        set("objects", ([
                "/clone/weapon/zhubang" : 1,
                "/clone/weapon/zhujian" : 1,
                "/clone/weapon/mudao"   : 1,
        ]));

        set("no_sleep_room", 1);
        setup();

        set("room_owner", "乌老二");
        set("room_name", "泥巴城堡");
        set("room_id", "mud");
        set("room_owner_id", "wulaoer");
        set("room_position", "青石官道");
}
