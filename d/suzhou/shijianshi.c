inherit ROOM;

void create()
{
	set("short", "�Խ�ʯ");
	set("long", @LONG
��ɽ���������Խ�ʯ������Բ�Σ���������������ѵ���
�죬�ഫ�����á��ɽ�������Īа������Ϊ�����������ʯ
������ʯ�Կ���Ԫ��������ʫ�䡰����һ�������ˮ������
��ΰ���󣬲�ն�Ը�ͷ������ʫ�䡣
LONG );
	set("outdoors", "suzhou");
	set("no_clean_up", 0);
	set("exits", ([
		"north" : __DIR__"zhenniang",
		"south" : __DIR__"zhishuang",
		"west"  : __DIR__"zhenshi",
		"east"  : __DIR__"wanjing",
	]));
	set("objects", ([
		"/d/taishan/npc/jian-ke" : 1,
	]));
	setup();
	replace_program(ROOM);
}

