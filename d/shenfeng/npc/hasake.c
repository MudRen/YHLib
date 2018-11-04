#include <ansi.h>
inherit NPC;

void create()
{
        set_name("��������", ({ "hasake ren", "hasake", "ren"}));
        set("gender", "����");
        set("age", 26);
        set("long", "һ�������������꣬���ż�ʮֻ��\n");
        set("attitude", "friendly");
        set("combat_exp", 4000);
        set("shen_type", 0);
        set("str", 32);
        set("int", 18);
        set("con", 22);
        set("dex", 17);
        set("max_qi", 600);
        set("max_jing", 600);
        set("neili", 600);
        set("max_neili", 600);
        set("jiali", 50);
        set_skill("unarmed", 50);
        set_skill("blade", 50);
        set_skill("parry", 50);
        set_skill("dodge", 50);
        set_temp("apply/attack", 25);
        set_temp("apply/defense", 25);
        set_temp("apply/damage", 25);

        set("inquiry", ([
            	"����"   : "ѽ����ҲҪ������ˤ�ӣ���������ͻ��ҵ�����",
            	"����"   : "̾����ˤ����Ӯ�������ա�",
            	"������" : "�����˻����������ҵ����ƣ���ҽţ����ƥ�ļ�����",
        ]));

        set("chat_chance", 10);
        set("chat_msg", ({
		CYN "�������˵����ϸ������õ�������һͷ�ǣ�������Ƥ�͸��۰��á�\n" NOR,
		CYN "�������˵��������ǲ�ԭ��һ�����·�Ļ���\n" NOR,
        }) );

        setup();
        carry_object(__DIR__"obj/duandao")->wield();
        carry_object(__DIR__"obj/ycloth")->wear();
}
