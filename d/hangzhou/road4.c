#include <room.h>
inherit ROOM;

void create()
{
        set("short", "��ʯ��");
        set("long", @LONG
��������ˣ����У���˽Σ�����������ϲ�������������
���������Ǻ鴺�š�����������򶫱��ߡ�
LONG);
        set("exits", ([
            "south"     : __DIR__"hongchunqiao",
            "northeast" : __DIR__"road5",
        ]));
        set("outdoors", "hangzhou");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
