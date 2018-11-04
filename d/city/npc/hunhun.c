#include <ansi.h>
inherit NPC;

void create()
{
	set_name("С���", ({ "xiao hunhun", "xiao", "hunhun" }));
	set("long", "�����������С��죬��������û�¸ɡ�\n");
	set("gender", "����");
	set("age", 15);
	set("attitude", "friendly");
	set("shen_type", -1);

	set("per", 15);
	set("str", 15);
	set("int", 14);
	set("con", 15);
	set("dex", 16);
	set("qi", 100);
	set("max_qi", 100);
	set("jing", 100);
	set("max_jing", 100);
	set("neili", 10);
	set("max_neili", 10);
	set("combat_exp", 200);
	set_skill("unarmed", 10);
	set_skill("dodge", 10);
	set_skill("parry", 10);

	set("chat_chance", 2);
	set("chat_msg", ({
		CYN "С��쳪��: һ�������壬��ɽ���ϻ����ϻ�û�Է���ר�Դ󻵵���\n" NOR,
		CYN "С���ߵ������²��ã�����Ҫ����ĸ��ĸ���ҿ��������ܣ�\n" NOR,
		(: random_move :)
	}) );

	setup();
	carry_object("/clone/misc/cloth")->wear();
}
