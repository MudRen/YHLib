#include <ansi.h>
inherit NPC;
inherit F_DEALER;

void create()
{
        set_name("����ǿ", ({ "huang zhiqiang", "zhiqiang", "huang" }));
	set("nickname", HIM "ʳ��ħ" NOR);
        set("title", "�ӻ����ϰ�");
	set("long", @LONG

LONG);
        set("shen_type", 1);
        set("gender", "����");
        set("age", 20);
	set("per", 24);
        set_skill("unarmed", 200);
        set_skill("dodge", 200);
        set_temp("apply/damage", 25);
        set("combat_exp", 800000);
	set("no_get", "1");
        set("attitude", "friendly");
        set("vendor_goods", ({
		"/d/xingxiu/obj/fire",
		"/d/henshan/obj/mujian",
		"/d/henshan/obj/jia",
                "/d/item/obj/chanhs",
                "/d/city/obj/rrose",
                "/d/city/obj/yrose",
                "/clone/misc/wood",
                "/clone/misc/shoeshine",
                "/clone/misc/brush",

        }));
        
        setup();
	carry_object("/clone/cloth/cloth")->wear();

}

void init()
{	
	object ob; 

	ob = this_player();

	::init();
	if( interactive(ob) && !is_fighting() ) 
	{
		remove_call_out("greeting");
		call_out("greeting", 2, ob);
	}

	add_action("do_buy", "buy");
	add_action("do_list", "list");
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;

	say(CYN "����ǿЦ��˵������λ" + RANK_D->query_respect(ob)+ "����"
	    "��Щʲô������㿴��\n" NOR);

	return;
}












