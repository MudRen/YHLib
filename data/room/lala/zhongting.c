// File(/data/room/lala/zhongting.c) of lala's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
        object ob;

        set("short", "奈落中庭");
	set ("long", @LONG
这是奈落之腰：中庭，两旁便是客人居住的厢房，后面通往后花
园和主人居所，前面则是议事厅，一直通往大院。 
LONG );

	set("exits", ([
		"north"  : __DIR__"houyuan",
                "south"  : __DIR__"yishiting",
                "east"   : __DIR__"zuoxiang",
                "west"   : __DIR__"youxiang",
	]));

        set("outdoors", "quanzhou");

        set("objects", ([
                "/d/room/roomnpc/shouwei" : 1,
        ]));

        create_door("east", "木门", "west", DOOR_CLOSED);
        create_door("west", "木门", "east", DOOR_CLOSED);

        set("no_sleep_room", 1);
        setup();

        ob = present("shou wei", this_object());
        ob->set("coagents", ({
                ([ "startroom" : __DIR__"zuowei",
                   "id"        : "shou wei 1" ]),
                ([ "startroom" : __DIR__"zuowei",
                   "id"        : "shou wei 2" ]),
                ([ "startroom" : __DIR__"youwei",
                   "id"        : "shou wei 2" ]),
                ([ "startroom" : __DIR__"youwei",
                   "id"        : "shou wei 1" ]),
        }));

        set("room_owner", "无悔");
        set("room_name", "奈落");
        set("room_id", "lai");
        set("room_owner_id", "lala");
        set("room_position", "山路");
}

int valid_leave(object me, string dir)
{
        object ob;

        ob = present("shou wei", this_object());
        if (dir != "north" || ! objectp(ob) || ! living(ob))
                return ::valid_leave(me, dir);

        if (ob->is_owner(me))
        {
                message_vision("$N弯腰对$n道：“请进！”\n", ob, me);
                return ::valid_leave(me, dir);
        }

        if (present(query("room_owner_id") + " pass", me))
        {
                message_vision("$N对$n道：“即然有主人的手谕，就请进吧。”\n",
                               ob, me);
                return ::valid_leave(me, dir);
        }

        message_vision("$N伸手拦住$n，道：“对不起，没有" +
                       query("room_owner") + "的手谕，不可擅自闯入！”\n", ob, me);
        return 0;
}
