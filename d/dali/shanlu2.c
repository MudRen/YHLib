inherit ROOM;

void create()
{
	set("short", "ɽ·");
	set("long", @LONG
һ��ɽ·���������ï�ܵ����ֺ����಻���Ĵ�ɽ����·���Լ�
��ɼ�һЩ����Ĵ�������һƬ��ɽ�������ƣ�ɽ�߰�ѩ��������
��������·������ɽ��һ����·���ϱ������š�
LONG);
	set("outdoors", "dali");
	set("exits", ([
                "east"    : __DIR__"shanlu3",
                "south"   : __DIR__"shanlu4",
                "northup" : __DIR__"nianhuasi",
                "westup"  : __DIR__"biluoxueshan",
	]));
        set("objects", ([
                "/clone/npc/walker" : 1,
        ]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

