#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIG "����������" NOR);
        set("long",@LONG

                  ��     ��    ��

    ���Ǹ��ܴ�����������������������ϰ�����书��
LONG NOR );
        set("exits", ([
                "west" : "/u/wfoxd/eroom2",
]));
        set("valid_startroom", 1);
        set("sleep_room", 1);
        setup();
}
