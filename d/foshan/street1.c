inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
��ɽ��ֵ�ƽ���������������ţ�������һ����������
����ΰ���ô�һ��������
LONG);
	set("objects", ([
	        __DIR__"npc/jiading": 1,
	]));
	set("outdoors", "foshan");
	set("exits", ([
                "north" : __DIR__"beidimiao",
                "west"  : __DIR__"westgate",
                "east"  : __DIR__"street2",
	]));
        set("objects", ([
                "/clone/npc/walker" : 1,
        ]));
	setup();
	replace_program(ROOM);
}

