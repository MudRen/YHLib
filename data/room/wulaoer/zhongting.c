// File(/data/room/wulaoer/zhongting.c) of wulaoer's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
        object ob;

        set("short", "��ͳǱ���ͥ");
	set ("long", @LONG
������ͳǱ�֮������ͥ�����Ա��ǿ��˾�ס���᷿������ͨ��
��԰�����˾�����ǰ��������������һֱͨ����Ժ�� 
LONG );

	set("exits", ([
		"north"  : __DIR__"houyuan",
                "south"  : __DIR__"yishiting",
                "east"   : __DIR__"zuoxiang",
                "west"   : __DIR__"youxiang",
	]));

        set("outdoors", "suzhou");

        set("objects", ([
                "/d/room/roomnpc/shouwei" : 1,
        ]));

        create_door("east", "ľ��", "west", DOOR_CLOSED);
        create_door("west", "ľ��", "east", DOOR_CLOSED);

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

        set("room_owner", "���϶�");
        set("room_name", "��ͳǱ�");
        set("room_id", "mud");
        set("room_owner_id", "wulaoer");
        set("room_position", "��ʯ�ٵ�");
}

int valid_leave(object me, string dir)
{
        object ob;

        ob = present("shou wei", this_object());
        if (dir != "north" || ! objectp(ob) || ! living(ob))
                return ::valid_leave(me, dir);

        if (ob->is_owner(me))
        {
                message_vision("$N������$n�������������\n", ob, me);
                return ::valid_leave(me, dir);
        }

        if (present(query("room_owner_id") + " pass", me))
        {
                message_vision("$N��$n��������Ȼ�����˵����ͣ�������ɡ���\n",
                               ob, me);
                return ::valid_leave(me, dir);
        }

        message_vision("$N������ס$n���������Բ���û��" +
                       query("room_owner") + "�����ͣ��������Դ��룡��\n", ob, me);
        return 0;
}
