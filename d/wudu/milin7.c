inherit ROOM;

void create()
{
        set("short", "��ɭ��");
        set("long", @LONG
������������ĺ�ɭ�֣����ܾ���ï�ܵĴ��֣��޴�Ĺ�ľ����
���գ�ͷ��������һƬ��ա����²�ʱ������΢�����죬�ƺ���ʲô
�����Ӳݴ����ι���Զ��ż������һ��Ұ�޵ĺ�������
LONG);
        set("outdoors", "wudujiao");

        set("exits", ([
                "east" : __DIR__"milin6",
                "south" : __DIR__"milin3",
                "enter" : __DIR__"huxue1",
                "north" : __DIR__"milin8",
        ]));

        setup();
        replace_program(ROOM);
}
