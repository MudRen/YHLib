#include <ansi.h>;

inherit KNOWER;
inherit F_DEALER;

void create()
{
	set_name("��С��", ({ "xiao er", "xiao" }));
	set("shen_type", 1);

	set("str", 30);
	set("gender", "����");
	set("age", 25);
	set("long",
		"�����С����æ�Ÿ������Ͳ裬���̡�");
	set("combat_exp", 500);
	set("attitude", "friendly");
		
	set("vendor_goods", ({
		__DIR__"obj/yan",
		__DIR__"obj/wan",
	}));

	setup();
	carry_object("/clone/misc/cloth")->wear();
}

void init()
{       
        object ob;

        ::init();
        add_action("do_buy", "buy");
        add_action("do_list", "list");

        if ( interactive(ob = this_player()) && !is_fighting() )
        {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

void greeting(object ob)
{
	if (! ob || environment(ob) != environment())
		return;
	switch(random(2))
        {
	case 0 :
		say (CYN "��С�������˵������λ" + RANK_D->query_respect(ob) +
		     CYN "�����ϸ����ϲ衣\n" NOR);
		break;
	case 1 :
		say (CYN "��С��˵������λ" + RANK_D->query_respect(ob) + 
		     CYN "Ҫ��Ҫ������ˮ��������\n" NOR);
		break;
	}
}
