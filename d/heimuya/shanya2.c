inherit ROOM;

void create()
{
        set("short", "ɽ��");
        set("long", @LONG
�˴����Ƹ��ʣ����Ǻ�ľ���ϣ�����վ����������̵ĵ�
�ӡ����ԵĿ������д��֣������ǡ��ĳ���¡��������ǡ���
��Ӣ����������Ͽ��š����¹������ĸ�����֡�
LONG);
        set("outdoors", "heimuya");
        set("exits", ([
            "south" : __DIR__"shanya3",
            "north" : __DIR__"shanya1",
        ]));
        set("objects", ([
                __DIR__"npc/dizi2" : 4,
        ]));
        setup();
        replace_program(ROOM);
}
