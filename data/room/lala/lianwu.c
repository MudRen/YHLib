// File(/data/room/lala/lianwu.c) of lala's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "���䳡");
	set ("long", @LONG
�˴�������������䳡�����ڽ������书���򲻿ɻķϡ� 
LONG );

	set("exits", ([
                "west" : __DIR__"houyuan",
	]));

        set("objects", ([
                "/clone/npc/mu-ren" : 4,
        ]));

        set("outdoors", "quanzhou");
        set("no_sleep_room", 1);

        setup();
    
        set("room_owner", "�޻�");
        set("room_name", "����");
        set("room_id", "lai");
        set("room_owner_id", "lala");
        set("room_position", "ɽ·");
}
