#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
���Ǹ�ɽׯ�����š������ε����ŷ������£����Ϲ��ſ�
���ƣ�����д�š����������ж��߳�û�����С�������Ŀ�Ĵ�
�֡��������������Ӳݴ��������ǻ�����
LONG);
        set("outdoors", "baituo");
        set("exits", ([
                "west" : __DIR__"cao1",
                "east" : __DIR__"changlang",
        ]));
        set("objects", ([
                __DIR__"npc/menwei" : 1,
        ]));
        setup();
}

int valid_leave(object me, string dir)
{
        object guarder;

        if (! objectp(guarder = present("men wei", this_object())))
                return 1;

        if (dir == "east")
                return guarder->permit_pass(me, dir);

	if (dir == "west"
	   && (int)me->query("combat_exp") < 600
	   && guarder)
	        return notify_fail(CYN "������ס������㾭��̫�ͣ��ᱻ"
                                   "����ҧ�������ǲ�Ҫ�Ҵ��ĺá�\n" NOR);

        return 1;
}
