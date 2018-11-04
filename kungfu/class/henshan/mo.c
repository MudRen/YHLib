#include <ansi.h>
#include "henshan.h"

#define ZHENYUE "/clone/lonely/zhenyue"

inherit NPC;
inherit F_MASTER;
inherit F_QUESTER;
inherit F_COAGENT;

void create()
{
        object ob;
        set_name("Ī��", ({ "mo da", "mo", "da" }));
        set("nickname", HIW "����ҹ��" NOR);
	set("gender", "����");
        set("class", "swordman");
        set("attitude", "peaceful");
        set("shen_type", 1);

        set("age", 55);
        set("str", 28);
        set("con", 26);
        set("int", 28);
        set("dex", 28);
        set("max_qi", 5000);
        set("max_jing", 3000);
        set("neili", 5000);
        set("max_neili", 5000);
        set("jiali", 200);
        set("combat_exp", 3000000);

        set_skill("force", 240);
        set_skill("henshan-xinfa", 240);   
	set_skill("zhenyue-jue", 240);
        set_skill("dodge", 240);
        set_skill("henshan-shenfa", 240);
        set_skill("cuff", 240);
        set_skill("henshan-quan", 240);
        set_skill("sword", 260);
        set_skill("henshan-jian", 260); 
        set_skill("tianzhu-jian", 260);
        set_skill("zigai-jian", 260);
        set_skill("furong-jian", 260);
        set_skill("shilin-jian", 260);
        set_skill("strike", 240);
        set_skill("biluo-zhang", 240);
        set_skill("liuyun-zhang", 240); 
        set_skill("parry", 240);
        set_skill("literate", 240);
	set_skill("tanqin-jifa", 300);
        set_skill("xiaoxiang-yeyu", 300);
        set_skill("martial-cognize", 220);

        map_skill("strike", "liuyun-zhang");
        map_skill("cuff", "henshan-quan");
        map_skill("sword", "shilin-jian");
        map_skill("force", "zhenyue-jue");
        map_skill("dodge", "henshan-shenfa");
        map_skill("parry", "shilin-jian");
	map_skill("tanqin-jifa", "xiaoxiang-yeyu");

        prepare_skill("strike", "liuyun-zhang");
             
        create_family("��ɽ��", 13, "����");

        set("chat_chance_combat", 120);
        set("chat_msg_combat", ({
                (: perform_action, "sword.luo" :),
                (: perform_action, "strike.pai" :),
		(: perform_action, "strike.die" :),
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
                ob = find_object(ZHENYUE);
                if (! ob) ob = load_object(ZHENYUE);
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
        set_temp("handing", carry_object("/d/henshan/npc/obj/huqin"));
}

void attempt_apprentice(object ob)
{
        if (! permit_recruit(ob))
                return;

        if ((int)ob->query("shen") < 40000)
        {
                command("say �Һ�ɽ�������������������ɣ��Ե���Ҫ���ϸ�");
                command("say ��������������з����Ƿ����ò�����");
                return;
        }

        if ((int)ob->query("combat_exp") < 300000)
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
   
        if ((int)ob->query_skill("force") < 180)
        {
                command("say �Һ�ɽ���������ý������ڹ�ȴ������֮����");
                command("say ���Ƿ�Ӧ�����ڹ��ķ��϶��µ㹦��");
                return;
        } 

        command("nod");
        command("say ����ƽʱ�̿�Ŭ���������Ҿ�������ɡ�");
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

        case "�ϸǻ���" :
                return MASTER_D->teach_pfm(me, this_object(),
                        ([ "perform" : "can_perform/zigai-jian/hui",
                           "name"    : "�ϸǻ���",
                           "sk1"     : "zigai-jian",
                           "lv1"     : 120,
                           "force"   : 150,
                           "dodge"   : 120,
                           "gongxian": 200,
                           "shen"    : 15000, ]));
                break;

        case "��Ӣ�׷�" :
                return MASTER_D->teach_pfm(me, this_object(),
                        ([ "perform" : "can_perform/shilin-jian/luo",
                           "name"    : "��Ӣ�׷�",
                           "sk1"     : "shilin-jian",
                           "lv1"     : 120,
                           "force"   : 180,
                           "gongxian": 500,
                           "shen"    : 50000, ]));
                break;

        case "���Ƶ�Ӱ" :
                return MASTER_D->teach_pfm(me, this_object(),
                        ([ "perform" : "can_perform/liuyun-zhang/die",
                           "name"    : "���Ƶ�Ӱ",
                           "msg1"    : "$N��΢���ͷ���Ʒ���Ȼ��죬"
                                       "˫�Ʋ����ĳ���������Ӱ��ã�"
                                       "������ͷ���ۣ�ֱ���㿴���ۻ�"
                                       "���ҡ�",
                           "sk1"     : "liuyun-zhang",
                           "lv1"     : 100,
                           "dodge"   : 150,
                           "gongxian": 300,
                           "shen"    : 50000, ]));
                break;

        case "��ɽ����" :
                return MASTER_D->teach_pfm(me, this_object(),
                        ([ "perform" : "can_perform/liuyun-zhang/pai",
                           "name"    : "��ɽ����",
                           "msg1"    : "$N���˵�ͷ��˵�������Ҹ�����"
                                       "ʾһ�飬�ɿ����ˡ���˵��$N��"
                                       "�����������Ʒ�֮�У�˫����Ȼ"
                                       "�ĳ����ۻ����������ư��磬��"
                                       "���ʹ������Ǻ�ɽ�ɾ�ѧ����ɽ"
                                       "��������",
                           "sk1"     : "liuyun-zhang",
                           "lv1"     : 140,
                           "force"   : 180,
                           "gongxian": 600,
                           "shen"    : 50000, ]));
                break;

        case "�����з�" :
                return MASTER_D->give_item(me, this_object(),
                        ([ "item"    : ZHENYUE,
                           "master"  : 1,
                           "sk1"     : "henshan-jian",
                           "lv1"     : 120,
                           "shen"    : 50000, ]));
                break;
        default:
                return 0;
        }
}

void unconcious()
{
        die();
}
