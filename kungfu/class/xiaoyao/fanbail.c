#include <ansi.h>
#include "xiaoyao.h"

inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("������", ({ "fan bailing", "fan", "bailing" }));
        set("long", "�������ǺӵĶ����ӣ�ͨ���弼��\n");
        set("gender", "����");
        set("title", "��ң�ɺ��Ȱ���");
        set("nickname", HIR "����" NOR);
        set("age", 53);
        set("class", "shaman");
        set("attitude", "peaceful");
        set("str", 25);
        set("int", 27);
        set("con", 25);
        set("dex", 25);

	set("max_qi", 2800);
	set("max_jing", 2800);
	set("neili", 3600);
	set("max_neili", 3600);
	set("jiali", 100);
	set("combat_exp", 1200000);

        set_skill("force", 180);
        set_skill("xiaoyao-xinfa", 180);
        set_skill("dodge", 160);
        set_skill("feiyan-zoubi", 160);
        set_skill("strike", 160);
        set_skill("panyang-zhang", 160);
        set_skill("hand", 160);
        set_skill("qingyun-shou", 160);
        set_skill("parry", 160);
        set_skill("blade", 160);
        set_skill("ruyi-dao", 160);
        set_skill("chess", 240);
        set_skill("literate", 160);
        set_skill("martial-cognize", 160);

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
        carry_object("/clone/cloth/cloth")->wear();
}

void attempt_apprentice(object ob)
{
        if (! permit_recruit(ob))
                return;

        if (ob->query_int() < 27)
        {
                command("sigh");
                command("say ѧϰ���Ҫ�����Լ���֮�ˣ��ҿ��㲢���ʺϡ�");
                return;
        }

        if (ob->query_skill("xiaoyao-xinfa", 1) < 30)
        {
                command("sigh");
                command("say �������ŵ������ķ���û��ѧ�ã�����������㣿");
                return;
        }

        command("say �ðɣ���Ȼ��ˣ��Ҿ��������ˡ�");
        command("recruit " + ob->query("id"));
}
