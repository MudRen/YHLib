inherit ROOM;

void create()
{
        set("short", "�ּ���");
        set("long", @LONG
������һ���ּ����������������ѡ��������Ǻ������ڡ�
�ϱ��Ǳ���ϡ�
LONG);
        set("outdoors", "hengyang");

        set("exits", ([
                "north"  : __DIR__"hsroad8",
                "south"  : __DIR__"hsroad6",
        ]));
        set("objects", ([
                "/clone/quarry/gou" : 1,
        ]));

        setup();
        replace_program(ROOM);
}

