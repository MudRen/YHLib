// zazhi.c
#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(HIG "����������־�ڶ�����Ŀ¼" NOR, ({ "zazhi mulu","zazhi","mulu" }));
	set_weight(100);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long",HIW 
"����2000���һ��"HIG"��������"HIW"��־��Ŀ¼�嵥�������(kankan mulu)
�Ӷ����Դ������˽⵽����"HIG"��������"HIW"��־�Ĵ�����ݡ��Ķ�������־��
ϸ�����뵽http://ultrahell.yeah.net"HIG"��������"HIW"��־���ܲ���"HIR"������־
���ر�ע���һ�졺�����۽��������ݡ�\n" NOR);
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
		message_vision(HIW
"$N��"HIG"��������"HIW"��־2000��ڶ��ڵ�Ŀ¼��
"HIR"���ڵ�һ�Ρ������۽��������˵��"HIW"
����֮��:����������ɡ���ľ��ֻ��qn ����exp�� 
����������������������|���޻���һ����|�����ݵ�һ���� 
��̸���ۣ���PK��ʦ�� |��PK DOING֮�ж��ƻ��� 
��ƪ���£�Ľ��С�--����������Ե��|�������ֺ�ɳɳ���Ĺ��� ��(��)
"HIG"��������"HIW"��־��ַ��http://ultrahell.yeah.net\n" NOR,this_player());
	}

	return 1;
}
