inherit ROOM;

void create()
{
        set("short", "С·");
        set("long", @LONG
����һ��С·�������죬���ܾ��ǻ������������ʱ
��������ࡣǰ����һ��СС��ɽ�ԡ�
LONG);
        set("outdoors", "wudujiao");
        set("exits", ([
                "northwest" : __DIR__"road3",
                "southup" : __DIR__"shanlu2",
        ]));
        set("objects", ([
                "/clone/quarry/tu" : 3,
        ]));

        setup();
        replace_program(ROOM);
}
