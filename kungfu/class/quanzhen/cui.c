inherit NPC;
inherit F_MASTER;

#include "quanzhen.h"

void create()
{
        set_name("��־��", ({ "cui zhifang", "cui", "zhifang"}));
        set("gender", "����");
        set("age", 24);
        set("class", "taoist");
        set("long", "������ȫ��̵����������еĺ��֣�����һ�Ķ����ӡ�\n");
        set("attitude", "friendly");
        set("shen_type", 1);
        set("str", 26);
        set("int", 25);
        set("con", 25);
        set("dex", 26);

        set("max_qi", 2200);
        set("max_jing", 1500);
        set("neili", 3000);
        set("max_neili", 3000);
        set("jiali", 100);

        set("combat_exp", 300000);

        set_skill("force", 140);
        set_skill("quanzhen-xinfa", 140);
        set_skill("dodge", 120);
        set_skill("tianshan-feidu", 120);
        set_skill("parry", 120);
        set_skill("sword", 120);
        set_skill("qixing-jian", 120);
        set_skill("strike", 120);
        set_skill("chongyang-shenzhang", 120);
        set_skill("literate", 100);
        set_skill("taoism", 100);
        set_skill("martial-cognize", 60);

        map_skill("force", "quanzhen-xinfa");
        map_skill("parry", "chongyang-shenzhang");
        map_skill("sword", "qixing-jian");
        map_skill("dodge", "tianshan-feidu");
        map_skill("strike", "chongyang-shenzhang");

        prepare_skill("strike", "chongyang-shenzhang");

        create_family("ȫ���", 3, "����");

        set("chat_chance_combat", 120);
        set("chat_msg_combat", ({
                (: exert_function, "recover" :),
                (: perform_action, "sword.xing" :),
                (: perform_action, "strike.lian" :),
        }));

        setup();
        carry_object("/d/quanzhen/npc/obj/grayrobe")->wear();

}

void attempt_apprentice(object ob)
{
        if (! permit_recruit(ob))
                return;

        command("say �ðɣ��Ҿ����������ͽ�ܡ�");
        command("recruit " + ob->query("id"));
}
