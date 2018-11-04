inherit NPC;
inherit F_DEALER;

void create()
{
        set_name("�Ե���", ({ "zhao deyan", "zhao", "deyan" }));
        set("title", "�ӻ����ϰ�");
        set("shen_type", 1);

        set("gender", "����");
        set("age", 45);
        set("long", "�Ե��������������������ˣ����˼�ʮ���С������\n");
        set_skill("unarmed", 50);
        set_skill("dodge", 50);
        set_temp("apply/damage", 15);

        set("combat_exp", 40000);
        set("attitude", "friendly");
        set("vendor_goods", ({
                "/clone/cloth/cuttonp",
                "/d/xingxiu/obj/fire",
                "/d/item/obj/chanhs",
                "/clone/misc/wood",
                "/clone/misc/shoeshine",
                "/clone/misc/brush",
        }));
        
        setup();
        carry_object("/clone/misc/cloth")->wear();
}

void init()
{
        add_action("do_list", "list");
        add_action("do_buy", "buy");
}
