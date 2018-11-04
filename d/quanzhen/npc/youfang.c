#include <ansi.h>;
inherit NPC;

void create()
{
	set_name("�η�����", ({ "youfang daoren", "youfang", "daoren" }));
	set("long", "����һλδͨ���ʵ�������ˣ����Ϲ��ź�\n"
                    "�����΢Ц��\n");

	set("gender", "����");
	set("attitude", "heroism");
	set("class", "taoist");

	set("age", 20);
	set("shen_type", 1);
	set("str", 15);
	set("int", 30);
	set("con", 30);
	set("dex", 18);
	set("max_qi", 280);
	set("max_jing", 300);
	set("neili", 380);
	set("max_neili", 380);
	set("jiali", 27);
	set("combat_exp", 10000);
	set("shen_type", 1);

	set("chat_chance", 10);
	set("chat_msg", ({
		CYN "�η�����˵������ʩ�����������Ӹ�ƶ������ϲ"
                "��ϲ���츣������\n" NOR,
		(: random_move :)
	}) );

	set_skill("force", 41);
	set_skill("strike", 41);
	set_skill("dodge", 41);
	set_skill("parry", 41);
	set_skill("jinyan-gong", 42);
	set_skill("haotian-zhang", 41);
	set_skill("quanzhen-xinfa", 41);

	map_skill("force", "quanzhen-xinfa");
	map_skill("dodge", "jinyan-gong");
	map_skill("strike", "haotian-zhang");
	map_skill("parry", "haotian-zhang");
        create_family("ȫ���", 4, "����");
	setup();
	carry_object("/d/city/obj/cloth")->wear();

	setup();

}
