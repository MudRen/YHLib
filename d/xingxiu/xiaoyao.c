#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "��ң��");
        set("long", @LONG
����һ���ֲڵ�ʯ�����������˼��ų����Ĳݵ��ӡ���
���Ա���һЩ�ƾƹ��ӡ�����(wall)����Щ�ּ���
LONG);
        set("sleep_room", 1);
        set("no_fight", 1);
        set("exits", ([
                "out" : __DIR__"xxh6",
        ]));
        set("item_desc", ([
                "wall" : HIW "\n           �����������˵ö���֮��\n\n" NOR,
        ]) );
        setup();
        replace_program(ROOM);
}

