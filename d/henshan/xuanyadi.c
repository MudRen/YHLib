#include <ansi.h>

inherit ROOM;

void create()
{
	set("short","���µ�");
	
	set("long",@LONG
�����Ǻ�ɽ���µף����ܶ������¾��ڰ�Χ�ţ���Ŀһ����
ֻ�������������±ڶ��ͣ�ֱû��ʣ���ֻ��ӥ���Ͽղ��ϵ�
�����������ϴ��¼�������(teng)����������˳������������
��������������ǰ��һ�þ޴�Ĺ���(tree)���ղ����Һ�ץס
�����������֦����Ȼ��ͷ�������ˡ��㵽�����˿�������
�ƺ�û������·���ߡ�
LONG);

	set("item_desc",([
	      "teng": HIG "\n������ٿ������ܽ�ʵ������������(climb)�����¡�\n" NOR,
	      "tree": YEL "\n������������ɴִ��ʵ�������и���֦�Ѿ����۶��ˡ�\n" NOR,
	]));	
	   
	set("objects",([
	      "/clone/quarry/tu" : 7,	
	]));

	set("outdoors","henshan");

	setup();
}


void init()
{              
	add_action("do_climb",({"climb","pa"}));
	
}

int do_climb(string arg)
{
	object me, here, zigai;
	string msg;
	int qi;

	me = this_player();
	qi = me->query("qi");
	
	if (! arg || (arg != "teng" && arg != "tree"))
		return notify_fail("�������Ķ�����\n");
	
	if ( !here = find_object(__DIR__"xuanyandi"))
		here = load_object(__DIR__"xuanyadi");
	if ( !zigai = find_object(__DIR__"zigai"))
		zigai=load_object(__DIR__"zigai");

	if ( arg == "teng")
	{
         	msg = HIG "\n$N" HIG "�����������ͱ�����ȥ��\n"NOR;
	
        	if(qi < 100)
		{
			msg += HIM "\n$N " HIM "������֪�����ͱ���ˤ��������\n" NOR;
			message_vision(msg, me);
			me->unconcious();
			return 1;
		}

		message_vision(msg, me);
		message("vision",HIG "\n"+me->name()+"���ͱ���������������\n", zigai, me);
		me->move(zigai);

		return 1;

        }

        me->move(__DIR__"ontree");

	return 1; 
	
}



