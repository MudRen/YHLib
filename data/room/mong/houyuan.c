
inherit PRIVATE_ROOM;

void create()
{
	set("short", "��Ժ");
	set ("long", @LONG
����Ǭ���ӵĺ�Ժ������һ����ɽ����Ȼ�������ǳ���ΰ����
��һˮ�أ���ɽ���ߣ���Ȼ��Ϣ��������������֮���������ǳ�����
LONG );

	set("exits", ([
                "south" : __DIR__"zhongting",
                "north" : __DIR__"huayuan",
                "east"  : __DIR__"lianwu",
                "west"  : __DIR__"chufang",
	]));

        set("outdoors", "yangzhou");
        set("no_sleep_room", 1);
        setup();

        set("room_owner", "����");
        set("room_name", "Ǭ����");
        set("room_id", "qiankun");
        set("room_owner_id", "mong");
        set("room_position", "��ʯ���");
}
