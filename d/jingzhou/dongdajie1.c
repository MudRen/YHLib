inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
����һ����������ʯ��ֵ����ϱ���һ�����ӵ�Ժ�ӣ���
���εĴ����Ϸ�д�š�������Ժ���ĸ��̽�Ĵ��֣��Ծ�ͦ��
���������治ʱ�ش���ѧ��������ٴ�Ķ�������������һ��
����ߵİ������ഫ��һλ״ԪΪ��ĸ����֮��������ġ�
LONG);
        set("outdoors", "jingzhou");
	set("exits", ([
		"east" : __DIR__"dongdajie2",
		"south" : __DIR__"shuyuan",
		"west" : __DIR__"guangchang",
		"north" : __DIR__"baita",
	]));
        set("objects", ([
                "/d/beijing/npc/shusheng1" : 2,
        ]));
	setup();
	replace_program(ROOM);
}

