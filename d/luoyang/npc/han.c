inherit NPC;
inherit F_VENDOR;

void create()
{
        set_name("����", ({ "han yun", "han", "yun" }) );
        set("gender", "����" );
        set("title", "�������ϰ�" );
        set("age", 32);
        set("long", "�����Ǵ�������ϰ壬���Ļ�����ֱ�Ӵ������ʽ��ġ�\n");
        set("shen_type", 1);
        set("combat_exp", 10000);
        set("str", 17);
        set("dex", 20);
        set("con", 17);
        set("int", 22);
        set("attitude", "peaceful");
        set_skill("dodge", 20);
        set_skill("unarmed", 20);
        set("chat_chance", 20);
        set("vendor_goods", ({
                __DIR__"obj/taoci",
                __DIR__"obj/taoci2",
                __DIR__"obj/taoci3",
                __DIR__"obj/taoci4",
                __DIR__"obj/taoci5",
                __DIR__"obj/taoci6",
                __DIR__"obj/taoci7",
                __DIR__"obj/taoci8",
        }) );

        setup();
        carry_object("/d/beijing/npc/obj/cloth")->wear();
        add_money("coin", 100);
}

void init()
{
        ::init();
        add_action("do_buy", "buy");
        add_action("do_list", "list");
}
