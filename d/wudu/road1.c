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
                "south" : __DIR__"road2",
                "north" : "/d/dali/luyuxi",
        ]));

        setup();
        replace_program(ROOM);
}
