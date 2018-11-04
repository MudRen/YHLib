#include <ansi.h>
inherit NPC;

void create()
{
        set_name("��ҩ����", ({ "zhangyao daozhang", "zhangyao", "daozhang" }));
        set("gender", "����");
        set("age", 28);
        set("class", "taoist");
        set("long", @LONG
����ȫ����е��ƹ�����ҩ��ĵ��ˡ������
���󣬵��������Ե������ϳɡ�
LONG);
        set("attitude", "friendly");
        set("shen_type",1);
        set("str", 21);
        set("int", 22);
        set("con", 23);
        set("dex", 22);

        set("qi", 600);
        set("max_qi", 600);
        set("jing", 400);
        set("max_jing", 400);
        set("neili", 1200);
        set("max_neili", 1200);
        set("jiali", 0);

        set("combat_exp", 30000);
        set("score", 20000);

        set_skill("force", 60);
        set_skill("quanzhen-xinfa", 50);
        set_skill("sword", 60);
        set_skill("quanzhen-jian",60);
        set_skill("dodge", 50);
        set_skill("jinyan-gong", 50);
        set_skill("parry", 60);
        set_skill("unarmed",60);
        set_skill("strike",60);
        set_skill("haotian-zhang", 50);
        set_skill("literate",50);
        set_skill("taoism",40);

        map_skill("force", "quanzhen-xinfa");
        map_skill("sword", "quanzhen-jian");
        map_skill("dodge", "jinyan-gong");
        map_skill("parry", "quanzhen-jian");
        map_skill("strike", "haotian-zhang");
        prepare_skill("strike", "haotian-zhang");

        create_family("ȫ���", 4, "����");

        set("inquiry", ([
                "ȫ���" :  "��ȫ��������µ����������ڡ�\n",
        ]) );

        setup();

        carry_object("/clone/weapon/changjian")->wield();
        carry_object(__DIR__"obj/grayrobe")->wear();

}

int accept_object(object who, object ob)
{
        object obj;
        object me = this_player();

        if (! who || environment(who) != environment())
		return 0;

        if (! objectp(ob))
		return 0;

        if (! present(ob, who))
                return notify_fail("��û�����������\n");

        if ((string)ob->query("id") != "gui jia"
           && ob->query("id") != "fu ling")
                return notify_fail(CYN "��ҩ����ҡͷ�����ⲻ����ҩ�Ĳ��ϡ�\n" NOR);

        if ((string)ob->query("id") == "gui jia")
        {
                if (query_temp("fuling"))
                {
                        obj = new(__DIR__"obj/gao");
                        obj->move(this_object());

                        write(CYN "��ҩ�����ӹ���ף�˵������׺����߶����ˣ���"
                              "�����߸�������ˡ�\n" NOR);
                        command("give guiling gao to " + who->query("id"));

                        delete_temp("guijia");
                        delete_temp("fuling");
                        destruct(ob);
                        return 1;
                } else
                {
                        if(query_temp("guijia"))
                        {
                                write(CYN "��ҩ����ҡ��ҡͷ��˵�����������Ѿ�"
                                      "���ˡ�\n" NOR);
                                return 0;
                        } else
                        {
                                set_temp("guijia", 1);
                                write(CYN "��ҩ�����ӹ���ף�Ц����������ˣ���"
                                      "ȱ�����ˡ�\n" NOR);
                                destruct(ob);
                                return 1;
                        }
                }
        }
        if (ob->query("id") == "fu ling")
        {
                if(query_temp("guijia"))
                {
                        obj = new(__DIR__"obj/gao");
                        obj->move(this_object());

                        write(CYN "��ҩ�����ӹ���ף�˵������׺����߶����ˣ���"
                              "�����߸�������ˡ�\n" NOR);
                        command("give guiling gao to " + who->query("id"));

                        delete_temp("guijia");
                        delete_temp("fuling");
                        destruct(ob);
                        return 1;
                } else
                {
                        if(query_temp("fuling"))
                        {
                                write(CYN "��ҩ����ҡ��ҡͷ��˵�������������Ѿ�"
                                      "���ˡ�\n" NOR);
                                return 0;
                        } else
                        {
                                set_temp("fuling", 1);
                                write(CYN "��ҩ�����ӹ����ߣ�Ц�����������ˣ���"
                                      "ȱ����ˡ�\n" NOR);
                                destruct(ob);
                                return 1;
                        }
                }
        }

}
