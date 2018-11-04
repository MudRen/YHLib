#include <ansi.h>
#include "xiaoyao.h"

inherit NPC;
inherit F_MASTER;
inherit F_COAGENT;

void create()
{
        set_name("ѦĽ��", ({ "xue muhua", "xue", "muhua" }));
        set("long", "�����Ǻų������е���ҽѦĽ������˵��\n"
                    "��ͨҽ����������������\n");
        set("gender", "����");
        set("title", "��ң�ɺ��Ȱ���");
        set("nickname", HIM "������" NOR);
        set("age", 50);
        set("class", "shaman");
        set("attitude", "peaceful");
        set("str", 25);
        set("int", 27);
        set("con", 25);
        set("dex", 25);

        set("inquiry", ([
                "����" : "�ơ���ʲô�ˣ�����ң��ҽ�����ѧ�����Լ����Լ��ơ�\n",
        ]));

	set("max_qi", 3000);
	set("max_jing", 3000);
	set("neili", 3500);
	set("max_neili", 3500);
	set("jiali", 100);
	set("combat_exp", 1000000);

        set_skill("force", 160);
        set_skill("xiaoyao-xinfa", 160);
        set_skill("dodge", 140);
        set_skill("feiyan-zoubi", 140);
        set_skill("strike", 160);
        set_skill("panyang-zhang", 160);
        set_skill("hand", 160);
        set_skill("qingyun-shou", 160);
        set_skill("parry", 160);
        set_skill("blade", 140);
        set_skill("ruyi-dao", 140);
        set_skill("xiaoyao-qixue", 220);
        set_skill("medical", 220);
        set_skill("literate", 120);
        set_skill("martial-cognize", 140);

	map_skill("force", "xiaoyao-xinfa");
	map_skill("dodge", "feiyan-zoubi");
	map_skill("hand", "qingyun-shou");
	map_skill("strike", "panyang-zhang");
	map_skill("parry", "panyang-zhang");
	map_skill("blade", "ruyi-dao");
        map_skill("medical", "xiaoyao-qixue");

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

        if (ob->query_int() < 26)
        {
                command("sigh");
                command("say ��Ȼ��˵���ܲ�׾�����ǡ����ҿ��㻹���߰ɡ�");
                return;
        }

        if (ob->query_skill("xiaoyao-xinfa", 1) < 30)
        {
                command("sigh");
                command("say �������ŵ������ķ���û��ѧ�ã�����������㣿");
                return;
        }

        command("say �ðɣ��Ҿ��������ˣ��Ժ�Ҫ��Ϊ��ң�ɳ�������");
        command("recruit " + ob->query("id"));
}
