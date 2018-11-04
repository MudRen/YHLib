#include <ansi.h>
#include <command.h>
#include <login.h>

inherit NPC;

string *death_msg = ({
	HIW "���޳�˵����ι�������ģ����ʲô���֣�\n\n" NOR,
	HIW "���޳���������۹ⶢ���㣬����Ҫ�������һ���Ƶġ�\n\n" NOR,
	HIW "���޳����ߡ���һ�����������ͳ�һ�����ʲ�Ķ�����������\n\n" NOR,
	HIW "���޳����ϲ��ӣ�˵�����ף�����δ������ô���ܣ�\n\n" NOR,
	HIW "���޳�ɦ��ɦͷ��̾�������˰��ˣ����߰ɡ�\n\n"
		"һ�������Ũ��ͻȻ���֣��ܿ�ذ�Χ���㡣\n\n" NOR,
});

void create()
{
	set_name("���޳�", ({ "hei wuchang", "hei", "wuchang" }));
	set("title", HIR "ڤ���ز�����ǰ" NOR);
	set("long", "\n���޳������㣬���Ƶ����Ͽ������κ�ϲŭ���֡�\n");
	set("attitude", "peaceful");
	set("chat_chance", 15);
	set("chat_msg", ({
		CYN "���޳��ٺٸ�Ц��������������䵽�ҵ������ˡ���\n" NOR,
		CYN "���޳�������������֪���ڴ�ʲô���⡣\n" NOR,
	}) );
	set("age", 217);

        set("max_qi", 9999);
        set("max_jing", 9999);
        set("neili", 9999);
        set("max_neili", 9999);
        set("jiali", 250);

        set("combat_exp", 50000000);

        set_skill("unarmed", 500);
        set_skill("sword", 500);
        set_skill("blade", 500);
        set_skill("staff", 500);
        set_skill("hammer", 500);
        set_skill("club", 500);
        set_skill("whip", 500);
        set_skill("dagger", 500);
        set_skill("throwing", 500);
        set_skill("parry", 500);
        set_skill("dodge", 500);
        set_skill("force", 500);
        set_skill("never-defeated", 1000);
        set_skill("magic", 1000);

        map_skill("sword", "never-defeated");
        map_skill("blade", "never-defeated");
        map_skill("staff", "never-defeated");
        map_skill("hammer", "never-defeated");
        map_skill("club", "never-defeated");
        map_skill("whip", "never-defeated");
        map_skill("dagger", "never-defeated");
        map_skill("parry", "never-defeated");
        map_skill("dodge", "never-defeated");
        map_skill("force", "never-defeated");

        setup();

        carry_object(__DIR__"obj/cloth1")->wear();
        carry_object(__DIR__"obj/suolian")->wield();
        set_temp("handing", carry_object(__DIR__"obj/bi"));
}

void init()
{
	::init();
	if (! previous_object() ||
	    ! userp(previous_object()) ||
	    ! previous_object()->is_ghost() ||
	    wizardp(previous_object())) return;
	call_out("death_stage", 5, previous_object(), 0);
}

void death_stage(object ob, int stage)
{
	int i;
	object *inv, mailbox;
	if (! ob || ! present(ob)) return;

	tell_object(ob, death_msg[stage]);
	if (++stage < sizeof(death_msg))
	{
		call_out( "death_stage", 5, ob, stage );
		return;
	} else
		ob->reincarnate();

        if (! wizardp(ob))
        {
    	        inv = all_inventory(ob);
    	        for (i = 0; i < sizeof(inv); i++)
    		        DROP_CMD->do_drop(ob, inv[i]);
        }
	
	ob->move(REVIVE_ROOM);
        ob->set("startroom", REVIVE_ROOM);
	message("vision", HIW "���Ȼ����ǰ�����һ����Ӱ����������Ӱ�ֺ����Ѿ�������\n"
		          "�ܾ��ˣ�ֻ����һֱû������\n" NOR, environment(ob), ob);
}
