inherit PRIVATE_ROOM;

void create()
{
        set("short", "Ѫ��ħ��������");
	set ("long", @LONG
����Ѫ��ħ��������������ʱ��Щ�����������ᣬ��һ�����֣�
����������������
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

        set("room_owner", "ħ������");
        set("room_name", "Ѫ��ħ��");
        set("room_id", "xhmg");
        set("room_owner_id", "iliilil");
        set("room_position", "ɽ·");
}
