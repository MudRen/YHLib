// jian-ke.c
#include <ansi.h>
inherit NPC;
void create()
{
    set_name("����", ({ "jian ke","ke" }) );
    set("gender", "����");
    set("age", 45);
    set("long",
        "����λ�������ˣ��米�����������Ľ������Ʈ������ƺ������ա�\n");
    set("combat_exp", 20000);
        set("shen_type", -1);
    set("attitude", "heroism");
    set("apply/attack",  30);
    set("apply/defense", 30);
    set_skill("sword", 60);
    set_skill("unarmed", 50);
    set_skill("parry", 50);
    set_skill("dodge", 50);
    setup();
    carry_object("/d/city/obj/changjian")->wield();
    carry_object("/clone/misc/cloth")->wear();
    add_money("silver", 20);
}
