inherit ROOM;
#include <ansi.h>

void create()
{
        set("short","����");
        set("long",@LONG
�ߣ�һ������ˮͰ�ֵİ��ߣ��������ڱ������У���������
����������һ��ֱ���������³�Ѫ������ӣ���ֱ���˹�������
����һ���ȳ���ζ�����Ա�һ����ںܱ�����Լ�ɼ�������ʲô
������
LONG);
        set("exits",([
            	"out"  : __DIR__"wave2", 
        ])); 
        set("objects", ([
                "/clone/beast/xuanmang" : 1, 
        ]));
        setup();
}

void init()
{
        add_action("do_break", "break");
}

int do_break(string arg)
{
    	object me;
    	me = this_player();

    	message_vision(HIW "$N" HIW "�ߵ�����ǰ���˾�����ں�ȥ��\n" NOR, me);

    	if (me->query("neili") < 2000)
    	{
       		message_vision(HIR "���ֻ��һ���ƺߣ�$N" HIR "�����ڵ�"
                               "�������־�������ǰһ�ڡ���\n" NOR, me);
       		me->set("neili", 0);
       		me->unconcious();
       		return 1;
    	}
    	message_vision(HIY "$N" HIY "ֻ��һ�����죬���ڱ��䴩�ˣ�¶��һ"
                       "��С������\n" NOR, me);
    	set("exits/enter", __DIR__"yudong");
    	me->set("neili", 0);
    	remove_call_out("close");
    	call_out("close", 5, this_object());
    	return 1;
}

void close_out()
{
    	if (query("exits/enter")) delete("exits/enter");
}

void close(object room)
{
    	message("vision", HIW "һ�ɺ����Զ���ð�����������ֶ��˸�����ʵʵ��\n"
                          NOR, room);
    	room->delete("exits/enter");
}

int valid_leave(object me)
{
        if (objectp(present("xuanbing chimang", environment(me))))
           	return notify_fail(HIY "�������뿪�˵أ�ȴֻ��" NOR + HIW "����" NOR +
                                   HIR "��" NOR + HIW "��" NOR + HIY "һ����������ʱ��"
                                   "ȥ·��ȫ������\n" NOR);
        return ::valid_leave(me);
}

