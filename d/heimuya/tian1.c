#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "������");
        set("long",@LONG
�����Ǻ�ľ�µĵ��Ĵ��������á������������������
����һ����һ���긾�˺�ü���ڵ��С����ϱ߳�����һƬ����
���Եĳ�����
LONG);
        set("exits", ([
            	"north" : __DIR__"dating4",
            	"south" : __DIR__"chitang",
            	"west" : __DIR__"tingptw",
            	"east" : __DIR__"tingpte",
        ]));
        set("objects", ([
                CLASS_D("riyue") + "/sang" : 1,
                __DIR__"npc/dizi6" : 4,
        ]));       
        setup();
}

int valid_leave(object me, string dir)
{
        if (objectp(present("sang sanniang", environment(me)))
           && dir == "south"
           && me->query("family/family_name")
           && me->query("family/family_name") != "�������")
                return notify_fail(CYN "ɣ���ｫ����ס��˵����������ʥ��"
                                   "��ס�������˲������ڡ�\n" NOR);

	if (objectp(present("sang sanniang", environment(me)))
           && (string)me->query("gender") != "Ů��"
           && dir == "south")
                return notify_fail(CYN "ɣ���ｫ����ס��˵����������ʥ��"
                                   "��ס������һ�����˽�ȥ���\n" NOR);

	if (objectp(present("sang sanniang", environment(me)))
           && ! me->query("family/family_name"))
                message_vision(CYN "ɣ���￴��$N" CYN "һ�ۣ���ü����ȥ��"
                               "ʦ�ɵù�ص㣬�ɱ�������ʥ�á�\n" NOR, me);

        return ::valid_leave(me, dir);
}
