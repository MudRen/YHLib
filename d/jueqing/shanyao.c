inherit ROOM;

void create()
{
        set("short", "ɽ��");
        set("long", @LONG
�˴�������ҫ��������ů���黨���ŵ��磬��ʱ�ѽ��˹�
ʵ���������ӻ����죬�е�������ӣ�����������ϸë����
��Զ����������������������ƣ�׳��֮����
LONG);
        set("outdoors", "jueqing");
        set("exits", ([
               "west"      : __DIR__"shanlu1",
               "eastup"    : __DIR__"qinghuaao",
        ]));

        set("objects", ([
                __DIR__"npc/dizi2" : 2,
        ]));  

        set("no_clean_up", 0);

        setup();
}

int valid_leave(object me, string dir)
{
        object guard;

        if (dir != "eastup"
           || ! objectp(guard = present("lvshan shaonv", this_object())))
                return ::valid_leave(me, dir);

        return guard->permit_pass(me, dir);
}
