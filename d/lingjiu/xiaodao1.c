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
                "north" : __DIR__"xiaodao2",
                "south" : __DIR__"huayuan",
        ]));
        set("objects",([
                "/d/baituo/npc/cungu" : 1,
        ]));
        setup();
        replace_program(ROOM);
}
