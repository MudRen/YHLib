inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
�����ڶ�����ϣ����ż�ʵ����ʯ����档���߲�Զ�Ƕ�
���ţ����������سǹٱ���ߺ���������������ʵĶ���������
��һ�𡣱�����һ��СС���ӻ��̡�
LONG);
        set("outdoors", "jingzhou");
	set("exits", ([
		"east" : __DIR__"jzdongmen",
		"west" : __DIR__"dongdajie1",
		"north" : __DIR__"shop",
		"south" : __DIR__"xxiang",
	]));
        set("objects", ([
                "/d/beijing/npc/boy3" : 1,
        ]));
	setup();
	replace_program(ROOM);
}

