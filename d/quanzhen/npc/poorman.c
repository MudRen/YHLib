#include <ansi.h>
inherit NPC;

void create()
{
        set_name("�", ({ "qiong han", "qiong", "han" }));
        set("gender", "����" );
        set("age", 33);
        set("long", "һ���������������ɫ�����\n");
        set("attitude", "friendly");
        set("combat_exp", 250);
        set("shen_type", 1);
        set("str", 20);
        set("dex", 18);
        set("con", 17);
        set("int", 13);
        setup();

        set("chat_chance", 15);
        set("chat_msg", ({
                CYN "�������ش��˸���Ƿ��\n" NOR,
                CYN "�׽ס���ϵ�ʭ�ӣ��������������û�����⣬ȫ�����Ǹ�ҧ�ˡ� \n" NOR,
                (: random_move :)
        }));
        carry_object(__DIR__"obj/cloth")->wear();
}
