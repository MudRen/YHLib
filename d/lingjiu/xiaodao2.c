inherit ROOM;

void create()
{
        set("short", "С��");
        set("long", @LONG
���ߵ����һ��С���������۵�ͨ��Զ��������������
�де����֣�΢�紵������Ҷ����������������
LONG);
        set("outdoors", "lingjiu");

        set("exits", ([
            "north" : __DIR__"men3",
            "south" : __DIR__"xiaodao1",
        ]));
        set("objects",([
                "/d/beijing/npc/old2" : 1,
                "/d/beijing/npc/kid1" : 1,
        ]));
        setup();
        replace_program(ROOM);
}
