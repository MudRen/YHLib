#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
        set("short", "��լ��Ժ");
        set("long", @LONG
������������լ�ĺ�Ժ�������Ƿ�������ù������Ҷ��Ժ
�ӵ�������һ�ھ�����̨�Ͽ���Щ�֡�Ժ��������һ���ţ���
�ѱ�̮����ש�ߵ�ס�ˡ�
LONG );
        set("exits", ([
            	"west" : __DIR__"mishi",
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
                set("exits/south", __DIR__"laozhai");
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
        delete("exits/south");
        delete("break");
}
