#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","ˮ������");
	set("long",@LONG
�ߵ������û��·�ˣ����ܶ���ͻ��Ĺ�ʯ(stone),����
��������ˮ˳��ͻʯ����������ˮ�ν��ڵ��Ϸ�����žણ�ž
ડ���������˳��ˮ��������ȥ����ˮ��Դͷ����Լ��һ˿��
�����������������ܸߣ�վ������Ҳ���������������Χһ
�������Ҳ�����ʱ��·�ˣ��������º�Ȼ��
LONG);
	
	set("item_desc",([
	      "stone" : HIG "\nֻ��ͻʯ������ᾣ�ˮ������˳����¡�"
                        "ʯͷ����ȴ�Ѿ���������̦��\n\n" NOR,
	]));
	
	setup();

}


void init()
{	
	add_action("do_climb",({"climb","pa"}));
	add_action("do_tiao",({"tiao","jump"}));
}

int do_tiao(string arg)
{
	object me = this_player();
	
	if (! arg || arg != "stone")
		return notify_fail("��Ҫ���Ķ�����\n");

	message_vision(HIC "\n$N������ͻʯ��һ������������ȴ��������̦��"
                        "$Nһ��������ˤ����������ʱ���˹�ȥ��\n\n" NOR,me);
	
	me->unconcious();

	return 1;
}


int do_climb(string arg)
{
	object me = this_player();

	if(! arg || arg != "stone")
		return notify_fail("��Ҫ���Ķ�����\n");

	write(HIC "\n���ߵ������ԣ���������ͻʯ���Ų�����ͻʯ��"
              "��һ����㵽�˸ߴ���\n\n" NOR);

	me->move(__DIR__"outzigai1");

 	return 1;
}

