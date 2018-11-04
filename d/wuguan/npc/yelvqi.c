#include <ansi.h>

inherit NPC;
string *names = ({"��ɨ��", "��ľͷ", "����", "���˵�", "����" });
string ask_job();

void create()
{
        set_name("Ү����", ({ "yelv qi", "yelv", "qi" }));
        set("title", "ȫ��̵ڶ�������");
        set("nickname", HIY "ؤ�����" NOR);
        set("long", "Ү�����ǹ����ͻ��صĴ�Ů������ܽ���ɷ�\n");
        set("gender", "����");
        set("age", 35);
        set("str", 35);
        set("dex", 30);
        set("int", 30);
        set("con", 30);
        set("per", 28);
        set("shen_type", 1);
        set("max_qi", 4000);
        set("max_jing", 3000);
        set("max_neili", 5000);
        set("neili", 5000);
        set("jiali", 200);
        set("combat_exp", 2500000);
        set("score", 5000);

        set_skill("force", 220);
        set_skill("quanzhen-xinfa", 200);
        set_skill("xiantian-gong", 220);
        set_skill("staff", 200);
        set_skill("dagou-bang", 200);
        set_skill("unarmed", 220);
        set_skill("kongming-quan", 220);
        set_skill("strike", 200);
        set_skill("haotian-zhang", 200);
        set_skill("sword", 200);
        set_skill("quanzhen-jian", 200);
        set_skill("dodge", 200);
        set_skill("jinyan-gong", 200);
        set_skill("parry", 200);
        set_skill("jinguan-yusuo", 200);
        set_skill("literate", 180);
        set_skill("martial-cognize", 220);

        map_skill("force", "xiantian-gong");
        map_skill("unarmed", "kongming-quan");
        map_skill("sword", "quanzhen-jian");
        map_skill("staff", "dagou-bang");
        map_skill("parry", "jinguan-yusuo");
        map_skill("dodge", "jinyan-gong");
        map_skill("strike", "haotian-zhang");

        prepare_skill("unarmed", "kongming-quan");

        create_family("����", 2, "Ů��");

        set("inquiry", ([
             "job"  : (: ask_job :),
             "����" : (: ask_job :),
             "����" : "��ȥ��Ʒ��������Ҫ�ɡ�",
        ]));

        set("chat_chance_combat", 120);
        set("chat_msg_combat", ({
                (: perform_action, "unarmed.ruo" :),
                (: perform_action, "unarmed.kong" :),
                (: exert_function, "hup" :),
                (: exert_function, "shield" :),
                (: exert_function, "recover" :),
                (: exert_function, "powerup" :),
        }) );

        setup();
        carry_object("clone/misc/cloth")->wear();
}

void init()
{
        object ob;

        ::init();

        if (interactive(ob = this_player())
          && ob->query("mark/guofu_ok")
          && ! ob->query_temp("job_name")
          && ob->query("combat_exp") < 20000)
	{
       		command("nod " + ob->query("id"));
        	command("say ���ڹ�������ȱ���֣�����������칤��(" HIY
               		"ask yelv qi about ����" NOR + CYN ")������" NOR);
	}
     	add_action("do_task", "task");
}

string ask_job()
{
        object me, ob;
        string target;

        ob = this_player();
        me = this_object();

        target = names[random(sizeof(names))];

        if (ob->query_temp("job_name"))
		return "�㲻���Ѿ����˹����𣿻�����ȥ����";

        if (ob->query("combat_exp") >= 20000)
             	return "�㹦���Ѿ��㹻��������������û��ʲô�ʺ���Ĺ����ˡ�";

        if (ob->query("mark/guofu_out"))
             	return "�㲻���Ѿ��������������ô�ֻ����ˣ�";

        ob->set_temp("job_name", target);
        ob->apply_condition("wuguan_job", random(3) + 4);
        return "���š����ȵ���Ʒ���칤�ߣ�Ȼ��ȥ��Ժ��" HIY + target + NOR
               + CYN "���ɡ�\n" NOR;
}

int do_task(string arg)
{
        object ob, me, obj;
        int exp, pot;

        ob = this_player();
        me = this_object();
        exp = 25 + random(10);
        pot = 6 + random(6);

        if (! arg || arg != "ok")
		return 0;

        if (! ob->query_temp("job_name"))
		return notify_fail(CYN "Ү������ü������û���㹤������"
                                   "ô���������ˣ�\n" NOR);

        if (! (ob->query_temp("mark/������")
           || ob->query_temp("mark/������")
           || ob->query_temp("mark/������")
           || ob->query_temp("mark/������")
           || ob->query_temp("mark/ɨ����")
           || ob->query_temp("mark/������")))
                return notify_fail(CYN "Ү������ü����������ɵ��¶���"
                                   "������\n" NOR);

        if (interactive(ob)
        && (int)ob->query_condition("wuguan_job"))
	{
              command("hmm " + ob->query("id"));
              return notify_fail(CYN "Ү������ü������ô��ô�죬�ǲ���"
                                 "û���갡���Ը����������\n" NOR);
        }

        if (! ob->query_temp("mark/����"))
		return notify_fail(CYN "Ү����������š��㻹���Ȱѹ���"
                                   "����""��˵�ɡ�\n" NOR);

        command("smile " + ob->query("id"));
        command("say �ɵò������Ǹ���Ľ��͡�");

        obj = new("/clone/money/silver");
        obj->set_amount(1 + random(2));
        obj->move(me, 1);
	command("give " + ob->query("id") + " silver");

        if (ob->query("potential") > ob->query_potential_limit()) 
		pot = 1;

        ob->add("combat_exp", exp);
        ob->improve_potential(pot);

        tell_object(ob, HIC "������" + chinese_number(exp) + "��"
                        "�����" + chinese_number(pot) + "��Ǳ�ܡ�"
                        "\n" NOR);
        ob->delete_temp("job_name");
        ob->delete_temp("mark");
        ob->add("mark/guofu_job", 1);
        return 1;
}

void unconcious()
{
        die();
}
