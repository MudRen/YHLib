inherit KNOWER;
inherit F_DEALER;

void create()
{
        set_name("�Է�", ({ "qiao fu", "qiao", "fu" }));
        set("gender", "����" );
        set("age", 50);
        set("long", @LONG
����һ��һ�����Կ���Ϊ�������Է����ڱ�
�ܷ�˪���Գ������䲻��Ƶ�˥�ϡ�
LONG);
        set("shen_type",1);
        set("combat_exp", 10000);
        set("str", 17);
        set("dex", 18);
        set("con", 18);
        set("int", 18);
        set("attitude", "friendly");
        setup();
        carry_object("/clone/misc/cloth")->wear();
        carry_object("/d/xiakedao/obj/knife")->wield();
}
