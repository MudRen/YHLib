#include <ansi.h>
inherit NPC;

void create()
{
        set_name("����", ({ "jiao zhong", "jiao", "zhong" }));
        set("long", "����һ����ӥ�̵Ľ��ڣ���Ŀ��ࡣ\n");
        set("attitude", "heroism");
        set("title", "��ӥ������̳");
        set("max_qi", 800);
        set("max_jing", 800);
        set("neili", 500);
        set("max_neili", 500);
        set("jiali", 50);
        set("combat_exp", 500000);

        set_skill("parry", 150);
        set_skill("dodge", 150);
        set_skill("force", 150);
        set_skill("unarmed", 150);

        setup();

        carry_object(__DIR__"obj/jiaofu")->wear();
}
