#include <ansi.h>
inherit NPC;
inherit F_DEALER;

void create()
{
        set_name("������", ({ "wushe ren", "wushen", "ren" }));
        set("long", "����һ���������������ˡ�\n");
        set("title", "��������");
        set("nickname", HIY "�߼���" NOR);
        set("gender", "����");
        set("age", 33);
        set("attitude", "friendly");
        set("shen_type", -1);
        set("str", 25);
        set("int", 24);
        set("con", 25);
        set("dex", 26);

        set_skill("unarmed", 75);
        set_skill("dodge", 65);
        set_skill("parry", 65);
        set_skill("force", 60);

        set("neili", 400);
        set("max_neili", 400);
        set("jiali", 20);
        set("combat_exp", 30000);
        set("snake_mount" ,3);
        set("score", 10000);

        set("chat_chance",5);
        set("chat_msg", ({
                CYN "������ߺ�ȵ���ͣһͣ����һ�������Ϻõ��ߵ��۳����ˡ�\n" NOR,
                CYN "�����˰����󻮳�һ�����ӣ��ַ����ߵ��ۣ��ף���Ѫ����ֹͣ�ˡ�\n" NOR,
                CYN "�����˰��������������ȥ���������ʵ�����������û��ᡣ\n" NOR,
        }));

        set("inquiry", ([
                "����ɽ" : "��������ߵ��۾����ð���ɽ���߾��������ġ�\n",
                "�ߵ���" : "�ҵ��ߵ������θ������ˣ���Ч������\n",
        ]));
        set("vendor_goods", ({
                "/d/baituo/obj/fen",
        }));
        setup();
        carry_object("/d/baituo/obj/baipao")->wear();
}

void init()
{
        object ob;

        ::init();

        add_action("do_list", "list");
        add_action("do_buy", "buy");

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

        say(CYN "�����˵�����λ" + RANK_D->query_respect(ob) +
            CYN "�����Ұ��ߵ��۰ɣ��������⡣\n");

        return;
}

int accept_fight(object ob)
{
        object obn;

        if (! objectp(present("mang she", environment(ob))))
        {
                if (query("snake_mount") <= 0)
                {
                        message_vision(CYN "���������㶣�˵�����š����찳"
                                       "û���һ���˰ɡ�\n" NOR, ob);
                        return 0;
                }
                message_vision(CYN "�����˴��һ�������Ҹ����ӹ���ȥ������"
                               "�ߵ�������\n" NOR, ob);
                obn=new("/clone/beast/mangshe");
                obn->move(environment(ob));
                obn->kill_ob(ob);
                add("snake_mount", -1);
                return 0;
        }

        message_vision(CYN "�����˴�ŭ��������С�ӳ������ӵ�������\n" NOR, ob);
        return 1;
}
