#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "���ִ���");
	set("long", @LONG
����վ�ھ������ֵ��ſڣ����Կ������������Ʒ��Ĺٱ�
���ڴ˵�Ѳ�ߣ���ʱ�ش����ź������ϰ����ǲ������ڴ˹ۿ�
�ģ�����øϿ��߿���
LONG);
	set("exits", ([
		"west" : __DIR__"nandajie2",
		"east" : __DIR__"liangcang",
	]));
	set("objects", ([
		"/d/city/npc/bing" : 2,
	]));

	setup();
}

int valid_leave(object me, string dir)
{
        if (dir == "east" &&
           objectp(present("guan bing", environment(me))))
                return notify_fail(CYN "�ٱ�һ����ס�㣬����������صأ�����������Щ"
                                   "������������õģ�\n" NOR);                
        return ::valid_leave(me, dir);
}
