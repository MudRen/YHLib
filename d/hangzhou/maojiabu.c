#include <room.h>
inherit ROOM;

void create()
{
        set("short", "é�Ҳ�");
        set("long", @LONG
·���Ը��ż���С���������ſ�һλ�ϴ�������ι������
��С������׷����Ϸ���������ϻ����롣�����Ƕ���ɽ��
LONG);
        set("exits", ([
            	"south"   : __DIR__"tulu2",
            	"northup"     : __DIR__"huangniling",
        ]));
        set("objects", ([
            	__DIR__"npc/boy" : 1,
            	__DIR__"npc/oldwoman" : 1,
        ]));
        set("outdoors", "hangzhou");
        setup();
        replace_program(ROOM);
}
