inherit NPC;

void create()
{
        set_name("Ϸ��", ({ "xi zi", "xi", "zi" }) );
        set("gender", "����" );
        set("age", 32);
        set("long",
              "һ����ϷԺ��Ϸ��Ϸ�ӡ�\n");
        set("shen_type", -1);
        set("combat_exp", 2501235);
        set("max_qi", 1);
        set("qi", 1);
        set("str", 1);
        set("dex", 1);
        set("con", 1);
        set("int", 1);
        set("attitude", "peaceful");
        
        setup();
        carry_object("/d/beijing/npc/obj/cloth")->wear();
        add_money("coin", 30);
}

