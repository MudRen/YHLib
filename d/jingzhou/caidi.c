inherit ROOM;

void create()
{
	set("short", "�˵�");
	set("long", @LONG
�㿴��һƬ�����͵Ĳ˵أ������˸��ָ����Ĳˣ��д�ͷ
�ˡ��ײˡ����Ĳˡ���
LONG);

	set("exits", ([
		"east" : __DIR__"whouyuan",
	]));

	setup();
	replace_program(ROOM);
}

