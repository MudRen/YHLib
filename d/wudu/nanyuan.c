inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", "��Ժ");
        set("long", @LONG
�������Ͽ�Ժ��Ժ�����пúܴ������������մ���ס
Ժ���ﾲ���ĵģ���ֻ�ߴ�Ĳ��������������ⲽ�� 
LONG);
        set("outdoors", "wudujiao");

        set("exits", ([
                "east" : __DIR__"yaoshi",
                "south" : __DIR__"liandu",
                "west" : __DIR__"xiangfang",
                "north" : __DIR__"lianwu",
        ]));
        set("objects", ([
                  "/clone/quarry/gou3" : 2,
        ]));
        setup();
}

void init()
{
        add_action("do_climb", "climb");
}

int do_climb(string arg)
{
       
        object me = this_player();
        object ob;

        if (! arg || arg != "tree")
                return notify_fail("��Ҫ��ʲô��\n");

        message_vision(HIC "$N" HIC "���˴��֣�����������֦�������"
                       "�¾�������ȥ��\n" NOR, me);

        ob = load_object(__DIR__"tree");
        ob = find_object(__DIR__"tree");
        message("vision", me->query("name") + "����������������\n", ob);
        me->move(__DIR__"tree");
        return 1;
}

