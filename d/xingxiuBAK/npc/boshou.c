#include <ansi.h>
inherit NPC;

void create()
{
        set_name("����������", ({ "bo shou", "bo", "shou" }));
        set("long", "����������һ��ͭ�࣬һ����һ�߳���\n"
                    "ɤ�ӳ�Щ����Ļ���\n");
        set("gender", "����");
        set("age", 33);
        set("attitude", "peaceful");
        set("shen_type", -1);
        set("str", 26);
        set("int", 16);
        set("con", 22);
        set("dex", 24);

        set("max_qi", 200);
        set("max_jing", 200);
        set("neili", 200);
        set("max_neili", 200);
        set("jiali", 10);
        set("combat_exp", 2000);

        set_skill("force", 20);
        set_skill("dodge", 20);
        set_skill("unarmed", 20);
        set_skill("parry", 20);

        setup();
        set("chat_chance", 10);
        set("chat_msg", ({
		CYN "��������ͭ�࣬�����������ǡ��ޡ��ϡ��ɡ�������御��\n" NOR,
		CYN "��������ͭ�࣬�����������ǡ��ޡ��ϡ��ɡ��¡��䡫�졫�ء�\n" NOR,
		CYN "��������ͭ�࣬�����������ǡ��ޡ��ϡ��ɡ��š����ޡ��ȡ�\n" NOR,
        }));
        carry_object("/clone/cloth/cloth")->wear();
        carry_object("/d/xingxiu/obj/tongbo")->wield();
}
