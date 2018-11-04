#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "������լ");
        set("long", @LONG
�����Ǹ����ھ�����ͷ�������ڸ����ľɾӡ����ڵļҾ�
�������˵ص��ڵ��ϡ������һ�ǽ���һ��֩���������ﵽ��
�ǳ�������Ȼ���Ѿ��ܾ�û����ס�ˡ�
LONG);
        set("exits", ([
                "south" : __DIR__"xiangyang",
        ]));
        set("item_desc", ([
                "men" : "�������ѱ���ס�޷�ͨ�У����������(break)����\n",
        ]) );
        setup();
}

void init()
{
        add_action("do_break", "break");
}

int do_break(string arg)
{
        int n = this_player()->query("neili");

        if (query("break"))
                return notify_fail("�����Ѿ����𿪣��ò����ٷ����ˡ�\n");

        if (! arg || arg != "men")
        {
                write("ʲô��\n");
                return 1;
        }

        message_vision(HIY "$N" HIY "�ߵ�����ǰ���ݳ��������ʽ������һ"
                       "������˫��ͬʱ�ĳ���\n" NOR, this_player());
        
        if (n >= 200)
        {
                message_vision(WHT "ֻ����Ȼһ�����죬$N" WHT "���Ÿ���"
                               "���ˡ�\n" NOR, this_player());
                set("exits/north", __DIR__"houyuan");
                set("break", 1);
                this_player()->set("neili", n-200);
                remove_call_out("close");
                call_out("close", 5);
        } else
        {
                message_vision(HIY "$N" HIY "���һ������������˫��ͬʱ"
                               "������ȥ��\n" HIR "������ű�������һ"
                               "�����ҳ��Ĵ����\n" NOR, this_player());
                this_player()->set("neili", 0);
        }
        return 1;
}

void close()
{
        message("vision", WHT "���ϵ�שͷ�߿�ϡ�ﻨ��̮���������ֵ�ס��"
                          "С�š�\n" NOR, this_object());
        delete("exits/north");
        delete("break");
}
