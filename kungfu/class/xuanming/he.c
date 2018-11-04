#include <ansi.h>
#include "xuanming.h"

inherit NPC;
inherit F_MASTER;
inherit F_GUARDER;

#define BI "/clone/lonely/hexingbi"

void create()
{
        set_name("�ױ���", ({ "hebi weng", "hebi", "weng" }));
	set("gender", "����");
        set("shen_type", -1);
        set("age", 50);
        set("str", 30);
        set("con", 38);
        set("int", 20);
        set("dex", 26);
        set("max_qi", 4400);
        set("max_jing", 2200);
        set("qi", 4400);
        set("jing", 2200);
        set("neili", 5500);
        set("max_neili", 5500);
        set("jiali", 135);
        set("combat_exp", 1200000);

        set_skill("force", 260);
        set_skill("xuanming-shengong", 260);
        set_skill("minggu-xinfa", 260);
        set_skill("dodge", 240);
        set_skill("liuying-bu", 240);
        set_skill("dagger", 240);
        set_skill("jingyue-bifa", 260);
        set_skill("hexing-bifa", 260);
        set_skill("strike", 260);
        set_skill("feihua-zhang", 260);
        set_skill("xuanming-zhang", 260);
        set_skill("cuff", 260);
        set_skill("piaofeng-quan", 260);
        set_skill("parry", 240);
        set_skill("claw", 240);
        set_skill("dulong-shenzhua", 240);
        set_skill("literate", 220);
        set_skill("martial-cognize", 200);
        
        map_skill("dagger",  "hexing-bifa");
        map_skill("strike", "xuanming-zhang");
        map_skill("force",  "xuanming-shengong");
        map_skill("dodge",  "liuying-bu");
        map_skill("parry",  "xuanming-zhang");
        map_skill("cuff",  "piaofeng-quan");
        map_skill("claw",  "dulong-shenzhua");

        prepare_skill("strike", "xuanming-zhang");
             
        create_family("��ڤ��", 2, "����");

        set("no_teach", ([
                "xuanming-shengong" : "��ڤ��Ҫ��ʦ������������Դ��ڡ�",
                "xuanming-zhang"    : "��ڤ����Ҫ��ʦ�����Դ��ڣ��㻹��ȥ�������˼Ұɣ�",
                "dulong-shenzhua"   : "����㻹������ʦ��¹�ȿͰɣ��������������ˣ�",
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
                "¹�ȿ�"    :   "������ʦ�֣����Ǵ�С����ʦ��ѧ�գ���ͬ���㡣\n", 
        ]));

        set_temp("apply/attack", 80);
        set_temp("apply/damage", 80);
        set_temp("apply/unarmed_damage", 80);
        set_temp("apply/armor", 80);

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

        if (ob->query("family/master_name") == "¹�ȿ�")
        {
                command("say ���Ȼ�ѵõ���ʦ��ָ�㣬���Ǻúø�����ѧ�ɣ�");
                return;
        }

        if ((int)ob->query("shen") > 0)
        {
                command("say ����ڤ����������������Щ������ʿ������");
                command("say �㻹����ذɣ�");
                return;
        }

        command("nod");
        command("say �����Ҿ����������㣬�պ���̿����䡣");
        command("recruit " + ob->query("id"));
}

int accept_ask(object me, string topic)
{
        switch (topic)
        {
        case "�ƴ�ɻ�" :
                return MASTER_D->teach_pfm(me, this_object(),
                        ([ "perform" : "can_perform/feihua-zhang/fei",
                           "name"    : "�ƴ�ɻ�",
                           "sk1"     : "feihua-zhang",
                           "lv1"     : 40,
                           "gongxian": 100,
                           "shen"    : -2000, ]));
                break;

        case "���־�" :
                return MASTER_D->teach_pfm(me, this_object(),
                        ([ "perform" : "can_perform/piaofeng-quan/juan",
                           "name"    : "���־�",
                           "sk1"     : "piaofeng-quan",
                           "lv1"     :  30,
                           "gongxian":  80,
                           "shen"    : -500, ]));
                break;

        case "���´�" :
                return MASTER_D->teach_pfm(me, this_object(),
                        ([ "perform" : "can_perform/jingyue-bifa/ci",
                           "name"    : "���´�",
                           "sk1"     : "jingyue-bifa",
                           "lv1"     : 30,
                           "gongxian": 200,
                           "shen"    : -2400, ]));
                break;

        case "�ڵ�Ǭ��" :
                return MASTER_D->teach_pfm(me, this_object(),
                        ([ "perform" : "can_perform/hexing-bifa/dian",
                           "name"    : "�ڵ�Ǭ��",
                           "sk1"     : "hexing-bifa",
                           "lv1"     : 100,
                           "gongxian": 320,
                           "shen"    : -8000, ]));
                break;

        case "��Ӱ����" :
                return MASTER_D->teach_pfm(me, this_object(),
                        ([ "perform" : "can_perform/xuanming-zhang/ying",
                           "name"    : "��Ӱ����",
                           "sk1"     : "xuanming-zhang",
                           "lv1"     :  100,
                           "dodge"   :  180,
                           "gongxian":  380,
                           "shen"    : -32000, ]));
                break;

         case "���α�" :
                return MASTER_D->give_item(me, this_object(),
                               (["item"     :  BI,
                                 "master"   :  1,
                                 "sk1"      :  "hexing-bifa",
                                 "lv1"      :  100,
                                 "shen"     :  -10000 ]));
                  break;
        default:
                return 0;
        }
}

void unconcious()
{
        die();
}
