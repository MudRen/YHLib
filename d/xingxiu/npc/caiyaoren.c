inherit NPC;

void create()
{
        set_name("��ҩ��", ({ "caiyao ren", "caiyao", "ren" }));
        set("gender", "����");
        set("age", 30 + random(10));

        set("long", "һ�����๤���Ĳ�ҩ�ˡ�\n");
        set("attitude", "friendly");

        set("combat_exp", 1000);
        set("shen_type", 1);

        set_skill("unarmed", 20);
        set_skill("dodge", 20);
        set_skill("hammer", 20);
        set("apply/attack", 15);
        set("apply/defense", 15);
        set("apply/damage", 5);

        setup();

        add_money("coin", 50);
        carry_object("/d/xingxiu/obj/yaochu")->wield();

        if (random(10) > 8)
        	carry_object("/clone/fam/pill/xuelian1");
}

