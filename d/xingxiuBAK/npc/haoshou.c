#include <ansi.h>
inherit NPC;

void create()
{
        set_name("�����ɺ���", ({ "hao shou", "hao", "shou" }));
        set("long", "����������һֻͭ�ţ��������������\n"
                    "���š�\n");
        set("gender", "����");
        set("age", 33);
        set("attitude", "peaceful");
        set("shen_type", -1);
        set("str", 26);
        set("int", 16);
        set("con", 22);
        set("dex", 24);

        set("max_qi", 300);
        set("max_jing", 300);
        set("neili", 300);
        set("max_neili", 300);
        set("jiali", 10);
        set("combat_exp", 3000);

        set_skill("force", 30);
        set_skill("dodge", 30);
        set_skill("unarmed", 30);
        set_skill("parry", 30);

        setup();
        set("chat_chance", 10);
        set("chat_msg", ({
		CYN "���ִ���ͭ�ţ������������ǡ��ޡ��ϡ��ɡ�������御��\n" NOR,
		CYN "���ִ���ͭ�ţ������������ǡ��ޡ��ϡ��ɡ��¡��䡫�졫�ء�\n" NOR,
		CYN "���ִ���ͭ�ţ������������ǡ��ޡ��ϡ��ɡ��š����ޡ��ȡ�\n" NOR,
        }));
        carry_object("/clone/cloth/cloth")->wear();
        carry_object("/d/xingxiu/obj/tonghao")->wield();
}
