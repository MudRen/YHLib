#include <ansi.h>
inherit ROOM;

#define HUANGJINFU    "/clone/lonely/huangjinfu"

void create()
{
        set("short", "��");
        set("long", @LONG
ǰ��ɽʯ��·���ѵ���ͷ��ֻ����ͷ���������⣬�߽���
ʱ��ȴ��һ��ʯ���š����Ÿߴ������������ţ�ֱ��һ���
�����ʯ��ʯ��(gate)�������һ����ĸ��Ż����������߶೤
�Ĵִ���ť������ס��
LONG);
        set("exits", ([ 
                "south" : __DIR__"yongdao2",
        ]));
        setup();
}

void init()
{
        object ob;

        ob = find_object(HUANGJINFU);
        if (! ob) ob = load_object(HUANGJINFU);

        if (! environment(ob))
	{
        	set("item_desc",([
        		"gate": WHT "\n���Ⱥ��Ĵ�ʯ�ţ��ƺ������ܴ�������ֻ��"
                                "ʯ�ŵ��Ż��ϲ�\n��һ��" NOR + YEL "�ƽ�" NOR
                                + WHT "(huangjin fu)" WHT "��\n\n" NOR,

			"huangjin fu" : YEL "����һ����������Ĵ󸫣�����ĩ����"
                                        "����Щ�ɶ���\n" NOR,

			"fu"          : YEL "����һ����������Ĵ󸫣�����ĩ����"
                                        "����Щ�ɶ���\n" NOR,

			"huangjin"    : YEL "����һ����������Ĵ󸫣�����ĩ����"
                                        "����Щ�ɶ���\n" NOR,
		]));
	        add_action("do_get", "get");
     	} else
	{
        	set("item_desc",([
        		"gate": WHT "���Ⱥ��Ĵ�ʯ�ţ��ƺ������ܴ�������\n" NOR,
		]));
	}
       	add_action("do_break", "break");
}

int do_get(string arg)
{
        object me, ob;

        me = this_player();
        ob = find_object(HUANGJINFU);
        if (! ob) ob = load_object(HUANGJINFU);

        if (environment(ob)) return 0;

        if (! arg || arg == "" ) return 0;

        if (arg == "huangjin fu from gate"
           || arg == "huangjin from gate"
	   || arg == "fu from gate")
	{
	        if ((int)me->query_skill("force", 1) > 200)
		{
	                ob->move(me, 1);
                     	message_vision(HIY "\n$N" HIY "���ۡ���һ������ʯ���ϰ�"
                                       "��һ���ƽ𸫣�ֻ���ó������\n\n" NOR,
                                       me);

                     	set("item_desc",([
	                     	"gate": WHT "���Ⱥ��Ĵ�ʯ�ţ��ƺ������ܴ�����"
                                        "��\n" NOR,
			]));

             	} else
		{
                     	message_vision(WHT "\n$N" WHT "ʹ���˳��̵����������Ż�"
                                       "�ϵ�" NOR + YEL "�ƽ�" NOR "(huangjin"
                                       " fu)" WHT "��Ȼ��˿������\n" NOR, me);
             	}
             	return 1;
        }
        return 0;
}

int do_break(string arg)
{
        object me, ob;
        object room;

        me = this_player();
        ob = me->query_temp("weapon");

    	if (! arg || arg != "gate")
        	return notify_fail("��Ҫ�ٵ�ʲô��\n");

        if (query("exits/north"))
                return notify_fail("ʯ���Ѿ��������ˣ�����ʲô��\n");

    	if (! ob)
	{
        	message_vision(HIY "\n$N" HIY "�������������������һ����˫ȭ"
                               "�͵Ļ���ʯ�ţ�\n" NOR, me);

    		if ((int)me->query_skill("force", 1) < 200)
		{
        		message_vision(HIR "���ֻ��$N" HIR "һ���ƺߣ���ʯ�ŵ�"
                                       "��������÷��˳�ȥ��\n\n" NOR, me);
	                me->receive_wound("qi", 300);
        		me->set("neili", 0);
        		me->unconcious();
        	} else
		{
        		message_vision(HIR "���ֻ�����һ�����죬��ʯ��ȴ����"
                                       "˿δ����\n\n" NOR, me);
        		me->set("neili", 0);
		}
        	return 1;
    	}

       	message_vision(HIY "\n$N" HIY "�߸߾������е�" + ob->query("name") + HIY
                       "����ʯ��������ȥ��\n" NOR, me);

    	if ((int)me->query_skill("force", 1) < 200
           || base_name(ob) != HUANGJINFU)
	{
        	message_vision(HIR "���ֻ����������һ����$N" HIR "����һ��"
                               + ob->query("name") + HIR "����ס���ַɳ���\n\n"
                               NOR, me);
        	ob->move(environment(me));
        	return 1;
    	}

    	if (! (room = find_object(__DIR__"yongdao4")))
        	room = load_object(__DIR__"yongdao4");

        if (! query("exits/north"))
        {
                message_vision(HIY "ֻ�����䡹��һ�����죬ʯ���ѱ�$N" HIY "����"
                               "���飬¶��һ�����ڡ�\n\n" NOR, me);

                set("exits/north", __DIR__"yongdao4");
                room->set("exits/south", __FILE__);

                message("vision", HIY "\nֻ�����桸�䡹��һ�����죬ʯ�ű�������"
                                  "�ˡ�\n" NOR, room);
        }
    	return 1;
}

