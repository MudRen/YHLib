inherit NPC;

void create()
{
        set_name("��ͯ", ({ "shu tong", "tong" }));
        set("gender", "����");
        set("age", 35);
        set("long", "����ׯ����������ͯ��ƽ�ؿ��ܲ��顣\n");
        set("combat_exp", 10000);
        set_skill("dodge", 50);
        set_skill("unarmed", 50);
        set_temp("apply/attack",  50);
        set_temp("apply/defense", 50);
        setup();

        carry_object("/clone/misc/cloth")->wear();
}
