inherit NPC;

void create()
{
        set_name("ά����帾Ů", ({ "fu nv", "fu", "nv" }));
        set("gender", "Ů��" );
        set("age", 40);
        set("long", "һ�����ֵ�ά��������긾Ů��\n");
        set("combat_exp", 150);
        set("env/wimpy", 60);
        set("chat_chance_combat", 50 );
        set("str", 13);
        set("dex", 12);
        set("con", 14);
        set("int", 13);
        set("attitude", "friendly");
        setup();
        carry_object("/clone/cloth/wcloth")->wear();
        add_money("coin", 100);
}

