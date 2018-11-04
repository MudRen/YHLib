#include <ansi.h>

inherit NPC;

void create()
{
        set_name("����", ({"zhu wanchun", "zhu", "wanchun"}));
        set("gender", "����");
        set("long", "���������ǵ������������򴺣���������һ������ü���ۡ�\n"
                    "Ҳ��Ϊ��ֹ���ˣ����������\n");
        set("age", 24);
        set("attitude", "peaceful");

        set("str", 25);
        set("con", 30);
        set("int", 24);
        set("dex", 30);

        set("max_qi", 1200);
        set("max_jing", 1000);
        set("neili", 1500);
        set("max_neili", 1500);
        set("jiali", 80);
        set("combat_exp", 500000);

        set_skill("force", 140);
        set_skill("xueshan-neigong", 140);
        set_skill("dodge", 120);
        set_skill("taxue-wuhen", 120);
        set_skill("cuff", 120);
        set_skill("lingxiao-quan", 120);
        set_skill("strike", 120);
        set_skill("piaoxu-zhang", 120);
        set_skill("sword", 140);
        set_skill("hanmei-jian", 140);
        set_skill("yunhe-jian", 140);
        set_skill("parry", 120);
        set_skill("literate", 100);
        set_skill("martial-cognize", 40);

        map_skill("force", "xueshan-neigong");
        map_skill("dodge", "taxue-wuhen");
        map_skill("cuff", "lingxiao-quan");
        map_skill("strike", "piaoxu-zhang");
        map_skill("sword", "yunhe-jian");
        map_skill("parry", "hanmei-jian");

        prepare_skill("strike", "piaoxu-zhang");
        prepare_skill("cuff", "lingxiao-quan");

        create_family("������", 6, "����");

        set("chat_chance_combat", 120);
        set("chat_msg_combat", ({
                (: perform_action, "sword.chong" :),
                (: perform_action, "cuff.jue" :),
                (: perform_action, "strike.piao" :),
                (: exert_function, "recover" :),
        }));

        setup();
        carry_object("/clone/cloth/cloth")->wear();
}

void attempt_apprentice(object ob)
{
        command("say ����������û������үү������������");
}