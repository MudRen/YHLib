#include <ansi.h>
inherit NPC;

void create()
{
        set_name("��������", ({ "lao zhe", "lao", "zhe"}) );
        set("gender", "����" );
        set("age", 64);
        set("long", "һ���뷢�԰׵����ߣ��������壬�����⡣\n");
        set("max_qi", 2000);
        set("max_jing", 2000);
        set("max_neili", 2000);
        set("jiali", 50);
        set("combat_exp", 400000);
        set("attitude", "friendly");
        set_skill("dodge", 120);
        set_skill("unarmed",120);
        set_skill("parry", 120);
        set_skill("force",120);
        set_skill("hammer", 120);
        set_skill("sword",120);
        set_skill("literate", 50);

        setup();
        carry_object("/clone/misc/cloth")->wear();
        carry_object("/d/wudu/obj/zhulou2")->wear();
}
