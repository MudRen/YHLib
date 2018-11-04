#include <ansi.h>
inherit NPC;
void greeting(object ob);
int accept_fight(object ob);
void create()
{
	seteuid(getuid());
	set_name("�ﲮ��", ({ "tian boguang", "tian","boguang" }));
	set("long", "��һ��Ʈ�ݵİ�ɫ�������������š�\n");
	set("nickname", HIM "�������" NOR);
	set("gender", "����");
	set("age", 37);
	set("attitude", "friendly");
	set("shen_type", -1);

       set("per", 23);
	set("str", 25);
	set("int", 24);
	set("con", 25);
	set("dex", 26);

	set("qi", 1000);
	set("max_qi", 1000);	
	set("combat_exp", 800000);
	set("score", 40000);

	set_skill("blade", 100);
	set_skill("dodge", 150);
	set("jing", 800);
	set("max_jing", 800);
	set("neili", 1000);
	set("max_neili", 1000);
	set("jiali", 100);

	set_skill("blade",150);
	set_skill("parry", 120);
	set_skill("force", 120);
	set_skill("lingxu-bu", 150);
	set_skill("kuangfeng-blade", 150);

	map_skill("dodge", "lingxu-bu");
	map_skill("parry", "kuangfeng-blade");
	map_skill("blade", "kuangfeng-blade");

        set("chat_msg_combat", ({
                (: perform_action, "blade.kuang" :),
        }) );
	set("chat_chance", 10);
	set("chat_msg", ({
		CYN "�ﲮ��Ц�������Ҳû��ϵ�����ͷ���������¾���С�����ˡ�\n" NOR,
	}) );

	setup();
	carry_object("/d/baituo/obj/baipao")->wear();
	carry_object("/clone/weapon/gangdao")->wield();
	add_money("silver",40);
}

void init()
{
	object ob;

	::init();

	if( interactive(ob = this_player()) && !is_fighting() ) 
       {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}
void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	if ((string)ob->query("gender")=="Ů��")
	{
	if (ob->query("age")<26) 
		say(CYN "�ﲮ��Ц����������������һ��С���\n" NOR);     
	else 
		say(CYN "�ﲮ��Ц������������ϧ̫���˵㣬�ҿ�ûθ�ڡ�\n" NOR);     
	}
	else 
		say(CYN "�ﲮ��Ц�������֣���λ"+RANK_D->query_respect(ob) + "����"
                    "���������С��������Ҳûʲô�£����������ž��ǡ�\n" NOR);
	return;
}

int accept_fight(object ob)
{
	if ((string)ob->query("gender") == "Ů��")
	{
		write(CYN "�ﲮ��Ц���������ɱ��̫��ϧ�˵ġ�\n" NOR);
		return 0;
        }
	return 1;
}
 
