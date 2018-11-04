// ����Ⱥ
// modify by rcwiz 2003

inherit NPC;
inherit F_MASTER;
inherit F_COAGENT;
inherit F_QUESTER;

#define ZIXIA "/clone/book/zixia_book"

#include <ansi.h>
#include "qizong.h"

int  do_xunshan();
void check_weapon();
void unwield_weapon();

// ���ظ��˼�����������֤��quest��ʱ���������quest
int is_bad() { return 0; }
int is_good() { return 1; }

void create()
{
        set_name("����Ⱥ", ({ "yue buqun", "yue" }) );
        set("title", "��ɽ������");
        set("nickname", HIC "���ӽ�" NOR);
        set("gender", "����");
        set("class", "swordsman");
        set("shen_type", 1);
        set("age", 55);
        set("long", "����Ⱥ����ִ�ƻ�ɽ�ɣ��˵���������һ��һ�ĸ��֡�\n");
        set("attitude", "peaceful");
        set("str", 26);
        set("con", 30);
        set("dex", 30);
        set("int", 28);

        set("max_qi", 5200);
        set("max_jing", 2600);
        set("neili", 6000);
        set("max_neili", 6000);
        set("jiali", 80);

        set("combat_exp", 2400000);
        set("xunshan", 1);
        set("apprentice_available", 3);

        set("inquiry", ([
                "Ѳɽ"           : (: do_xunshan :),
                "�����������ɽ�" : "�������ڵĽ�������������ʲô��\n",
                "����"           : "���꽣��֮������ɽ�������������������²���Ҳ�գ�\n",
        ]));

        set_skill("unarmed", 240);
        set_skill("cuff", 240);
        set_skill("strike", 240);
        set_skill("sword", 260);
        set_skill("blade", 260);
        set_skill("force", 260);
        set_skill("parry", 240);
        set_skill("dodge", 240);
        set_skill("literate", 220);
        set_skill("huashan-jian", 260);
        set_skill("fanliangyi-dao", 260);
        set_skill("huashan-xinfa", 260);
        set_skill("zixia-shengong", 260);
        set_skill("huashan-quan", 240);
        set_skill("poyu-quan", 240);
        set_skill("huashan-zhang", 240);
        set_skill("hunyuan-zhang", 240);
        set_skill("huashan-shenfa", 240);
        set_skill("pixie-jian", 240); 
        set_skill("martial-cognize", 200);

        map_skill("sword", "pixie-jian");
        map_skill("parry", "pixie-jian");
        map_skill("blade", "fanliangyi-dao");
        map_skill("force", "zixia-shengong");
        map_skill("cuff", "poyu-quan");
        map_skill("strike", "hunyuan-zhang");
        map_skill("dodge", "pixie-jian");

        prepare_skill("strike", "hunyuan-zhang");
        prepare_skill("cuff", "poyu-quan");

        set("no_teach", ([
                "pixie-jian"     : "�����������ּҵļҴ��书��"
                                   "����ô���ܻ��أ�",
        ]));

        set_temp("apply/attack", 220);
        set_temp("apply/dodge", 220);
        set_temp("apply/parry", 200);
        set_temp("apply/damage", 150);
        set_temp("apply/unarmed_damage", 150);
        set_temp("apply/armor", 200);

        create_family("��ɽ��", 13, "����");

	set("chat_chance_combat", 120);
	set("chat_msg_combat", ({
		(: perform_action, "sword.duo" :),
		(: perform_action, "sword.pi" :),
		(: perform_action, "sword.gui" :),
		(: perform_action, "strike.wuji" :),
		(: perform_action, "cuff.lei" :),
		(: perform_action, "cuff.po" :),
		(: exert_function, "recover" :),
		(: exert_function, "powerup" :),
                (: check_weapon :),
	}));             

        setup();

	set("book_count", 1);
        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/clone/cloth/cloth")->wear();
        carry_object("/clone/misc/pin");
}

void check_weapon()
{
        if (objectp(query_temp("weapon")))
                return;

        command("wield pin");
        set("chat_msg_combat", ({
                (: exert_function, "recover" :),
                (: exert_function, "powerup" :),
		(: perform_action, "sword.duo" :),
		(: perform_action, "sword.pi" :),
		(: perform_action, "sword.gui" :),
        }));
        set("chat_chance", 120);
        set("chat_msg", ({
                (: unwield_weapon :),
        }));
}

void unwield_weapon()
{
        command("unwield pin");
        delete("chat_chance");
        delete("chat_msg");
        set("chat_msg_combat", ({
                (: exert_function, "powerup" :),
                (: exert_function, "recover" :),
		(: perform_action, "sword.cimu" :),
		(: perform_action, "sword.pi" :),
		(: perform_action, "sword.gui" :),
                (: check_weapon :),
        }));
}

void attempt_apprentice(object ob)
{
        if( query("apprentice_available") ) {
                if( find_call_out("do_recruit") != -1 )
                        command("say ������һ��һ������");
                else
                        call_out("do_recruit", 2, ob);
        } else {
                command("say �Ϸ�����Ѿ������������ӣ���������ͽ�ˡ�");
        }
}

void do_recruit(object ob)
{
        if( !permit_recruit(ob) )
                return;
        
        if (ob->query("gender") == "Ů��")
        {
                command("say �Ҳ���Ůͽ�ܣ��㻹��ȥ����ʦ�ðɣ�");
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
        
        command("say �ã��ã��ã��ܺá�");
        command("say �����ұ��������ˣ��Ժ�Ҫ���������壬����һ�ɽ�ɣ�");
        command("recruit " + ob->query("id") );        
        
}

int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
        add("apprentice_availavble", -1);
}

void reset()
{
	set("book_count", 1);
        set("apprentice_available", 3);
}

int do_xunshan()
{
        object me = this_player();
      	string date;

    	date = NATURE_D->game_time();
	sscanf(date, "%s��%*s��", date);

        if (me->query_temp("xunshan"))
        {
               if (!me->query_temp("xunshan/chaoyang"))
               {
                      	message_vision("$N����$n˵���㳯����ûȥ������"
                                       "����Ѳ��ʲôɽ��\n", this_object(), me);
                        return 1;
               }
               if (!me->query_temp("xunshan/lianhua"))
               {
                      	message_vision("$N����$n˵����������ûȥ������"
                                       "����Ѳ��ʲôɽ��\n", this_object(), me);
                      	return 1;
               }
               if (!me->query_temp("xunshan/yuntai"))
               {
                      	message_vision("$N����$n˵������̨��ûȥ����������"
                                       "Ѳ��ʲôɽ��\n", this_object(), me);
                      	return 1;
               }
               if (!me->query_temp("xunshan/sheshen"))
               {
                      	message_vision("$N����$n˵������ôûȥ�����£�����"
                                       "Ѳ��ʲôɽ��\n", this_object(), me);
                      	return 1;
               }
               if (!me->query_temp("xunshan/siguo"))
               {
                      	message_vision("$N����$n˵���㵽��˼����ȥ�ˣ�����"
                                       "Ѳ��ʲôɽ��\n", this_object(), me);
                      	return 1;
               }
               if (!me->query_temp("xunshan/yunu"))
               {
                      	message_vision("$N����$n˵���㵽��Ů����滪ɽС��"
                                       "ȥ�����ˣ�����Ѳ��ʲôɽ��\n",
                                       this_object(), me);
                      	return 1;
               	}
               	message_vision("$N����$n˵�����������ˡ������ȥ"
                               "��Ϣȥ�ɡ�\n", this_object(), me);
               	me->delete_temp("xunshan");                      
               	me->add("combat_exp", 100 + random(100));
               	return 1;
        }
        else
        {
               if (query("xunshan") == date)
               {
                      	message_vision("$N����$n˵�������Ѿ�����Ѳɽ"
                                     "ȥ�ˡ������������ɡ�\n", this_object(), me);
                      	return 1;
               }
               if( me->query("family/family_name") != "��ɽ��")
               {
                      	message_vision("$N����$n���һ�������ɵ��Ӳ���"
                                     "Ѳɽ�����������ļ�ϸ��\n", this_object(), me);
                      	return 1;
               }
               else
               {
                      	set("xunshan", date);
                      	message_vision("$N����$n˵�����ɵ�������Ѳɽ���㣬�ܺã���"
                                       "�ã������ȥѲɽ�ɡ�\n",
				       this_object(), me);
                      	me->set_temp("xunshan/start", 1);
                      	me->set_temp("xunshan/time", time());
                      	return 1;
               }
        }
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

        case "���������" :
                return MASTER_D->teach_pfm(me, this_object(),
                        ([ "perform" : "can_perform/fanliangyi-dao/san",
                           "name"    : "���������",
                           "sk1"     : "fanliangyi-dao",
                           "lv1"     : 100,
                           "sk2"     : "force",
                           "lv2"     : 140,
                           "neili"   : 2000,
                           "gongxian": 300,
                           "shen"    : 24000, ]));
                break;

        case "��Ԫ�޼�" :
                return MASTER_D->teach_pfm(me, this_object(),
                        ([ "perform" : "can_perform/hunyuan-zhang/wuji",
                           "name"    : "��Ԫ�޼�",
                           "sk1"     : "hunyuan-zhang",
                           "lv1"     : 120,
                           "sk2"     : "force",
                           "lv2"     : 120,
                           "gongxian": 400,
                           "neili"   : 1400,
                           "shen"    : 28000, ]));
                break;

        case "�����" :
                return MASTER_D->teach_pfm(me, this_object(),
                        ([ "perform" : "can_perform/poyu-quan/feng",
                           "name"    : "�����",
                           "sk1"     : "poyu-quan",
                           "lv1"     : 60,
                           "force"   : 150,
                           "gongxian": 200,
                           "shen"    : 30000, ]));
                break;

        case "�׶�����" :
                return MASTER_D->teach_pfm(me, this_object(),
                        ([ "perform" : "can_perform/poyu-quan/lei",
                           "name"    : "�׶�����",
                           "sk1"     : "poyu-quan",
                           "lv1"     : 120,
                           "gongxian": 400,
                           "shen"    : 40000, ]));
                break;

        case "��ʯһ��" :
                return MASTER_D->teach_pfm(me, this_object(),
                        ([ "perform" : "can_perform/poyu-quan/po",
                           "name"    : "��ʯһ��",
                           "sk1"     : "poyu-quan",
                           "lv1"     : 140,
                           "sk2"     : "force",
                           "lv2"     : 120,
                           "gongxian": 600,
                           "shen"    : 60000, ]));
                break;

        case "��ϼ�ؼ�" :
                return MASTER_D->give_item(me, this_object(),
                        ([ "item"    : ZIXIA,
                           "sk1"     : "huashan-xinfa",
                           "lv1"     : 160,
                           "neili"   : 1200,
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
