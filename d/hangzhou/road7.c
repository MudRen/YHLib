#include <room.h>
inherit ROOM;

void create()
{
        set("short", "��ʯ��");
        set("long", @LONG
��������ˣ����У���˽Σ�����������ϲ�������������
����������������ߺͶ����ߡ������߱����ϱ�ɽ���ϱ���ͨ������
�š�
LONG);
        set("exits", ([
            	"east" : __DIR__"road8",
            	"north"     : __DIR__"shanlu8",
            	"south"     : __DIR__"xilingqiao",
            	"west"      : __DIR__"road6",
        ]));
        set("objects", ([
            	__DIR__"npc/youfang" : 1,
        ]));
        set("outdoors", "hangzhou");
        setup();
        replace_program(ROOM);
}

