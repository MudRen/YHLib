inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
����һ����������ʯ��ֵ���������ͷ���졣���߲�ʱ
�ش�������ײ�����������������ӡ�������һ��Ժ�ӣ�������
�Ĵ����Ϸ�д�š���¹��Ժ���ĸ��̽���֣��Ծ�����������
��ʱ�ش���ѧ��������ٴ�Ķ��������ϱ���һ���ӻ��̡�
LONG );
        set("outdoors", "city");
	set("exits", ([
		"east" : __DIR__"dongdajie2",
		"south" : __DIR__"zahuopu",
		"west" : __DIR__"guangchang",
		"north" : __DIR__"shuyuan",
	]));

	set("objects", ([
		"/clone/npc/xunbu" : 1,
	]));
	setup();
	replace_program(ROOM);
}

