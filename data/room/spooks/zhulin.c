// File(/data/room/spooks/zhulin.c) of spooks's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "����");
	set ("long", @LONG
�������źô�һƬ���֣��ǳ��ľ�����һ�������Ҷɳɳ���죬
��ʱ��ʹ��ȥ���θ�Ĭ�����������������书�� 
LONG );

	set("exits", ([
                "west" : __DIR__"huayuan",
                "east" : __DIR__"tingtao",
	]));

        set("outdoors", "suzhou");
        set("sleep_room", 1);
        setup();

        set("room_owner", "��ʹ");
        set("room_name", "ʱ�����");
        set("room_id", "suidao");
        set("room_owner_id", "spooks");
        set("room_position", "��ʯ�ٵ�");
}
