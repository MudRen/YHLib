#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "��ʯС��");
        set("long", @LONG
������һ����ʯС���������ɵ�����������µڶ����ð�
���õĴ��ţ����ﲻʱ�а׻��õĵ����߶���
LONG);
        set("outdoors", "heimuya");
        set("exits", ([
                "north" : __DIR__"baigate1",
                "south" : __DIR__"linjxd3",
        ]));
        set("objects", ([
                __DIR__"npc/dizi4" : 1,
        ]));
        setup();
        replace_program(ROOM);
}
