#include <ansi.h>
#include "songshan.h"

inherit NPC;
inherit F_MASTER;
inherit F_GUARDER;
inherit F_COAGENT;

void create()
{
        set_name("�ѱ�", ({ "fei bing", "bing", "fei" }) );
        set("nickname", HIW "��������" NOR);
        set("gender", "����");
        set("class", "swordsman");
        set("age", 45);
        set("attitude", "peaceful");
        set("str", 26);
        set("con", 30);
        set("dex", 30);
        set("int", 26);

        set("max_qi", 4500);
        set("max_jing", 2000);
        set("neili", 4000);
        set("max_neili", 4000);
        set("jiali", 150);
        set("shen_type", 1);
        set("combat_exp", 940000);

        set_skill("cuff", 200);
        set_skill("strike", 220);       
        set_skill("sword", 220);
        set_skill("force", 200);
        set_skill("parry", 200);
        set_skill("dodge", 200);
        set_skill("songshan-jian", 220);
        set_skill("lingyun-jian", 220);
        set_skill("chuanyue-jian", 220);
        set_skill("jiuqu-jian", 220);
        set_skill("songshan-xinfa", 200);
        set_skill("songyang-zhang", 200);
        set_skill("songshan-zhang", 200);
        set_skill("songshan-quan", 200);
        set_skill("literate", 200);
        set_skill("martial-cognize", 180);

        map_skill("force", "songshan-xinfa");
        map_skill("sword", "chuanyue-jian");
        map_skill("parry", "chuanyue-jian");
        map_skill("strike", "songyang-zhang");
        map_skill("cuff", "songshan-quan");
        map_skill("dodge", "lingxu-bu");

        prepare_skill("strike", "songyang-zhang");
             
        create_family("��ɽ��", 13, "����");

        set("chat_chance_combat", 120);
        set("chat_msg_combat", ({
                (: perform_action, "sword.hao" :),
                (: perform_action, "strike.ying" :),
		(: perform_action, "cuff.chui" :),
                (: exert_function, "recover" :),
                (: exert_function, "powerup" :),
        }));
     
        set_temp("apply/attack", 60);
        set_temp("apply/damage", 60);
        set_temp("apply/unarmed_damage", 60);
        set_temp("apply/armor", 120);

        setup();

        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/clone/cloth/cloth")->wear();
}


void attempt_apprentice(object ob)
{
        if (! permit_recruit(ob))
                return;

        if ((int)ob->query("shen") < 30000)
        {
                command("say ����ɽ�������������������ɣ��Ե���Ҫ���ϸ�");
                command("say ��������������з����Ƿ����ò�����");
                return;
        }

	if ((int)ob->query("combat_exp") < 200000)
	{
		command("say �����ھ�����ǳ�����Ƕ��ڽ��������߰ɡ�");
		return;
	}

        if ((int)ob->query_skill("songshan-jian", 1) < 120)
	{	
		command("say ����ɽ��������������֮һ����Ϊ���ӽ�����");
		command("say �����ɽ������������������ȥ���������ɡ�");
        	return;
        }
   
        if ((int)ob->query_skill("songshan-xinfa", 1) < 100)
	{
		command("say ����ɽ���������ý������ڹ�ȴ������֮����");
		command("say ���Ƿ�Ӧ������ɽ�ķ��϶��µ㹦��");
		return;
 	} 

	command("haha");
        command("say ���ӿɽ̣����ӿɽ̡������Ҿ�������ɡ�");
        command("say ���Ժ�Ҫ�����䣬�����ƣ�������ɽ�����۷硣");
        command("recruit " + ob->query("id"));
}
 
int accept_ask(object me, string topic)
{
        switch (topic)
        {
        case "��Ӱ��" :
                return MASTER_D->teach_pfm(me, this_object(),
                        ([ "perform" : "can_perform/songyang-zhang/ying",
                           "name"    : "��Ӱ��",
                           "sk1"     : "songyang-zhang",
                           "lv1"     : 80,
                           "force"   : 80,
                           "dodge"   : 80,
                           "gongxian": 300,
                           "shen"    : 32000, ]));
                break;

        case "��������" :
                return MASTER_D->teach_pfm(me, this_object(),
                        ([ "perform" : "can_perform/lingyun-jian/xiao",
                           "name"    : "��������",
                           "sk1"     : "lingyun-jian",
                           "lv1"     : 100,
                           "force"   : 120,
                           "gongxian": 400,
                           "shen"    : 41000, ]));
                break;

        case "��´���" :
                return MASTER_D->teach_pfm(me, this_object(),
                        ([ "perform" : "can_perform/chuanyue-jian/hao",
                           "name"    : "��´���",
                           "sk1"     : "chuanyue-jian",
                           "lv1"     : 120,
                           "force"   : 120,
                           "gongxian": 520,
                           "shen"    : 52000, ]));
                break;
        default:
                return 0;
        }
}

void unconcious()
{
        die();
}


