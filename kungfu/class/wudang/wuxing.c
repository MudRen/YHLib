#include <command.h>
#include <ansi.h>

inherit NPC;

void create()
{
        set_name("���е���", ({ "wuxing dizi", "dizi", "wuxing" }));
        set("age", 23);
        set("gender", "����");
        set("long", "���佣������з�λ���ӡ�\n");
        set("attitude", "peaceful");
        set("str", 24);
        set("dex", 27);
        set("combat_exp", 80000);
        set("shen_type", 1);

        set("max_qi", 10);
        set("max_jing", 10);

        set_skill("unarmed", 80);
        set_skill("sword", 80);
        set_skill("force", 80);

        set("chat_chance", 1);
        set("chat_msg", ({
                CYN "���е�������ߺ�ȣ����佣�����µ�һ��\n" NOR,
        }));
        create_family("�䵱��", 3, "����");
        setup();
        carry_object("/clone/weapon/changjian");
        carry_object("/d/wudang/obj/wuxingfu")->wear();
}

void unconcious()
{
        die();
}
