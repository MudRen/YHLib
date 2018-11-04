inherit NPC;
inherit F_MASTER;

#include "quanzhen.h"

void create()
{
        set_name("��־��", ({ "qi zhicheng", "qi", "zhicheng" }));
        set("gender", "����");
        set("age", 24);
        set("class", "taoist");
        set("long", @LONG
������ȫ��̵����������еĺ��֣�̷���˵�
�������־�ϡ�����òӢ���������ܸɣ�����
���������Ρ�
LONG);
        set("attitude", "friendly");
        set("shen_type",1);
        set("str", 25);
        set("int", 25);
        set("con", 24);
        set("dex", 24);

        set("max_qi", 2000);
        set("max_jing", 1400);
        set("neili", 2600);
        set("max_neili", 2600);
        set("jiali", 80);

        set("combat_exp", 350000);

        set_skill("force", 120);
        set_skill("quanzhen-xinfa", 120);
        set_skill("dodge", 100);
        set_skill("tianshan-feidu", 100);
        set_skill("parry", 100);
        set_skill("sword", 120);
        set_skill("qixing-jian", 120);
        set_skill("finger", 100);
        set_skill("zhongnan-zhi", 100);
        set_skill("strike", 100);
        set_skill("chongyang-shenzhang", 100);
        set_skill("literate", 100);
        set_skill("taoism", 100);
        set_skill("martial-cognize", 60);

        map_skill("force", "quanzhen-xinfa");
        map_skill("parry", "qixing-jian");
        map_skill("sword", "qixing-jian");
        map_skill("dodge", "tianshan-feidu");
        map_skill("finger", "zhongnan-zhi");
        map_skill("strike", "chongyang-shenzhang");

        prepare_skill("finger", "zhongnan-zhi");
        prepare_skill("strike", "chongyang-shenzhang");

        create_family("ȫ���", 3, "����");

        set("chat_chance_combat", 120);
        set("chat_msg_combat", ({
                (: exert_function, "recover" :),
                (: perform_action, "sword.xing" :),
                (: perform_action, "finger.zhi" :),
                (: perform_action, "strike.lian" :),
        }));

        setup();

        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/d/quanzhen/npc/obj/grayrobe")->wear();

}

void attempt_apprentice(object ob)
{
        if (! permit_recruit(ob))
                return;

        if ((int)ob->query("shen") < 2000)
        {
                command("say ����������֮������̫�٣��Ҳ������㡣\n");
                return;
        }

        command("say �ðɣ�����͸����ң�û�°�æ�������Ҳ�á�");
        command("recruit " + ob->query("id"));
}
