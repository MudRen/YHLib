#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "֥��");
        set("long", @LONG
�����Ǿ���ȴ��ظ���ҩ�ĵĵط���ֻ��ǽ�Ƿ���һ��ҩ
��(chest)������ҩζ����ɢ��������

         =====δ�������������=====
LONG);

        set("item_desc",([
               "chest" : HIC "���Ǵ���ҩ��Ĺ��ӣ�������涨�ǲ����������ҩ�ġ�\n" NOR,
        ]));

        set("exits", ([
               "east"   : __DIR__"houtang",
        ]));

        set("no_clean_up", 0);

        setup();
}

void init()
{       
        add_action("do_open", ({ "open" }));
}

int do_open(string arg)
{
        object me = this_player();
        object ob;

        if (! arg || arg != "chest")
                return notify_fail("��Ҫ��ʲô��\n");


       return 1;
}


