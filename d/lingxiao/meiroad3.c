inherit ROOM;
#include <ansi.h> 

void create()
{
        set("short","÷��");
        set("long",@LONG
������������÷��վ������ƺ�����������������Զ��
���ܿ����Ĵ���һ����һ��΢�紵��������÷�ĺ����е�����
��������ͬʱ���ǹɽ�����Ƣ�����㣬�͵�ÿ���˵����С���
�߾��������ǵĹ۾�ʤ��Ϸ÷ͤ�ˡ�
LONG);
        set("outdoors", "lingxiao");
        set("exits", ([
            	"west"  : __DIR__"meiroad1",
            	"east"  : __DIR__"ting",
        ]));
        set("objects", ([ 
                __DIR__"obj/ban" : 1,
        ])); 
        setup();
}

void init()
{
        add_action("do_pick","pick");
}

int do_pick(string arg)
{
        object me = this_player();
        object ob;

        if (arg == "mei hua" || arg == "meihua")
        {
                if (query("count") < -5)
                        return notify_fail("�����÷���Ѿ���ժ���ˡ�\n");

                ob = new(__DIR__"obj/mei");
                ob->move(me, 1);
                add("count", -1);

                message_vision("$N��·�Ե�����ժ��һ��" +
                               ob->query("name") + "��\n", me);
                return 1;
        } else
                return notify_fail("��Ҫժʲô��\n");
}
