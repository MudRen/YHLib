#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "��");
        set("long", @LONG
���ɽ�������ֲ�����ָ���ڳ�������ôҲ�Ʋ�����
LONG);
	set("exits", ([
		"out" : __DIR__"shenfeng",
	]));
        setup();
}

void init()
{
        add_action("do_use", "use");
        add_action("do_tiao", "tiao");
        add_action("do_tiao", "jump");
}

int do_use(string arg)
{
        object me = this_player();

        if (! arg || arg == "" ) 
		return 0;

        if (! present("fire", me))
		return 0;

        if (this_object()->query("mark/light"))
                return notify_fail("���Ѿ����Ż����ˡ�\n");

        if (arg == "fire")
	{
             	message_vision(HIR "\n$N" HIR "ȡ������һ�Σ����ִ�����ȥ���"
                               "��������ʮ�߰��ɣ����ڵ���Զ�������Ϊ�͡�\n"
                               "\n" NOR, me);

        	set("long", "ƾ����۵�΢�⣬����Կ���������ȥ�����������ʮ"
                            "��\n���ɸߣ����ڵ���Զ�������Ϊ�͡�\n");

	        add("mark/light", me->query("id"));
                return 1;
       }
}

int do_tiao(string arg)
{
        object ob, me = this_player();

        if (! this_object()->query("mark/light"))
		return notify_fail("����һƬ��ڣ������̽���巽��\n");

       	if (! arg || arg != "down")
		return notify_fail("��Ҫ��������\n");

        message_vision(HIY "\n$N" HIY "ԥ��һ�£�����������������ȥ��\n\n" NOR, me);

	// �ж���˭��ȼ�Ļ��ۣ�����ֻ�����������ȥ����ָ��ڰ���
	if (this_object()->query("mark/light") == me->query("id"))
	{
	        delete("mark/light");
       		set("long", "ɽ�������ֲ�����ָ���ڳ�������ôҲ�Ʋ�����\n");

                message("vision", HIR + me->name() + HIR "�������Ż���������ȥ"
                        "�������漴����һƬ��ڡ�\n" NOR, environment(me), ({me}));
	}

    	if ((int)me->query_skill("dodge", 1) < 150 )
	{
        	me->move(__DIR__"shishi");
                me->receive_wound("qi", 300);
                me->unconcious();
                message("vision", HIR "\nͻȻ���á��项��һ����ֻ��һ���˴���"
                                  "���ɽ����׹������������׳�ۡ�\n" NOR,
                                  environment(me), ({me}));

	        if (objectp(ob = present("fire", this_player())))
	               	destruct(ob);

        } else
	{
        	me->move(__DIR__"shishi");
        	message("vision", HIY + me->name() + HIY "����������������\n" NOR,
                                  environment(me), ({me}));

	        if (objectp(ob = present("fire", this_player())))
		{
                	message_vision(HIR "\nͻȻ��$N" HIR "��һ�ɣ������Ӳ�"
                                       "֪��������ȥ�ˡ�\n", me);
                	destruct(ob);
        	}
        }
       	return 1;
}
