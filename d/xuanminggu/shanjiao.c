inherit ROOM;

void create()
{
	set("short", "��ڤ��ɽ��");
	set("long", @LONG
������ڤ��ɽ�ţ�����ǰ�߾�����ڤ���ˡ�������ľ���̣��̲���
����ɽ��Ұ�����ⱼ�ܡ�
LONG );
	set("exits", ([
		"eastdown"  : __DIR__"xiaolu1",
		"northwest" : __DIR__"shanlu1",
	]));

	set("outdoors", "xuanming");
	setup();
	replace_program(ROOM);
}

