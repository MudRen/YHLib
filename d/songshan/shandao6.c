inherit ROOM;

void create()
{
	set("short", "ɽ��");
	set("long", @LONG
��������ɽɽ�������ɴ�أ�ɽ�����ʱ��Ʈ����Զ��
ɽ��Ȯ�ͼ��䣬�����ɷ�֮�С����������ɽ������Ժ��
LONG );
	set("exits", ([
		"northup"   : __DIR__"junjigate",
		"southdown" : __DIR__"chaotian",
	]));
	set("no_clean_up", 0);
	set("outdoors", "songshan");
	setup();
	replace_program(ROOM);
}

