#include <ansi.h>
inherit NPC;

void create()
{
        set_name("������", ({"zhu ziliu", "zhu", "ziliu"}));
        set("gender", "����");
        set("age", 55);
        set("title", HIY "�ϵ��Ĵ����" NOR);
        set("long", @LONG
����������һ�ƴ�ʦ���Ĵ����֮һ��������Э��
�������������������ǡ�
LONG );
        set("attitude", "peaceful");
        set("per", 17);
        set("str", 40);
        set("int", 20);
        set("con", 30);
        set("dex", 25);

        set("max_qi", 3200);
        set("max_jing", 2600);
        set("neili", 4200);
        set("max_neili", 4200);
        set("jiali", 150);
        set("combat_exp", 2500000);
        set("score", 5000);

        set_skill("force", 180);
        set_skill("duanshi-xinfa", 180);
        set_skill("dodge", 180);
        set_skill("tiannan-bu", 180);
        set_skill("cuff", 180);
        set_skill("jinyu-quan", 180);
        set_skill("strike", 180);
        set_skill("wuluo-zhang", 180);
        set_skill("dagger", 200);
        set_skill("qingliang-daxuefa", 200);
        set_skill("parry", 180);
        set_skill("literate", 400);
        set_skill("martial-cognize", 180);

        map_skill("force", "duanshi-xinfa");
        map_skill("dodge", "tiannan-bu");
        map_skill("cuff", "jinyu-quan");
        map_skill("strike", "wuluo-zhang");
        map_skill("dagger", "qingliang-daxuefa");
        map_skill("parry", "qingliang-daxuefa");

        prepare_skill("cuff", "jinyu-quan");
        prepare_skill("strike", "wuluo-zhang");

        create_family("���ϻ���", 6, "�ҳ�");

        set("chat_chance_combat", 120);
        set("chat_msg_combat", ({
                (: perform_action, "dagger.ding" :),
                (: perform_action, "cuff.man" :),
                (: perform_action, "strike.bian" :),
                (: exert_function, "recover" :),
        }));

        setup();
        carry_object("/d/dali/npc/obj/junfu")->wear();
        carry_object("/d/meizhuang/obj/panguanbi")->wield();
        add_money("silver", 10);
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

int recognize_apprentice(object ob, string skill)
{
        if (ob->query("combat_exp") > 20000)
        {
                command("say �㾭��Ҳ�����ˣ�Ӧ�ö��ȥ�������ɱ���û�����");
                return -1;
        }

        if (skill != "literate")
        {
                command("shake");
                command("say ���������ഫ����һЩ����д�ֵĳ�ʶ��");
                command("say �����Ļ��ǵ��㽫����ʦ����ʦ��ѧ�ɡ�");
                return -1;
        }

        if (skill == "literate" && ob->query_skill("literate", 1) > 99)
        {
                command("haha");
                command("say �����ѧ�����Ѿ��ǳ������ˣ��͵���Ϊֹ�ɡ�");
                return -1;
        }

        if (! ob->query_temp("can_learn/zhuziliu"))
        {
                command("smile");
                command("say �������������Ǻ��£��Ҿͽ�������д�ֵĳ�ʶ�ɡ�");
                ob->set_temp("can_learn/zhuziliu", 1);
        }
        return 1;
}

void greeting(object ob)
{
       if (! ob || environment(ob) != environment()) return;

       if (ob->query_skill("literate") > 99) return;

       command("pat " + ob->query("id"));
       command("say ��λ" + RANK_D->query_respect(ob) + "����������ѧЩ֪"
               "ʶ(" HIY "xue zhu ziliu literate" NOR + CYN ")�ɡ�" NOR);

}
