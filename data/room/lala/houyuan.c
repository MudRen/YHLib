// File(/data/room/lala/houyuan.c) of lala's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "��Ժ");
	set ("long", @LONG
��������ĺ�Ժ������һ����ɽ����Ȼ�������ǳ���ΰ������һ
ˮ�أ���ɽ���ߣ���Ȼ��Ϣ��������������֮���������ǳ����� 
LONG );

	set("exits", ([
                "south" : __DIR__"zhongting",
                "north" : __DIR__"huayuan",
                "east"  : __DIR__"lianwu",
                "west"  : __DIR__"chufang",
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
