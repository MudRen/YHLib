
inherit PRIVATE_ROOM;

void create()
{
	set("short", "��Ժ");
	set ("long", @LONG
����Ѫ��ħ���ĺ�Ժ������һ����ɽ����Ȼ�������ǳ���ΰ����
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

        set("room_owner", "ħ������");
        set("room_name", "Ѫ��ħ��");
        set("room_id", "xhmg");
        set("room_owner_id", "iliilil");
        set("room_position", "ɽ·");
}
