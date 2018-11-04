// File(/data/room/lala/dayuan.c) of lala's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "奈落大院");
	set ("long", @LONG
这是一个宽阔的院落，种着各种树木，阳光照下来透过树荫投下
层层影子。一条大路通向里面，踩得非常平滑的，看来是经常有人来
往。 
LONG );

	set("exits", ([
		"north"  : __DIR__"qianting",
                "out"    : "/d/quanzhou/qzroad1",
	]));

        set("outdoors", "quanzhou");
        set("no_sleep_room", 1);
        set("valid_startroom", 1);
        setup();

        set("room_owner", "无悔");
        set("room_name", "奈落");
        set("room_OWNER_id", "lala");
        set("room_id", "lai");
        set("room_owner_id", "lala");
        set("room_position", "山路");
}
