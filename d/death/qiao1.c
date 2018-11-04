#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", NOR + WHT "���κ��š�" NOR);
        set("long", NOR + WHT @LONG

                    ��         ��         ��

    �����������������ͨ�����κ��š���������ǰ������һ��������
ʯ�ƹ��ţ�����������޿�������ж����ţ���ͷһλ�׷��ԲԵ��ϸ�
�ˣ���Ϊÿһ�����ŵ�����Ҩ������


LONG NOR );
        set("exits", ([
                "north" : __DIR__"qiao2",
                "south" : __DIR__"road6",
        ]) );
        set("objects", ([
                __DIR__"npc/mengpo":1,
                __DIR__"npc/ghost":1,
        ]) );

        set("no_fight", 1);
        set("no_sleep_room", 1);

        setup();
}

int valid_leave(object me, string dir)
{
        object ob;
        me = this_player();

        if (dir == "north")
        {
                if (! me->query_temp("last_eat/mengpo_tang")
                   && objectp(present("meng po", environment(me))) )
                        return notify_fail(CYN "����˵������λ" +
                                           RANK_D->query_respect(me) +
                                           CYN "�����������߰ɡ�\n" NOR);
        }
        return ::valid_leave(me, dir);
}

void init()
{
        add_action("do_move", "jump");
        add_action("do_move", "tiao");
}

int do_move(string arg)
{
        object paper,
        me = this_player();

        if (! arg || arg == "")
                return 0;

        if (arg == "qiao" || arg == "��" || arg == "�κ���")
        {
                if (! me->query("hell_quest/������")
                   && objectp(present("meng po", environment(me))))
                {
                        write(CYN "ֻ������һ����ס�㣬˵������λ"
                              + RANK_D->query_respect(me) + CYN
                              "�������²��ã��²��ã����˿ɾͻز�"
                              "���ˡ�\n" NOR);
                        return 1;
                }
                message_vision(HIC "\nֻ��$N" HIC "ҧ��ҧ����һ��"
                               "����κ�����������ȥ����\n" NOR,
                               this_player());
                me->move("/d/death/hantan1");
                message_vision(HIC "\nֻ������ͨ��һ����$N" HIC
                               "�������κ�������������\n" NOR,
                               this_player());
                return 1;
        }
        return 0;
}
