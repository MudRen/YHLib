inherit NPC;

void create()
{
	set_name("�販ʿ", ({ "cha boshi", "cha", "boshi" }) );
	set("gender", "����" );
	set("age", 32);
	set("long",
		"һ���ڲ������˵��Ϊ������ͷ��\n");
	set("shen_type", 1);
	set("combat_exp", 10000);
       set("str", 10);
       set("dex", 10);
       set("con", 10);
       set("int", 10);
	set("attitude", "peaceful");
       set_skill("dodge",20);
       set_skill("unarmed",20);
       set("chat_chance", 1);
       set("chat_msg", ({
                "�販ʿҡͷ���Ե�˵���顣\n",
        }) );       
	setup();
       carry_object("/d/beijing/npc/obj/cloth")->wear();
	add_money("silver", 2);
}
