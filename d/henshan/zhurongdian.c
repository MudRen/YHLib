#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "ף�ڵ�");
        set("long", 
"ף�ڵ������ʥ�������ף�ڡ�����ʯ��ǽ�����߸�\n������"
"����հ�ѩ��ΡȻ�����ں�ɽ���������ŵ�ʯ��Ͽ���\n�С�" HIW
"�����ճ�����������" NOR "����������ԶԶ��ȥ�ַ��ۻ��������"
"\n���ϻ����С�" HIR "ʥ���ػ�" NOR "����鹶\n");
        set("exits", ([
                "southdown"  : __DIR__"wangritai",
                "northdown"  : __DIR__"wangyuetai",
                "westup"     : __DIR__"shanlu003",
	        "east"       : __DIR__"changlang",
        ]));

	set("objects", ([
                CLASS_D("henshan") + "/mi" : 1,
                __DIR__"npc/dizi1"   : 4,
		__DIR__"npc/xiangke" : 2,
	]));
	set("no_clean_up", 0);
        setup();

        "/clone/board/henshan_b"->foo();
}

int valid_leave(object me, string dir)
{
        object guard;

        if (dir == "northdown"
           || ! objectp(guard = present("mi weiyi", this_object())))
                return ::valid_leave(me, dir);

        return guard->permit_pass(me, dir);
}
