#include <ansi.h>

inherit NPC;

void create ()
{
        set_name("����Ѿ��" ,({"liaotian xiaojie","xiaojie","liaotian"}));
        set("gender","Ů��");
        set("title",HIW "����������־" NOR);
        set("nickname",HIB "���޵�" NOR);
        set("age",18);
        set("long", 
                 "����Ѿ����Ȼ�ŵ����ˣ����������Ѿ����˺ܸߵ����衣\n");
        set("str",10);
        set("dex",16);
        set("con",30);
        set("int",56);

        set_skill("idle-force",300);

        set("combat_exp",2000);

        set("max_qi",200);
        set("max_jing",200);
        set("max_neili",100);
        set("neili",100);

        set("attitude","friendly");
        set("inquiry",([
               "name" : "�Ҿ�������Ѿ�ߡ�",
               "����" : "���Ǻ�������Щ���ĵ������졣",
               "work" : "���Ǻ�������Щ���ĵ������졣",
        ]));

        setup();
        set("chat_chance", 1);
        set("chat_msg",({
                    "����С������˵������˭�ܱ��һ��������أ�\n",
        }));
        carry_object("/clone/cloth/female1-cloth")->wear();
        carry_object("/clone/cloth/female-shoe")->wear();

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

void greeting(object me)
{
        if (me->query("name") == "���")
        {
                command("jump " + me->query("id"));
                command("say ���һ�ӭ����糤��鹤�������\n");
                return;
        }

        if (me->query("age") < 18)
        {
                command("say С������ʲô�죬һ��ȥ�棡");
                command("kick " + me->query("id"));
                message("vision", me->name() + "������Ѿ�����˳�ȥ��\n",
                        environment(me),({me}));
                me->move("/d/city/kedian");
                message("vison", me->mane() + "���˴��������˳�����\n",
                        environment(me),({me}));
                return;
        }

        if (me->query("gender") == "����")
        {
                if (me->query("per") >= 27)
                {
                        command("wa " + query("id"));
                        command("say ��λ˧�磬���ǿ��Ժú�������\n");
                } else 
                {
                        command("nod " + query("id"));
                        command("say ��λ�����кι�ɣ�\n");
                }
                return;
        }
        command("say �����������\n");
        return;
}
