inherit ROOM;

void create()
{
	set("short", "��ʥ��");
	set("long", @LONG
������ʥ��ǰ�����������������ˣ��ߴ����������
ȭ��ŭĿͦ�أ������۽����򱱾������������ĵ���������
���ˡ�
LONG );
	set("exits", ([
		"north" : __DIR__"dadian",
		"south" : __DIR__"tianzhongge",
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

