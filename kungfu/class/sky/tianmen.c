#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIW "��ͨ���š�" NOR);
        set("long", HIW @LONG
�����������������ããһƬ�ƺ�����ǰһ����ΰ�ĳ����Ĵ�
�ţ����ŵ�������������һλ���ӣ��ƺ�����ĵ����������⡣
LONG NOR );
        set("exits", ([
                "enter" : __DIR__"sky1",
]));
        set("sleep_room", 1);
        set("objects", ([
                __DIR__"npc/li": 1,
        ]));

        setup();
}

