#include <room.h>
inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
�����񷶥�ϵ�ʯ���������һ����⣬��������һ���족����
�ϱ�����ɽ��·��
LONG);
        set("exits", ([
                "east" : __DIR__"longhongdong",
        ]));
        set("objects", ([
             __DIR__"npc/mengmian":1,
        ]));
        set("outdoors", "hangzhou");
        setup();
        replace_program(ROOM);
}
