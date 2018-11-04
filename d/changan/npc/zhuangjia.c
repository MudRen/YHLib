#include <ansi.h>

inherit NPC;

object room = 0;

void create()
{
	set_name( "ׯ��", ({ "zhuang jia", "zhuang" }) );
	set("long", "���Ƕĳ���ְҵ��ͽ�������ϵĹ�������뻯��\n");
	set("attitude", "friendly");
	set("title", HIR "����ʥ��" NOR);
        set("force_factor", 30);
        set("max_kee", 3000);
        set("max_sen", 3000);
        set("eff_gin", 3000);
        set("eff_kee", 3000);
        set("eff_sen", 3000);
        set("kee", 3000);
        set("sen", 3000);
        set("max_force", 3000);
        set("force", 3000);
        set("max_mana", 3000);
        set("mana", 3000);
	set("age", 47);
	set_temp("apply/damage",600);
        set("gender", "����" );
	set("str", 40);
	set("cor", 35);
	set("cps", 30);
	set("per",10);
	set("max_force",3000);
	set("force_factor",40);
	set_skill("parry",170);
	set_skill("unarmed",170);
        set_skill("force",170);
	set_skill("dodge",170);
	set("combat_exp", 300000);

	setup();
        carry_object(__DIR__"obj/choupao")->wear();
}

void init()
{       
        object ob;

        ::init();

        if (interactive(ob = this_player()) && ! is_fighting())
        {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

void greeting(object ob)
{
        if (! ob || environment(ob) != environment())
                return;
        switch(random(3))
        {
        case 0:
                say(CYN "ׯ��Ц�����˵������λ" + RANK_D->query_respect(ob) +
                    CYN "�����������֣�����������Σ�\n" NOR);
                break;
        case 1:
                say(CYN "ׯ�һ��˻����е����ӣ��е�����λ" + RANK_D->query_respect(ob) +
                    CYN "������ԥ�ˡ�����һע�ɣ�\n" NOR);
                break;
        case 2:
                say(CYN "ׯ��˵������λ" + RANK_D->query_respect(ob) +
                    CYN "�������������� ��Ѻһ�ѣ�\n" NOR);
                break;
        }
}
