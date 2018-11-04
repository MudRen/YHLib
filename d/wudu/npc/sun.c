#include <ansi.h>;

inherit KNOWER;
inherit F_DEALER;

void create()
{
        set_name("�����", ({ "sun erniang", "sun", "waiter" }) );
        set("gender", "Ů��" );
        set("age", 22);
        set("long",
                "��λ�ϰ�����Ц��������ڹ�̨���棬��������������\n");
        set("combat_exp", 100000);
        set("attitude", "friendly");
        set("rank_info/respect", "ĸҹ��");
        set_skill("dodge", 80);
        set_skill("unarmed",80);
        set_skill("parry", 80);
        set_skill("literate", 150);

        set("vendor_goods", ({
               __DIR__"obj/jitui",
               __DIR__"obj/baozi",
               __DIR__"obj/flagon",
        }));
        setup();
        carry_object("/clone/misc/cloth")->wear();
}

void init()
{       
        object ob;

        ::init();
        add_action("do_buy", "buy");
        add_action("do_list", "list");

        if ( interactive(ob = this_player()) && !is_fighting() )
        {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

void greeting(object ob)
{
        if ( ! ob || environment(ob) != environment() ) return;
        switch( random(2) )
        {
        case 0:
                say( CYN "�����Ц�����˵������λ" + RANK_D->query_respect(ob)
                   + CYN + "�������ȱ��裬ЪЪ�Ȱɡ�\n" NOR);
                break;
        case 1:
                say( CYN "������ò����ϵ�ë��Ĩ��Ĩ�֣�˵������λ" + RANK_D->query_respect(ob)
                   + CYN + "����������\n" NOR);
                break;
        }
}

