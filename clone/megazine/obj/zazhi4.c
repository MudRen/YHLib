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
                                    "�����������ǡ���ѡ�˵�� \n"
                                    "�Ӽ����𣬷��򡼵�������־��Ͷ������߶����ʸ��Ϊ�����������ǡ��ĺ�ѡ�ˡ� \n"
                                    "�����������ǡ�����ѡ������Լ�ͶƱѡ��������������־�縺�����ڼ�İ��Ź�����  \n"
                                   "�����������ǡ�����ѡ��ÿ�����½���һ�Σ�����Ϊ�����������ǡ��߿ɻ�á����������ǡ���ͷ��һ�����Լ�200GOLD�Ľ����� \n"
                                    "�������Ȩ������������־�����С�  \n"
                                   "��ƪ���أ�sasamei�����¼������أ���֪��sasamei��kidd�������������뿴: \n"
                                   "              �������ֺ�ɳɳ���Ĺ��¡����£� \n"
                                   "������������һ������ҵĻ��������£������¼�˲��ٵ�����ǰ�����飬������ǿɲ��ܴ����  \n"
                                   "                   ���̽��߽�����  \n" NOR);
	}

	return 1;
}
