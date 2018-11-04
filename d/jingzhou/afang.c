#include <ansi.h>;

inherit KNOWER;
inherit F_DEALER;

void create()
{
        set_name("����", ({ "afang", "fang" }));
        set("title", "�����ϰ�");
        set("nickname", "�����Ϲ���");
        set("shen_type", 1);

        set("str", 30);
        set("gender", "Ů��");
        set("age", 20);
        set("long", "����ò���ʻ����ɲ�֪����ԭ�򣬳ٳٲ��ޣ��ǵ�ү������������\n");
        set("combat_exp", 500);
        set("attitude", "friendly");
        set("inquiry", ([
                "���" : "��飿���м������ƽ𣿣��ﹻ�������Ұɡ�������\n",
                "����" : "���ô�����������͡�\n",
        ]));
        
        set("vendor_goods", ({
                __DIR__"obj/peanut",
                __DIR__"obj/tofu",
        }));

        setup();
        carry_object("/clone/misc/cloth")->wear();
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
        add_action("do_list", "list");
        add_action("do_buy", "buy");
}

void greeting(object ob)
{
        if ( ! ob || environment(ob) != environment())
                return;

        switch(random(2))
        {
        case 0 :
                say(CYN "����Ц���е�˵������λ" + RANK_D->query_respect(ob)
                    + CYN + "����������ȱ��Ȳ衣\n" NOR);
                break;
        case 1 :
                say(CYN "����˵����Ӵ����λ" + RANK_D->query_respect(ob)
                    + CYN + "�����˰���\n" NOR);
                break;
        }
}

