inherit NPC;

void create()
{
        set_name("ɽ��ͷ", ({ "shanzei tou", "shanzei", "tou" }));
        set("gender", "����" );
        set("age", 29);
        set("long", "���Ǹ���³��ɽ��ͷ��\n");
        set("attitude", "friendly");
        set("shen_type", -1);

        set("str", 24);
        set("int", 23);
        set("con", 24);
        set("dex", 23);

        set("max_qi", 800);
        set("max_jing", 800);
        set("neili", 800);
        set("max_neili", 800);
        set("combat_exp", 100000);
        set("score", 2000);

        setup();
        carry_object("/clone/misc/cloth")->wear();
        carry_object("/d/baituo/obj/dadao")->wield();
}

