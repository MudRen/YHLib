
inherit PRIVATE_ROOM;

void create()
{
	set("short", "���䳡");
	set ("long", @LONG
�˴�����Ѫ��ħ�������䳡�����ڽ������书���򲻿ɻķϡ� 
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

        set("room_owner", "ħ������");
        set("room_name", "Ѫ��ħ��");
        set("room_id", "xhmg");
        set("room_owner_id", "iliilil");
        set("room_position", "ɽ·");
}
