inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
����һ����������ʯ��ֵ���������ͷ���졣��������
ϡ�٣������ĵغ������塣������һ�����ֵĹ㳡���ϱ��Ǿ�
�ݸ��á�������һ��������Ժ���Ǿ����������ˡ�
LONG);
        set("outdoors", "jingzhou");

	set("exits", ([
		"east" : __DIR__"guangchang",
		"south" : __DIR__"jzyamen",
		"west" : __DIR__"xidajie2",
		"north" : __DIR__"wanghouse",
	]));
        set("objects", ([
                "/d/beijing/npc/kid1" : 1,
        ]));
	setup();
	replace_program(ROOM);
}

