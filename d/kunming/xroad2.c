inherit ROOM;

void create()
{
        set("short", "�ٵ�");
        set("long", @LONG
����һ�����ϵĻ����ٵ���������һƬƬ�����͵�ˮ���
���е���ͯ������������������������������˶�����������
��ͷ�󺹵ĴҴҸ�·���ƺ���������������������԰��⡣
LONG);
        set("outdoors", "kunming");
        set("exits", ([
                "west" : "/d/dali/road1",
                "east" : __DIR__"xroad1",
        ]));
        setup();
        replace_program(ROOM);
}
