#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIC "��������" NOR);
        set("long", @LONG
��վ��һ��ˮ֮�е�һ�������ϣ�������ˮ�����ͣ����վ�������û��
����Ṧ���Ǽ�ֲ��˶�õġ����������п�ȥ�����������ƺ�󣬽�ˮ������
���Ŀ�ȥ������ˮ����һЩ�ŹֵĶ�����

LONG);
        setup();
} 

void init()
{
	add_action("do_jump", "jump");
}

int do_jump (string arg)
{
 	object me = this_player();
	if (! arg || arg == "") return 0;
	if (arg == "down")
	{
		if(! random(10)) 
		{
                	me->set_temp("die_reason", "��������");
			me->die();
		} else
		{
			tell_object(me, "��ܲ�����������˽��У�һ��ˮӿ������\n");
			me->move(__DIR__"river");
		 	me->unconcious();}
			return 1;
		}	
	else
	return notify_fail("��Ҫ��ʲô��\n");
}