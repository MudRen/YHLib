#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", NOR + RED "��������" NOR);
        set("long", @LONG
��������������������ȥ��ͻȻ�о�һ��ѣ�Σ�ԭ������
��������а����̸��ˡ�̧ͷһ������Ȼ�����۹�һ��������
���澹��һ������(teng)���¡�
LONG);
        set("item_desc", ([
              "teng" : HIG "\n�������Խ����������(climb)��ʯ�ߡ�\n" NOR,
        ]));
        set("exits", ([
              "down"  :  __DIR__"ontree2",
        ]));

        set("no_clean_up", 0);

        setup();

}

void init()
{       
        add_action("do_climb", ({ "climb", "pa" }));
}

int do_climb(string arg)
{
        object me = this_player();
        object ob;

        if (! arg || arg != "teng" )
                return notify_fail("��Ҫ���Ķ�����\n");

        if (! ob = find_object(__DIR__"ligui"))
                ob = load_object(__DIR__"ligui");

        if (me->is_busy())
                return notify_fail("��������æ���أ�\n");

        if (me->is_fighting())
                return notify_fail("�㻹���Ȱ�����ǰ����һ�������˵��\n");

        message_vision(HIY "$N˳������������ȥ��\n" NOR, me);

        me->move(ob);

        return 1;

}

int valid_leave(object me, string dir)
{
        if (dir != "down")
                 write(HIC "���������̫�ߣ�������ֻ������ȥ�ˡ�\n" NOR);

        return 1;
}


