#include <ansi.h>;

inherit KNOWER;
inherit F_DEALER;

void create()
{
	set_name("�°���", ({ "chen apo", "chen", "apo" }));
	set("title", "�ӻ����ϰ�");
	set("shen_type", 1);
	set("str", 20);
	set("gender", "Ů��");
	set("age", 55);
	set("long", "�°��žþӷ��ݳǣ���˵������ʱ���м��ַ��ϡ�\n");
	set("combat_exp", 800);
	set("attitude", "friendly");
	set("inquiry", ([
                "������" : "���������ǿ����ǻ���һ�����������ţ�����\n",
	]));
	
	set("vendor_goods", ({
		"/d/fuzhou/obj/xiuhua",
		"/d/fuzhou/obj/flower_shoe",
                "/d/fuzhou/obj/pink_cloth",
                "/d/city/obj/goldring",
                "/d/city/obj/necklace",
	}));

	setup();
        carry_object("/clone/misc/cloth")->wear();
}

void init()
{
	object ob;	
	::init();

	if (interactive(ob = this_player()) && ! is_fighting())
        {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
        add_action("do_list", "list");
        add_action("do_buy", "buy");
}

void greeting(object ob)
{
	if (! ob || environment(ob) != environment())
		return;
	switch(random(2))
        {
	case 0 :
		say(CYN "�°���Ц���е��к������˿�������\n" NOR);
		break;
	case 1 :
		say(CYN "�°���Ц���е�˵��������ģ���Ҫ��ʲ��\n" NOR);
		break;
	}
}
