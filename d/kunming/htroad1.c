inherit ROOM;

void create()
{
        set("short", "����·");
        set("long", @LONG
����һ�����ϵĻ��������������һƬƬ�����͵�ˮ���
���е���ͯ������������������������������˶�����������
��ͷ�󺹵ĴҴҸ�·���ƺ���������������������԰��⡣
LONG);
        set("outdoors", "kunming");
        set("exits", ([
                "south" : __DIR__"htroad2",
                "north" : __DIR__"nanmen",
        ]));
        setup();
        replace_program(ROOM);
}
