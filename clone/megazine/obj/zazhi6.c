// zazhi.c
#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(HIG "����������־��������Ŀ¼" NOR, ({ "zazhi mulu","zazhi","mulu" }));
	set_weight(100);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", 
"����2000�������"HIG"��������"NOR"��־��Ŀ¼�嵥�������(list mulu)
�Ӷ����Դ������˽⵽����"HIG"��������"NOR"��־�Ĵ�����ݡ��Ķ�������־��
ϸ�����뵽http://www.cnnetgame.com/hell/hell.htm"HIG"��������"NOR"��־���ܲ���\n");
		set("value", 1);
		set("material", "paper");
                set("no_sell", 1);		              
	}
        setup ();
}

void init()
{
	if( this_player() == environment() )
	{
		add_action("do_kankan", "list");
	}
}

int do_kankan(string arg)
{
	object me, magazine;
	
	if ( !arg )
	{
		return notify_fail("ʲô��\n");
	}

	me = this_player();

	if ( arg == "mulu" )
	{
		tell_object(me,HIW "���ڡ���������־Ŀ¼��\n"
                                   " ������� ����ª�ĵ����ˣ�һ������è�ӵĹ��¡���ª�ĵ����ˣ�����--��ˮ���Ĵ�˵ \n"
                                   "            �����㡢to jeeny ���� ��Զ���������塢͵͵���� to Nymph���뵱��\n"
                                   "���ռ�������������Ƥ��: ��ת�𵤼�����Ƥ��\n"
                                   "\n" NOR);
	}

	return 1;
}
