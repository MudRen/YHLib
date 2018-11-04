// FanYao.c
// creat by Rcwiz 2003

#include "ansi.h"

inherit NPC;
inherit F_COAGENT;
inherit F_GUARDER;

string ask_me();

void create()
{
	set_name("��ң", ({ "fan yao", "fan", "yao" }));
	set("long",
        	"����һλ�������е�ͷ�ӣ����ײ����ۡ�\n"
        	"�����������߰˰˵�ȫ���˰̣���ֱ������������Ŀ�ˡ�\n"
	);

	set("title",HIR "����" HIG "������ʹ" NOR);
	set("gender", "����");
	set("attitude", "peaceful");
	set("class", "bonze");

	set("age", 38);
	set("shen_type", 1);
	set("per", 12);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);

	set("max_qi", 6500);
	set("max_jing", 6500);
	set("neili", 8000);
	set("max_neili", 8000);
	set("jiali", 200);
	set("combat_exp", 3000000);
	set("score", 800000);

	set_skill("force", 340);
	set_skill("shenghuo-xinfa", 340);
        set_skill("shenghuo-shengong", 340);
	set_skill("dodge", 340);
	set_skill("lingxu-bu", 340);
	set_skill("finger", 340);
	set_skill("strike", 340);
	set_skill("hand", 340);
	set_skill("claw", 340);
	set_skill("parry", 340);
	set_skill("sword", 340);
	set_skill("xiaoyao-jian", 340);
	set_skill("nianhua-zhi", 340);
	set_skill("sanhua-zhang", 340);
	set_skill("fengyun-shou", 340);
	set_skill("longzhua-gong", 340);
	set_skill("buddhism", 340);
	set_skill("literate", 340);

	map_skill("force", "shenhuo-shengong");
	map_skill("dodge", "lingxu-bu");
	map_skill("finger", "nianhua-zhi");
	map_skill("strike", "sanhua-zhang");
	map_skill("hand", "fengyun-shou");
	map_skill("claw", "longzhua-gong");
	map_skill("parry", "nianhua-zhi");
        map_skill("sword", "xiaoyao-jian");

	set("chat_chance_combat", 120);
	set("chat_msg_combat", ({
		(: prepare_skill("finger", "nianhua-zhi") :),
		(: prepare_skill("strike", "sanhua-zhang") :),
	}) );

	create_family("����", 0, "������ʹ");

	set("coagents", ({
                ([ "startroom" : "/d/mingjiao/dadian",
                   "id"        : "zhang wuji" ]),
        }));

	setup();

        carry_object("/d/mingjiao/obj/baipao")->wear();
        carry_object("/clone/weapon/gangjian")->wield();
}

void unconcious()
{
        die();
}

