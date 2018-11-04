#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("�Ʋ���", ({ "huang boliu", "huang", "boliu"}));
	set("title", "�ƺӰ����");
	set("nickname", HIW "������" NOR);
        set("long", @LONG
�����������̻ƺӰ�����Ʋ�����������ȥ
�Ѿ���Ϊ�����ˣ�����˫Ŀ�������䣬����Ʈ
Ʈ��ģ������֮����
LONG);
        set("gender", "����");
        set("class", "scholar");
        set("age", 81);
        set("attitude", "friendly");
        set("shen_type", -1);
        set("str", 36);
        set("int", 36);
        set("con", 36);
        set("dex", 36);
        
        set("max_qi", 4000);
        set("max_jing", 3000);
        set("neili", 5500);
        set("max_neili", 5500);
        set("jiali", 150);
        set("combat_exp", 2500000);
        set("score", 30000);

        set_skill("force", 180);
        set_skill("tianhuan-shenjue", 180);
        set_skill("riyue-xinfa", 180);
        set_skill("dodge", 180);
        set_skill("juechen-shenfa", 180);
        set_skill("cuff", 180);
        set_skill("zhenyu-quan", 180);
        set_skill("claw", 180);
        set_skill("poyue-zhao", 180);
        set_skill("parry", 180);
        set_skill("blade", 180);
        set_skill("danding-dao", 180);
        set_skill("strike", 180);
        set_skill("qingmang-zhang", 180);
        set_skill("martial-cognize", 180);
        set_skill("literate", 140);

        map_skill("dodge", "juechen-shenfa");
        map_skill("force", "tianhuan-shenjue");
        map_skill("blade", "danding-dao");
        map_skill("strike", "qingmang-zhang");
        map_skill("parry", "danding-dao");
        map_skill("cuff", "zhenyu-quan");
        map_skill("claw", "poyue-zhao");

        prepare_skill("claw", "poyue-zhao");
        prepare_skill("cuff", "zhenyu-quan");

        create_family("�ƺӰ�", 7, "����");

	set("chat_chance_combat", 120);
	set("chat_msg_combat", ({
		(: perform_action, "blade.kou" :),
                (: perform_action, "cuff.tong" :),
                (: perform_action, "claw.duan" :),
		(: exert_function, "recover" :),
		(: exert_function, "powerup" :),
	}) );

        setup();

        carry_object("/clone/weapon/gangdao")->wield();
        carry_object("/clone/cloth/cloth")->wear();
}

void attempt_apprentice(object ob)
{
     	command("say �Ҳ���ͽ��\n");
}

