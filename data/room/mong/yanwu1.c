inherit PRIVATE_ROOM;

void create()
{
        set("short", "Ǭ����������");
	set ("long", @LONG
������ͳǱ�������������ʱ��Щ�����������ᣬ��һ�����֣�
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

        set("room_owner", "����");
        set("room_name", "Ǭ����");
        set("room_id", "qiankun");
        set("room_owner_id", "mong");
        set("room_position", "��ʯ���");
}
