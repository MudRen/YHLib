#include <ansi.h>
#include "lingxiao.h"

inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("�����", ({"wen wanfu", "wen", "wanfu"}));
        set("long", "�������������ѩɽ�����е��������ӣ��Ѿ���ѩ\n"
                    "ɽ�����Ǵ��˶��꣬���似����ƽƽ��\n");
        set("gender", "����");
        set("age", 34);
        set("attitude", "friendly");
        set("shen_type", 1);
        set("str", 30);
        set("int", 30);
        set("con", 30);
        set("dex", 30);
        set("max_qi", 1000);
        set("max_jing", 800);
        set("neili", 2000);
        set("max_neili", 2000);
        set("jiali", 50);
        set("combat_exp", 500000);

        set_skill("force", 100);
        set_skill("xueshan-neigong", 100);
        set_skill("dodge", 100);
        set_skill("taxue-wuhen", 100);
        set_skill("cuff", 100);
        set_skill("lingxiao-quan", 100);
        set_skill("strike", 100);
        set_skill("piaoxu-zhang", 100);
        set_skill("sword", 120);
        set_skill("yunhe-jian", 120);
        set_skill("parry", 100);
        set_skill("literate", 100);
        set_skill("martial-cognize", 80);

        map_skill("force", "xueshan-neigong");
        map_skill("dodge", "taxue-wuhen");
        map_skill("cuff", "lingxiao-quan");
        map_skill("strike", "piaoxu-zhang");
        map_skill("sword", "yunhe-jian");
        map_skill("parry", "yunhe-jian");

        prepare_skill("strike", "piaoxu-zhang");
        prepare_skill("cuff", "lingxiao-quan");

        create_family("������", 6, "����");

        set("chat_chance_combat", 120);
        set("chat_msg_combat", ({
                (: perform_action, "sword.chong" :),
                (: perform_action, "cuff.jue" :),
                (: perform_action, "strike.piao" :),
                (: exert_function, "recover" :),
                (: exert_function, "powerup" :),
        }));

        setup();
        
        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/clone/cloth/cloth")->wear();
}

void attempt_apprentice(object me)
{
        if (! permit_recruit(me))
                return;

        command("say ��Ȼ�������Ҿʹ�ʦ���������ˡ�");
        command("recruit " + me->query("id"));
}

void kill_ob (object ob)
{
        object me = this_object();
        object where = environment (me);
        object guard1 = present ("lingxiao dizi", where);
        object guard2 = present ("lingxiao dizi 2", where);
        object guard3 = present ("lingxiao dizi 3", where);

        set_temp("my_killer",ob);
        ::kill_ob(ob);

        if (guard1 && ! guard1->is_fighting())
        {
	        message_vision (HIW "\n������ŭ���ȵ�����Ȼ�۵���������"
                                "��ͷ�����ˣ���Ҳ������ϣ�\n\n" NOR,
                                guard1);
                guard1->kill_ob(ob);
	}

        if (guard2 && ! guard2->is_fighting())
                guard2->kill_ob(ob);

        if (guard3 && ! guard3->is_fighting())
                guard3->kill_ob(ob);
}
