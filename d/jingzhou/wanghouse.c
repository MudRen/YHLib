#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "�򸮴���");
	set("long",
"�ߵ����һ�������ûʵĴ�լԺ�����������ǰ����ͷ
�ߴ��ʯʨ����ס�˴������࣬����������������������
��������������д�š�" HIY "������" NOR "���ĸ�������֡�ֻ��������
������������վ�ڴ������࣬�����ע�������ˡ�\n");
        set("no_fight", 1);
        set("no_sleep_room", 1);
	set("exits", ([
		"south" : __DIR__"xidajie1",
		"north" : __DIR__"dayuan",
	]));
        set("objects", ([
                "/d/shaolin/npc/shang2" : 2,
        ]));
	setup();
}

int valid_leave(object me, string dir)
{
        if (dir == "north" &&
           objectp(present("jia ding", environment(me))))
                return notify_fail(CYN "�Ҷ���ס�������ʲô��������Ȼ����"
                                   "��ү�ĸ�ۡ�����Ҵ���\n" NOR);                
        return ::valid_leave(me, dir);
}
