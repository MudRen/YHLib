#include <ansi.h>
inherit ROOM;

void create()
{
        set("short",  "�ϴ��" );
        set("long", @LONG
��������������Ľֵ��ϣ������������ò����֣��ֵ�
��������෷����Ʒ���ˣ����ڷ���һЩ���ز����ؽ���һЩ
���̣�������һ�ҵ��̣�����һ���߸ߵĻ������˳�����
LONG);
        set("outdoors", "kunming");

        set("exits", ([
                "south" : __DIR__"nandajie2", 
                "north" : __DIR__"jinrilou",
                "west"  : __DIR__"dangpu",
                "east" : __DIR__"jiulou",
        ]));
        set("objects", ([
                "/d/beijing/npc/hunhun" : 1,
        ]));
        setup();
        replace_program(ROOM);
}
