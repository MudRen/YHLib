// File(/data/room/spooks/houyuan.c) of spooks's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "��Ժ");
	set ("long", @LONG
����ʱ������ĺ�Ժ������һ����ɽ����Ȼ�������ǳ���ΰ����
��һˮ�أ���ɽ���ߣ���Ȼ��Ϣ��������������֮���������ǳ�����
LONG );

	set("exits", ([
                "south" : __DIR__"zhongting",
                "north" : __DIR__"huayuan",
                "east"  : __DIR__"lianwu",
                "west"  : __DIR__"chufang",
	]));

        set("outdoors", "suzhou");
        set("no_sleep_room", 1);
        setup();

        set("room_owner", "��ʹ");
        set("room_name", "ʱ�����");
        set("room_id", "suidao");
        set("room_owner_id", "spooks");
        set("room_position", "��ʯ�ٵ�");
}
