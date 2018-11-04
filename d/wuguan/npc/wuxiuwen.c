#include <ansi.h>
inherit NPC;

string give_tools();

void create()
{
        set_name("������", ({"wu xiuwen", "wu", "xiuwen"}));
        set("title", HIY "����������" NOR);
        set("gender", "����");
        set("age", 21);
        set("long", "���ǹ����Ķ����ӣ�����ǿ�ɣ�ר�Ÿ�����ڡ�\n");
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("per", 24);
        set("str", 20);
        set("int", 20);
        set("con", 30);
        set("dex", 25);

        set("max_qi", 3000);
        set("max_jing", 2500);
        set("neili", 2800);
        set("max_neili", 2800);
        set("jiali", 50);
        set("combat_exp", 400000);
        set("score", 20000);
         
        set_skill("force", 160);
        set_skill("yijin-duangu", 160);
        set_skill("dodge", 160);
        set_skill("shexing-lifan", 160);
        set_skill("finger", 160);
        set_skill("yiyang-zhi", 160);
        set_skill("sword", 160);
        set_skill("yuenv-jian", 160);
        set_skill("parry", 160);
        set_skill("literate", 140);
        set_skill("jingluo-xue", 160);
        set_skill("martial-cognize", 140);

        map_skill("force", "yijin-duangu");
        map_skill("dodge", "shexing-lifan");
        map_skill("finger", "yiyang-zhi");
        map_skill("sword", "yuenv-jian");
        map_skill("parry", "jinyuan-gun");

        prepare_skill("finger", "yiyang-zhi");

        create_family("����", 2, "����");

        set("inquiry", ([
                "����" : "������ʦĸ��",
                "����" : "������ʦ����",
                "����" : (: give_tools :),
                "tools" : (: give_tools :),
        ]));

        set("chat_chance_combat", 120);
        set("chat_msg_combat", ({
                (: perform_action, "finger.qian" :),
                (: perform_action, "finger.dian" :),
                (: perform_action, "dodge.gui" :),
                (: perform_action, "powerup" :),
                (: exert_function, "recover" :),
        }));

        setup();
        carry_object("/clone/misc/cloth")->wear();
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
	
string give_tools()
{
       	object tools, ob, me;

       	me = this_object();
       	ob = this_player();

       	if (ob->query_temp("mark/����"))
		return "�Ҳ����Ѿ�����������ô��ô���£�";

       	if (ob->query_temp("mark/����"))
		return "�㻹���ȵ�Ү��ʦ���Ǹ�������˵�ɡ�";

       	if (! ((ob->query_temp("job_name") == "��ľͷ")
	   || (ob->query_temp("job_name") == "����")
           || (ob->query_temp("job_name") == "���˵�")
	   || (ob->query_temp("job_name") == "����")
	   || (ob->query_temp("job_name") == "��ɨ��")))
             	return "����û���칤��������Ҫʲô���ߣ�";

       	if (ob->query_temp("job_name") == "����")
		tools = new("/d/wuguan/obj/chutou");
       	else
	if (ob->query_temp("job_name") == "���˵�")
		tools = new("/d/wuguan/obj/piao");
        else
	if (ob->query_temp("job_name") == "��ľͷ")
		tools = new("/d/wuguan/obj/juzi");
        else
	if (ob->query_temp("job_name") == "����")
		tools = new("/d/wuguan/obj/chaidao");
        else
		tools = new("/d/wuguan/obj/saozhou");

        tools->move(this_player());

        message_vision(HIC "$N" HIC "����$n" HIC "һ�ѹ��ߡ�\n"
                       NOR, me, ob);
        ob->set_temp("mark/����", 1);
        return "�����������ˣ���ҪС�ı��ܣ���Ū���ˡ�";
}

int accept_object(object me, object obj)
{
      	object ob;
      	me = this_object();
      	ob = this_player();

      	if (! (ob->query_temp("mark/������")
	   || ob->query_temp("mark/������")
	   || ob->query_temp("mark/������")
	   || ob->query_temp("mark/������")
	   || ob->query_temp("mark/ɨ����")))
	{
              	command("say �㻹û��ɹ�������ô�ͻ����������ˣ�͵����");
	      	return 0;
        }

      	if ((obj->query("id") != "ju zi")
	   && (obj->query("id") != "chu tou")
	   && (obj->query("id") != "shui piao")
	   && (obj->query("id") != "sao zhou")
	   && (obj->query("id") != "chai dao"))
	{
              	command("say �㻹�����˰ɣ��Ҵ�û�з����������ߡ�");
              	return 0;
        }

	if (! ob->query_temp("job_name"))
	{  
              	command("shake");
              	command("say ��û�з���������������ǲ��ǻ����ˣ�");
              	return 0;
        }
     	command("nod");
     	command("say �ɵò���������ȥҮ��ʦ���Ƕ���ȡ���Ͱɡ�");
     	ob->set_temp("mark/����", 1);
        destruct(obj);
     	return 1;
}

void greeting(object ob)
{
	if (! ob || environment(ob) != environment())
		return;

        if (ob->query_temp("mark/������")
	   || ob->query_temp("mark/������")
	   || ob->query_temp("mark/������")
	   || ob->query_temp("mark/������")
	   || ob->query_temp("mark/ɨ����"))
	{
		command("nod " + ob->query("id"));
         	command("say ��Ĺ��������ˣ������ڰѹ��߻����Ұɡ�");
         	return; 
        }

        if (ob->query_temp("mark/����"))
		return 0; 

        if ((ob->query_temp("job_name") == "��ľͷ")
	   || (ob->query_temp("job_name") == "����")
	   || (ob->query_temp("job_name") == "���˵�")
	   || (ob->query_temp("job_name") == "����")
	   || (ob->query_temp("job_name") == "��ɨ��"))
	{
       		command("nod " + ob->query("id"));
       		command("say �������������칤��(" HIY "ask wu xiuwen about ����"
                        NOR + CYN ")�İɡ�" NOR);
       	}
}
