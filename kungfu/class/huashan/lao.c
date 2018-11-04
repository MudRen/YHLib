// lao-denuo.c

inherit NPC;
inherit F_GUARDER;
inherit F_MASTER;

int permit_pass(object me, string dir);
#include "qizong.h"

void create()
{
        set_name("�͵�ŵ", ({ "lao denuo","lao","denuo" }) );
        set("nickname", "�Ϻ���");
        set("gender", "����");
        set("age", 61);
        set("long", "�͵�ŵ������Ⱥ�Ķ����ӣ�����Ҳ�ǲ�����\n");
        set("attitude", "peaceful");

        set("str", 26);
        set("con", 30);
        set("int", 24);
        set("dex", 30);

        set("max_qi", 3400);
        set("max_jing", 1700);
        set("neili", 2800);
        set("max_neili", 2800);

        set("combat_exp", 150000);
        set("shen_type", -1);
        set("score", 5000);

        set("chat_chance_combat", 120);
        set("chat_msg_combat", ({
                (: perform_action, "strike.lao" :),
                (: perform_action, "cuff.song" :),
                (: perform_action, "sword.feng" :),
                (: perform_action, "sword.lian" :),
                (: exert_function, "recover" :)
        }) );

        set_skill("unarmed", 120);
        set_skill("sword", 140);
        set_skill("force", 140);
        set_skill("cuff", 120);
        set_skill("strike", 120);
        set_skill("parry", 120);
        set_skill("dodge", 120);
        set_skill("literate", 100);
        set_skill("martial-cognize", 100);

        set_skill("huashan-jian", 140);
        set_skill("huashan-xinfa", 140);
        set_skill("huashan-quan", 120);
        set_skill("huashan-zhang", 120);
        set_skill("huashan-shenfa", 120);

        map_skill("sword", "huashan-jian");
        map_skill("parry", "huashan-jian");
        map_skill("force", "huashan-xinfa");
        map_skill("cuff", "huashan-quan");
        map_skill("strike", "huashan-zhang");
        map_skill("dodge", "huashan-shenfa");

        prepare_skill("strike", "huashan-zhang");
        prepare_skill("claw", "huashan-quan");

        set_temp("apply/damage", 100);
        set_temp("apply/armor", 100);

        set("inquiry", ([
               "����Ⱥ"     :  "��������ʦ��������������\n",
               "������"     :  "������ʦĸ��\n",
        ]));

        set("apply/dodge", 100);

        set("coagents", ({
                ([ "startroom" : "/d/huashan/qunxianguan",
                   "id"        : "yue buqun" ]),
        }));

        create_family("��ɽ��", 14, "����");
        setup();

        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/clone/cloth/cloth")->wear();
}

int permit_pass(object me, string dir)
{
        object *inv;
        int i;

        inv = deep_inventory(me);
        for (i = 0; i < sizeof(inv); i++)
        {
                if (! playerp(inv[i])) continue;
                if ((string) inv[i]->query("family/family_name") != "��ɽ��")
                {
                        message_vision("$N��$n�ȵ����㱳����˭�����������£�\n",
                                       this_object(), me);
                        return 0;
                }
        }

        if (me->query("family/family_name") &&
            me->query("family/family_name") != "��ɽ��" ||
            ! me->query("family/family_name"))
        {
                message_vision("$N��$n�����Բ��𣬲������ǻ�ɽ�ɵ���"
                               "�����뱾���صء�\n", this_object(), me);
                return 0;
        }

        return 1;
}

void attempt_apprentice(object ob)
{
        if( !permit_recruit(ob) )
                return;
        
        if (ob->query("shen") < 0)
        {
             command("shake");
             command("say �һ�ɽ�����������ɣ�������������������֮ͽ��");
             return;
        }

        command("say �ðɣ��Ҿ��������ˡ�");
        command("recruit " + ob->query("id"));
}


int accept_ask(object me, string topic)
{
        switch (topic)
        {
        case "����ʽ" :
                return MASTER_D->teach_pfm(me, this_object(),
                        ([ "perform" : "can_perform/huashan-jian/jie",
                           "name"    : "����ʽ",
                           "sk1"     : "huashan-jian",
                           "lv1"     : 30,
                           "gongxian": 60,
                           "shen"    : 500, ]));
                break;

        case "����Ʈ��" :
                return MASTER_D->teach_pfm(me, this_object(),
                        ([ "perform" : "can_perform/huashan-zhang/piao",
                           "name"    : "����Ʈ��",
                           "sk1"     : "huashan-zhang",
                           "lv1"     : 30,
                           "gongxian": 60,
                           "shen"    : 600, ]));
                break;

        case "����ʽ" :
                return MASTER_D->teach_pfm(me, this_object(),
                        ([ "perform" : "can_perform/huashan-quan/song",
                           "name"    : "����ʽ",
                           "sk1"     : "huashan-quan",
                           "lv1"     : 40,
                           "gongxian": 100,
                           "shen"    : 800, ]));
                break;

        case "����������" :
                return MASTER_D->teach_pfm(me, this_object(),
                        ([ "perform" : "can_perform/huashan-jian/lian",
                           "name"    : "����������",
                           "sk1"     : "huashan-jian",
                           "lv1"     : 50,
                           "force"   : 100,
                           "gongxian": 150,
                           "shen"    : 1200, ]));
                break;

        default:
                return 0;
        }
}

void unconcious()
{
        die();
}

