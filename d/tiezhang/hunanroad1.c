inherit ROOM;

void create()
{
        set("short", "��·");
        set("long", @LONG
����������������·�ϣ�ż��������������ҴҶ����������Ѿ��Ǻ�
�ϵؽ磬��������������ڡ�
LONG
        );
        set("outdoors", "tiezhang");

        set("exits", ([
            "east" : "d/xiangyang/caodi6",
            "southwest" : __DIR__"hunanroad2",
        ]));

        setup();
        replace_program(ROOM);
}

