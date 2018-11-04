// WeiYiXiao.c
// by rcwiz 2003 for yhonline

#include <ansi.h>
#include "mingjiao.h"

inherit NPC;
inherit F_MASTER;
inherit F_GUARDER;
inherit F_COAGENT;

void create()
{
	set_name("ΤһЦ", ({"wei yixiao", "wei", "yixiao",}));
	set("long",
		"�����û�����һֻ���������\n"
		"������ɫ�����˵ġ�\n"
	);

	set("title",HIR "����" HIG "��������" NOR);
	set("gender", "����");
	set("attitude", "peaceful");
	set("age", 48);
	set("shen_type", 1);
	set("str", 28);
	set("int", 27);
	set("con", 33);
	set("dex", 38);
	set("max_qi", 4500);
	set("max_jing", 2200);
	set("neili", 5500);
	set("max_neili", 5500);
	set("jiali", 160);

	set("combat_exp", 1800000);

	set_skill("force", 220);
    	set_skill("dodge", 240);        
    	set_skill("strike", 240);
	set_skill("sword", 220);
        set_skill("claw", 220);
        set_skill("shougu-yingzhua", 220);
	set_skill("parry", 220);
    	set_skill("shenghuo-xinfa", 220);
      	set_skill("qingfu-shenfa", 240);
        set_skill("shenghuo-bu", 240);
      	set_skill("hanbing-mianzhang", 240);
      	set_skill("literate", 200);
        set_skill("martial-cognize", 180);

    	map_skill("force", "shenghuo-xinfa");
    	map_skill("dodge", "qingfu-shenfa");
    	map_skill("strike", "hanbing-mianzhang");
    	map_skill("parry", "hanbing-mianzhang");
        map_skill("claw", "shougu-yingzhua");

	prepare_skill("strike","hanbing-mianzhang");

        set_temp("apply/attack", 120);
        set_temp("apply/damage", 120);
        set_temp("apply/unarmed_damage", 120);
        set_temp("apply/armor", 120);

	set("coagents", ({
                ([ "startroom" : "/d/mingjiao/dadian",
                   "id"        : "zhang wuji" ]),
                ([ "startroom" : "/d/mingjiao/dadian",
                   "id"        : "fan yao" ]),
                ([ "startroom" : "/d/mingjiao/dadian",
                   "id"        : "dai jisi" ]),
                ([ "startroom" : "/d/mingjiao/dadian",
                   "id"        : "xie xun" ]),
                ([ "startroom" : "/d/mingjiao/dadian",
                   "id"        : "yin tianzheng" ]),
        }));


	set("chat_chance_combat", 120);
	set("chat_msg_combat", ({
		(: command("perform strike.jue") :),
	}) );
	create_family("����", 36, "����");
	setup();

        carry_object("/d/mingjiao/obj/baipao")->wear();
}


void attempt_apprentice(object ob)
{
        if (! permit_recruit(ob))
                return;

        if ((int)ob->query("shen") < 10000)
        {
                command("say ����������������û�������������ذɡ�");
                return;
        }
      
        if (ob->query_skill("shenghuo-xinfa", 1) < 100)
        {       
                command("say ��ʥ���ķ�������죬������ȥ����ϰһ�°ɣ�");
                return ;
        }

        if (ob->query_skill("dodge", 1) < 100)
        {       
                command("say ������Ṧ��򲻹�����ôѧ�ҵ���������");
                return ;
        }

        command("nod");
        command("say �ã��ã������Ҿ�����Ϊ���ӡ�");
        command("recruit " + ob->query("id"));
}

int accept_ask(object me, string topic)
{
        switch (topic)
        {

        case "��Ѫצ" :
                return MASTER_D->teach_pfm(me, this_object(),
                        ([ "perform" : "can_perform/shougu-yingzhua/xue",
                           "name"    : "��Ѫצ",
                           "sk1"     : "shougu-yingzhua",
                           "lv1"     : 60,
                           "force"   : 80,
                           "gongxian": 200,
                           "shen"    : 11000, ]));
                break;

        case "���಻��" :
                return MASTER_D->teach_pfm(me, this_object(),
                        ([ "perform" : "can_perform/hanbing-mianzhang/jue",
                           "name"    : "���಻��",
                           "sk1"     : "hanbing-mianzhang",
                           "lv1"     : 100,
                           "gongxian": 480,
                           "shen"    : 14000, ]));
                break;

        default:
                return 0;
        }
}

void unconcious()
{
        die();
}

