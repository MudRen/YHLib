#include <ansi.h>;

inherit KNOWER;
inherit F_DEALER;

void create()
{
        set_name("����ͷ", ({ "chen laotou", "chen", "laotou" }) );
         set("title", "�͵��ϰ�");
        set("gender", "����" );
        set("age", 32);
        set("long",
              "һ�������Ѯ��С��ͷ�����������С�͵���ϰ塣\n");
        set("shen_type", 1);
        set("combat_exp", 3000);
        set("str", 10);
        set("dex", 10);
        set("con", 10);
        set("int", 10);
        set("attitude", "peaceful");
        set_skill("dodge",10);
        set_skill("unarmed",10);
        set("chat_chance", 10);
        set("chat_msg", ({
                CYN "����ͷһ�ߺ���С��һ������Ĩ������������\n" NOR,
                CYN "����ͷһ�����ֹ���������Ҳ�û����ˡ�\n" NOR,
        }) );       

        setup();
        carry_object("/d/beijing/npc/obj/cloth")->wear();
        add_money("silver", 20);
}

void init()
{       
        object ob;

        ::init();
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
                say( CYN "����ͷ��Ц�Ŷ���˵������λ" + RANK_D->query_respect(ob)
                   + CYN + "�����ǶԲ�ס��С���Ѿ������ˡ�\n" NOR);
                break;
        case 1:
                say( CYN "����ͷ�ò����ϵ�ë��Ĩ��Ĩ�֣����ε�˵������λ" + RANK_D->query_respect(ob)
                   + CYN + "���治�ɣ�С���Ѿ������ˡ�\n" NOR);
                break;
        }
}

