#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "��Ѩ�");
        set("long", @LONG
������ɭ�����Ҷ��������ֻ�����¼����µ�С������
�ڶ�����Ϸ����ͻȻ���ֶ��ڽ�������һ�Ѱ׹ǣ�����ϸһ��
��Ȼ��һ��������Źǡ�
LONG);

        set("exits", ([
                "north" : __DIR__"huxue1",
        ]));
        set("objects", ([
                "/clone/quarry/laohu" : 1,
        ]));
        set("item_desc", ([
            	"bone"  : "һ��������Źǣ������ƺ�ѹ��ʲô�������������ϸ����(sousuo)һ�¡�\n",
        ]) );

        setup();
}

void init()
{
        add_action("do_search", "search");
        add_action("do_search", "sousuo");
        add_action("do_train", "rain");

}

int do_search(string arg)
{
        object me = this_player();
        object ob; 
        if ((! arg) || ! ((arg == "bone") || (arg == "�Ź�")))
                return notify_fail("��Ҫ����ʲô��\n");

        message_vision(HIR "\n$N" HIR "���Ღ���ǶѰ׹ǡ�\n\n" NOR, me);
 
        if(query("not_tongpai"))
        {
                message("vission", HIR "ֻ������һ����������ܳ���һֻ������\n" NOR, me);
                return 1;
        }


        ob = new(__DIR__"obj/tongpai.c");
        ob->move(environment(me));
        message_vision(HIY "ֻ������ॡ�����һ���������������һ��ͭ�ơ�\n\n\n" NOR, me);
        set("not_tongpai", 1);
        call_out("regenerate", 86400);
        return 1;
}

int regenerate()
{
        set("not_tongpai", 0);
        return 1;
} 

