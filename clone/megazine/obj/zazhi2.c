// zazhi.c
#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(HIG "〖地狱〗杂志第二期总目录" NOR, ({ "zazhi mulu","zazhi","mulu" }));
	set_weight(100);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "册");
		set("long",HIW 
"这是2000年第一期"HIG"〖地狱〗"HIW"杂志的目录清单，你可以(kankan mulu)
从而可以从上面了解到本期"HIG"〖地狱〗"HIW"杂志的大概内容。阅读本期杂志详
细内容请到http://ultrahell.yeah.net"HIG"〖地狱〗"HIW"杂志社总部。"HIR"本期杂志
请特别注意第一届『地狱论剑』的内容。\n" NOR);
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
		return notify_fail("什么？\n");
	}

	me = this_player();

	if ( arg == "mulu" )
	{
		message_vision(HIW
"$N打开"HIG"〖地狱〗"HIW"杂志2000年第二期的目录：
"HIR"关于第一次『地狱论剑』的相关说明"HIW"
地狱之窗:新手问题答疑《打木人只涨qn 不涨exp》 
泥友心声：《男人心声》|《无悔这一生》|《短暂的一生》 
奇谈怪论：《PK巫师》 |《PK DOING之行动计划》 
长篇故事：慕容小寰--《新网络情缘》|《柳长街和沙沙美的故事 》(上)
"HIG"〖地狱〗"HIW"杂志地址：http://ultrahell.yeah.net\n" NOR,this_player());
	}

	return 1;
}
