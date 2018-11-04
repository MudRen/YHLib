#include <ansi.h>
#include "xiaoyao.h"

inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("ʯ��¶", ({ "shi qinglu", "shi", "qinglu" }));
        set("long", "�������Ǻ���С��ͽ�ܣ��ٸ���磬��ò������\n");
        set("gender", "Ů��");
        set("title", "��ң�ɺ��Ȱ���");
        set("nickname", MAG "ݪ���ٸ�" NOR);
        set("age", 33);
        set("class", "shaman");
        set("attitude", "peaceful");
        set("str", 25);
        set("int", 27);
        set("con", 25);
        set("dex", 25);

	set("max_qi", 1200);
	set("max_jing", 1000);
	set("neili", 2000);
	set("max_neili", 2000);
	set("jiali", 40);
	set("combat_exp", 800000);

        set_skill("force", 80);
        set_skill("xiaoyao-xinfa", 80);
        set_skill("dodge", 100);
        set_skill("feiyan-zoubi", 100);
        set_skill("strike", 80);
        set_skill("panyang-zhang", 80);
        set_skill("hand", 80);
        set_skill("qingyun-shou", 80);
        set_skill("parry", 80);
        set_skill("blade", 80);
        set_skill("ruyi-dao", 80);
        set_skill("literate", 120);
        set_skill("martial-cognize", 80);

	map_skill("force", "xiaoyao-xinfa");
	map_skill("dodge", "feiyan-zoubi");
	map_skill("hand", "qingyun-shou");
	map_skill("strike", "panyang-zhang");
	map_skill("parry", "panyang-zhang");
	map_skill("blade", "ruyi-dao");

        prepare_skill("hand", "qingyun-shou");
        prepare_skill("strike", "panyang-zhang");

        create_family("��ң��", 3, "����");

        set("chat_chance_combat", 120);
        set("chat_msg_combat", ({
                (: perform_action, "hand.zhuo" :),
                (: perform_action, "strike.pan" :),
                (: exert_function, "recover" :),
        }));

        setup();
        carry_object("/d/city/npc/cloth/color-dress")->wear();
}

void attempt_apprentice(object ob)
{
        if (! permit_recruit(ob))
                return;

        if (ob->query_int() < 25)
        {
                command("say ����������̫���ң���ǲ��������ġ�");
                return;
        }

        command("say ���š������Ժ�͸����Ұɡ�");
        command("recruit " + ob->query("id"));
}
