inherit ROOM;

void create()
{
        set("short", "�������");
        set("long", @LONG
����һ�����ϵĻ��������������һƬƬ�����͵�ˮ������е�
��ͯ������������������������������˶�������������ͷ�󺹵Ĵ�
�Ҹ�·���ƺ���������������������԰��⡣
LONG);

        set("outdoors", "wudujiao");

        set("exits", ([
                "south" : __DIR__"road3",
                "north" : __DIR__"road1",
        ]));
        set("objects", ([
                "/d/taishan/npc/tiao-fu": 2,
        ]));

        setup();
        replace_program(ROOM);
}

