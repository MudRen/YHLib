#include <ansi.h>
inherit NPC;

void create()
{
        set_name("�����ɹ���", ({ "gu shou", "gu", "shou" }));
        set("long", "����ǰ����һֻͭ�ģ�һ����һ�߳���\n"
                    "ɤ�ӳ�Щ����Ļ���\n");
        set("gender", "����");
        set("age", 43);
        set("attitude", "peaceful");
        set("shen_type", -1);
        set("str", 26);
        set("int", 16);
        set("con", 20);
        set("dex", 20);

        set("max_qi", 400);
        set("max_jing", 400);
        set("neili", 400);
        set("max_neili", 400);
        set("jiali", 10);
        set("combat_exp", 4000);

        set_skill("force", 40);
        set_skill("dodge", 40);
        set_skill("unarmed", 40);
        set_skill("parry", 40);

        setup();
        set("chat_chance", 10);
        set("chat_msg", ({
		CYN "��������ͭ�ģ������������ǡ��ޡ��ϡ��ɡ�������御��\n" NOR,
		CYN "��������ͭ�ģ������������ǡ��ޡ��ϡ��ɡ��¡��䡫�졫�ء�\n" NOR,
		CYN "��������ͭ�ģ������������ǡ��ޡ��ϡ��ɡ��š����ޡ��ȡ�\n" NOR,
        }));
        carry_object("/clone/cloth/cloth")->wear();
        carry_object("/d/xingxiu/obj/tonggu")->wield();
}
