inherit ROOM;

void create()
{
	set("short", "��Ϫ��");
	set("long", @LONG
��Ϫ��Ҳ���������������Ĳ��䡣���ﴦ���µأ������в���ũ
���ũҵ�����Ҫ�����ָ���������񾭳�Ǩ�㣬��������˼�
������⣬�������ݶ��ܼ�ª��
LONG);
	set("outdoors", "dali");
	set("exits", ([
                "northwest" : __DIR__"atoubu",
                "south"     : __DIR__"wuyiminju4",
                "east"      : __DIR__"biluoshan",
	]));
	set("objects", ([
                __DIR__"npc/shaonu": 1,
                "/clone/npc/walker" : 1,
	]));
	setup();
	replace_program(ROOM);
}

