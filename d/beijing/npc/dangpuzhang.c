#include <ansi.h>
inherit NPC;
inherit F_DEALER;
int ask_weiwang();

void create()
{
	set_name("�ŵ¹�", ({ "zhang degui", "zhang", "dedui" }));
	set("title", "�����ϰ�");
	set("shen_type", 1);

	set("gender", "����");
	set_max_encumbrance(100000000);
	set("age", 35);
	set("long","\nһ����ʮ��������ӣ���ĸ��ݣ�������ʮ�־����ܸɡ�\n");
	set("no_get_from", 1);

	set_skill("unarmed", 60);
	set_skill("dodge", 60);
	set_temp("apply/attack", 30);
	set_temp("apply/attack", 30);
	set_temp("apply/damage", 15);

	set("combat_exp", 50000);
	set("attitude", "friendly");

	setup();
	carry_object("/d/beijing/npc/obj/cloth")->wear();
}

void init()
{
       add_action("do_list", "list");
       add_action("do_buy", "buy");
	add_action("do_sell", "sell");
	add_action("do_value", "value");
}