#include <room.h>
inherit ROOM;

void create()
{
        set("short", "��ʯ���");
        set("long", @LONG
��������ˣ����У���˽Σ�����������ϲ�������������
����������ȥ��Ȫ�µ�·������������򶫱ߺ����ϱߡ�
LONG);
        set("exits", ([
            "southwest" : __DIR__"road4",
            "west"    : __DIR__"yuquan",
            "south"     : __DIR__"dadao1",
            "east"      : __DIR__"road6",
        ]));
        set("objects" , ([
            __DIR__"npc/honghua1" :1,
            __DIR__"npc/tiao-fu" :1,
        ]));

        set("outdoors", "hangzhou");
        setup();
        replace_program(ROOM);
}
