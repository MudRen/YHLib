// LengQian.c
// by rcwiz 2003 for yhonline

#include <ansi.h>
#include "mingjiao.h"

inherit NPC;
inherit F_MASTER;
inherit F_GUARDER;
inherit F_COAGENT;

void create()
{
        set_name("��ǫ", ({ "leng qian", "leng", "qian", }));
	set("long",
        "����һλ��������ߣ���һ���ײ����ۡ�\n"
        "��˵����Ϊ��ݣ�����ɱ������ͷҲ���϶�˵���ϻ���\n"
	);

        set("title", HIR "����" NOR + WHT "��ɢ��" NOR);
        set("nickname", "��������");
	set("gender", "����");
	set("attitude", "friendly");
        set("class", "fighter");

        set("age", 54);
	set("shen_type", 1);
	set("str", 25);
	set("int", 25);
	set("con", 25);
	set("dex", 25);
	set("max_qi", 2200);
	set("qi", 2200);
	set("max_jing", 1200);
	set("neili", 3000);
	set("max_neili", 3000);
	set("jiali", 75);
	set("combat_exp", 600000);
	set("score", 5000);

	set_skill("force", 140);
	set_skill("shenghuo-xinfa", 140);
	set_skill("dodge", 120);
	set_skill("shenghuo-bu", 120);
	set_skill("cuff", 140);
	set_skill("pili-quan", 140);
	set_skill("parry", 140);
	set_skill("strike", 140);
	set_skill("sword", 140);
	set_skill("literate", 120);
        set_skill("martial-cognize", 100);

	map_skill("force", "shenghuo-xinfa");
	map_skill("dodge", "shenghuo-bu");
	map_skill("cuff", "pili-quan");
	map_skill("parry", "pili-quan");

	prepare_skill("cuff", "pili-quan");

        create_family("����", 37, "����");

        set_temp("apply/attack", 120);
        set_temp("apply/damage", 120);
        set_temp("apply/unarmed_damage", 120);
        set_temp("apply/armor", 120);

	set("coagents", ({
                ([ "startroom" : "/d/mingjiao/dadian",
                   "id"        : "zhang wuji" ]),
                ([ "startroom" : "/d/mingjiao/dadian",
                   "id"        : "fan yao" ]),
                ([ "startroom" : "/d/mingjiao/dadian",
                   "id"        : "yang xiao" ]),
        }));


	set("chat_chance_combat", 120);
	set("chat_msg_combat", ({
		(: command("perform cuff.jin") :),
	}) );

	setup();

        carry_object("/d/mingjiao/obj/baipao")->wear();
}


void attempt_apprentice(object ob)
{
        if (! permit_recruit(ob))
                return;

        if ((int)ob->query("shen") < 0)
        {
                command("say ������Ⱦа�������Ǽ����ͷ�úá�");
                return;
        }

        command("nod");
        command("say �ã��ã������Ҿ�����Ϊ���ӣ��Ӵ�����������̣��ŷ�����");
        command("recruit " + ob->query("id"));
}

int accept_ask(object me, string topic)
{
        switch (topic)
        {

        case "���׾�" :
                return MASTER_D->teach_pfm(me, this_object(),
                        ([ "perform" : "can_perform/pili-quan/jin",
                           "name"    : "���׾�",
                           "sk1"     : "pili-quan",
                           "lv1"     : 40,
                           "gongxian": 80,
                           "shen"    : 500, ]));
                break;

        default:
                return 0;
        }
}

void unconcious()
{
        die();
}


