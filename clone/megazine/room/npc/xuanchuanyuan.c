#include <ansi.h>

inherit NPC;

void create()
{
	set_name("ӭ��С��", ({ "yingbin xiaojie","yingbin" }) );
	set("title",HIW "����������־��" NOR);
	set("gender", "Ů��" );
	set("age", 19);
	set("long",
		"��λӭ��С�����������΢Ц��ӭ����ĵ�����\n");
	set("combat_exp", 100);
	set("attitude", "friendly");
	set("rank_info/respect", "С��");
	setup();
        carry_object("clone/cloth/female3-cloth")->wear();
}

void init()
{
	object ob;

	::init();
	if (interactive(ob = this_player()) && !is_fighting())
        {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
		call_out("greeting", 1, ob);
        }
}

void greeting(object ob)
{
	if (! ob || environment(ob) != environment()) return;
	switch (random(2))
        {
	case 0:
		say("ӭ��С�������۵�����˵������λ" + RANK_D->query_respect(ob) +
                    "����ӭ�������ռ���������\n");
		break;
	case 1:
		say("ӭ��С������΢΢�Ϲ��������۵�����˵������λ" + RANK_D->query_respect(ob) +
                    "����ӭ��ȥ������վ����http://www.cnnetgame.com��\n");
		break;
        }
}
