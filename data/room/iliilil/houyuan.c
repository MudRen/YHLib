
inherit PRIVATE_ROOM;

void create()
{
	set("short", "后院");
	set ("long", @LONG
这是血海魔宫的后院，正中一个假山，傲然而立、非常雄伟。下
有一水池，环山而走，悠然不息。东面乃是练武之处，西面是厨房。
LONG );

	set("exits", ([
                "south" : __DIR__"zhongting",
                "north" : __DIR__"huayuan",
                "east"  : __DIR__"lianwu",
                "west"  : __DIR__"chufang",
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
