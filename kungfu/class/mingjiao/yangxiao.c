// YangXiao.c

#include <ansi.h>
#include "mingjiao.h"

#define JIAN "/clone/lonely/huanlingjian"

inherit NPC;
inherit F_COAGENT;
inherit F_MASTER;
inherit F_GUARDER;

void create()
{
	set_name("����", ({"yang xiao","yang","xiao",}));
	set("long",
        "����һλ�������������ײ����ۡ�\n"
        "����ò���ţ�ֻ��˫ü�����´������¶��������������ƣ������Դ�˥�����\n"
        "֮�ࡣ�����Բ�������ɫĮȻ���ƺ��ĳ�Զ����������ʲô���顣\n"
	);

	set("title",HIR "����" HIW "������ʹ" NOR);
	set("gender", "����");
	set("attitude", "peaceful");
	
	set("age", 42);
	set("shen_type", 1);
	set("per", 29);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);

	set("max_qi", 7500);
	set("max_jing", 2500);
	set("neili", 8000);
	set("max_neili", 8000);
	set("jiali", 150);
	set("combat_exp", 4000000);
	set("score", 800000);

	set_skill("force", 320);
    	set_skill("dodge", 340);
    	set_skill("strike", 340);
	set_skill("sword", 320); 
	set_skill("parry", 320);
        set_skill("cuff", 320);
        set_skill("unarmed", 320);
        set_skill("pili-quan", 320);
    	set_skill("shenghuo-xinfa", 320);
        set_skill("shenghuo-bu", 340);
      	set_skill("pomopima-jian", 340);
        set_skill("xiaoyao-jian", 340);
      	set_skill("literate", 300);
        set_skill("martial-cognize", 280);

	map_skill("force", "shenghuo-xinfa");
	map_skill("dodge", "shenghuo-bu");
	map_skill("cuff", "pili-quan");
	map_skill("parry", "xiaoyao-jian");
        map_skill("sword", "xiaoyao-jian");
       
 	prepare_skill("cuff", "pili-quan");

	set("chat_chance_combat", 20);
	set("chat_msg_combat", ({
		(: command("perform sword.kuai") :),
		(: command("perform sword.qi") :),
		(: command("perform sword.fei") :),
		(: command("perform cuff.jin") :),
	}) );

        set_temp("apply/attack", 120);
        set_temp("apply/damage", 120);
        set_temp("apply/unarmed_damage", 120);
        set_temp("apply/armor", 120);

	set("coagents", ({
                ([ "startroom" : "/d/mingjiao/dadian",
                   "id"        : "zhang wuji" ]),
        }));

	create_family("����", 36, "����");
	setup();

        carry_object("/d/mingjiao/obj/baipao")->wear();
        carry_object("/clone/weapon/gangjian")->wield();
}

void attempt_apprentice(object ob)
{
        if (! permit_recruit(ob))
                return;

        if ((int)ob->query("shen") < 80000)
        {
                command("say ����������������û�������������ذɡ�");
                return;
        }
      
        if (ob->query_skill("shenghuo-xinfa", 1) < 160)
        {       
                command("say ��ʥ���ķ�������죬������ȥ����ϰһ�°ɣ�");
                return ;
        }

        if (ob->query_skill("dodge", 1) < 160)
        {       
                command("say ������Ṧ��򲻹�����ôѧ�ҵ���ң������");
                return ;
        }
     
        if (ob->query("combat_exp") < 700000)
        {
                command("say �㽭��������ǳ������ȥ�ള��һ�°ɣ�");
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

        case "����Ǭ��" :
                return MASTER_D->teach_pfm(me, this_object(),
                        ([ "perform" : "can_perform/pomopima-jian/zui",
                           "name"    : "����Ǭ��",
                           "sk1"     : "pomopima-jian",
                           "lv1"     : 120,
                           "force"   : 180,
                           "gongxian": 700,
                           "shen"    : 80000, ]));
                break;

        case "�ɽ���" :
                return MASTER_D->teach_pfm(me, this_object(),
                        ([ "perform" : "can_perform/xiaoyao-jian/fei",
                           "name"    : "�ɽ���",
                           "sk1"     : "xiaoyao-jian",
                           "lv1"     : 60,
                           "gongxian": 400,
                           "shen"    : 80000, ]));
                break;


        case "�콣��" :
                return MASTER_D->teach_pfm(me, this_object(),
                        ([ "perform" : "can_perform/xiaoyao-jian/kuai",
                           "name"    : "�콣��",
                           "sk1"     : "xiaoyao-jian",
                           "lv1"     : 160,
                           "dodge"   : 260,
                           "gongxian": 680,
                           "shen"    : 85000, ]));
                break;


        case "�潣��" :
                return MASTER_D->teach_pfm(me, this_object(),
                        ([ "perform" : "can_perform/xiaoyao-jian/qi",
                           "name"    : "�潣��",
                           "sk1"     : "xiaoyao-jian",
                           "lv1"     : 160,
                           "neili"   : 3000,
                           "gongxian": 780,
                           "shen"    : 88000, ]));
                break;


         case "���齣" :
                return MASTER_D->give_item(me, this_object(),
                               (["item"     :  JIAN,
                                 "master"   :  1,
                                 "sk1"      :  "xiaoyao-jian",
                                 "lv1"      :  120,
                                 "shen"     :  80000 ]));
                  break;
        default:
                return 0;
        }
}


void unconcious()
{
        die();
}

