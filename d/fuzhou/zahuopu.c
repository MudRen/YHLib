inherit ROOM;

void create()
{
	set("short", "�ӻ���");
	set("long", @LONG
������һ����Ϊ�¾ɵ����棬��̨������������ڷ���Щ
Ů��ר�õ��ӻ���
LONG);
	set("exits", ([
		"east" : __DIR__"xiangyang",
	]));
	set("objects", ([
		__DIR__"npc/chen" : 1,
	]) );
	setup();
	replace_program(ROOM);
}

