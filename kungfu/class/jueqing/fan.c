#include <ansi.h>
#include "jueqing.h"

inherit NPC;
inherit F_MASTER;
inherit F_GUARDER;

void create()
{
        set_name("��һ��", ({ "fan yiweng", "fan", "yiweng" }));
	set("gender", "����");
        set("shen_type", 0);
        set("age", 60);
        set("str", 38);
        set("con", 28);
        set("int", 20);
        set("dex", 26);
        set("max_qi", 4000);
        set("max_jing", 3000);
        set("neili", 4000);
        set("max_neili", 4000);
        set("jiali", 200);
        set("combat_exp", 2200000);

        set_skill("force", 180);
        set_skill("jueqing-xinfa", 180);   
        set_skill("dodge", 180);
        set_skill("jueqing-shenfa", 180);
        set_skill("staff", 180);
        set_skill("poshui-zhang", 180);
        set_skill("strike", 180);
        set_skill("cuff", 160);
        set_skill("guhong-zhang", 180);
        set_skill("pokong-quan", 160);
        set_skill("jueqing-zhang", 160);
        set_skill("sword", 160);
        set_skill("jueqing-jian", 160);
        set_skill("guxing-jian", 160);
        set_skill("blade", 160);
        set_skill("tianjue-dao", 160);
        set_skill("luoyun-dao", 160);
        set_skill("parry", 180);
        set_skill("literate", 160);
        set_skill("martial-cognize", 160);
        
        map_skill("staff",  "poshui-zhang");
        map_skill("sword",  "guxing-jian");
        map_skill("strike", "guhong-zhang");
        map_skill("force",  "jueqing-xinfa");
        map_skill("blade",  "luoyun-dao");
        map_skill("dodge",  "jueqing-shenfa");
        map_skill("parry",  "poshui-zhang");

        prepare_skill("strike", "jueqing-zhang");
             
        create_family("�����", 5, "����");

        set("chat_chance_combat", 120);
        set("chat_msg_combat", ({
                (: perform_action, "staff.tai" :),
                (: perform_action, "strike.qian" :),
                (: exert_function, "recover" :),
        }));

        set_temp("apply/attack", 60);
        set_temp("apply/damage", 60);
        set_temp("apply/unarmed_damage", 60);
        set_temp("apply/armor", 60);

	set("coagents", ({
                ([ "startroom" : "/d/jueqing/zizhuxuan",
                   "id"        : "gongsun zhi" ]),
        }));

        setup();

        carry_object("/clone/cloth/cloth")->wear();
        carry_object("/clone/weapon/gangzhang")->wield();
}

void attempt_apprentice(object ob)
{
        if (! permit_recruit(ob))
                return;

        if ((int)ob->query("shen") > 0)
        {
                command("say �Ҿ������������������Щ������ʿ������");
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
        case "��ˮ����" :
                return MASTER_D->teach_pfm(me, this_object(),
                        ([ "perform" : "can_perform/jueqing-jian/liu",
                           "name"    : "��ˮ����",
                           "sk1"     : "jueqing-jian",
                           "lv1"     : 60,
                           "force"   : 60,
                           "gongxian": 80,
                           "shen"    : -4000, ]));
                break;

        case "�����" :
                return MASTER_D->teach_pfm(me, this_object(),
                        ([ "perform" : "can_perform/tianjue-dao/suo",
                           "name"    : "�����",
                           "sk1"     : "tianjue-dao",
                           "lv1"     :  40,
                           "gongxian":  100,
                           "shen"    : -4000, ]));
                break;

        case "�������" :
                return MASTER_D->teach_pfm(me, this_object(),
                        ([ "perform" : "can_perform/pokong-quan/kong",
                           "name"    : "�������",
                           "sk1"     : "pokong-quan",
                           "lv1"     : 50,
                           "force"   : 70,
                           "gongxian": 100,
                           "shen"    : -4000, ]));
                break;

        case "������" :
                return MASTER_D->teach_pfm(me, this_object(),
                        ([ "perform" : "can_perform/jueqing-zhang/wan",
                           "name"    : "������",
                           "msg1"    : this_object()->name() + "����"
                                       "��ͷ����Ȼһ����Х���������"
                                       "��������ʹ�������ٸ�������"
                                       "����Ȼ��˫�Ʒ�������򳤿�"
                                       "�������������£�������ȴ����"
                                       "����ɱ�����㿴�����в��ɵ���"
                                       "̾��",
                           "sk1"     : "jueqing-zhang",
                           "lv1"     : 100,
                           "dodge"   : 80,
                           "gongxian": 120,
                           "shen"    : -8000, ]));
                break;

        case "��������" :
                return MASTER_D->teach_pfm(me, this_object(),
                        ([ "perform" : "can_perform/guxing-jian/lian",
                           "name"    : "��������",
                           "sk1"     : "guxing-jian",
                           "lv1"     :  80,
                           "force"   :  60,
                           "gongxian": 180,
                           "shen"    : -12000, ]));
                break;

        case "�쵶����ʽ" :
                return MASTER_D->teach_pfm(me, this_object(),
                        ([ "perform" : "can_perform/luoyun-dao/tian",
                           "name"    : "�쵶����ʽ",
                           "sk1"     : "luoyun-dao",
                           "lv1"     :  80,
                           "force"   :  60,
                           "gongxian": 180,
                           "shen"    : -12000, ]));
                break;

        case "ǧɽ�º�Ӱ" :
                return MASTER_D->teach_pfm(me, this_object(),
                        ([ "perform" : "can_perform/guhong-zhang/qian",
                           "name"    : "ǧɽ�º�Ӱ",
                           "msg1"    : this_object()->name() + "��΢��"
                                       "�˵�ͷ��˵��������ɿ�����ˡ�"
                                       "��˵��˫�ƶ�Ȼ�����ĳ������д�"
                                       "�ᣬ˫�ƴ��磬�����������Ʒ�֮"
                                       "�У����������ȴҲ����������",
                           "sk1"     : "guhong-zhang",
                           "lv1"     : 80,
                           "force"   : 100,
                           "gongxian": 220,
                           "shen"    : -12000 ]));
                break;

        case "̩ɽѹ��" :
                return MASTER_D->teach_pfm(me, this_object(),
                        ([ "perform" : "can_perform/poshui-zhang/tai",
                           "name"    : "̩ɽѹ��",
                           "sk1"     : "poshui-zhang",
                           "lv1"     : 120,
                           "force"   : 160,
                           "gongxian": 300,
                           "shen"    : -18000, ]));
                break;

        default:
                return 0;
        }
}

void unconcious()
{
        die();
}
