#include <ansi.h>
inherit NPC;
inherit F_DEALER;

void create()
{
	set_name(HIG "����������־����С��" NOR, ({ "xiaojie"}) );
	set("female", "Ů��" );
	set("age", 21);
	set("long",
		"����һλ����������С�㣬���������͡���������־,�����������Ҫ(yao zazhi)��\n");
	set("combat_exp", 100);
	set("attitude", "friendly");
	set("rank_info/respect", "С��");
       	set("inquiry", ([ 
		"zazhi": "���������ṩ����ҵġ���������־��\n",
		"mulu": "���������ṩ����ҵġ���������־��\n",
		"������־": "û��������һ���Ǵ�ɵ�ϡ�\n"
	]) );
       	set("chat_chance", 15); 
       	set("chat_msg", ({
		"����С��˵�������ǵġ���������־���Ǻã����Ƴ��͵õ��˴�ҵ��Ͽɡ�\n"
		"����С�����˵������û��������������־���Ǿ�̫��ϧ��! \n",
		"����С������ϵġ���������־������һ�¡�\n",
	}) );
	carry_object("/clone/cloth/female5-cloth")->wear();
       	setup ();
}

