#include <ansi.h>
inherit ROOM;
   

void create ()
{
        set("short", "�߲�����");
        set("long",
"��ת����һ����ľ���������ֻ��һ��ʯɽ��Ƕ������
�����Ĵ��š����ȴ��ſ���������ǧ������˵�ǹŴ��߲�����
Ϊ�˵���ǿ�ж���Ƶġ�����������߲���������ʱ�Ѿõľ�
��������ϵ��Ż�(huan)��������д�ţ�

        " WHT "��������������������������������������
        ��                                  ��
        ��     " NOR + HIR "��     ��      ��     ��" NOR + WHT "     ��
        ��                                  ��
        ��������������������������������������" NOR "\n\n");

        set("outdoors", "gaochang");
        set("exits", ([
                "southdown" : __DIR__"shijie3",
        ]));
        set("item_desc", ([
                "huan" : HIY "\nһֻ�⼣�߰ߵĽ����Ż����������ƺ�����Ť(turn)����\n" NOR,
        ]) );
        setup();
}

void init()
{
        add_action("do_turn", "turn");
}

void check_trigger()
{
   	object room;
   	object me = this_player();
        int exp, pot, sc;

        exp = 500 + random(1000);
        pot = random(300);
        sc = random(10);

	if ((int)query("left_trigger") == 2 &&
           (int)query("right_trigger") == 5 &&
           ! query("exits/down"))
	{
     		message("vision", WHT "\n��Ȼ�䣬ֻ�����ŷ���������������¶��һ�����µĽ�"
                                  "�ݡ�\n" NOR, this_object());

		if (! (room = find_object(__DIR__"dadian")))
		room = load_object(__DIR__"dadian");

	     	if (room = find_object(__DIR__"dadian"))
		{
			set("exits/down", __DIR__"dadian");
		        room->set("exits/up", __FILE__);
                	message("vision", HIY "��Ȼ�䣬ֻ�����ŷ���������������¶��һ����"
                                          "�ϵĽ��ݡ�\n" NOR, room);

			if (! (int)me->query("skybook/baima/enter"))
			{
                		me->add("combat_exp", exp);
                		me->add("potential", pot);
                		me->add("score", sc);
                		tell_object(me, HIW "\n��ɹ��Ŀ����˸߲��Թ���ڣ�\n" NOR + HIC "ͨ"
                                                "����ε�������������" + chinese_number(exp) + "��"
                                                "���顢" + chinese_number(pot) + "��Ǳ���Լ�" +
                                                 chinese_number(sc) + "�㽭��������\n\n" NOR);
                                me->set("skybook/baima/enter", 1);
			}
     		}
     		delete("left_trigger");
     		delete("right_trigger");
     		call_out("close_passage", 10);
   	}
}

void close_passage()
{
   	object room;

   	if (! query("exits/down")) return;
   	message("vision", WHT "���ź�Ȼ���������������������µ�ͨ����"
                          "ס�ˡ�\n" NOR, this_object() );
   	if (room = find_object(__DIR__"dadian"))
	{
     		room->delete("exits/up");
     		message("vision", WHT "���ź�Ȼ�������������������ϵ�"
                                  "ͨ���ֻ����ر���ס�ˡ�\n" NOR, room);
   	}
   	delete("exits/down");
	delete("left_trigger");
	delete("right_trigger");
}


int do_turn(string arg)
{
   	string dir;
   	object me = this_player();

   	if (! arg || arg == "" ) return 0;

   	if (arg == "huan")
	{
	        if (me->query("max_neili") < 300)
		{
     			write(HIC "\n��ʹ�㾢Ť���Ż��������Ż�������˿������\n" NOR);
     			return 1;
		} else
		{
   	  		write(HIC "\n������Ť���Ż��������Ż��ƺ��������һ�����\n" NOR);
			delete("left_trigger");
			delete("right_trigger");
	     		return 1;
		}
   	}

   	if (sscanf(arg, "huan %s", dir) == 1)
	{
	        if (me->query("max_neili") < 300)
		{
     			write(HIC "\n��ʹ�㾢Ť���Ż��������Ż�������˿������\n" NOR);
     			return 1;
		} else
     		if (dir == "right" )
		{
			if (query("exits/down"))
				return notify_fail("�����Ѿ���Ť���ˡ�\n");

	        	message_vision(HIY "$N" HIY "���Ż�����Ť������Ȼ������һ����"
                                       "�����ƻ�ԭλ��\n" NOR, me);
        		add("right_trigger", 1);
        		check_trigger();
        		return 1;
     		} else
		if (dir == "left")
		{
			if (query("exits/down")) return notify_fail("�����Ѿ���Ť���ˡ�\n");
        		message_vision(HIY "$N" HIY "���Ż�����Ť������Ȼ������һ����"
                                       "�����ƻ�ԭλ��\n" NOR, me);
        		add("left_trigger", 1);
        		check_trigger();
        		return 1;
     		} else
		{
        		write("��Ҫ���Ż����ı�Ť��\n");
        		return 1;
     		}
   	}
}


void reset()
{
   	::reset();
   	delete("left_trigger");
   	delete("right_trigger");
}
