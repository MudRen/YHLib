inherit ROOM;

void create()
{
	set("short","����");
	set("long",@LONG
�����Ƿ�ɽ��ı��š����������򱱣���������ɴ���ԭ��
����һ��������Ĵ���Ƿ�ɽ�����Ҫ�ֵ���
LONG);
	set("outdoors", "foshan");
	set("exits", ([
	        "south" : __DIR__"street3",
	        "north" : __DIR__"nanling",
	]));
	setup();
	replace_program(ROOM);
}

