
inherit ROOM;
#include <ansi.h>

void create()
{
        set("short","���̵ص�");
        set("long", @LONG
���������̵ĵص���ֻ��ǰ��һ�����������ĵ�·��֪��ͨ����
������ֻ�����ߣ�zou����ȥ������
LONG );
        set("exits",([
            "out"    : __DIR__"neishi",
        ]));
        set("no_beg","1");

        set("no_clean_up", 0);
        setup();
}

void init()
{
        add_action("do_zou", "zou");
}

int do_zou(string arg)
{       
        object me = this_player();
 
        if (me->is_busy() || me->is_fighting())
             return notify_fail("�㻹��æ������˵�ɣ�\n");

        message_vision(HIY "$N" HIY "�첽��ǰ��ȥ ����\n" NOR, me);

        me->move("/d/lanzhou/guangchang");

        me->start_busy(2);

        return 1;
}

