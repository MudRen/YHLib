// yue-wife.c    changed by cocacola on 2.19.1997 Just for adding Chushi
// ������
// modify by rcwiz 2003

inherit NPC;
inherit F_MASTER;

#include "qizong.h"

void create()
{
        set_name("������", ({ "yue wife", "ning", "ning zhongze" }) );
        set("nickname", "��Ů��");
        set("gender", "Ů��");
        set("class", "swordsman");
        set("age", 50);
        set("long", "������ԭ����������������"
                    "������Ⱥ��ʦ�ã�Ҳ���������ӡ�\n");
        set("attitude", "peaceful");
        set("shen_type", 1);

        set("str", 24);
        set("int", 25);
        set("con", 23);
        set("dex", 22);

        set("max_qi", 3000);
        set("max_jing",1500);
        set("neili", 3700);
        set("max_neili", 3700);
        set("jiali", 30);
        set("combat_exp", 720000);

        set("apprentice_available", 3);

        set_skill("unarmed", 240);
        set_skill("cuff", 240);
        set_skill("strike", 240);
        set_skill("sword", 260);
        set_skill("blade", 260);
        set_skill("force", 260);
        set_skill("parry", 240);
        set_skill("dodge", 240);
        set_skill("literate", 180);
        set_skill("huashan-jian", 260);
        set_skill("shunv-jian", 260);
        set_skill("fanliangyi-dao", 260);
        set_skill("huashan-xinfa", 260);
        set_skill("huashan-quan", 240);
        set_skill("poyu-quan", 240);
        set_skill("huashan-zhang", 240);
        set_skill("hunyuan-zhang", 240);
        set_skill("huashan-shenfa", 240); 
        set_skill("martial-cognize", 200);

        map_skill("sword", "shunv-jian");
        map_skill("parry", "shunv-jian");
        map_skill("blade", "fanliangyi-dao");
        map_skill("force", "huashan-xinfa");
        map_skill("cuff", "poyu-quan");
        map_skill("strike", "hunyuan-zhang");
        map_skill("dodge", "huashan-shenfa");

        prepare_skill("strike", "hunyuan-zhang");
        prepare_skill("cuff", "poyu-quan");

        set_temp("apply/attack", 220);
        set_temp("apply/dodge", 220);
        set_temp("apply/parry", 200);
        set_temp("apply/damage", 150);
        set_temp("apply/unarmed_damage", 150);
        set_temp("apply/armor", 200);

        create_family("��ɽ��", 13, "���ŷ���");

	set("chat_chance_combat", 120);
	set("chat_msg_combat", ({
		(: perform_action, "sword.ning" :),
		(: perform_action, "strike.wuji" :),
		(: perform_action, "cuff.lei" :),
		(: perform_action, "cuff.po" :),
		(: exert_function, "recover" :),
	}));

        setup();

        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/clone/cloth/cloth")->wear();
}

void attempt_apprentice(object ob)
{
        if( query("apprentice_available") ) {
                if( find_call_out("do_recruit") != -1 )
                        command("say ������һ��һ������");
                else
                        call_out("do_recruit", 2, ob);
        } else {
                command("say �������Ӵ��");
        }
}

void do_recruit(object ob)
{
        if (! permit_recruit(ob))
                return;

        if ((string)ob->query("gender") != "Ů��")
	{
                command("say ��λ"+RANK_D->query_respect(ob) + "�㻹������ʦ��ȥ��.");
                return;
        }

        if (ob->query("shen") < 20000)
        {
                command("say ������������»����ò������һ��������㣡");
                return;
        }
 
        if (ob->query_skill("huashan-xinfa", 1) < 140)
        {
                command("say �һ�ɽ��������Ϊ�������������ķ��������������Ҳ������㣡");
                return;
        }
      
        if (ob->query_skill("huashan-jian", 1) < 140)
        {
                command("say �㻪ɽ������������������ȥ����ϰ��ϰ�������Ұɣ�");
                return;
        }        

        command("say ΢Ц�����ã��ã�ֻҪ������ѧ�����ձ��гɾ͡�");
        command("recruit " + ob->query("id") );
}

int recruit_apprentice(object ob)
{
        if (::recruit_apprentice(ob))
                ob->set("class", "huashan");
        add("apprentice_availavble", -1);
}

void reset()
{
        set("apprentice_available", 3);
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

        case "����һ��" :
                return MASTER_D->teach_pfm(me, this_object(),
                        ([ "perform" : "can_perform/shunv-jian/ning",
                           "name"    : "����һ��",
                           "sk1"     : "shunv-jian",
                           "lv1"     : 100,
                           "sk2"     : "force",
                           "lv2"     : 100,
                           "sk3"     : "dodge",
                           "lv3"     : 100,                           
                           "gongxian": 600,
                           "shen"    : 30000, ]));
                break;

        default:
                return 0;
        }
}

void unconcious()
{
        die();
}


