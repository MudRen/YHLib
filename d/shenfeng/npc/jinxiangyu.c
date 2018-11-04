#include <ansi.h>;

inherit KNOWER;
inherit F_DEALER;

void create()
{
        set_name("������", ({ "jin xiangyu", "jin", "xiangyu" }));
        set("title", "���ſ�ջ�ϰ���");
        set("shen_type", 0);
        set("gender", "Ů��");
        set("per", 34);
        set("long", "�������ǻ�����ԭһ�������Ĵ����ˡ�һЩ���\n"
                    "���ˣ��������ӳ���������ЪϢ������������һ\n"
                    "����һ��һ��������ָ�ơ�\n");
        set("combat_exp", 500);
        set("attitude", "friendly");
        set("vendor_goods", ({
                "/d/xingxiu/obj/fire",
                "/d/city/npc/obj/jiudai",
                "/d/shenfeng/npc/obj/dogrou",
                "/d/shenfeng/npc/obj/hulu",
        }));
        setup();
        carry_object("/d/city/npc/cloth/yan-dress")->wear();
}

void init()
{       
        object ob;

        ::init();
        add_action("do_buy", "buy");
        add_action("do_list", "list");

        if (interactive(ob = this_player()) && ! is_fighting())
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
                say(CYN "������Ц���е�˵������λ" + RANK_D->query_respect(ob)
                  + CYN + "�������������ưɡ�\n" NOR);
                break;
        case 1:
                say(CYN "������˵����Ӵ����λ" + RANK_D->query_respect(ob)
                  + CYN + "������������иճ�Ҥ�ĺþơ�\n" NOR);
                break;
        }
}
