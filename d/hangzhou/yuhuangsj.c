#include <room.h>
inherit ROOM;
void create()
{
        set("short", "���ɽ��");
        set("long", @LONG
ֻ�����ϵ�ɽ·�������ӡ�ɽ·����һ��С����ͤ������������
��ͤ��Ъ�š���������һ����ʯ�������������ɽ��·��
LONG);
        set("exits", ([
            	"north" : __DIR__"road15",
            	"westup"    : __DIR__"shanlu7",
        ]));
        set("objects", ([
            	__DIR__"npc/honghua1" : 2,
        ]));
        set("outdoors", "hangzhou");
        setup();
        replace_program(ROOM);
}
