inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
������һƬŨ�ܵ������֣�ǰ���Ѿ�û���˵�·������벻ʱ��
�Ϻ�������ǰ��֦�⡣���ڹ��ߺڰ������������������Լ�����������
ֻ������ڵ��Ϻ�������Ϳ�֦�Ϸ�����ɳɳ����ǰ����ϡ͸��һ
��������㲻�ɳ���������һ������
LONG);
        set("outdoors", "wudujiao");

        set("exits", ([
                "west" : __DIR__"sl2",
                "south" : __DIR__"sl5",
        ]));

        setup();
        replace_program(ROOM);
}

