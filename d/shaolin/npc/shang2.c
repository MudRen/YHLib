inherit NPC;

void create()
{
        set_name("�Ҷ�", ({ "jia ding", "jia", "ding"}));
        set("gender", "����" );
        set("age", 20);
        set("long", "һ����ʮ��������꣬���̼ұ��ڵ��\n");
        set("shen_type", 1);
        set("combat_exp", 2000);
        set("str", 17);
        set("dex", 20);
        set("con", 17);
        set("int", 22);
        set("attitude", "peaceful");
        set_skill("dodge",10);
        set_skill("unarmed",10);

        setup();
        carry_object("/clone/cloth/cloth")->wear();
}
