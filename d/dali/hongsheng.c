inherit ROOM;

void create()
{
	set("short","��ʥ����");
	set("long",@LONG
��ʥ����������һ�����������ڲ�ɽ֮´�����������Ϊ������
������֮һ����ʥ����Ϊ�ķ��ο���שʯ�����������֮����ש����
��ɬ����ʹ���ĽǷ��̡��������������������ߣ�����������
LONG);
	set("exits", ([
                "west"  : __DIR__"cangshan",
                "enter" : __DIR__"hongsheng1",
                "south" : "/d/tianlongsi/damen",
	]));
        set("objects", ([
                "/clone/npc/walker" : 1,
        ]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

