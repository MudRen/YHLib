#include <room.h>
inherit ROOM;

void create()
{
        set("short", "��ϲ��");
        set("long", @LONG
��ϲ��������������������ĵ�һ����������οͲ�ʱ�Ľ���
�����������ɴ���������������ɽ��·��
LONG);
        set("exits", ([
                "east"  : __DIR__"shanlu4",
        ]));
        set("objects", ([
            	__DIR__"npc/guest" : 2,
            	__DIR__"npc/seng" : 1,
        ]));
        set("outdoors", "hangzhou");
        setup();
        replace_program(ROOM);
}
