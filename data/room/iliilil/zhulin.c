inherit PRIVATE_ROOM;

void create()
{
	set("short", "竹林");
	set ("long", @LONG
这里种着好大一片竹林，非常幽静。风一起就听竹叶沙沙的响，
有时魔渡众生就去听涛阁默听竹浪涛声，参悟武功。 
LONG );

	set("exits", ([
                "west" : __DIR__"huayuan",
                "east" : __DIR__"tingtao",
	]));

        set("outdoors", "yangzhou");
        set("sleep_room", 1);
        setup();

        set("room_owner", "魔渡众生");
        set("room_name", "血海魔宫");
        set("room_id", "xhmg");
        set("room_owner_id", "iliilil");
        set("room_position", "山路");
}
