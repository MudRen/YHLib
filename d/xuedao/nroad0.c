inherit ROOM;

void create()
{
        set("short", "ɽ·");
        set("long", @LONG
ɽ·Խ��Խխ������������ǰ���ֳַ��˼�����·��
LONG);
        set("exits", ([
                "south" : __DIR__"sroad0",
                "north" : __DIR__"nroad1",
        ]));
        set("outdoors", "xuedao");
        setup();
        replace_program(ROOM);
}

