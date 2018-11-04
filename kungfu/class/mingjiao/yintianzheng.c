// yintianzheng.c
// by rcwiz 2003 for yhonline

#include <ansi.h>
#include "mingjiao.h"

inherit NPC;
inherit F_MASTER;
inherit F_GUARDER;
inherit F_COAGENT;

void create()
{
	set_name("������", ({"yin tianzheng", "yin", "tianzheng", }));
	set("long",
        "����һλ��Ŀ����ͺ���ߣ���һ����ɫ���ۡ�\n"
        "����üʤѩ�������۽ǣ����ӹ���������ӥ�졣\n"
	);
                                                          
	set("title",HIR "����" HIW "��üӥ��" NOR);
	set("gender", "����");
	set("attitude", "peaceful");

	set("age", 72);
	set("shen_type", 1);
	set("per", 22);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);

	set("max_qi", 6500);
	set("max_jing", 2500);
	set("neili", 7000);
	set("max_neili", 7000);
	set("jiali", 210);

	set("combat_exp", 3900000);
	set("score", 800000);

	set_skill("force", 280);
    	set_skill("dodge", 260);
	set_skill("parry", 260);
	set_skill("strike", 280);
        set_skill("cuff", 280);
        set_skill("pili-quan", 280);
        set_skill("finger", 280);
    	set_skill("shenghuo-xinfa", 280);
      	set_skill("shenghuo-bu", 260);
        set_skill("yinfeng-dao", 280);
        set_skill("tougu-zhen", 280);
      	set_skill("literate", 240);
        set_skill("martial-cognize", 220);

    	map_skill("force", "shenghuo-xinfa");
    	map_skill("dodge", "shenghuo-bu");
    	map_skill("parry", "yinfeng-dao");
    	map_skill("finger", "tougu-zhen");
        map_skill("cuff", "pili-quan");
    	map_skill("strike", "yinfeng-dao");

	prepare_skill("strike", "yinfeng-dao");
        prepare_skill("finger", "tougu-zhen");

	set("chat_chance_combat", 120);
	set("chat_msg_combat", ({
		(: command("perform strike.jue") :),
		(: command("perform finger.feng") :),
	}) );
	create_family("����", 36, "����");

        set_temp("apply/attack", 150);
        set_temp("apply/damage", 150);
        set_temp("apply/unarmed_damage", 150);
        set_temp("apply/armor", 150);

	set("coagents", ({
                ([ "startroom" : "/d/mingjiao/dadian",
                   "id"        : "zhang wuji" ]),
                ([ "startroom" : "/d/mingjiao/dadian",
                   "id"        : "fan yao" ]),
                ([ "startroom" : "/d/mingjiao/dadian",
                   "id"        : "dai jisi" ]),
                ([ "startroom" : "/d/mingjiao/dadian",
                   "id"        : "weiyi xiao" ]),
                ([ "startroom" : "/d/mingjiao/dadian",
                   "id"        : "xie xun" ]),
        }));
	setup();
    	carry_object("/d/mingjiao/obj/baipao")->wear();
}

void attempt_apprentice(object ob)
{
        if (! permit_recruit(ob))
                return;

        if ((int)ob->query("shen") < 60000)
        {
                command("say ����������������û�������������ذɡ�");
                return;
        }
      
        if (ob->query_skill("shenghuo-xinfa", 1) < 180)
        {       
                command("say ��ʥ���ķ�������죬������ȥ����ϰһ�°ɣ�");
                return ;
        }

        if (ob->query("combat_exp") <450000)
        {
                command("say �㽭�����鲻�㣬���Ƕ�ĥ��һ�°ɣ�");
                return;
        }

        command("nod");
        command("say �ã��ã������Ҿ�����Ϊ���ӡ�");
        command("recruit " + ob->query("id"));
}

int accept_ask(object me, string topic)
{
        switch (topic)
        {

        case "��ɱ" :
                return MASTER_D->teach_pfm(me, this_object(),
                        ([ "perform" : "can_perform/tougu-zhen/feng",
                           "name"    : "��ɱ",
                           "sk1"     : "tougu-zhen",
                           "lv1"     : 100,
                           "force"   : 260,
                           "neili"   : 2400,
                           "gongxian": 750,
                           "shen"    : 68000, ]));
                break;

        case "��ɱ" :
                return MASTER_D->teach_pfm(me, this_object(),
                        ([ "perform" : "can_perform/yinfeng-dao/jue",
                           "name"    : "��ɱ",
                           "sk1"     : "yinfeng-dao",
                           "lv1"     : 140,
                           "force"   : 260,
                           "neili"   : 2400,
                           "gongxian": 750,
                           "shen"    : 68000, ]));
                break;

        default:
                return 0;
        }
}

void unconcious()
{
        die();
}


