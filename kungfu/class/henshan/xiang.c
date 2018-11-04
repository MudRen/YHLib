#include <ansi.h>
#include "henshan.h"

inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("�����", ({ "xiang danian", "xiang", "danian" }));
        set("gender", "����" );
        set("class", "swordman");
        set("attitude", "peaceful");
        set("shen_type", 1);

        set("age", 28);
        set("str", 26);
        set("con", 24);
        set("int", 27);
        set("dex", 26);
        set("max_qi", 1800);
        set("max_jing", 1200);
        set("neili", 2000);
        set("max_neili", 2000);
        set("jiali", 100);
        set("combat_exp", 600000);

        set_skill("force", 100);
        set_skill("henshan-xinfa", 100);
        set_skill("dodge", 100);
        set_skill("henshan-shenfa", 100);
        set_skill("cuff", 120);
        set_skill("henshan-quan", 120);
        set_skill("sword", 120);
        set_skill("henshan-jian", 120);
        set_skill("zigai-jian", 120);
        set_skill("strike", 100);
        set_skill("biluo-zhang", 100);
        set_skill("parry", 100);
        set_skill("literate", 100);
        set_skill("martial-cognize", 80);

        map_skill("force", "henshan-xinfa");
        map_skill("dodge", "henshan-shenfa");
        map_skill("sword", "zigai-jian");
        map_skill("parry", "henshan-jian");
        map_skill("strike", "biluo-zhang");
        map_skill("cuff", "henshan-quan");

	prepare_skill("cuff", "henshan-quan");
        prepare_skill("strike", "biluo-zhang");

        create_family("��ɽ��", 15, "����");

        set("chat_chance_combat", 120);
        set("chat_msg_combat", ({
                (: perform_action, "sword.hui" :),
                (: perform_action, "cuff.riyue" :),
                (: perform_action, "strike.lian" :),
                (: exert_function, "recover" :),
        }));

        setup();

        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/clone/cloth/cloth")->wear();
}

void attempt_apprentice(object ob)
{
        if (! permit_recruit(ob))
                return;

        if ((int)ob->query("shen") < 2000)
        {
                command("say �������֮�����������Һ�ɽ���ɣ�");
                return;
        }

        if ((int)ob->query("combat_exp") < 20000)
        {
                command("say �����ھ�����ǳ�����Ƕ��ڽ��������߰ɡ�");
                return;
        }

        if ((int)ob->query_skill("henshan-jian", 1) < 30)
        {       
                command("hmm");
                command("say ���ɽ��������������ƽʱ����ʲôȥ�ˣ�");
                return;
        }
   
        if ((int)ob->query_skill("force") < 80)
        {
                command("say ����ڹ��ķ�̫����ܸ���ѧʲô��");
                return;
        } 

        command("nod");
        command("say ����������ǣ��պ�ɱ�����������");
        command("recruit " + ob->query("id"));
}

int accept_ask(object me, string topic)
{
        switch (topic)
        {
        case "��������" :
                return MASTER_D->teach_pfm(me, this_object(),
                        ([ "perform" : "can_perform/biluo-zhang/lian",
                           "name"    : "��������",
                           "sk1"     : "biluo-zhang",
                           "lv1"     : 100,
                           "force"   : 120,
                           "gongxian": 200,
                           "shen"    : 5000, ]));
                break;

        default:
                return 0;
        }
}
