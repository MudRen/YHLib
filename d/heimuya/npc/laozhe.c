inherit NPC;
 
void create()
{
        set_name("����", ({ "lao zhe", "oldman" }) );
        set("gender", "����" );
        set("age", 70);
        set("long", "�����ͷ���麵�̳������ء�\n");
        set("combat_exp", 1000);
        set("attitude", "friendly");
        set("rank_info/respect", "�ϴ�ү");
        setup();
        carry_object("/clone/cloth/cloth")->wear();
        add_money("silver", 10);
}

