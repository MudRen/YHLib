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
		set("long",HIW 
"����2000�������"HIG"��������"HIW"��־��Ŀ¼�嵥�������(kankan mulu)
�Ӷ����Դ������˽⵽����"HIG"��������"HIW"��־�Ĵ�����ݡ��Ķ�������־��
ϸ�����뵽http://ultrahell.yeah.net"HIG"��������"HIW"��־���ܲ���\n" NOR);
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
		add_action("do_kankan", "kankan");
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
		                   "����֮��:�����ֲ���ȥ�ĵط��� | ���Ĵ���ʦλ�á�\n"
		                   "��������:��PKER������ | �������ˡ��� | ������ʡ�\n"
		                   "������:��ǳ��mud���Լ��ɴ����쵽�����е���Ů��ϵ��\n"
		                   "��ƪ����:���ռ�����֮�ڿ��¼���\n" NOR);
	}

	return 1;
}
