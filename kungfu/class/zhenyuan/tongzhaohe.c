// tongzhaohe ͯ�׺�

#include <ansi.h>
#include "zhenyuan.h"

inherit NPC;
inherit F_MASTER;
inherit F_GUARDER;

void create()
{
	set_name("ͯ�׺�", ({ "tong zhaohe", "tong", "zhaohe"}));
  	set("long", "������ò��������������һ������û�������ӡ�"
                    "����Զ�ھ���պ������Ļ�졣\n");
	set("title", "��Զ�ھ���ʦ");
  	set("gender", "����");
  	set("age", 35);
	set("class", "fighter");
        set("attitude", "peaceful");
        set("str", 25);
        set("int", 25);
        set("con", 25);
        set("dex", 25);

        set("max_qi", 3000);
        set("max_jing", 3000);
        set("neili", 1000);
        set("max_neili", 1000);
        set("jiali", 20);
        set("combat_exp", 150000);

  	set_skill("parry", 60);
  	set_skill("force", 60);
  	set_skill("bagua-xinfa", 60);
  	set_skill("dodge", 60);
  	set_skill("bagua-bu", 60);
  	set_skill("strike", 60);
  	set_skill("bagua-zhang", 60);
  	set_skill("cuff", 60);
  	set_skill("bagua-quan", 60);
  	set_skill("literate", 40);
  	set_skill("blade", 60);
  	set_skill("kuimang-dao", 60);
  	set_skill("martial-cognize", 40);

	map_skill("blade", "kuimang-dao");
	map_skill("dodge", "bagua-bu");
	map_skill("force", "bagua-xinfa");
	map_skill("strike", "bagua-zhang");
	map_skill("cuff", "bagua-quan");
	map_skill("parry", "bagua-quan");

	prepare_skill("cuff", "bagua-quan");
	prepare_skill("strike", "bagua-zhang");

        set("coagents", ({
                ([ "startroom" : "/d/beijing/shufang",
                   "id"        : "wang weiyang" ]),
        }));

        set("guarder", ([
                "refuse_other": CYN "$N" CYN "��$n" CYN "��ü����"
                                "ι�����⵹���������߰���" NOR,
                "refuse_carry": CYN "$N" CYN "��$n" CYN "��ƤЦ��"
                                "�ص����㱳�ϱ����Ǹ�ɶ����������"
                                "�����ơ�" NOR,
        ]));

  	create_family("������", 3, "����");
  	setup();

        carry_object("/clone/weapon/gangdao")->wield();
  	carry_object("/clone/misc/cloth")->wear();
}

void attempt_apprentice(object me)
{
        if (! permit_recruit(me))
                return;

        command("@@");
        command("say ��Ȼ���˰���Ϊʦ�����������ģ��Ҿ���������ˡ�");
        command("recruit " + me->query("id"));
        if ((string)me->query("class") != "fighter")
                me->set("class", "fighter");
}
