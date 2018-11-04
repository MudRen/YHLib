inherit ROOM;
#include <ansi.h> 

void create()
{
        set("short","÷��");
        set("long",@LONG 
��Ҳ��һ������÷�������С��������ⲻͬ���ǣ����
������÷��������ȫ������Ѫ����õĺ�÷������ƬƬƮ�䵽
��׵�ѩ���ϣ�����һ�������˳�����ˣ��ڸ��Լ���������
����ʱ����С�Ĵ�������ָ��������һ��Ѫ�������˰׾�������
һֻͨ��ѩ�׵�ѩ���ڵ�����Ȼ���裬��ң�Եá�
LONG);
        set("outdoors", "lingxiao");
        set("exits", ([
            	"west"  : __DIR__"stone",
            	"east"  : __DIR__"meiroad1",
        ]));
        set("objects", ([
                "/clone/quarry/he2" : 1,
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
