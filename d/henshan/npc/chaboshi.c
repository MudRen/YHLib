#include <ansi.h>;

inherit KNOWER;
inherit F_DEALER;

void create()
{
	set_name("�販ʿ", ({ "cha boshi", "boshi" }));
	set("title", "����ϰ�");
	set("shen_type", 1);

	set("str", 30);
	set("gender", "����");
	set("age", 35);
	set("long",
		"����販ʿ���Ǻ���������Ϣ��ͨ��ʿ��ÿ��ӭ��������\n"
		"���ԶԳ����һ��һ��������ָ�ơ�\n");
	set("combat_exp", 500);
	set("attitude", "friendly");
	
	set("vendor_goods", ({
        	"/d/city/npc/obj/peanut",
        	"/d/city/npc/obj/tofu",
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

        if (interactive(ob = this_player()) && ! is_fighting())
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
		say(CYN "�販ʿ���˿�����˵������λ" + RANK_D->query_respect(ob) +
			"������ҿ�������ȱ��Ȳ衣\n" NOR);
		break;
	case 1 :
		say(CYN "�販ʿ˵��������ң���λ" + RANK_D->query_respect(ob) + 
			"�����С�����費���ƣ�����ң�\n" NOR);
		break;
	}
}
