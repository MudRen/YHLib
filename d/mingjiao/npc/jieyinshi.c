// JieYinShi
// pal 1997.05.11

#include "ansi.h"

inherit NPC;
inherit F_GUARDER;

void create()
{
	set_name("����ʹ", ({"jieyin shi","jieyin","shi",}));
	set("long",
		"����һλ�����������ˣ���һ���ײ����ۡ�\n"
		"���������´������㡣\n"
		);

	set("title", HIR "����" NOR);

	set("gender", "����");
	set("attitude", "friendly");

	set("age", 30);
	set("shen_type", 1);
	set("str", 25);
	set("int", 17);
	set("con", 50);
	set("dex", 21);
	set("max_qi", 450);
	set("max_jing", 200);
	set("neili", 350);
	set("max_neili", 350);
	set("jiali", 30);
	set("combat_exp", 5000);
	set("score", 100);

	set_skill("force", 30);
	set_skill("hunyuan-yiqi", 30);
	set_skill("dodge", 50);
	set_skill("shaolin-shenfa", 50);
	set_skill("cuff", 50);
	set_skill("jingang-quan", 50);
	set_skill("parry", 30);
	set_skill("buddhism", 30);
	set_skill("literate", 30);

	map_skill("force", "hunyuan-yiqi");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("cuff", "jingang-quan");
	map_skill("parry", "jingang-quan");

	prepare_skill("cuff", "jingang-quan");

	set("coagents", ({
                ([ "startroom" : "/d/mingjiao/shanmen",
                   "id"        : "leng qian" ]),
        }));

	setup();

        carry_object("/d/mingjiao/obj/baipao")->wear();
}
