inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�������Ƿ�ɽ������š������������ɹ�������������
��һ��������Ĵ���Ƿ�ɽ�����Ҫ�ֵ���
LONG);
	set("outdoors", "foshan");
	set("exits", ([
	        "east" : __DIR__"street1",
	        "west" : __DIR__"road7",
	]));
	setup();
	replace_program(ROOM);
}

