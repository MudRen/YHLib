inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
�˵ر������ݳǵĳ����ģ����������������Ĳ���ͤ����
�ӱ���֣��ϲ����Ǳ������ˡ������Ļ���������ţ�ʹ����
Ů���ٶ�ϲ����������ͥɢ����������ȥ������һƬ���̵Ĳ�
ƺ�������Ŀ�������
LONG );
	set("outdoors", "suzhou");
	set("exits", ([
		"east"  : __DIR__"dongdajie1",
		"west"  : __DIR__"xidajie1",
		"north" : __DIR__"canlangting",
		"south" : __DIR__"baodaiqiao",
	]));
        set("objects", ([
                "/d/beijing/npc/maiyi2" : 1,
                "/d/beijing/npc/old1" : 1,
                "/d/beijing/npc/kid1" : 1,
        ]));

	setup();
	replace_program(ROOM);
}

