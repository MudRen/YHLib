#include <ansi.h>
#include "jueqing.h"

#define HEIJIAN "/clone/lonely/heijian"
#define JUCHI   "/clone/lonely/juchidao"

inherit NPC;
inherit F_MASTER;
inherit F_QUESTER;
inherit F_COAGENT;

void create()
{
        object ob1,ob2;
        set_name("����ֹ", ({ "gongsun zhi", "gongsun", "zhi" }));
        set("nickname", HIR "������" NOR);
	set("gender", "����");
        set("attitude", "peaceful");
        set("shen_type", 0);
        set("age", 40);
        set("str", 35);
        set("con", 35);
        set("int", 25);
        set("dex", 35);
        set("max_qi", 6000);
        set("max_jing", 4000);
        set("neili", 6000);
        set("max_neili", 6000);
        set("jiali", 200);
        set("combat_exp", 3000000);

        set_skill("force", 240);
        set_skill("jueqing-xinfa", 240);   
	set_skill("fenxin-jue", 240);
        set_skill("dodge", 240);
        set_skill("jueqing-shenfa", 240);
        set_skill("strike", 240);
        set_skill("jueqing-zhang", 240);
        set_skill("guhong-zhang", 240);
        set_skill("cuff", 240);   
        set_skill("pokong-quan", 240);
        set_skill("medical", 240);
        set_skill("jueqing-yaoli", 240);
        set_skill("sword", 260);
        set_skill("yinyang-ren", 260); 
        set_skill("zilei-jian", 260);
        set_skill("guxing-jian", 260);
        set_skill("blade", 260);
        set_skill("tianjue-dao", 260);
        set_skill("luoyun-dao", 260);
        set_skill("poguang-dao", 260);
        set_skill("parry", 240);
        set_skill("literate", 240);
        set_skill("medical", 240);
        set_skill("jueqing-yaoli", 240);
        set_skill("martial-cognize", 220);

        map_skill("strike", "jueqing-zhang");
        map_skill("sword", "yinyang-ren");
        map_skill("blade", "yinyang-ren");
        map_skill("force", "fenxin-jue");
        map_skill("dodge", "jueqing-shenfa");
        map_skill("parry", "yinyang-ren");
        map_skill("parry", "jueqing-yaoli");

        prepare_skill("strike", "jueqing-zhang");
             
        create_family("�����", 4, "����");

        set("chat_chance_combat", 120);
        set("chat_msg_combat", ({
                (: perform_action, "sword.huan" :),
                (: perform_action, "sword.heng" :),
                (: perform_action, "strike.hun" :),
		(: perform_action, "strike.wan" :),
                (: exert_function, "recover" :),
                (: exert_function, "powerup" :),
        }));

        set_temp("apply/attack", 100);
        set_temp("apply/damage", 100);
        set_temp("apply/unarmed_damage", 100);
        set_temp("apply/armor", 200);

        setup();

        if (clonep())
        {
                ob1 = find_object(HEIJIAN);
                if (! ob1) ob1 = load_object(HEIJIAN);
                if (! environment(ob1))
                {
                        ob1->move(this_object());
                        set_temp("handing", ob1);
                } else
                {
                        ob1 = new("/clone/weapon/changjian");
                        ob1->move(this_object());
                        set_temp("handing", ob1);
                }

                ob2 = find_object(JUCHI);
                if (! ob2) ob2 = load_object(JUCHI);
                if (! environment(ob2))
                {
                        ob2->move(this_object());
                        ob2->wield();
                }else
                {
                        ob2 = new("/clone/weapon/gangdao");
                        ob2->move(this_object());
                        ob2->wield();
                }
	}
        carry_object("/clone/cloth/cloth")->wear();
}

void attempt_apprentice(object ob)
{
        if (! permit_recruit(ob))
                return;

        if (ob->query("family/master_name") == "��ǧ��")
        {
                command("sneer");
                command("say �ҹ���ֹ�ɲ�����ǧ���Ƕ񸾵�ͽ�ܡ�");
                return;
        }

        if ((int)ob->query("shen") > -30000)
        {
                command("say �ҹ���ֹ�����������Щ������ʿ��");
                command("say �㻹����ذɣ�");
                return;
        }

        if ((int)ob->query("combat_exp") < 300000)
        {
                command("say �����ھ�����ǳ�����Ƕ��ڽ��������߰ɡ�");
                return;
        }

        if ((int)ob->query_skill("jueqing-xinfa", 1) < 120)
        {       
                command("say �Ҿ�����书���������һ�������ӻ����ķ���");
                command("say ��ľ����ķ���������������ȥ���������ɡ�");
                return;
        }
   
        if ((int)ob->query_skill("dodge") < 180)
        {
                command("say �Ҿ�����书������鶯������");
                command("say ���Ƿ�Ӧ�����Ṧ��Ϊ�϶��µ㹦��");
                return;
        } 

        command("nod");
        command("say ���㻹�Ǹ�����֮�ţ������Ҿ�������ɡ�");
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

        case "����ʽ" :
                return MASTER_D->teach_pfm(me, this_object(),
                        ([ "perform" : "can_perform/zilei-jian/luo",
                           "name"    : "����ʽ",
                           "sk1"     : "zilei-jian",
                           "lv1"     : 100,
                           "force"   : 120,
                           "gongxian": 400,
                           "shen"    : -60000, ]));
                break;

        case "���ʽ" :
                return MASTER_D->teach_pfm(me, this_object(),
                        ([ "perform" : "can_perform/zilei-jian/feng",
                           "name"    : "���ʽ",
                           "sk1"     : "zilei-jian",
                           "lv1"     : 100,
                           "dodge"   : 140,
                           "gongxian": 400,
                           "shen"    : -45000, ]));
                break;

        case "������" :
                return MASTER_D->teach_pfm(me, this_object(),
                        ([ "perform" : "can_perform/poguang-dao/yang",
                           "name"    : "������",
                           "sk1"     : "poguang-dao",
                           "lv1"     : 100,
                           "force"   : 120,
                           "gongxian": 400,
                           "shen"    : -60000, ]));
                break;

        case "������" :
                return MASTER_D->teach_pfm(me, this_object(),
                        ([ "perform" : "can_perform/poguang-dao/bing",
                           "name"    : "������",
                           "sk1"     : "poguang-dao",
                           "lv1"     : 100,
                           "force"   : 140,
                           "gongxian": 400,
                           "shen"    : -45000, ]));
                break;

        case "�����ɢ" :
                return MASTER_D->teach_pfm(me, this_object(),
                        ([ "perform" : "can_perform/jueqing-zhang/hun",
                           "name"    : "�����ɢ",
                           "sk1"     : "jueqing-zhang",
                           "msg1"    : this_object()->name() + "����"
                                       "��ͷ��˵�������ã��Ҹ�����ʾ"
                                        "һ�飬�㿴����ˡ���˵��" +
                                       this_object()->name() + "��ת"
                                       "������������ע���Ʒ�֮�У�˫"
                                       "����Ȼ������գ��Ʒ������ޱ�"
                                       "���������ˣ�ֱ�ɾ���أ�����"
                                       "��",
                           "lv1"     : 120,
                           "force"   : 160,
                           "gongxian": 500,
                           "shen"    : -92000, ]));
                break;

        case "�����޻�" :
                return MASTER_D->teach_pfm(me, this_object(),
                        ([ "perform" : "can_perform/yinyang-ren/hua",
                           "name"    : "�����޻�",
                           "sk1"     : "yinyang-ren",
                           "lv1"     : 160,
                           "gongxian": 600,
                           "shen"    : -35000, ]));
                break;

        case "��ճ���" :
                return MASTER_D->teach_pfm(me, this_object(),
                        ([ "perform" : "can_perform/yinyang-ren/heng",
                           "name"    : "��ճ���",
                           "sk1"     : "yinyang-ren",
                           "lv1"     : 180,
                           "dodge"   : 180,
                           "force"   : 180,
                           "gongxian": 700,
                           "shen"    : -100000 ]));
                break;

        case "������" :
                return MASTER_D->teach_pfm(me, this_object(),
                        ([ "perform" : "can_perform/yinyang-ren/huan",
                           "name"    : "������",
                           "sk1"     : "yinyang-ren",
                           "lv1"     : 180,
                           "dodge"   : 200,
                           "gongxian": 600,
                           "shen"    : -120000, ]));
                break;

        case "�ڽ�" :
                return MASTER_D->give_item(me, this_object(),
                        ([ "item"    : HEIJIAN,
                           "master"  : 1,
                           "sk1"     : "yinyang-ren",
                           "lv1"     : 150,
                           "shen"    : -46000, ]));
                break;

        case "�ƽ��ݵ�" :
                return MASTER_D->give_item(me, this_object(),
                        ([ "item"    : JUCHI,
                           "master"  : 1,
                           "sk1"     : "yinyang-ren",
                           "lv1"     : 180,
                           "shen"    : -50000, ]));
                break;
        default:
                return 0;
        }
}

void unconcious()
{
        die();
}
