inherit ROOM;

void create()
{
	set("short", "��ľ��ڭ");
	set("long", @LONG
��ľ��ڭ�ںɻ��������棬һ�Ų�ͬͼ����©����ʹ��͸
��©�����������в���ˮ��ɽɫ�͸ߵʹ����¥�󣬴˴��;���
�С��Ʋ���Ӱ��֮��������׿���ң������������ɪ¥����
��һ�֡�ͥԺ��������Ϳռ䲻��֮�С�
LONG );
	set("outdoors", "suzhou");
	set("no_clean_up", 0);
	set("exits", ([
		"east"  : __DIR__"hehuating",
		"south" : __DIR__"chitang",
	]));
        set("objects", ([
                "/clone/npc/walker" : 1,
        ]));
	setup();
	replace_program(ROOM);
}

