#include <ansi.h>;

inherit NPC;

void create()
{
        set_name("���µ���", ({ "riyue dizi", "riyue", "dizi" }));
        set("title", WHT "��ľ��" NOR);
        set("long", "����פ����ľ�µĵ��ӣ��������Ѳ�������ܵ����Ρ�\n");
        set("gender", "����");
        set("attitude", "peaceful");

        set("str", 30);
        set("con", 30);
        set("int", 30);
        set("dex", 30);
        set("neili", 500);
        set("max_neili", 500);
        set("max_jing", 400);
        set("jing", 400);
        set("max_qi", 600);
        set("qi", 600);
        set("jiali", 20);

        set("combat_exp", 20000);
        set("shen_type", -1);
        set("score", 50000);

        set_skill("unarmed", 80);
        set_skill("sword", 80);
        set_skill("force", 80);
        set_skill("parry", 80);
        set_skill("dodge", 80);
        set_skill("literate", 40);

        setup();       
        carry_object("/clone/cloth/cloth")->wear();
}

void init()
{       
        object ob;

        ::init();

        if (interactive(ob = this_player()) && !is_fighting())
        {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

void greeting(object ob)
{
        if (! ob || environment(ob) != environment()) return;

	say(CYN "���µ��Ӹ�����������������̣��ĳ���¡�ǧ�����أ�һͳ������\n" NOR);
}

