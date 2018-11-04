#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", NOR + RED "��������" NOR);
        set("long", @LONG
������ʯ���ڵ�һ�ð��̸ߵĴ������ϣ������˴�����Ҷ
���ǣ��ܲ�͸�硣
LONG);
        set("exits", ([
              "up"    :  __DIR__"ontree2",
              "down"  :  __DIR__"undertan",
        ]));

        set("no_clean_up", 0);

        setup();

}

void init()
{       
        add_action("do_jump", ({ "jump", "tiao" }));
}

int do_jump(string arg)
{
        object me = this_player();
        object ob;

        if (! arg || arg != "down" )
                return notify_fail("��Ҫ���Ķ�����\n");

        if (! ob = find_object(__DIR__"undertan"))
                ob = load_object(__DIR__"undertan");

        if (me->is_busy())
                return notify_fail("��������æ���أ�\n");

        if (me->is_fighting())
                return notify_fail("�㻹���Ȱ�����ǰ����һ�������˵��\n");

        tell_room(ob, HIC + me->name() + "�Ӵ�����������������\n" NOR, me);

        me->move(ob);

        return 1;

}

int valid_leave(object me, string dir)
{
        if (dir == "down")
        { 
               write(HIC "���������̫�ߣ�������ֻ������ȥ�ˡ�\n" NOR);
               return -1;
        }

        return 1;
} 


