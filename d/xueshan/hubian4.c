inherit ROOM;

void create()
{
        set("short", "����С·");
        set("long", @LONG
����ʥ���ߵ�С·��·�೤��û��, ���̿�ϲ��
LONG);
        set("outdoors", "xuedao");
        set("exits", ([
                "north" : __DIR__"shanjiao",
                "south" : __DIR__"hubian3",
        ]));
        set("objects", ([
                "/clone/npc/walker" : 1,
        ]));
        setup();
        replace_program(ROOM);
}
