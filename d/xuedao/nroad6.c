inherit ROOM;

void create()
{
        set("short", "ɽ·");
        set("long", @LONG
������һɽ·�ϣ�������һ����Сɽ��Զ�����Կ�����
���ѩ��ɽ�⡣��Χ�������Ѿ����ѿ��õ��ˡ�
LONG);
        set("exits", ([
                "north" : __DIR__"nroad7",
                "south" : __DIR__"nroad5",
        ]));
        set("objects", ([
                "/clone/npc/walker" : 1,
        ]));
        set("outdoors", "xuedao");
        setup();
        replace_program(ROOM);
}

