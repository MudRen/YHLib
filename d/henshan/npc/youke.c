inherit NPC;

void create()
{
    set_name("�ο�", ({ "you ke","ke","you"}));
    set("gender", "����");
    set("age", 25);
    set("long", "��������ɽ���ε��ο͡�\n");
    set("combat_exp", 2000);
    set("attitude", "friendly");
    setup();
    carry_object("/clone/misc/cloth")->wear();
    add_money("silver", 5);
}
