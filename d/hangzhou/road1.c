#include <room.h>
inherit ROOM;

void create()
{
        set("short", "��ʯɽ·");
        set("long", @LONG
����ϼ�������������������Ϸ�������ο͡����߹���СϪ��
���������ˡ��ϱ����Ϸ������·��
LONG);
        set("exits", ([
                "northwest" : "/d/quanzhou/jxnanmen",
                "northeast" : __DIR__"road2",
                "north"     : __DIR__"lingyinsi",
                "south"     : __DIR__"feilaifeng",
        ]));
        set("outdoors", "hangzhou");
        setup();
        replace_program(ROOM);
}
