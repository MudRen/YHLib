inherit ROOM;

void create()
{
	set("short", "��С��");
	set("long", @LONG
�ֵ����࣬��ľ���졣����ʢ�Ŀ��ȣ���ֲ����������
ˬ���������ųǡ�������ͳ����ˣ������ǳ����ġ�
LONG );
	set("exits", ([
		"east"    : __DIR__"dongmen",
		"west"    : __DIR__"dongdajie",
	]));
        set("objects", ([
                "/clone/npc/walker" : 1,
        ]));
	set("outdoors", "fuzhou");
	setup();
	replace_program(ROOM);
}

