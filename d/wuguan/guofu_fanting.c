#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
������������ò͵ĵط������ﲼ�úܼ�, ֻ���ż���
���μ�������һ������س��š�һ�������ڲ�ͣ��æµ�ţ���
��������Ҫ(serve)ʳ���ˮ��
LONG);
        set("exits", ([
                "east" : __DIR__"guofu_shilu-4",
        ]));

        set("objects", ([
          	__DIR__"npc/chushi" : 1,
        ]));       
        set("no_fight", 1);
        setup();
}

int valid_leave(object me, string dir)
{
        if ((dir == "east")
           && present("chu shi", environment(me)))
	{
	        if (present("tea", me))
              		return notify_fail(CYN "��ʦ��ס������㻹���ȰѲ�"
                                           "�������߰ɡ�\n" NOR);

	        if (present("rice", me))
              		return notify_fail(CYN "��ʦ��ס������㻹���Ȱѷ�"
                                           "�������߰ɡ�\n" NOR);

        }
        return ::valid_leave(me, dir);
}
