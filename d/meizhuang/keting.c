#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "ӭ��ͤ"); 
        set("long", @LONG
ͨ��������磬��������÷ׯ��ӭ��ͤ��������Ȼֻ��һ��ʯ��
�ͼ���ʯ�ʣ���ȴ��һ����Ⱦ��ʯ�ʺ�ʯ��֮��Ŀ�϶�ܴ����Ƿ�
�������������໥���ѡ�
LONG
        );
        set("exits", ([
                "south" : __DIR__"dating",
                "north" : __DIR__"senlin1",
        ]));

        set("objects", ([
                CLASS_D("meizhuang") + "/ding" : 1,
        ]));

        set("no_clean_up", 0);

        setup();
}

int valid_leave(object me, string dir)
{
        object ding;

        if (dir != "north" ||
            ! objectp(ding = present("ding jian", this_object())))
                return ::valid_leave(me, dir);

        return ding->permit_pass(me, dir);
}
