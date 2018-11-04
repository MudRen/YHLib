#include <ansi.h>
#include "duan.h"

inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("����ʯ", ({ "ba tianshi", "ba", "tianshi" }));
        set("title", "�������������" );
        set("nickname", HIW "˾��" NOR);
        set("long", @LONG
���Ǵ��������֮һ��һ�������ֺڵĺ��ӣ�����
���ó��Ṧ��
LONG);
        set("gender", "����");
        set("age", 46);
        set("class", "officer");
        set("attitude", "friendly");
        set("shen_type", 1);
        set("str", 30);
        set("int", 20);
        set("con", 25);
        set("dex", 25);

        set("max_qi", 3000);
        set("max_jing", 1800);
        set("neili", 3200);
        set("max_neili", 3200);
        set("jiali", 150);
        set("combat_exp", 1500000);
        set("score", 10000);

        set_skill("force", 180);
        set_skill("duanshi-xinfa", 180);
        set_skill("dodge", 220);
        set_skill("tiannan-bu", 220);
        set_skill("cuff", 160);
        set_skill("jinyu-quan", 160);
        set_skill("strike", 160);
        set_skill("wuluo-zhang", 160);
        set_skill("sword", 160);
        set_skill("duanjia-jian", 160);
        set_skill("parry", 160);
        set_skill("literate", 140);
        set_skill("martial-cognize", 160);

        map_skill("force", "duanshi-xinfa");
        map_skill("dodge", "tiannan-bu");
        map_skill("cuff", "jinyu-quan");
        map_skill("strike", "wuluo-zhang");
        map_skill("parry", "duanjia-jian");
        map_skill("sword", "duanjia-jian");

        prepare_skill("cuff", "jinyu-quan");
        prepare_skill("strike", "wuluo-zhang");

        create_family("���ϻ���", 15, "˾��");

        set("chat_chance_combat", 120);
        set("chat_msg_combat", ({
                (: perform_action, "cuff.man" :),
                (: perform_action, "strike.bian" :),
                (: perform_action, "sword.jing" :),
                (: perform_action, "sword.lian" :),
                (: exert_function, "recover" :),
                (: exert_function, "powerup" :),
        }));

        setup();
        carry_object("/d/dali/npc/obj/junfu")->wear();
        carry_object("/clone/weapon/changjian")->wield();
        add_money("silver", 10);
}

void attempt_apprentice(object ob)
{
        if (! permit_recruit(ob))
                return;

        command("smile");
        command("say ���ӵ��º�����ˣ�ֻҪ���·Ը�����һ�����ǡ�");
        return;
}