inherit ROOM;

void create()
{
	set("short","������");
	set("long",@LONG
�˴���˵������ʱ�����������ߴ����ϻ�֮�����ϻ�Ի����
��������Ҳ����Ƚ������˲�����Ҳ�������ʴ˵���������һ����ͨ
�ϱ��Ĵ�·����ȥʮ����ϲ�ݳǣ�����Լ��ʮ��ɴ����ǡ�
LONG);
	set("outdoors", "dali");
	set("exits", ([
                "north" : __DIR__"road4",
                "south" : __DIR__"xizhou",
	]));
        set("objects", ([
                "/clone/npc/walker" : 1,
        ]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

