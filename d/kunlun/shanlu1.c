inherit ROOM;

void create()
{
	set("short", "����ɽ·");
        set("long", @long
���н���������һ������һ�죬����������������ǿ����
;������ʲôǿ����ֻ�ǻ�ɳ���棬����͸�ǣ�ȴҲ��ʵ�Ѱ���
long);
        set("exits",([
		"westup" : __DIR__"shanlu2",
		"east" : __DIR__"shanlu",
	]));
        set("objects", ([
                __DIR__"npc/seller" : 1,
        ]));
	set("outdoors", "kunlun");
	setup();
	replace_program(ROOM);
}
