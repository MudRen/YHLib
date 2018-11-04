#include <ansi.h>
#include "tiezhang.h"

inherit NPC;
inherit F_MASTER;
inherit F_GUARDER;

void create()
{
        set_name("˾ͽ��", ({ "situ fen", "situ", "fen"}));
        set("long", "һ����ʮ������������ӣ����������ư��������\n"
                    "�е�ٮٮ�ߣ�Ϊ�˺��Ǿ�������ð�����ϲ����\n" );
        set("gender", "����");
        set("age", 40);
        set("attitude", "friendly");
        set("shen_type", -1);
        set("str", 25);
        set("int", 25);
        set("con", 25);
        set("dex", 25);
       
        set("qi", 3500);
        set("max_qi", 3500);
        set("jing", 2000);
        set("max_jing", 2000);
        set("neili", 4000);
        set("max_neili", 4000);
        set("jiali", 120);
        set("combat_exp", 2000000);
        set("score", 40000);

        set_skill("force", 180);
        set_skill("tiezhang-xinfa", 200);
        set_skill("dodge", 200);
        set_skill("dengping-dushui", 200);
        set_skill("strike", 200);
        set_skill("parry", 200);
        set_skill("chuanxin-zhang", 200);
        set_skill("tongbi-zhang", 200);
        set_skill("cuff", 180);
        set_skill("tiexian-quan", 180);
        set_skill("unarmed", 180);
        set_skill("tiexue-dao", 180);
        set_skill("blade", 180);
        set_skill("literate", 160);
        set_skill("martial-cognize", 160);

        map_skill("force", "tiezhang-xinfa");
        map_skill("strike", "chuanxin-zhang");
        map_skill("cuff", "tiexian-quan");
        map_skill("parry", "chuanxin-zhang");
        map_skill("dodge", "dengping-dushui");
        map_skill("blade", "tiexue-dao");

        prepare_skill("strike", "chuanxin-zhang");
        prepare_skill("cuff", "tiexian-quan");

        set("coagents", ({
                ([ "startroom" : "/d/tiezhang/wztang",
                   "id"        : "qiu qianren" ]),
        }));

        create_family("���ư�", 14, "����");

        set("chat_chance_combat", 120);
        set("chat_msg_combat", ({
                (: perform_action, "blade.xue" :),
                (: perform_action, "cuff.kai" :),
                (: perform_action, "unarmed.zhui" :),
                (: exert_function, "recover" :),
                (: exert_function, "powerup" :),
        }) );

        setup();

        carry_object("/clone/misc/cloth")->wear();
        carry_object("/clone/weapon/gangdao")->wield();
        add_money("silver", 200);
}

void attempt_apprentice(object me)
{
        string purename, name, new_name;

        if (! permit_recruit(me))
                return;

        if ( me->query("family/family_name") &&
             me->query("family/family_name") == "�����" &&
             me->query("family/master_name") == "��ǧ��" )
        {
                command("yi");
                command("say ԭ����������ǧ��ʦ��ĺ��ᣬ������ͱ����м����ԨԴ��");

                command("consider");
                command("say ��������������������㻹��ֱ��ȥ�Ұ����ɡ�");

                me->set("move_party/����ȡ����ư�", 1);
                return;
        }

        if ((int)me->query("shen") > -10000)
        {
                command("heng");
                command("say �������Ĵ�����ɲ��С�");
                return;
        }

        if ((int)me->query("combat_exp") < 140000)
        {
                command("heng");
                command("say ������������ܳɴ������������������ɣ�");
                return;
        }

        if ((int)me->query_skill("force") < 60)
        {
                command("say ѧ��֮������ڹ��������ҿ����µĹ��򻹲���ѽ��");
                return;
        }

        if ((int)me->query_skill("strike", 1) < 40)
        {
                command("say ���֮������������Ʒ���û���ã����������ư�������");
                return;
        }

        command("say  ��Ȼ�������ұ������㣬ϣ������������񹦣���֮������");

        command("recruit " + me->query("id"));
}

void init()
{
        object me, ob;
        mapping fam;

        ::init();

        ob = this_player();
        me = this_object();
        
        if (interactive(ob) 
            && ! environment(ob)->query("no_fight")
            && ! present("tiezhang ling", ob)
            && ! ob->query("move_party/����ȡ����ư�", 1)
            && ( (fam = ob->query("family"))
            && fam["family_name"] != "���ư�" ) )
        {
                if( ob->query_temp("warned") < 3 )
                {
                        command("say վס���㲻�����ư���ӣ������ڴ˾�����");
                        command("say �㻹�������뿪�˵ذɣ���Ȼ�ҿ�Ҫ���㲻�����ˣ���");
                        ob->add_temp("warned", 1);
                }
           else if( ob->query_temp("stay") < 3 )
                        ob->add_temp("stay", 1);
           else {
                        command("say ���ò��ͷ��ˣ����ҵ����ư�����Ұ��\n");
                        remove_call_out("hiting_ob");
                        call_out("hiting_ob", 1, ob);
                }
        }       
}

int hiting_ob(object ob)
{
        object me;
        me = this_object();
        ob->kill_ob(me);
        me->fight_ob(ob);
        remove_call_out("moving_ob");
        call_out("moving_ob",1,ob);
}

int accept_ask(object me, string topic)
{
        switch (topic)
        {
        case "Ѫ������" :
                return MASTER_D->teach_pfm(me, this_object(),
                          ([ "perform" : "can_perform/tiexue-dao/xue",
                           "name"    : "Ѫ������",
                           "msg1"    : HIY "$N" HIY "΢΢һЦ������"
                                       "���������ֹ��˼��䣬Ȼ��˳"
                                       "�ְγ�����ĸյ������ն��"
                                       "���£���ʽ���Ǿ��档������"
                                       "����ĵ��˵�ͷ��",
                            "sk1"     : "tiexue-dao",
                           "lv1"     : 100,
                           "force"   : 60,
                           "gongxian": 60,
                           "shen"    : -15000, ]));
                break;

        case "����׶" :
                return MASTER_D->teach_pfm(me, this_object(),
                        ([ "perform" : "can_perform/chuanxin-zhang/zhui",
                           "name"    : "����׶",
                           "sk1"     : "chuanxin-zhang",
                           "lv1"     : 100,
                           "force"   : 150,
                           "dodge"   : 220,
                           "neili"   : 200,
                           "gongxian": 200,
                           "shen"    : -18000, ]));
                break;

        case "�Ƽ���ɽ" :
                return MASTER_D->teach_pfm(me, this_object(),
                        ([ "perform" : "can_perform/tiexian-quan/tui",
                           "name"    : "�Ƽ���ɽ",
                           "sk1"     : "tiexian-quan",
                           "lv1"     : 100,
                           "force"   : 90,
                           "neili"   : 400,
                           "gongxian": 260,
                           "shen"    : -23000, ]));
                break;

        case "����׶" :
                return MASTER_D->teach_pfm(me, this_object(),
                        ([ "perform" : "can_perform/chuanxin-zhang/zhui",
                           "name"    : "����׶",
                           "sk1"     : "chuanxin-zhang",
                           "lv1"     : 100,
                           "force"   : 150,
                           "dodge"   : 220,
                           "neili"   : 200,
                           "gongxian": 200,
                           "shen"    : -18000, ]));
                break;

        default:
                return 0;
        }
}

