inherit ROOM;

void create()
{
	set("short", "������Ժ");
	set("long", @LONG
������Ժ����ɽ������Ժ�йŰ�ɭɭ�����ϲ��޷���Ժ
������������ǧ�ˡ�
LONG );
	set("exits", ([
		"southdown" : __DIR__"junjigate",
                "east"      : __DIR__"changlang",
	]));
	set("objects", ([
		__DIR__"npc/shi" :1,
	]));
	setup();
	replace_program(ROOM);
	"/clone/board/songshan_b"->foo();
}

