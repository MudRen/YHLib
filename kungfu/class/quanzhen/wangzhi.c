inherit NPC;
inherit F_MASTER;

#include "quanzhen.h"

void create()
{
        set_name("��־̹", ({ "wang zhitan", "wang", "zhitan" }));
        set("gender", "����");
        set("class", "taoist");
        set("long", "����ȫ������������еĺ��֣��������ĵ��ӡ�\n");
        set("age", 24);
        set("attitude", "friendly");
        set("shen_type", 1);
        set("str", 28);
        set("int", 25);
        set("con", 25);
        set("dex", 25);

        set("max_qi", 2000);
        set("max_jing", 1400);
        set("neili", 2800);
        set("max_neili", 2800);
        set("jiali", 100);

        set("combat_exp", 220000);

        set_skill("force", 120);
        set_skill("quanzhen-xinfa", 120);
        set_skill("dodge", 100);
        set_skill("tianshan-feidu", 100);
        set_skill("parry", 120);
        set_skill("sword", 120);
        set_skill("qixing-jian", 120);
        set_skill("finger", 120);
        set_skill("zhongnan-zhi", 120);
        set_skill("literate", 80);
        set_skill("taoism", 80);
        set_skill("martial-cognize", 60);

        map_skill("force", "quanzhen-xinfa");
        map_skill("parry", "qixing-jian");
        map_skill("sword", "qixing-jian");
        map_skill("dodge", "tianshan-feidu");
        map_skill("finger", "zhongnan-zhi");

        prepare_skill("finger", "zhongnan-zhi");

        create_family("ȫ���", 3, "����");

        set("chat_chance_combat", 120);
        set("chat_msg_combat", ({
                (: exert_function, "recover" :),
                (: perform_action, "sword.xing" :),
                (: perform_action, "finger.zhi" :),
        }));

        setup();

        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/d/quanzhen/npc/obj/grayrobe")->wear();

}

void attempt_apprentice(object ob)
{
        if (! permit_recruit(ob))
                return;

        command("hmm");
        command("say ����͸����Ұɡ�");
        command("recruit " + ob->query("id"));
}
