inherit NPC;

void create()
{
        set_name("�컨����", ({ "honghua dizi", "hong", "honghua", "dizi" }) );
        set("gender", "����");
        set("age", 25);
        set("long", "����λ������ӣ���ǰ���һ���컨��\n");
        set("combat_exp", 20000);
        set("shen_type", 1);
        set("attitude", "heroism");

        set("apply/attack",  30);
        set("apply/defense", 30);

        set_skill("sword", 60);
        set_skill("unarmed", 50);
        set_skill("parry", 50);
        set_skill("dodge", 50);

        setup();

        carry_object("/clone/misc/cloth")->wear();
        add_money("silver", 20);
}
