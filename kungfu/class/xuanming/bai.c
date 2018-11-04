#include <ansi.h>
#include "xuanming.h"

inherit NPC;
inherit F_MASTER;
inherit F_COAGENT;
inherit F_QUESTER;

void create()
{
        set_name("�������", ({ "baisun daoren", "baisun", "daoren" }));
	set("gender", "����");
        set("long", @LONG
��������ڤ�ȿ�ɽ��ʦ������ˣ�ֻ�����ٷ�Ʈ����˫��������䣬���˾�η��
LONG);
        set("shen_type", -1);
        set("age", 72);
        set("str", 40);
        set("con", 38);
        set("int", 40);
        set("dex", 46);
        set("max_qi", 7400);
        set("max_jing", 3400);
        set("qi", 7400);
        set("jing", 3400);
        set("neili", 8500);
        set("max_neili", 8500);
        set("jiali", 250);
        set("combat_exp", 3200000);

        set_skill("force", 320);
        set_skill("xuanming-shengong", 320);
        set_skill("minggu-xinfa", 300);
        set_skill("dodge", 300);
        set_skill("liuying-bu", 300);
        set_skill("strike", 320);
        set_skill("feihua-zhang", 320);
        set_skill("xuanming-zhang", 320);
        set_skill("cuff", 300);
        set_skill("piaofeng-quan", 300);
        set_skill("parry", 320);
        set_skill("claw", 320);
        set_skill("dulong-shenzhua", 320);
        set_skill("literate", 260);
        set_skill("martial-cognize", 220);
        
        map_skill("strike", "xuanming-zhang");
        map_skill("force",  "xuanming-shengong");
        map_skill("dodge",  "liuying-bu");
        map_skill("parry",  "xuanming-zhang");
        map_skill("cuff",  "piaofeng-quan");
        map_skill("claw", "dulong-shenzhua");

        prepare_skill("strike", "xuanming-zhang");
             
        create_family("��ڤ��", 1, "��ɽ��ʦ");

        set("chat_chance_combat", 120);
        set("chat_msg_combat", ({               
                (: perform_action, "strike.ying" :),
                (: perform_action, "strike.lang" :),
                (: exert_function, "recover" :),
                (: exert_function, "powerup" :),
        }));

        set("inquiry", ([
                "¹�ȿ�"    :   "�����Ұ�ͽ��\n",
                "�ױ���"    :   "������ʦ�ܡ�\n", 
        ]));

        set_temp("apply/attack", 120);
        set_temp("apply/damage", 120);
        set_temp("apply/unarmed_damage", 120);
        set_temp("apply/armor", 120);

        setup();

        carry_object("/clone/cloth/baipao")->wear();
}

void attempt_apprentice(object ob)
{
        if (! permit_recruit(ob))
                return;

        if ((int)ob->query("shen") > -35000)
        {
                command("say �ߣ��Ұ�����˴Ӳ����������˽�����");
                return;
        }        
    
        if (ob->query_skill("minggu-xinfa", 1) < 160)
        {
                command("say ��ڤ���ķ�����㣬���Ǹ���ͽ������ϰ��ϰ�ɣ�");
                return ;
        }
        
        if (ob->query_skill("strike", 1) < 160)
        {
                command("say ������Ʒ���Ϊ���������Ժ����ѧϰ����ڤ�Ⱦ�ѧ��ڤ���ƣ�");
                return ;
        }

        if (ob->query("combat_exp") < 500000)
        {
                command("say �㽭�����黹���㣬����ȥ�ള��һ�°ɣ�");
                return;
        }

        command("nod");
        command("say �ã��ã��Ϸ���վ������㡣");
        command("haha");
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

        case "������" :
                return MASTER_D->teach_pfm(me, this_object(),
                        ([ "perform" : "can_perform/dulong-shenzhua/bao",
                           "name"    : "������",
                           "sk1"     : "dulong-shenzhua",
                           "lv1"     : 180,
                           "dodge"   : 150,
                           "gongxian": 420,
                           "shen"    : -38000, ]));
                break;

        case "������" :
                return MASTER_D->teach_pfm(me, this_object(),
                        ([ "perform" : "can_perform/dulong-shenzhua/ju",
                           "name"    : "������",
                           "sk1"     : "dulong-shenzhua",
                           "lv1"     :  130,
                           "force"   :  180,
                           "gongxian":  580,
                           "shen"    : -43000, ]));
                break;

        case "���κ���" :
                return MASTER_D->teach_pfm(me, this_object(),
                        ([ "perform" : "can_perform/xuanming-zhang/lang",
                           "name"    : "���κ���",
                           "sk1"     : "xuanming-zhang",
                           "lv1"     : 180,
                           "sk2"     : "xuanming-shengong",
                           "lv2"     : 180,
                           "neili"   : 3000,
                           "gongxian": 1200,
                           "shen"    : -68000, ]));
                break;

        default:
                return 0;
        }
}

void unconcious()
{
        die();
}
