inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
������һƬŨ�ܵ������֣�ǰ���Ѿ�û���˵�·������벻ʱ��
�Ϻ�������ǰ��֦�⡣���ڹ��ߺڰ������������������Լ�����������
ֻ������ڵ��Ϻ�������Ϳ�֦�Ϸ�����ɳɳ����
LONG);
        set("outdoors", "wudujiao");

        set("exits", ([
                "north" : __DIR__"sl1",
                "east" : __DIR__"sl7",
        ]));

        setup();
        replace_program(ROOM);
}

