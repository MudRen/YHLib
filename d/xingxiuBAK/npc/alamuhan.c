inherit NPC;

void create()
{
        set_name("����ľ��", ({ "ala muhan", "ala", "muhan" }));
        set("long", "����β���Ҳ���ݡ�����üë�����£������۾��ܶ��顣\n");
        set("title", "�������");
        set("gender", "Ů��");
        set("age", 17);

        set_skill("unarmed", 20);
        set_skill("dodge", 40);
        set_skill("parry", 20);
        set_skill("whip", 50);

        set_temp("apply/attack", 30);
        set_temp("apply/defense", 30);
        set_temp("apply/damage", 5);

        set("combat_exp", 5000);
        set("attitude","friendly");

        set("shen_type", 1);
        setup();
        carry_object("/clone/cloth/wcloth")->wear();
        carry_object("/clone/weapon/changbian")->wield();
}
