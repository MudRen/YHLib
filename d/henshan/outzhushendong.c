#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "�����ɶ�");
        set("long", @LONG
��Ŀ��������Χ���������ͱ�(bi)����һ̧ͷ����������
д�š������ɶ����ĸ����֡��������徭������ĳ�ʴ�Ѿ�ĥ
����ΧҰ�����������б������ѡ�
LONG);
	set("item_desc",([
	       "bi" :   "��ͻͻ���ͱ��ϴ�����������(teng)��\n",  
               "teng" : YEL "�����ܽ�ʵ����������֮�á�\n" NOR,
	]));

	set("exits",([
	       "enter":__DIR__"inzhushendong",
	]));	
	     	
       setup();
}

void init()
{              
	add_action("do_climb",({"climb","pa"}));
	
}

int do_climb(string arg)
{
	object me, here, shilin;
	string msg;
	int qi;

	me = this_player();
	qi = me->query("qi");
	
	if (! arg || arg != "teng")
		return notify_fail("�������Ķ�����\n");
	
	if ( !here = find_object(__DIR__"outzhushendong"))
		here = load_object(__DIR__"outzhushendong");
	if ( !shilin = find_object(__DIR__"shilinfeng"))
		shilin =load_object(__DIR__"shilinfeng");

       	msg = HIG "\n$N" HIG "�����������ͱ�����ȥ��\n"NOR;
	
       	if(qi < 100)
	{
		msg += HIM "\n$N" HIM "������֪�����ͱ���ˤ��������\n" NOR;
		message_vision(msg, me);
		me->unconcious();
		return 1;
	}
	message_vision(msg, me);
	message("vision",HIG "\n"+me->name()+"���ͱ���������������\n", shilin, me);
	me->move(shilin);

	return 1;

}