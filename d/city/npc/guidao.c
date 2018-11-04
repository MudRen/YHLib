#include <ansi.h>

inherit NPC;

string ask_me(object who);

void create()
{
	set_name("����", ({ "wang wu", "wang", "wu" }));
	set("title", "����¥�ƿ�");
	set("gender", "����" );
	set("long", "���Ǹ��ȵ��������ľƹ����������еľƱ��૵���߶��ʲ�ᡣ\n" );
	set("shen_type", -1);
	set("age", 40);
	set("str", 25);
	set("con", 25);
	set("dex", 25);
	set("int", 25);
        set("max_qi", 800);
        set("max_jing", 500);
        set("neili", 500);
        set("max_neili", 500);
        set("jiali", 10);
	set("combat_exp", 100000);
	set("attitude", "heroism");
	set("chat_chance_combat", 15);
	set("chat_msg_combat", ({
		CYN "����˵�����㵱����˱��ӵ����Ҹ���ү������\n" NOR,
		CYN "�����Ȼ�ӳ�һ�����������棬��������;ȴ�ּ�æ���С�\n" NOR,
		CYN "����˵����������������˻����С���\n" NOR
	}) );

	set("inquiry", ([
		"������" : "����������Ȥ��Ȥ����ϧ���ϴ����ˡ�" ,
		"��"   : (: ask_me :),
	]) );
	set_skill("blade", 100);
	set_skill("dodge", 80);
	set_skill("unarmed", 80);
	set_skill("parry", 80);
        set_skill("literate", 60);
        set_skill("lamaism", 80);
        set_skill("martial-cognize", 80);

	setup();	
	carry_object("/clone/weapon/gangdao")->wield();
	carry_object("/clone/cloth/cloth")->wear();
}

string ask_me(object who)
{
	int i;
	object *ob;

	if (query("revealed"))
	{
		if (is_killing(who))
			return "���Ȼ֪�����ҵ���֣��������������\n";
		else {
			kill_ob(who);
			who->fight_ob(this_object());
			return "���Ӿ��ǹ����壬��������������ӣ��������ɣ�\n";
		}
	}

	if( (random(10) < 5) || is_fighting() )
		return "�ҡ����Ҳ�֪����\n";

	set_temp("apply/attack",  80);
	set_temp("apply/defense", 80);
	set_temp("apply/damage",  50);

	set("title", HIR "��" NOR);

	message("vision", HIY "��������ͻȻ�ų������Ĺ�â������˵���������������㶼֪���ˣ�\n"
		          "������һ�����е�����Ȼ��ˣ����ӽ��췴�����ȥ������ƴ�ˡ�\n" 
		          "����ʹ���������������棬���ͺ������͸ղŵ�����ֱ�������ˡ�\n" NOR,
		          environment(), this_object() );

	set("pursuer", 1);
	set("attitude", "aggressive");
	set("vendetta/authority", 1);
	set("chat_msg_combat", ({(: random_move :)}) );
	set("chat_chance", 15);
	set("chat_msg", ({(: random_move :)}) );
	set("bellicosity", 10000);
	set("combat_exp", 300000);
        set("neili", 1000);
        set("max_neili", 1000);
        set("jiali", 50);

	set_skill("xuedao-dafa", 100);
        set_skill("shenkong-xing", 80);
        set_skill("hand", 80);
        set_skill("dashou-yin", 80);
        set_skill("cuff", 80);
        set_skill("yujiamu-quan", 80);

        map_skill("force", "xuedao-dafa");
        map_skill("dodge", "shenkong-xing");
        map_skill("hand", "dashou-yin");
        map_skill("cuff", "yujiamu-quan");
        map_skill("parry", "xuedao-dafa");
        map_skill("blade", "xuedao-dafa");

        prepare_skill("cuff", "yujiamu-quan");
        prepare_skill("hand", "dashou-yin");

        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                (: perform_action, "hand.yin" :),
                (: perform_action, "cuff.jiang" :),
                (: exert_function, "powerup" :),
                (: exert_function, "resurrect" :),
        }) );

	ob = all_inventory(environment());
	for(i = sizeof(ob)-1; i >= 0; i--)
	{
		if (! userp(ob[i])) continue;
		kill_ob(ob[i]);
		ob[i]->fight(this_object());
	}
        add_money("silver", 50);
	set("revealed", 1);
	return "���Ӿ��ǹ����壬��������������ӣ��������ɣ�\n";
}
