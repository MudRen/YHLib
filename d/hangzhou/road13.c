#include <room.h>
inherit ROOM;

void create()
{
        set("short", "��ʯ���");
        set("long", @LONG
�غ�����Ե������������ֹ��ӣ������۴��αȣ���������������
һƬ̫ƽ���־��󡣽ֶ�����һ�ҿ͵ꡣ
LONG);
        set("exits", ([
            "north"     : __DIR__"road12",
            "south" : __DIR__"road14",
            "east"      : __DIR__"kedian",
        ]));
        set("outdoors", "hangzhou");
        setup();
        replace_program(ROOM);
}
