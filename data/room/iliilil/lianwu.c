
inherit PRIVATE_ROOM;

void create()
{
	set("short", "练武场");
	set ("long", @LONG
此处便是血海魔宫的练武场，人在江湖，武功万万不可荒废。 
LONG );

	set("exits", ([
                "west" : __DIR__"houyuan",
	]));

        set("objects", ([
                "/clone/npc/mu-ren" : 4,
        ]));

        set("outdoors", "yangzhou");
        set("no_sleep_room", 1);

        setup();

        set("room_owner", "魔渡众生");
        set("room_name", "血海魔宫");
        set("room_id", "xhmg");
        set("room_owner_id", "iliilil");
        set("room_position", "山路");
}
