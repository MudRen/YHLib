#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "�嶾�̴���");
        set("long", @LONG
������һ����û��ɽ���еĴ�լԺ���߸ߵ�Χǽ�����ɫ�Ĵ��ţ�
������һ����Ǯ�˼ҵı����Ժ��
LONG);
        set("outdoors", "wudujiao");

        set("exits", ([
                "east" : __DIR__"lianwu",
                "west" : __DIR__"wdsl7",
        ]));
        set("objects", ([
                __DIR__"npc/jiaotu": 4,
                CLASS_D("wudu") + "/jiaotou" : 1,
        ]));

        setup();
}

int valid_leave(object me, string dir)
{
        object sha;

        if (dir != "east" ||
            ! objectp(sha = present("sha qianli", this_object())))
                return ::valid_leave(me, dir);

        return sha->permit_pass(me, dir);
}
