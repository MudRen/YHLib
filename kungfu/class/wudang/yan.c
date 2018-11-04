#include <ansi.h>
#include "wudang.h"

inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("�����", ({ "yu daiyan", "yu" }));  
        set("nickname", HIC "�䵱����" NOR);
        set("long", "�����������������������ҡ�ֻ������\n"
                    "һ���ɸɾ����Ļ�ɫ���ۣ��������ʮ����\n"
                    "���ݳ����񵭳�ͣ���Ĭ���ԡ�\n");
        set("gender", "����");
        set("age",43);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 29);
        set("int", 28);
        set("con", 31);
        set("dex", 25);
        
        set("max_qi", 5500);
        set("max_jing", 4000);
        set("neili", 6500);
        set("max_neili", 6500);
        set("jiali", 160);
        set("combat_exp", 1500000);
        set("score", 50000);

        set_skill("force", 240);
        set_skill("wudang-xinfa", 240);
        set_skill("taiji-shengong", 220);
        set_skill("dodge", 240);
        set_skill("tiyunzong", 240);
        set_skill("unarmed", 240);
        set_skill("taiji-quan", 220);
        set_skill("strike", 240);
        set_skill("wudang-zhang", 240);
        set_skill("hand", 240);
        set_skill("paiyun-shou", 240);
        set_skill("parry", 240);
        set_skill("sword", 240);
        set_skill("wudang-jian", 240);
        set_skill("taiji-jian", 240);
        set_skill("taoism", 220);
        set_skill("literate", 200);
        set_skill("martial-cognize", 200);

        set("no_teach", ([
                "taiji-shengong" : "Ҫ��ѧϰ̫����������������̡�",
                "taiji-jian"     : "̫���������������״���",
                "taiji-quan"     : "̫��ȭ�����������״���",
        ]));

        map_skill("force", "taiji-shengong");
        map_skill("dodge", "tiyunzong");
        map_skill("unarmed", "taiji-quan");
        map_skill("parry", "taiji-quan");
        map_skill("sword", "taiji-jian");
        map_skill("strike", "wudang-zhang");

        prepare_skill("unarmed", "taiji-quan");
        prepare_skill("strike", "wudang-zhang");

        create_family("�䵱��", 2, "����");

        set("chat_chance_combat", 120);
        set("chat_msg_combat", ({
                (: perform_action, "sword.chan" :),
                (: perform_action, "sword.jia" :),
                (: perform_action, "sword.sui" :),
                (: perform_action, "sword.zhuan" :),
                (: perform_action, "unarmed.zhen" :),
                (: perform_action, "unarmed.zhan" :),
                (: perform_action, "unarmed.ji" :),
                (: perform_action, "unarmed.yin" :),
                (: exert_function, "shield" :),
                (: exert_function, "powerup" :),
                (: exert_function, "recover" :),
        }) );

        setup();

        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/d/wudang/obj/greyrobe")->wear();

}

void init()
{
        object ob;

        ::init();
        if (interactive(ob = this_player()) && ! is_fighting())
        {
                remove_call_out("greeting");
                call_out("greeting", 2, ob);
        }
}

void greeting(object ob)
{
        int i;

        if (! objectp(ob) || environment(ob) != environment())
                return;

        if ((int)ob->query_skill("wudang-xinfa", 1) == 0)
        {
                message_vision(CYN "���а��Ե��Ӷ�$N" CYN "�����ȵ��������"
                               "аħ������������佣��\n\n" NOR, ob);
                ob->set("eff_qi", 1);
                ob->set("qi", 1);
                message_vision(HIR "ֻ�����佣���ʱ��������̨�Ͻ����ݺᣬ��$N"
                               HIR "Χ�����롣ʮ��\n�����а��Ե��ӵ�ʮ���ڳ���"
                               "�����˲����$N" HIR "���ϻ�����ʮ����\n���ӣ�"
                               "��ʱ��Ѫ���졣\n\n" NOR, ob);

                say(CYN "���������ŭ�ݣ��ȵ���аħ�����Ҳ�Ҵ����佣��\n");
                message_vision(HIY "ֻ������ҾӸ����£�����һ�ư�$N" HIY
                                   "�����̨��\n\n" NOR, ob);
                ob->move("/d/wudang/nanyangong");
                CHANNEL_D->do_channel(this_object(), "chat", sprintf("%s˽��"
                                      "���佣������ɳ����ף�����һ����",
                                      ob->name(1)));
        }
}

void attempt_apprentice(object me)
{
        if (! permit_recruit(me))
                return;

        if ((int)me->query_skill("wudang-xinfa", 1) < 30)
        {
                command("say ���䵱�����ڼ��书���������ڹ��ķ���");
                command("say " + RANK_D->query_respect(me) +
                        "�Ƿ�Ӧ����̫�����϶��µ㹦��");
                return;
        }

        if ((int)me->query("shen") < 10000)
        {
                command("say ���䵱���������������ɣ��Ե���Ҫ���ϡ�");
                command("say �ڵ��з��棬" + RANK_D->query_respect(me) +
                        "�Ƿ����ò�����");
                return;
        }

        if ((int)me->query_skill("wudang-xinfa", 1) < 70)
        {
                command("say ���䵱����ע���ڹ��ķ�" + RANK_D->query_respect(me)+
                        "�Ƿ�Ӧ�����䵱�ķ��϶��µ㹦��?");
                return;
        }

        if ((int)me->query_skill("taoism", 1) < 70)
        {
                command("say ϰ����Ϊ��ǿ���壬һζ�������ǲ���ȡ�ģ�");
                command("say �ҿ��㻹��Ҫ���������Է�����������������"
                        "����ĵ����ķ���");
                return;
        }

        command("say �ðɣ��Ҿ��������ˡ�");
        command("recruit " + me->query("id"));
}

void unconcious()
{
        die();
}
