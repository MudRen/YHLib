inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", "��԰С·");
        set("long", @LONG
��ǰ��Ȼ���ʣ������ɵ����ڹ�԰�ߵ�С·�ϡ�·����Ӣ
�ͷף������������֣�ʢ���ŷۺ���һ�������һƬ��������
�ߡ������Կ��۷䡸���ˡ����ڻ�����Ϸ���æ����ͣ�����
����Գ���ߴզ����
LONG);
        set("outdoors", "wudang");

        set("exits", ([
                "west" : __DIR__"tyroad13",
                "east" : __DIR__"gyroad2",
        ]));
        set("objects", ([
                "/clone/beast/mangshe": 1
        ]));
        setup();
}

int valid_leave(object me, string dir)
{
        me = this_player();
        if ( dir == "east" && objectp(present("mang she", environment(me))))
                return notify_fail(HIG "��������һ��������ʱ��ס�����ȥ·��\n" NOR);

        return ::valid_leave(me, dir);
}

