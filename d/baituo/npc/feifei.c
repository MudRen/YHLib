inherit NPC;

void create()
{
	set_name("��ʦ", ({ "chu shi", "chu", "shi" }));
	set("gender", "����" );
	set("age", 35);
	set("long", "һ����ͷ����ĳ�ʦ����ֻС�۾���ͣ��գ���š�\n");
	set("shen_type", -1);
	set("combat_exp", 10000);
	set("str", 20);
	set("dex", 22);
	set("con", 20);
	set("int", 21);
	set("attitude", "friendly");
	setup();
	carry_object("/clone/misc/cloth")->wear();
	add_money("silver", 3);
}
