inherit NPC;

void create()
{
	set_name("�����ױ�", ({ "qin bing", "qin", "bing" }));
	set("age", 32);
	set("gender", "����");
	set("long", "һ������ְ�ص��ױ��������ע���Ź������ˡ�\n");
	set("attitude", "peaceful");
	set("str", 24);
	set("dex", 23);
	set("combat_exp", 100000);
	set("shen_type", 1);

	set_skill("unarmed", 60);
	set_skill("dodge", 60);
	set_skill("parry", 60);
	set_skill("sword", 60);
	set_skill("force", 60);
	set_temp("apply/attack", 60);
	set_temp("apply/defense", 60);
	set_temp("apply/damage", 60);
	set_temp("apply/armor", 60);


	setup();
	carry_object(__DIR__"obj/changjian")->wield();
	carry_object(__DIR__"obj/armor")->wear();
}


