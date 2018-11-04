#include <ansi.h> 
inherit NPC;

void create()
{
        set_name("��������", ({ "gong zi", "gong", "zi" }));
        set("nickname", HIR "�ɻ����" NOR);
        set("gender", "����" );
        set("age", 21);
        set("long", "���Ǹ����������Ļ������ӡ�\n");
        set("attitude", "friendly");
        set("shen_type", -1);

        set("str", 21);
        set("int", 23);
        set("con", 22);
        set("dex", 20);

        set("max_qi", 800);
        set("max_jing", 800);
        set("neili", 600);
        set("max_neili", 600);
        set("combat_exp", 500000);
        set("score", 10000);

        set_skill("force", 120);
        set_skill("dodge", 140);
        set_skill("chanchu-bufa", 140);
        set_skill("unarmed", 120);
        set_skill("changquan", 120);
        set_skill("dagger", 140);
        set_skill("poxu-daxuefa", 140);
        set_skill("parry", 140);

        map_skill("dodge", "chanchu-bufa");
        map_skill("parry", "poxu-daxuefa");
        map_skill("dagger", "poxu-daxuefa");
        map_skill("unarmed", "changquan");

        setup();
        carry_object("/clone/cloth/jinduan")->wear();
        carry_object("/d/city/npc/shanzi/zhe-shan")->wield();
        add_money("silver", 2);
}
