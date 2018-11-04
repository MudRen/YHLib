#include <ansi.h>
#include "henshan.h"

inherit NPC;
inherit F_MASTER;
inherit F_GUARDER;

void create()
{
        set_name("��Ϊ��", ({ "mi weiyi", "mi", "weiyi" }));
        set("gender", "����" );
        set("class", "swordman");
        set("attitude", "peaceful");
        set("shen_type", 1);

        set("age", 25);
        set("str", 24);
        set("con", 22);
        set("int", 25);
        set("dex", 24);
        set("max_qi", 3000);
        set("max_jing", 2000);
        set("neili", 1400);
        set("max_neili", 1400);
        set("jiali", 80);
        set("combat_exp", 200000);

        set_skill("force", 100);
        set_skill("henshan-xinfa", 100);   
        set_skill("dodge", 80);
        set_skill("henshan-shenfa", 80);
        set_skill("cuff", 80);
        set_skill("henshan-quan", 80);
        set_skill("strike", 80);
        set_skill("biluo-zhang", 80); 
        set_skill("sword", 100);
        set_skill("henshan-jian", 100);
        set_skill("parry", 80);
        set_skill("literate", 100);
        set_skill("martial-cognize", 80);

        map_skill("force", "henshan-xinfa");
        map_skill("dodge", "henshan-shenfa");
        map_skill("sword", "henshan-jian");
        map_skill("parry", "hengshan-jian");
        map_skill("cuff", "henshan-quan");
        map_skill("strike", "biluo-zhang");

        prepare_skill("cuff", "henshan-quan");
        prepare_skill("strike", "biluo-zhang");

        create_family("��ɽ��", 15, "����");

        set("chat_chance_combat", 120);
        set("chat_msg_combat", ({
                (: perform_action, "sword.huan" :),
                (: perform_action, "cuff.riyue" :),
                (: exert_function, "recover" :),
        }));
     
	set("coagents", ({
                ([ "startroom" : "/d/henshan/zhurongfeng",
                   "id"        : "mo da" ]),
        }));

        setup();

        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/clone/cloth/cloth")->wear();
}


void attempt_apprentice(object ob)
{
        if (! permit_recruit(ob))
                return;

        if ((string)ob->query("family/master_id") == "xiang danian")
	{
		command("say ����Ѱ�����ʦ��Ϊʦ����Ҳ��������Ϊͽ��");
		return;
	}

        if ((int)ob->query("shen") < 0)
        {
                command("say �����˲������£��Һ�ɽ�ɿ����㲻�á�");
                return;
        }

        command("say ��Ȼ��ˣ������Ժ�͸����Ұɡ�");
        command("recruit " + ob->query("id"));
}

int accept_ask(object me, string topic)
{
        switch (topic)
        {
        case "����������" :
                return MASTER_D->teach_pfm(me, this_object(),
                        ([ "perform" : "can_perform/henshan-quan/lan",
                           "name"    : "����������",
                           "sk1"     : "henshan-quan",
                           "lv1"     : 60,
                           "force"   : 80,
                           "gongxian": 50,
                           "shen"    : 2000, ]));
                break;

        default:
                return 0;
        }
}
