#include <ansi.h>
#include "lingxiao.h"

inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("��������", ({"huyan wanshan", "huyan", "wanshan"}));
        set("long", "����������������ѩɽ�������������н�Ϊ��ɫ��\n"
                    "һλ��ƽʱ���ʦ����ϲ����ֻ��������Ӣ������\n"
                    "���ӣ�һ����֪�书������\n");
        set("gender", "����");
        set("age", 32);
        set("attitude", "friendly");
        set("shen_type", 1);
        set("str", 30);
        set("int", 30);
        set("con", 30);
        set("dex", 30);
        set("max_qi", 1500);
        set("max_jing", 1000);
        set("neili", 2200);
        set("max_neili", 2200);
        set("jiali", 80);
        set("combat_exp", 800000);

        set_skill("force", 120);
        set_skill("xueshan-neigong", 120);
        set_skill("dodge", 120);
        set_skill("taxue-wuhen", 120);
        set_skill("cuff", 120);
        set_skill("lingxiao-quan", 120);
        set_skill("strike", 120);
        set_skill("piaoxu-zhang", 120);
        set_skill("sword", 120);
        set_skill("yunhe-jian", 120);
        set_skill("parry", 120);
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

        command("say �ܺã����Ժ�͸����Ұɡ�");
        command("recruit " + me->query("id"));
}
