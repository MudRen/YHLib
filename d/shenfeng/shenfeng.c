#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "���");
        set("long", @LONG
����������ɽ�������ܾ��и���ۼ����쿴��ڷ��ֶ�
�ڵĺۼ��������ԣ�ֻ�������¾ã�����(gate)�����ܶ��ѱ�
ɳ��(sand)���ζ���ס�ˡ�
LONG);
        set("outdoors", "gaochang");
        set("item_desc", ([
		"gate" : WHT "Ƕ�����ɽ���ľ޴���ص�ʯ�ţ�����������"
                         "�ƶ���\n" NOR,
		"sand" : HIY "�޴��ʯ������ʱ��������ѱ�ɳ�Ӷµ�����"
                         "ʵʵ��\n���Ҫ���ʯ�ţ������ǵý���Щɳ��"
                         "�ƿ����С�\n" NOR,
        ]));
        setup();
}

void init()
{
        add_action("do_climb", "climb");
        add_action("do_push", "push");
        add_action("do_move", "move");
}

int do_climb(string arg)
{
        object me = this_player();

        if (! arg || arg != "down")
                return notify_fail("��Ҫ���ĸ���������\n");

        message("vision", HIW "ֻ��" + me->name() + HIW "սս����������"
                          "������ȥ��\n" NOR, environment(me), ({me}));

        me->move(__DIR__"shanjiao");

        tell_object(me, HIW "\n��˳�����ɽ���ĸ���ۼ�����������������"
                          "\n\n" NOR);
        message("vision", HIW "ֻ��" + me->name() + HIW "սս�����ش���"
                          "��������������\n", environment(me), ({me}));
        return 1;
}

int do_move(string arg)
{
        object me = this_player();

        if (! arg || arg != "sand")
	        return notify_fail("��Ҫ��ʲô��\n");

        if (this_object()->query("mark/sand") > 5)
	        return notify_fail("ʯ���������Ѿ�û��ɳ���ˡ�\n");

        if (me->is_busy())
	        return notify_fail("����æ���ء�\n");

        if (this_object()->query("mark/sand") < 5)
	        message_vision(HIC "$N" HIC "��ϸ������Ÿ�����ʯ����Χ"
                               "��ɳ�ӡ�\n" NOR, me);
	else
	        message_vision(HIC "$N" HIC "���ڽ�������ʯ����Χ��ɳ��"
                               "���øɸɾ�����\n" NOR, me);
        add("mark/sand", 1);
        me->start_busy(2);
        return 1;
}

int do_push(string arg)
{
        object room, me = this_player();

        if (! arg || arg != "gate")
                return notify_fail("��Ҫ��ʲô��\n");

        if (query("exits/enter"))
                return notify_fail("ʯ���Ѿ��ǿ��ŵ��ˣ�����ʲô��\n");

        message_vision(HIY "\n$N" HIY "���������˫�۶�Ȼ��ʯ���ͻ���ȥ"
                       "��\n" NOR, me);

        if ((int)me->query_skill("force") < 300
	   || this_object()->query("mark/sand") < 5
	   || me->query("neili") < 1500)
	{
	        write(HIR "������䡹��һ�����죬�㱻ʯ�ڵķ�������÷�"
                      "�˳�ȥ��\n\n" NOR);

        	message("vision", HIR "ȴ��" + me->name() + HIR "������"
                                  "Ȼһ�Σ�����÷��˳�ȥ��׹����ɽ����"
                                  "��\n\n" NOR, environment(me), ({me}));

                me->move(__DIR__"shanjiao");
                me->receive_wound("qi", 200);
                me->unconcious();
                message("vision", HIR "\nͻȻ���á��项��һ����ֻ��һ��"
                                  "�˴������ɽ����׹������������׳�ۡ�"
                                  "\n" NOR, environment(me));
                return 1;
        }

        if (! (room = find_object(__DIR__"yongdao1")))
        	room = load_object(__DIR__"yongdao1");

        if (! query("exits/enter"))
	{
                message_vision(HIY "$N" HIY "��ʯ����һ�ߣ�¶��һ����"
                               "�ڣ����Ƕ���һƬ��ڣ���ôҲ�Ʋ�����\n"
                               NOR, me);

        	set("exits/enter", __DIR__"yongdao1");
            	room->set("exits/out", __FILE__);
                me->add("neili", -1000);

            	message("vision", HIY "\nֻ�����洫��һ���ƶ�ʯ�ŵ�¡¡"
                                  "��������\n" NOR, room);
            	return 1;
    	}
        return 1;
}
