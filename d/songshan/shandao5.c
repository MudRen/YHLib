inherit ROOM;

void create()
{
	set("short", "ɽ��");
	set("long", @LONG
��������ɽɽ�������ɴ�أ�ɽ�����ʱ��Ʈ����Զ��
ɽ��Ȯ�ͼ��䣬�����ɷ�֮�С�
LONG );
	set("exits", ([
		"northup"   : __DIR__"chaotian",
		"southwest" : __DIR__"fawangsi",
		"east"      : __DIR__"shandao7",
	]));
	set("outdoors", "songshan");
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

