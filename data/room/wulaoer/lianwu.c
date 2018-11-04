// File(/data/room/wulaoer/lianwu.c) of wulaoer's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "练武场");
	set ("long", @LONG
此处便是泥巴城堡的练武场，人在江湖，武功万万不可荒废。 
LONG );

	set("exits", ([
                "west" : __DIR__"houyuan",
	]));

        set("objects", ([
                "/clone/npc/mu-ren" : 4,
        ]));

        set("outdoors", "suzhou");
        set("no_sleep_room", 1);

        setup();
    
        set("room_owner", "乌老二");
        set("room_name", "泥巴城堡");
        set("room_id", "mud");
        set("room_owner_id", "wulaoer");
        set("room_position", "青石官道");
}
