inherit ROOM;

void create()
{
	set("short", "���и�");
	set("long", @LONG
���и���������Ĵ��ţ�ԭ�ƻ��и������йŰ�������
�꣬��ʯ���ٰ���������ǰʯ���٣����ƹ��ӡ���������ɽ��
����̫���ڡ�
LONG );
	set("outdoors", "songshan");
	set("exits", ([
		"north" : __DIR__"chongsheng",
		"south" : __DIR__"taishique",
	]));

        set("objects", ([
                __DIR__"npc/seller" : 1,
                "/clone/npc/walker" : 1,
        ]));

	setup();
	replace_program(ROOM);
}

