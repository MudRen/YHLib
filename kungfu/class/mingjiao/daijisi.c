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
	set_name("���˿", ({"dai jisi", "dai", "jisi", }));
	set("long",
        "����ɫ���ˣ����޲��ɷ�����˲��̴��˿����֮�⡣\n"
	);
                                                          
	set("title",HIR "����" MAG "��������" NOR);
	set("gender", "Ů��");
	set("attitude", "peaceful");

	set("age", 22);
	set("shen_type", 1);
	set("per", 29);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);

	set("max_qi", 6500);
	set("max_jing", 2500);
	set("neili", 7000);
	set("max_neili", 7000);
	set("jiali", 210);

	set("combat_exp", 3500000);
	set("score", 800000);

	set_skill("force", 320);
    	set_skill("dodge", 300);
	set_skill("parry", 300);
        set_skill("throwing", 320);
        set_skill("staff", 320);
        set_skill("cuff", 320);
        set_skill("pili-quan", 320);
        set_skill("duoming-jinhua", 320);
        set_skill("yinhu-zhang", 320);
    	set_skill("shenghuo-xinfa", 320);
      	set_skill("shenghuo-bu", 300);
      	set_skill("literate", 260);
        set_skill("martial-cognize", 240);

    	map_skill("force", "shenghuo-xinfa");
    	map_skill("dodge", "shenghuo-bu");
    	map_skill("parry", "yinfeng-dao");
    	map_skill("throwing", "duoming-jinhua");
        map_skill("cuff", "pili-quan");
    	map_skill("staff", "yinhu-zhang");

        prepare_skill("cuff", "pili-quan");

	set("chat_chance_combat", 120);
	set("chat_msg_combat", ({
		(: command("perform staff.lao") :),
		(: command("perform cuff.jin") :),
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
                   "id"        : "yin tianzheng" ]),
                ([ "startroom" : "/d/mingjiao/dadian",
                   "id"        : "weiyi xiao" ]),
                ([ "startroom" : "/d/mingjiao/dadian",
                   "id"        : "xie xun" ]),
        }));
	setup();
    	carry_object("/d/mingjiao/obj/baipao")->wear();
    	carry_object("/d/mingjiao/obj/muzhang")->wield();    	
       
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

        case "������" :
                return MASTER_D->teach_pfm(me, this_object(),
                        ([ "perform" : "can_perform/yinhu-zhang/lao",
                           "name"    : "������",
                           "sk1"     : "yinhu-zhang",
                           "lv1"     : 100,
                           "force"   : 260,
                           "neili"   : 2000,
                           "gongxian": 750,
                           "shen"    : 70000, ]));
                break;

        case "����ɻ�" :
                return MASTER_D->teach_pfm(me, this_object(),
                        ([ "perform" : "can_perform/duoming-jinhua/hua",
                           "name"    : "��ɱ",
                           "sk1"     : "duoming-jinhua",
                           "lv1"     : 120,
                           "force"   : 200,
                           "neili"   : 2400,
                           "gongxian": 750,
                           "shen"    : 70000, ]));
                break;

        default:
                return 0;
        }
}

void unconcious()
{
        die();
}


