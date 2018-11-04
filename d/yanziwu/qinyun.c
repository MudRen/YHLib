//room: qinyun.c

inherit ROOM;

void create()
{
        set("short","����С��");
        set("long",@LONG
����һ��С������ķ��ᣬ��Ϊ���š���Χϡϡ�������
���С���ݣ�������һ����֪��С�����ǰ뵺�ϡ�
LONG );
        set("exits", ([
		"westdown"  : __DIR__"muti",
		"east"      : __DIR__"xiaoting",
		"south"     : __DIR__"neitang",
        ]));

	set("objects", ([
	 	__DIR__"npc/bao"  : 1,
		__DIR__"npc/feng" : 1,
	]));

        setup();
}

int valid_leave(object me, string dir)
{
        object guard;

        if (dir != "east"
           || ! objectp(guard = present("bao butong", this_object())))
                return ::valid_leave(me, dir);

        return guard->permit_pass(me, dir);
}


