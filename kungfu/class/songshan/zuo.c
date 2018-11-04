#include <ansi.h>
#include "songshan.h"

#define CANYANG "/clone/lonely/canyang"

inherit NPC;
inherit F_MASTER;
inherit F_QUESTER;
inherit F_COAGENT;

void create()
{
        object ob;

        set_name("������", ({ "zuo lengchan", "zuo" }) );
        set("title", HIR"������������"HIY"��ɽ�ɵ�ʮ��������"NOR);
        set("gender", "����");
        set("class", "swordsman");
        set("age", 55);
        set("attitude", "peaceful");
        set("str", 36);
        set("con", 33);
        set("dex", 30);
        set("int", 28);

        set("max_qi",5500);
        set("max_jing",2200);
        set("neili", 5000);
        set("max_neili", 5000);
        set("jiali", 220);
        set("combat_exp", 1850000);
        set("shen_type", -1);

        set_skill("cuff", 240);
        set_skill("strike", 260);       
        set_skill("sword", 260);
        set_skill("force", 280);
        set_skill("parry", 240);
        set_skill("dodge", 240);
        set_skill("lingxu-bu", 240);
        set_skill("songshan-jian", 260);
        set_skill("lingyun-jian", 260);
        set_skill("chuanyue-jian", 260);
        set_skill("jiuqu-jian", 260);
        set_skill("poyang-jian", 260);      
        set_skill("songshan-xinfa", 280);
        set_skill("hanbing-zhenqi", 280);
        set_skill("hanbing-zhang", 260);
        set_skill("songshan-zhang", 260);
        set_skill("songshan-quan", 240);
        set_skill("literate", 220);
        set_skill("martial-cognize", 200);

        map_skill("force", "hanbing-zhenqi");
        map_skill("sword", "poyang-jian");
        map_skill("parry", "poyang-jian");
        map_skill("strike", "hanbing-zhang");
        map_skill("cuff", "songshan-quan");
        map_skill("dodge", "lingxu-bu");

        prepare_skill("strike", "hanbing-zhang");
             
        create_family("��ɽ��", 13, "����");

        set("chat_chance_combat", 120);
        set("chat_msg_combat", ({
                (: perform_action, "sword.long" :),
                (: perform_action, "sword.xian" :),
                (: perform_action, "strike.heng" :),
                (: perform_action, "strike.han" :),
                (: exert_function, "recover" :),
                (: exert_function, "powerup" :),
                (: exert_function, "freezing" :)
        }));
     
        set_temp("apply/attack", 100);
        set_temp("apply/damage", 100);
        set_temp("apply/unarmed_damage", 100);
        set_temp("apply/armor", 200);

        setup();

        if (clonep())
        {
                ob = find_object(CANYANG);
                if (! ob) ob = load_object(CANYANG);
                if (! environment(ob))
                {
                        ob->move(this_object());
                        ob->wield();
                } else
                {
                        ob = new("/clone/weapon/changjian");
                        ob->move(this_object());
                        ob->wield();
                }
        }
        carry_object("/clone/cloth/cloth")->wear();
}


void attempt_apprentice(object ob)
{
        if (! permit_recruit(ob))
                return;

        if ((int)ob->query("shen") > -30000)
        {
                command("say �������������Щ����֮ʿ���㻹����ذɣ�");
                return;
        }

	if ((int)ob->query("combat_exp") < 360000)
	{
		command("say �����ھ�����ǳ�����Ƕ��ڽ��������߰ɡ�");
		return;
	}

        if ((int)ob->query_skill("songshan-jian", 1) < 160)
	{	
		command("say ����ɽ��������������֮һ����Ϊ���ӽ�����");
		command("say �����ɽ������������������ȥ���������ɡ�");
        	return;
        }
   
        if ((int)ob->query_skill("songshan-xinfa", 1) < 160)
	{
		command("say ����ɽ���������ý������ڹ�ȴ������֮����");
		command("say ���Ƿ�Ӧ������ɽ�ķ��϶��µ㹦��");
		return;
 	} 

	command("haha");
        command("say ���ӿɽ̣����ӿɽ̡������Ҿ�������ɡ�");
        command("say ���Ժ�Ҫ�����䣬������ɽ���۷硣");
        command("recruit " + ob->query("id"));
}
 

int accept_ask(object me, string topic)
{
        switch (topic)
        {
        case "����" :
        case "����" :
        case "����" :
                return QUEST_D->accept_ask(this_object(), me, topic);
                break;

        case "̤ѩ�޺�" :
                return MASTER_D->teach_pfm(me, this_object(),
                        ([ "perform" : "can_perform/hanbing-zhang/heng",
                           "name"    : "̤ѩ�޺�",
                           "sk1"     : "hanbing-zhang",
                           "lv1"     : 100,
                           "force"   : 160,
                           "gongxian": 550,
                           "shen"    : -32000, ]));
                break;

        case "���캮��" :
                return MASTER_D->teach_pfm(me, this_object(),
                        ([ "perform" : "can_perform/hanbing-zhang/han",
                           "name"    : "���캮��",
                           "sk1"     : "hanbing-zhang",
                           "lv1"     : 120,
                           "force"   : 200,
                           "gongxian": 750,
                           "shen"    : -48000, ]));
                break;

        case "�������" :
                return MASTER_D->teach_pfm(me, this_object(),
                        ([ "perform" : "can_perform/poyang-jian/xian",
                           "name"    : "�������",
                           "sk1"     : "poyang-jian",
                           "lv1"     : 100,
                           "dodge"   : 140,
                           "gongxian": 650,
                           "shen"    : -54000, ]));
                break;

        case "��������" :
                return MASTER_D->teach_pfm(me, this_object(),
                        ([ "perform" : "can_perform/poyang-jian/long",
                           "name"    : "��������",
                           "sk1"     : "poyang-jian",
                           "lv1"     : 120,
                           "force"   : 180,
                           "gongxian": 900,
                           "shen"    : -72000, ]));
                break;


        case "��������" :
                return MASTER_D->teach_pfm(me, this_object(),
                        ([ "perform" : "can_perform/hanbing-zhenqi/freezing",
                           "name"    : "��������",
                           "sk1"     : "hanbing-zhenqi",
                           "lv1"     : 80,
                           "force"   : 140,
                           "gongxian": 1500,
                           "shen"    : -93000, ]));
                break;

        case "��������" :
                return MASTER_D->give_item(me, this_object(),
                        ([ "item"    : CANYANG,
                           "master"  : 1,
                           "sk1"     : "songshan-jian",
                           "lv1"     : 120,
                           "shen"    : -20000, ]));
                break;
        default:
                return 0;
        }
}

