#include <ansi.h>

inherit NPC;
inherit F_UNIQUE;
inherit F_COAGENT;

void create()
{
        set_name("����ң", ({ "li xiaoyao", "li", "xiaoyao"}));
        set("long", "�ɽ��������еĴ�������������ɽ����\n" 
                    "�������գ���ϰ�Ҵ���ѧ����̽�����Լ���\n"
                    "�ľ�����һ�������Ľ�����\n"); 
        set("nickname", HIW "��ɽ����" NOR);
        set("title", HIY "����ʦ" NOR);
        set("gender", "����");
        set("age", 24);
        set("attitude", "friendly");
        set("shen_type", 1);
        set("str", 50);
        set("int", 50);
        set("con", 50);
        set("dex", 50);

        set("max_qi", 9000);
        set("max_jing", 6000);
        set("max_neili", 12000);
        set("neili", 12000);
        set("jiali", 250);
        set("combat_exp", 10000000);

        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                (: perform_action, "sword.fei" :),
                (: exert_function, "freeze" :),
                (: exert_function, "powerup" :),
        }) );

        set_skill("dodge", 460);
        set_skill("parry", 460);
        set_skill("unarmed", 460);
        set_skill("hand", 460);
        set_skill("sword", 460);
        set_skill("yujian-shu", 460);
        set_skill("feilong-shou", 460);
        set_skill("zuixian-bu", 460);
        set_skill("force", 460);
        set_skill("bingxin-jue", 460);
        set_skill("literate", 200);

        map_skill("force", "bingxin-jue");
        map_skill("dodge", "zuixian-bu");
        map_skill("parry", "yujian-shu");
        map_skill("sword", "yujian-shu");
        map_skill("unarmed", "feilong-shou");
        map_skill("hand", "feilong-shou");

        prepare_skill("hand", "feilong-shou");

        setup();

        carry_object(__DIR__"obj/pangukai")->wear();
        carry_object(__DIR__"obj/chiyoujian")->wield();
        carry_object("/kungfu/class/sky/obj/miji3");
        set_temp("handing", carry_object("/kungfu/class/sky/obj/shenjiu"));
}

