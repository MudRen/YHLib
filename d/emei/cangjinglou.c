#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "�ؾ�¥");
        set("long", @LONG
�����Ǳ����²ؾ�¥����¥�������������˺ö���ܣ���
�ϰ����˾��顣�����������µ�Сʦ̫����һ�Ǿ����ض���
���顣
LONG);
        set("objects", ([
                CLASS_D("emei") + "/daoming" : 1,
                __DIR__"obj/fojing1" + random(2) : 1,
                __DIR__"obj/fojing2" + random(2) : 1,
        ]));
        set("exits", ([
                "south" : __DIR__"dxdian",
        ]));
        setup();
}

int valid_leave(object me, string dir)
{
        me = this_player();

        if (dir == "south"
           && present("shu", me)
           && objectp(present("dao ming", environment(me))))
                return notify_fail(CYN "����Сʦ��������Ѿ������ߣ���ǰ��"
                                   "��˵����������ˡ����衣\n" NOR);

        return ::valid_leave(me, dir);
}
