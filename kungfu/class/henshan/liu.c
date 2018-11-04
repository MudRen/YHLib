#include <ansi.h>
#include "henshan.h"

inherit NPC;
inherit F_MASTER;
inherit F_GUARDER;
inherit F_COAGENT;

void create()
{
        set_name("������", ({ "liu zhengfeng", "liu", "zhengfeng" }));
        set("nickname", HIR "���㽣" NOR);
        set("gender", "����" );
        set("class", "swordman");
        set("attitude", "peaceful");
        set("shen_type", 1);

        set("age", 45);
        set("str", 28);
        set("con", 26);
        set("int", 28);
        set("dex", 28);
        set("max_qi", 4500);
        set("max_jing", 2000);
        set("neili", 4000);
        set("max_neili", 4000);
        set("jiali", 150);
        set("combat_exp", 1800000);

        set_skill("force", 240);
        set_skill("henshan-xinfa", 240);
        set_skill("zhenyue-jue", 240);
        set_skill("dodge", 220);
        set_skill("henshan-shenfa", 220);
        set_skill("cuff", 220);
        set_skill("henshan-quan", 220);
        set_skill("sword", 240);
        set_skill("henshan-jian", 240);
        set_skill("tianzhu-jian", 240);
        set_skill("zigai-jian", 240);
        set_skill("furong-jian", 240);
        set_skill("shilin-jian", 240);
	set_skill("luoyan-jian", 240);
        set_skill("strike", 220);
        set_skill("biluo-zhang", 220);
        set_skill("liuyun-zhang" , 220);
        set_skill("parry", 220);
        set_skill("literate", 260);
	set_skill("tanqin-jifa", 280);
        set_skill("xiaoao-jianghu", 280);
	set_skill("guangling-san", 280);
        set_skill("martial-cognize", 220);

        map_skill("strike", "liuyun-zhang");
        map_skill("cuff", "henshan-quan");
        map_skill("sword", "luoyan-jian");
        map_skill("force", "zhenyue-jue");
        map_skill("dodge", "henshan-shenfa");
        map_skill("parry", "luoyan-jian");
	map_skill("tanqin-jifa", "xiaoao-jianghu");
	map_skill("tanqin-jifa", "xiaoao-jianghu");

        prepare_skill("strike", "liuyun-zhang");
             
        create_family("��ɽ��", 13, "����");

	set("no_teach", ([
		"liuyun-zhang" : "������������ֻ�����������ڣ��㻹������ʦ�ִ��ڰɣ�",
		"shilin-jian"  : "ʯ�޽�������ֻ�����������ڣ��㻹������ʦ�ִ��ڰɣ�",
        ]));

        set("chat_chance_combat", 120);
        set("chat_msg_combat", ({
                (: perform_action, "sword.luo" :),
                (: perform_action, "strike.pai" :),
		(: perform_action, "strike.ying" :),
                (: exert_function, "recover" :),
                (: exert_function, "powerup" :),
        }));
     
        set("coagents", ({
                ([ "startroom" : "/d/henshan/furongfeng",
                   "id"        : "qu yang" ]),
        }));

        set_temp("apply/attack", 100);
        set_temp("apply/damage", 100);
        set_temp("apply/unarmed_damage", 100);
        set_temp("apply/armor", 200);

        setup();

        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/clone/cloth/cloth")->wear();
        set_temp("handing", carry_object("/d/henshan/npc/obj/tanmuqin"));
}


void attempt_apprentice(object ob)
{
        if (! permit_recruit(ob))
                return;

        if ((int)ob->query("shen") < 30000)
        {
                command("say �Һ�ɽ�������������������ɣ��Ե���Ҫ���ϸ�");
                command("say ��������������з����Ƿ����ò�����");
                return;
        }

	if ((int)ob->query("combat_exp") < 200000)
	{
		command("say �����ھ�����ǳ�����Ƕ��ڽ��������߰ɡ�");
		return;
	}

        if ((int)ob->query_skill("henshan-jian", 1) < 120)
	{	
		command("say �Һ�ɽ����������֮һ����Ϊ���ӽ�����");
		command("say ��ĺ�ɽ������������������ȥ���������ɡ�");
        	return;
        }
   
        if ((int)ob->query_skill("force") < 150)
	{
		command("say �Һ�ɽ���������ý������ڹ�ȴ������֮����");
		command("say ���Ƿ�Ӧ�����ڹ��ķ��϶��µ㹦��");
		return;
 	} 

	command("haha");
        command("say ���ӿɽ̣����ӿɽ̡������Ҿ�������ɡ�");
        command("say ���Ժ�Ҫ�����䣬�����ƣ����Һ�ɽ���۷硣");
        command("recruit " + ob->query("id"));
}
 
int accept_ask(object me, string topic)
{
        switch (topic)
        {
        case "�ҽ�����" :
                return MASTER_D->teach_pfm(me, this_object(),
                        ([ "perform" : "can_perform/furong-jian/luan",
                           "name"    : "�ҽ�����",
                           "msg1"    : "$N���˵�ͷ����Ȼһ����Х����"
                                       "�ն���������һ����������"
                                       "�̼�ֻ���ý�����ɢ����������"
                                       "��������������Ӱ�����£���"
                                       "ʽ���澫���ޱȡ�",
                           "sk1"     : "furong-jian",
                           "lv1"     : 100,
                           "force"   : 140,
                           "dodge"   : 140,
                           "neili"   : 1600,
                           "gongxian": 300,
                           "shen"    : 20000, ]));
                break;

        case "һ�������" :
                return MASTER_D->teach_pfm(me, this_object(),
                        ([ "perform" : "can_perform/luoyan-jian/luo",
                           "name"    : "һ�������",
                           "sk1"     : "luoyan-jian",
                           "lv1"     : 150,
                           "force"   : 220,
                           "dodge"   : 220,
                           "neili"   : 2800,
                           "gongxian": 1500,
                           "shen"    : 50000, ]));
                break;
        default:
                return 0;
        }
}

void init(object ob)
{
        string startroom;

        if (interactive(ob = this_player())
           && ! is_fighting())
        {
                if (! ob || environment(ob) != environment())
                        return;

                if (stringp(startroom = query("startroom"))
                   && find_object(startroom) == environment())
                        command("play xiaoao-jianghu");
                else
                        say(CYN + this_object()->name() +
                            CYN "�����̾�˿�����\n" NOR);
        }
        return;
}
