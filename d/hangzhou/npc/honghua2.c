inherit NPC;

void create()
{
        set_name("��Ӫ����", ({ "hui zhong", "hui", "zhong" }) );
        set("gender", "����");
        set("age", 25);
        set("long", "����λ��ִ��ǹ����Ӫ������컨���ڽ���\n"
                    "���ƴ�ʢ����ӪҲ���л��ڡ�\n");
        set("combat_exp", 20000);
        set("shen_type", 1);
        set("attitude", "heroism");

        set("apply/attack",  30);
        set("apply/defense", 30);

        set_skill("club", 60);
        set_skill("unarmed", 50);
        set_skill("parry", 50);
        set_skill("dodge", 50);

        setup();

        carry_object("/clone/weapon/changqiang")->wield();
        carry_object("/d/city/obj/junfu")->wear();
        add_money("coin", 20);
}
