inherit NPC;
#include <ansi.h>

void create()
{
        set_name("��԰����", ({ "caiyuan guanshi", "guanshi" }) );
        set("gender", "����" );
        set("age", 50);
        set("long", "���ǲ�԰���£�ר�ܲ�԰���С���£�\n");
        set("combat_exp", 2500);
        set("attitude", "friendly");
        set("inquiry", ([
        	"��ˮ" : "�����������ʵʵ���ҽ�ˮ��û���ҵ����⣬������ȥ������",
        ]) );
        setup();

}

void init()
{
        object ob;

        ::init();
        if (interactive(ob = this_player()) && ! is_fighting())
	{
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

void greeting(object ob)
{
        if (! ob || environment(ob) != environment()) return;
         
        if (ob->query_temp("job_name") != "���˵�") return;

        if (! (present("shui piao", ob)))
        {
        	command("hmm " + ob->query("id"));
        	command("say �㻹û�칤�߰ɣ�ȥ����Ʒ������үҪ��������\n");
        	return;
        }

        if (! (ob->query_temp("job_name") != "���˵�"))   
        {
        	command("nod " + ob->query("id"));
                command("say ��Ү�ɴ�ү�Ը������İɣ���������⽽ˮ(" HIY
                        "jiao shui" NOR + CYN ")���ˡ�\n" NOR);
        }
}
