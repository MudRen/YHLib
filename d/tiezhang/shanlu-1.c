inherit ROOM;

void create()
{
        set("short", "ɽ·");
        set("long", @LONG
������һ����᫵�ɽ·�ϣ�����ɽ����������ݹ������м�һ����С
·������һ����ǿ��ȥ��
LONG    );
        set("exits", ([
                "north" : __DIR__"shanlu-2",
                "southdown" : __DIR__"shanmen",
        ]));

        set("no_clean_up", 0);
        set("outdoors", "tiezhang");

        setup();
        replace_program(ROOM);
}

