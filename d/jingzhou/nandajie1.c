inherit ROOM;

void create()
{
	set("short", "�ϴ��");
	set("long", @LONG
�ϴ�����ǳ���ķ����ضΣ�������һ�����ֵĹ㳡����
����һ�Ҵ����̡������Ǿ��ݵ���ݣ�������·�˶�붼����
��ЪЪ�š�
LONG);
        set("outdoors", "jingzhou");
	set("exits", ([
                "east" : __DIR__"datiepu",
		"south" : __DIR__"nandajie2",
                "west" : __DIR__"chaliao",
		"north" : __DIR__"guangchang",
	]));
        set("objects", ([
                "/d/beijing/npc/youke" : 1,
        ]));
	setup();
	replace_program(ROOM);
}

