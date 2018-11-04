// hanwenchong.c ���ĳ�

#include <ansi.h>

inherit NPC;

void create()
{
	set_name("���ĳ�", ({ "han wenchong", "han", "wenchong"}));
  	set("long", "���˱����������Һ��������£����ں���Զ��\n"
                    "������ͷ��ά�Ｐ���������ӽ������ƣ�����\n"
                    "�����������������ھֵ�������������磬\n"
                    "���ײ����ۣ���ò���ţ��ٿ���˫�������\n"
                    "��������ָ������羫��һ�㣬��֪���Ϲ���\n"
                    "��ͬһ�㡣\n" );
	set("title", "��Զ�ھ���ʦ");
  	set("gender", "����");
  	set("age", 35);
	set("class", "fighter");
        set("attitude", "peaceful");
        set("str", 25);
        set("int", 25);
        set("con", 25);
        set("dex", 25);

        set("max_qi", 1000);
        set("max_jing", 1000);
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

	map_skill("dodge", "bagua-bu");
	map_skill("force", "bagua-xinfa");
	map_skill("strike", "bagua-zhang");
	map_skill("cuff", "bagua-quan");
	map_skill("parry", "bagua-quan");

	prepare_skill("cuff", "bagua-quan");
	prepare_skill("strike", "bagua-zhang");

  	setup();

  	carry_object("/clone/misc/cloth")->wear();
}

void attempt_apprentice(object ob)
{
        command("say �Ҳ���ͽ������������ʦȥ�� ");
        return;
}
