#include <ansi.h>;
inherit NPC;

void create()
{
        set_name("ά�����Ů", ({ "shao nv", "shao", "nv" }) );
        set("gender", "Ů��" );
        set("age", 19);
        set("long", "��λС����һ��æ��æ�⣬���Ϳ�����˵��Ц��\n");
        set("combat_exp", 100);
        set("attitude", "friendly");
        set("rank_info/respect", "С����");
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
        if (! ob || environment(ob) != environment() ) return;
        switch(random(2))
	{
        case 0:
                say(CYN "ά�����Ů˵������λ" + RANK_D->query_respect(ob) +
                    CYN "�������ȱ��̲裬ЪЪ�Ȱɡ�\n" NOR);
                break;
        case 1:
                say(CYN "ά�����Ů˵������λ" + RANK_D->query_respect(ob) +
                    CYN "�����������\n" NOR);
                break;
        }
}

int accept_object(object who, object ob)
{
        
        if (ob->query("money_id") && ob->value() >= 5000) 
        {
                tell_object(who, CYN "ά�����Ůæ˵������л����������¥ЪϢ�ɡ�\n" NOR);

                who->set_temp("rent_paid",1);

                return 1;
        }
        return 0;
}
