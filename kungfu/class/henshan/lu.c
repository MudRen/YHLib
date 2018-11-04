#include <ansi.h>
#include "henshan.h"

inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("³����", ({ "lu lianrong", "lu", "lianrong" }));
        set("gender", "����" );
        set("nickname", HIY "���۵�" NOR);
        set("class", "swordman");
        set("attitude", "peaceful");

        set("age", 45);
        set("str", 28);
        set("con", 26);
        set("int", 29);
        set("dex", 28);
        set("max_qi", 2800);
        set("max_jing", 1800);
        set("neili", 3000);
        set("max_neili", 3000);
        set("jiali", 150);
        set("combat_exp", 800000);

        set_skill("force", 140);
        set_skill("henshan-xinfa", 140);
        set_skill("zhenyue-jue", 100);
        set_skill("dodge", 140);
        set_skill("henshan-shenfa", 140);
        set_skill("cuff", 140);
        set_skill("henshan-quan", 140);
        set_skill("sword", 160);
        set_skill("henshan-jian", 160);
        set_skill("tianzhu-jian", 160);
        set_skill("zigai-jian", 140);
        set_skill("strike", 140);
        set_skill("biluo-zhang", 140); 
        set_skill("parry", 140);
        set_skill("literate", 140);
        set_skill("martial-cognize", 120);

        map_skill("strike", "biluo-zhang");
        map_skill("cuff", "henshan-quan");
        map_skill("sword", "tianzhu-jian");
        map_skill("force", "henshan-xinfa");
        map_skill("dodge", "henshan-shenfa");
        map_skill("parry", "henshan-jian");

        prepare_skill("cuff", "henshan-quan");
        prepare_skill("strike", "biluo-zhang");

        set("no_teach/zhenyue-jue", "�����ڹ���Ҳ�Ǹ������ã�����ý���");

        create_family("��ɽ��", 14, "����");

        set("chat_chance_combat", 120);
        set("chat_msg_combat", ({
                (: perform_action, "sword.huan" :),
                (: perform_action, "cuff.riyue" :),
                (: perform_action, "strike.lian" :),
                (: exert_function, "recover" :),
        }));

        setup();
        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/clone/cloth/cloth")->wear();
}

void attempt_apprentice(object ob)
{
        if (! permit_recruit(ob))
                return;

        if ((int)ob->query("shen") < 5000)
        {
                command("say �Һ�ɽ�������������������ɣ��Ե���Ҫ���ϸ�");
                command("say ��������������з����Ƿ����ò�����");
                return;
        }

        if ((int)ob->query("combat_exp") < 50000)
        {
                command("say �����ھ�����ǳ�����Ƕ��ڽ��������߰ɡ�");
                return;
        }

        if ((int)ob->query_skill("henshan-jian", 1) < 50)
        {       
                command("say �Һ�ɽ����������֮һ����Ϊ���ӽ�����");
                command("say ��ĺ�ɽ������������������ȥ���������ɡ�");
                return;
        }
   
        if ((int)ob->query_skill("force") < 100)
        {
                command("say �Һ�ɽ���������ý������ڹ�ȴ������֮����");
                command("say ���Ƿ�Ӧ�����ڹ��ķ��϶��µ㹦��");
                return;
        } 

        command("say �ðɣ��Ҿ������㡣�Ժ�һ��Ҫ����Ŭ����");
        command("recruit " + ob->query("id"));
}

int accept_ask(object me, string topic)
{
        switch (topic)
        {
        case "�ý�ʽ" :
                return MASTER_D->teach_pfm(me, this_object(),
                        ([ "perform" : "can_perform/henshan-jian/huan",
                           "name"    : "�ý�ʽ",
                           "sk1"     : "henshan-jian",
                           "msg1"    : "$N���˵�ͷ���ȵ������������"
                                       "�����������䣬���$Nͻ������"
                                       "�������ڽ�������Ȼ�ӿ죬"
                                       "���г��������˶�������ã���"
                                       "����������һ��Ϯ��һ�㣬��ʽ"
                                       "��Ϊ���",
                           "lv1"     : 60,
                           "force"   : 80,
                           "gongxian": 50,
                           "shen"    : 2000, ]));
                break;

        case "��������" :
                return MASTER_D->teach_pfm(me, this_object(),
                        ([ "perform" : "can_perform/tianzhu-jian/suo",
                           "name"    : "��������",
                           "sk1"     : "tianzhu-jian",
                           "lv1"     : 120,
                           "force"   : 150,
                           "dodge"   : 150,
                           "gongxian": 300,
                           "shen"    : 20000, ]));
                break;
        default:
                return 0;
        }
}
