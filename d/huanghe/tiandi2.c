inherit ROOM;

void create()
{
	set("short", "���");
	set("long", @LONG
������ľ����ϡ�裬��Զ����Щ��ׯ�������������𡣴�
ׯ��Χ��һ������أ�������һЩ���ڸ�����ũ�ˡ�
LONG);
	set("exits", ([
		"southwest" : __DIR__"shulin5",
		"east"      : __DIR__"tiandi1",
	]));
	set("outdoors", "huanghe");
	setup();
	replace_program(ROOM);
}

