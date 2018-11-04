#include <ansi.h>
inherit NPC;

void create()
{
        set_name("ʯ����", ({"shi potian", "shi", "potian"}));
        set("nickname", HIW "���ְ���" NOR);
        set("gender", "����");
        set("age", 20);
        set("long", "����Լ��ʮ���꣬����һ�����õ��·���ȴ"
                    "Ҳ����ס��һ���Ӣ����\n");
        set("max_qi", 8000);
        set("max_jing", 6000);
        set("neili", 10000);
        set("max_neili", 10000);
        set("jiali", 200);
        set("combat_exp", 5000000);
        set("shen_type", 1);
        set("score", 20000);

        set_skill("force", 340);
        set_skill("taixuan-gong", 340);
        set_skill("dodge", 340);
        set_skill("blade", 340);
        set_skill("jinwu-daofa", 320);
        set_skill("unarmed", 340);
        set_skill("sword", 340);
        set_skill("shangqing-jian", 320);
        set_skill("xueshan-jian", 320);
        set_skill("parry", 300);
        set_skill("strike", 280);
        set_skill("bizhen-qingzhang", 180);
        set_skill("martial-cognize", 260);

        map_skill("force", "taixuan-gong");
        map_skill("dodge", "taixuan-gong");
        map_skill("unarmed", "taixuan-gong");
        map_skill("parry", "taixuan-gong");
        map_skill("strike", "bizhen-qingzhang");
        map_skill("blade", "jinwu-daofa");
        map_skill("sword", "taixuan-gong");

        prepare_skill("unarmed", "taixuan-gong");

        set_temp("apply/attack", 100);
        set_temp("apply/defense", 100);
        set_temp("apply/dodge", 100);
        set_temp("apply/damage", 120);
        set_temp("apply/unarmed_damage", 100);

        set("chat_chance_combat", 120);
        set("chat_msg_combat", ({
                (: perform_action, "unarmed.jing" :),
                (: exert_function, "recover" :),
                (: exert_function, "powerup" :),
                (: exert_function, "shield" :),
        }) );

        set("inquiry", ([
                "ʯ����" : "�����ҵ��ֵܣ���������Ħ���¡�",
                "����"   : "ѽ����������������ðɡ�",
                "л�̿�" : "�ϲ������Ǹ����˰���",
                "������" : "�Ҿ��ǹ����֣�������ʲô����",
                "���͵�" : "�ǡ������桭������㻹�Ǳ���Ϊ�á�",
                "ʷ����" : "������ʦ��ѽ��Ҳ��֪����������ô���ˡ�",
                "̫����" : "�ҡ��Ҳ�֪�������������ҡ�",
                "̫����" : "�ҡ��Ҳ�֪�������������ҡ�",
        ]));

        create_family("������", 2, "���ŵ���");
        setup();

        carry_object("/clone/misc/cloth")->wear();
        carry_object("/clone/weapon/gangjian")->wield();

        if (random(8) == 1)
                set_temp("handing", carry_object("/d/xiakedao/obj/jiu"));
}

void init()
{
        object ob;

        ::init();
        if (interactive(ob = this_player())
           && ! is_fighting()
           && random(3) == 1)
        {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

void greeting(object ob)
{
        if (! objectp(ob)
           || environment(ob) != environment())
                return;

        say(HIW "\nֻ��ʯ������ϥ�������ϣ����������ȽȽ���������ķ���\n" NOR);

        return;
}

void attempt_apprentice(object ob)
{
        command("ah");
        command("say �ǲ��ɣ��ǲ��ɡ����Լ�����ûѧ���ء�");
}

void unconcious()
{
        die();
}

