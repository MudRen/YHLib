#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIG "【练功房】" NOR);
        set("long",@LONG

                  练     功    房

    这是个很大的练功房，你可以在这里练习所有武功。
LONG NOR );
        set("exits", ([
                "west" : "/u/wfoxd/eroom2",
]));
        set("valid_startroom", 1);
        set("sleep_room", 1);
        setup();
}
