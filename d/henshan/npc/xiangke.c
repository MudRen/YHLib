inherit NPC;

void create()
{
    set_name("�����", ({ "jingxiang ke","ke","jingxiang"}));
    set("gender", "����");
    set("age", 45);
    set("long", "��������ɽ���ݵ��ˡ�\n");
    set("combat_exp", 2000);
    set("attitude", "friendly");
    setup();
    carry_object("/clone/misc/cloth")->wear();
    add_money("silver", 5);
}
