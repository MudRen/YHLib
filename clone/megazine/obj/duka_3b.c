inherit ITEM;
inherit F_UNIQUE;
#include <ansi.h>

int sy=0;
string qd="ƽ��";
int peis=3,peig=5;
int peis=4,peig=5;

void create()
{
        set_name(HIC"����B"NOR, ({ "duqiu ka","ka", }));
        set_weight(500);
       if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long",HIY 
        "���Ŷ�������д��:" + qd + "Ӯ\n"
        "��ֵ��10 cash ����:" + peis + "." + peig +"\n"
        "�����ڿ��Զһ�(change)֧Ʊ�ˡ�\n"  NOR
        );
                set("value", 1);
                set("material", "silk");
                set("no_sell",1);
                set("no_pawn",1);
        }
}

void init()
{
	if( this_player() == environment() )
	{
		add_action("do_change", "change");
	}
}

int do_change()
{
	object ob=this_object();
	object me=this_player();

	if (sy == 1)
	 {
	   message_vision(HIC "$N�һ��˶��򿨡�\n" NOR,me);
	   tell_object(me,HIC "����Ӯ��Ǯ�Ѿ��㵽����������ʺ��ϡ�\n" NOR);
           me->add("balance", 1000000 * peis);
           me->add("balance",100000 * peig);

	   destruct(ob);
	   return 1;
	 }
	else if (sy == 0)
	  {
	    message_vision(HIC "$N�һ��˶��򿨡�\n" NOR,me);
	    tell_object(me,HIC "��Ǹ�������ˣ���ʲôҲû�õ���\n" NOR);
	    destruct(ob);
	    return 1;
	  }
	 else if (sy ==2)
	    {
	    	tell_object(me,HIC "�Բ�����û��Ҫ�󻻿���������������ˡ�\n" NOR);
	    	destruct(ob);
	    }
	 return 1;
}
