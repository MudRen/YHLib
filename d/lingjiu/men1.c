inherit ROOM;

void create()
{
        set("short", "���Ҵ���");
        set("long", @LONG
������翷����չ���Ѻ���˵ĵط����������Ҷ��ߣ�����
�������ҡ�
LONG);
        set("exits", ([
		"west" : __DIR__"qiushi",
		"east" : __DIR__"changl11",
        ]));
	setup();
        replace_program(ROOM);
}
