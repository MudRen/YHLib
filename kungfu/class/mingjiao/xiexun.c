// XieXun.c
// by rcwiz 2003 for yhonline

#include <ansi.h>
#include "mingjiao.h"

inherit NPC;
inherit F_MASTER;
inherit F_GUARDER;
inherit F_COAGENT;

void create()
{
	set_name("лѷ", ({"xie xun", "xie", "xun", }));
	set("long",
        "����һλ��Ŀ�ΰ�쳣�ĵ����ߣ���һ���ײ����ۡ�\n"
        "����ͷ�Ʒ����������ݣ���������һ�㣬ֻ����ֻ�۾�����������\n"
	);

	set("title",HIR "����" HIY "��ëʨ��" NOR);
	set("gender", "����");
	set("attitude", "peaceful");

	set("age", 61);
	set("shen_type", 1);
	set("per", 23);
	set("str", 40);
	set("int", 30);
	set("con", 40);
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
    	set_skill("shenghuo-xinfa", 280);
      	set_skill("shenghuo-bu", 260);
      	set_skill("pili-shou", 280);
	set_skill("pili-quan", 280);
	set_skill("qishang-quan", 280);
      	set_skill("literate", 240);
        set_skill("martial-cognize", 220);

    	map_skill("force", "shenghuo-xinfa");
    	map_skill("dodge", "shenghuo-bu");
    	map_skill("strike", "pili-shou");
    	map_skill("parry", "qishang-quan");
        map_skill("cuff", "qishang-quan");

	prepare_skill("cuff", "qishang-quan");

	set("chat_chance_combat", 120);
	set("chat_msg_combat", ({
		(: command("perform cuff.shang") :),
		(: command("perform cuff.fei") :),
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
                   "id"        : "yin tianzheng" ]),
        }));
	setup();
    	carry_object("/d/mingjiao/obj/baipao")->wear();
}
/*
int accept_object(object who, object ob)
{
        if ((string)ob->query("id") == "yi xin")
	{
		say("лѷ˵����лл����������֪���������������䣬��"
		    "�����������޲��м���\n");
	}
	return 1;
}
*/

void attempt_apprentice(object ob)
{
        if (! permit_recruit(ob))
                return;

        if ((int)ob->query("shen") < 40000)
        {
                command("say ����������������û�������������ذɡ�");
                return;
        }
      
        if (ob->query_skill("shenghuo-xinfa", 1) < 140)
        {       
                command("say ��ʥ���ķ�������죬������ȥ����ϰһ�°ɣ�");
                return ;
        }

        if (ob->query("combat_exp") < 380000)
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

        case "��ػ�Ԫ" :
                return MASTER_D->teach_pfm(me, this_object(),
                        ([ "perform" : "can_perform/pili-shou/hun",
                           "name"    : "��ػ�Ԫ",
                           "sk1"     : "pili-shou",
                           "lv1"     : 140,
                           "force"   : 240,
                           "gongxian": 550,
                           "shen"    : 48000, ]));
                break;

        case "���־�" :
                return MASTER_D->teach_pfm(me, this_object(),
                        ([ "perform" : "can_perform/qishang-quan/shang",
                           "name"    : "���־�",
                           "sk1"     : "qishang-quan",
                           "lv1"     : 120,
                           "force"   : 180,
                           "gongxian": 550,
                           "shen"    : 48000, ]));
                break;

        case "���Ƿ���" :
                return MASTER_D->teach_pfm(me, this_object(),
                        ([ "perform" : "can_perform/qishang-quan/fei",
                           "name"    : "���Ƿ���",
                           "sk1"     : "qishang-quan",
                           "lv1"     : 160,
                           "force"   : 260,
                           "gongxian": 850,
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




