#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","���±�");
	set("long",@LONG
�������ϸ��ɶ�������¾���(xuanya)��վ�ڴ˴�������
ȥ�������������紵�����㲻�ɵش��˸���ս��
LONG);
	set("item_desc", ([
	       "xuanya"  : HIG "\nֻ���Ӿ����ϴ���һЩ����(teng)�� �ƺ�����˳��"
                           "��(climb)\n��ȥ��������ȴ��������Ԩ������ס�\n" NOR,

	       "teng"    : YEL"\n��Щ���ٿ������ܽ�ʵ��\n" NOR,
	]));

	set("exits",([
	       "south":__DIR__"zigaihole",
	]));	    
	
	setup();

}

void init()
{
	add_action("do_tiao", ({"tiao", "jump"}));
	add_action("do_climb", "climb");
}

int do_tiao(string arg)
{
	object me, room1, room2;
	string msg;

	me=this_player();
	
	if (! room1 = find_object(__DIR__"xuanya"))
              	room1 = load_object(__DIR__"xuanya");

 	if (! arg || (arg != "ya" && arg != "xuanya" && 
                      arg != "����"))
		return 0;
	
	if (me->is_fighting() || me->is_busy())
	{
		write("��������æ���ء�\n");
		return 1;
	}	

	if (! room2 = find_object(__DIR__"xuanyadi"))
              	room2 = load_object(__DIR__"xuanyadi");

	msg = HIC"\n�����������������һ�������ߵķ硰���������죬���"
              "��Խ\n��Խ�죬һ���Ķ�Ҫ���˳�������Ȼ���㿴��������һ�ô�����"
              HIC"\n������ץס��֦��������֦ȴ��ž����һ�����ˣ������ص�ˤ\n"
	      HIC"�ڵ��ϣ���ʱ���˹�ȥ��\n\n" NOR;

	write(msg);
        me->move(room2);
	me->unconcious();
       
	me->receive_wound("qi", (int)(me->query("max_qi") / 2));

        if (random(99)<62)
		CHANNEL_D->do_channel(this_object(), "rumor", 
                   	   me->name() + "����׹�º�ɽ���£�����������");
	
	return 1;
}

int do_climb(string arg)
{
	object me, room;
	string msg;

	me = this_player();

	if (! room = find_object(__DIR__"zigai"))
		room=load_object(__DIR__"zigai");
	
	if (! arg || arg != "teng")
		return notify_fail("\n��Ҫ���Ķ�����\n\n");

	if (me->is_fighting() || me->is_busy())
		return notify_fail("\n����æ���ء�\n\n");

	msg = HIG "\n$N�����������ͱ�����ȥ��\n\n" NOR;

	message_vision(msg, me);
	write(HIW "\n����������������\n\n" NOR);
	message("vision", HIG "\n" + me->name() + HIG "���ͱ���������������\n\n" NOR,
                          room, me);

	me->move(room);

	return 1;
	
}


