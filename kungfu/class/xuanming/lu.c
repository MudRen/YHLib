#include <ansi.h>
#include "xuanming.h"

inherit NPC;
inherit F_MASTER;
inherit F_GUARDER;

#define ZHANG "/clone/lonely/lutouzhang"

void create()
{
        set_name("¹�ȿ�", ({ "luzhang ke", "luzhang", "ke" }));
	set("gender", "����");
        set("shen_type", -1);
        set("age", 52);
        set("str", 30);
        set("con", 38);
        set("int", 20);
        set("dex", 26);
        set("max_qi", 5400);
        set("max_jing", 2400);
        set("qi", 5400);
        set("jing", 2400);
        set("neili", 6500);
        set("max_neili", 6500);
        set("jiali", 220);
        set("combat_exp", 2200000);

        set_skill("force", 280);
        set_skill("xuanming-shengong", 280);
        set_skill("minggu-xinfa", 280);
        set_skill("dodge", 260);
        set_skill("liuying-bu", 260);
        set_skill("staff", 280);
        set_skill("ningxue-zhang", 280);
        set_skill("lutou-zhang", 280);
        set_skill("strike", 280);
        set_skill("feihua-zhang", 280);
        set_skill("xuanming-zhang", 280);
        set_skill("cuff", 260);
        set_skill("piaofeng-quan", 260);
        set_skill("parry", 260);
        set_skill("claw", 260);
        set_skill("dulong-shenzhua", 260);
        set_skill("literate", 240);
        set_skill("martial-cognize", 220);
        
        map_skill("staff",  "lutou-zhang");
        map_skill("strike", "xuanming-zhang");
        map_skill("force",  "xuanming-shengong");
        map_skill("dodge",  "liuying-bu");
        map_skill("parry",  "xuanming-zhang");
        map_skill("cuff",  "piaofeng-quan");
        map_skill("claw", "dulong-shenzhua");

        prepare_skill("strike", "xuanming-zhang");
             
        create_family("��ڤ��", 2, "����");

        set("no_teach", ([
                "xuanming-shengong" : "��ڤ��Ҫ��ʦ������������Դ��ڡ�",
                "xuanming-zhang"    : "��ڤ����Ҫ��ʦ�����Դ��ڣ��㻹��ȥ�������˼Ұɣ�",
        ])); 

        set("chat_chance_combat", 120);
        set("chat_msg_combat", ({               
                (: perform_action, "strike.ying" :),
                (: perform_action, "strike.zhe" :),
                (: perform_action, "strike.lang" :),
                (: exert_function, "recover" :),
                (: exert_function, "powerup" :),
        }));

        set("inquiry", ([
                "���޼�"    :   "�ߣ���С���Ŵλ��Ҵ��£��ҷ�ɱ�������ɣ�\n",
                "����"      :   "��Ѿͷ��ƶ�ˣ��������壬�����ֵ�Ϊ������������\n",
                "�������"  :   "�����Ҷ�ʦ���������ʲô��\n",
                "�ױ���"    :   "������ʦ�ܣ����Ǵ�С����ʦ��ѧ�գ���ͬ���㡣\n", 
        ]));

        set_temp("apply/attack", 120);
        set_temp("apply/damage", 120);
        set_temp("apply/unarmed_damage", 120);
        set_temp("apply/armor", 120);

	set("coagents", ({
                ([ "startroom" : "xxxxxxxxxxxx",
                   "id"        : "baisun daoren" ]),
        }));

        setup();

        carry_object("/clone/cloth/baipao")->wear();
}

void attempt_apprentice(object ob)
{
        if (! permit_recruit(ob))
                return;

        if ((int)ob->query("shen") > -20000)
        {
                command("say �ߣ�������һ��������Ȼ�������Ҿ�������");
                return;
        }        
    
        if (ob->query_skill("minggu-xinfa", 1) < 120)
        {
                command("say ��ڤ���ķ�����㣬���Ǹ���ʦ�ܶ���ϰ��ϰ�ɣ�");
                return ;
        }
        
        if (ob->query_skill("strike", 1) < 120)
        {
                command("say ������Ʒ���Ϊ���������Ժ����ѧϰ����ڤ�Ⱦ�ѧ��ڤ���ƣ�");
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
        case "�ͷ�ѩ��" :
                return MASTER_D->teach_pfm(me, this_object(),
                        ([ "perform" : "can_perform/ningxue-zhang/xue",
                           "name"    : "�ͷ�ѩ��",
                           "sk1"     : "ningxue-zhang",
                           "lv1"     : 50,
                           "gongxian": 220,
                           "shen"    : -20000, ]));
                break;

        case "ͨ�쳹��" :
                return MASTER_D->teach_pfm(me, this_object(),
                        ([ "perform" : "can_perform/lutou-zhang/tong",
                           "name"    : "ͨ�쳹��",
                           "sk1"     : "lutou-zhang",
                           "lv1"     :  100,
                           "force"   :  140,
                           "gongxian":  380,
                           "shen"    : -23000, ]));
                break;

        case "ֻ������" :
                return MASTER_D->teach_pfm(me, this_object(),
                        ([ "perform" : "can_perform/xuanming-zhang/zhe",
                           "name"    : "ֻ������",
                           "sk1"     : "xuanming-zhang",
                           "lv1"     : 150,
                           "sk2"     : "xuanming-shengong",
                           "lv2"     : 150,
                           "neili"   : 2000,
                           "gongxian": 880,
                           "shen"    : -50000, ]));
                break;


         case "¹ͷ��" :
                return MASTER_D->give_item(me, this_object(),
                               (["item"     :  ZHANG,
                                 "master"   :  1,
                                 "sk1"      :  "lutou-zhang",
                                 "lv1"      :  100,
                                 "shen"     :  -20000 ]));
                  break;

        default:
                return 0;
        }
}

void unconcious()
{
        die();
}
