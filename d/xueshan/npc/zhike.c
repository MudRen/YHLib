#include <ansi.h>
inherit KNOWER;

void create()
{
        set_name("֪��ɮ", ({ "zhike seng", "zhike", "seng" }));
        set("gender", "����");
        set("age", 40 + random(10));
        set("attitude", "friendly");
        set("combat_exp", 60000);
        set("shen_type", 1);
        set_skill("unarmed", 50);
        set_skill("blade", 50);
        set_skill("parry", 50);
        set_skill("dodge", 50);
        set_temp("apply/attack", 15);
        set_temp("apply/defense", 15);
        set_temp("apply/damage", 20);
        setup();
        carry_object("/clone/cloth/cloth")->wear();
}

