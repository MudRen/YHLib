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
                "west" : __DIR__"xroad2",
                "east" : __DIR__"xiaoximen",
        ]));
        setup();
        replace_program(ROOM);
}
