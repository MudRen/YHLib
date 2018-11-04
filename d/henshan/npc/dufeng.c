#include <ansi.h>
inherit NPC;
inherit F_DEALER;

void create()
{
	set_name("�ŷ��", ({ "du fenge", "du", "fenge" }) );
	set("gender", "����" );
	set("age", 22);
	set("long", "�ŷ��һ����꣬��֪������������Ϊ���¡�\n");
	set("combat_exp", 400000);
	set("attitude", "friendly");
	set("no_get", "1");
        set_skill("unarmed", 200);
        set_skill("dodge", 200);
        set_temp("apply/damage", 25);

	set("inquiry", ([
		"����"  : "��˵���ܻ��ɺ��ɣ��ҵ���������һ�ء�\n",
		"���"  : "��ٹ���þ�û�������ҵĻ��ˣ���֪����������ô���ˣ�\n",
	]));
        set("vendor_goods", ({
                "/clone/tattoo/face1",
                "/clone/tattoo/face2",
                "/clone/tattoo/face3",
                "/clone/tattoo/face4",
                "/clone/tattoo/face5",
                "/clone/tattoo/face6",
                "/clone/tattoo/face7",
                "/clone/tattoo/face8",
                "/clone/tattoo/face9",
                "/clone/tattoo/face10",
                "/clone/tattoo/face11",
                "/clone/tattoo/face12",
                "/clone/tattoo/face13",
                "/clone/tattoo/face14",
                "/clone/tattoo/face15",
                "/clone/tattoo/face16",
                "/clone/tattoo/face17",
                "/clone/tattoo/face18",
                "/clone/tattoo/face19",
                "/clone/tattoo/face20",
        }));
	setup();
	carry_object("/clone/misc/cloth")->wear();
}

void init()
{	
	object ob; 

	ob = this_player();

	::init();
	if (interactive(ob) && ! is_fighting()) 
	{
		remove_call_out("greeting");
		call_out("greeting", 2, ob);
	}
        add_action("do_list", "list");
        add_action("do_buy", "buy");
}

void greeting(object ob)
{
	if (! ob || environment(ob) != environment()) return;

	say(CYN "�ŷ��ҡ��ҡͷ������λ" + RANK_D->query_respect(ob) +
            "�����ź��ܻ��ɺ�����\n" NOR);

	return;
}
