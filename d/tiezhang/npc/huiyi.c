#include <ansi.h>

inherit NPC;

void create()
{
        set_name("���°���", ({ "huiyi bangzhong", "huiyi", "bangzhong"}));
        set("long", "����һ�����н�׳�ĺ��ӣ����۴�׳��������Բ�����������ࡣ\n");
        set("gender", "����");
        set("attitude", "peaceful");
        set("age", 30);
        set("shen_type", -1);
        set("str", 25);
        set("int", 20);
        set("con", 20);
        set("dex", 25);
        set("max_qi", 500);
        set("max_jing", 300);
        set("neili", 500);
        set("max_neili", 500);
        set("jiaji", 50);
        set("combat_exp", 10000);
        set("score", 1);

        set_skill("force", 80);
        set_skill("tiezhang-xinfa", 80);
        set_skill("dodge", 80);
        set_skill("dengping-dushui", 80);
        set_skill("strike", 80);
        set_skill("tongbi-zhang", 80);
        set_skill("parry", 80);

        map_skill("force", "tiezhang-xinfa");
        map_skill("dodge", "dengping-dushui");
        map_skill("strike", "tongbi-zhang");
        map_skill("parry", "tongbi-zhang");

        setup();
        carry_object(__DIR__"obj/black-cloth")->wear();
}