#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "��ʯ̲");
        set("long", @LONG
�����ʯ������·�������ߣ���С�ľ�Ҫˤ������������
��Ƭʯ̲�����ǳ������ߡ�
LONG);
        set("outdoors", "jingzhou");

        set("exits", ([
                "south" : __DIR__"road2", 
                "north" : "/d/jingzhou/nanshilu1",
        ]));

        setup();
        replace_program(ROOM);
}
