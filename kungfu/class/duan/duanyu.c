// duanyu.c ����

#include <ansi.h>

inherit NPC;

void create()
{
        set_name("����", ({"duan yu", "duan", "yu"}));
        set("gender", "����");
        set("title", "���������");
        set("age", 22);
        set("long", "����һ�����������������ӡ������Լ⣬��һ�������Ĵ�����\n");
        set("attitude", "peaceful");
        set("class", "royal");
        
        set("str", 21);
        set("int", 36);
        set("con", 32);
        set("dex", 29);

        set("chat_chance", 1);
        set("chat_msg", ({
                CYN "����̾�˿������������ϰ�������ô���£�\n" NOR,
        }));

        set("inquiry", ([
                "����" : "�����Ǹ��õط���ɽ��ˮ�㣬�羰���ˡ�\n",
                "������" : "����������ֻ������磬������û���ҷ������\n",
                "��ʦ" : "�š����ҵ�ʦ�������ӡ����Ӻ�ׯ�ӣ����ǵ�ѧ���һ�ûѧȫ�ء�\n",
        ]));

        set("qi", 5000);
        set("max_qi", 5000);
        set("jing", 2500);
        set("max_jing", 2500);
        set("neili", 9000);
        set("max_neili", 9000);
        set("jiali", 150);

        set("combat_exp", 1500000);

        set_temp("apply/damage", 50);
        set_temp("apply/defense", 50);

        set_skill("force", 280);
        set_skill("beiming-shengong", 280);
        set_skill("finger", 280);
        set_skill("liumai-shenjian", 280);
        set_skill("dodge", 280);
        set_skill("lingbo-weibu", 280);
        set_skill("parry", 200);
        set_skill("chess", 200);
        set_skill("buddhism", 280);
        set_skill("literate", 280);
        set_skill("lamaism", 280);
        set_skill("jingluo-xue", 240);
        set_skill("martial-cognize", 200);

        map_skill("force", "beiming-shengong");
        map_skill("dodge", "lingbo-weibu");
        map_skill("parry", "liumai-shenjian");
        map_skill("finger", "liumai-shenjian");

        prepare_skill("finger", "liumai-shenjian");

        set("chat_chance_combat", 120);
        set("chat_msg_combat", ({
                (: perform_action, "finger.six" :),
                (: perform_action, "finger.zhongheng" :),
                (: exert_function, "recover" :),
                (: exert_function, "powerup" :),
        }));

        set_temp("apply/attack", 150);
        set_temp("apply/defense", 150);
        set_temp("apply/unarmed_damage", 150);

        setup();

        carry_object("/clone/misc/cloth")->wear();
}

void help_girl(object me)
{
        object wang;
        string msg;

        if (! living(this_object()))
                return;

        command("say �������ӣ���Ҫ���ţ����Ҷ����ڴˣ�");

        switch (me->query("gender"))
        {
        case "����":
                msg = "��λ" + RANK_D->query_respect(me) +
                      "����������˺��ģ���ô���˵�������Ҳ�µ����֣�";
                break;
        case "Ů��":
                msg = "��λ" + RANK_D->query_respect(me) +
                      "����Ī�Ƕʼ��˼���ò�������´˶��֣�";
                break;
        default:
                msg = "��λ" + RANK_D->query_respect(me) +
                      "����˵����Ȼ���в�Ů����ô����Ů���ӵ����⣿";
                break;
        }        
        command("say " + msg);

        if (wang = present("wang yuyan"))
        {
                if (living(wang))
                        message_vision(HIW "\n$N" HIW "��æ��ס$n" HIW "��������"
                                       "��\n$n" HIW "�������ɣ��ҿ����书������"
                                       "����ָ������������\n" NOR, this_object(), wang);
                else
                        message_vision(HIW "\n$N" HIW "һ��§ס$n" HIW "�����ڻ�"
                                       "�С�\n" NOR, this_object(), wang);

                me->remove_enemy(wang);
                wang->move(this_object());
                remove_call_out("check_enemys");
                call_out("check_enemys", 1, wang);
        }

        kill_ob(me);
}


int accept_fight(object me)
{
        command("say ��ѽѽ���л��ú�˵����Ҫ�Ͷ����");
        return 0;
}

int accept_hit(object me)
{
        command("say ��������ô���£���ôͻȻ�Ͷ��ִ����أ���");
        return 1;
}

int accept_kill(object me)
{
        command("say ���˷��ˣ�����ͷ��������û�У�");
        return 1;
}

void unconcious()
{
        object wang;

        command("say �������ӡ���");

        if (wang = present("wang yuyan", this_object()))
        {
                wang->move(environment());
                message_vision(HIW "\n$N" HIW "��$n" HIW "���ϵ�����������"
                               "ʧɫ���������ɣ����ɣ�����ô������\n" NOR, wang,
                               this_object());
        }

        ::unconcious();
}

void die()
{
        object wang;

        if (wang = present("wang yuyan", this_object()))
        {
                wang->move(environment());
                message_vision(HIW "$N" HIW "��$n" HIW "���ϵ�����������ʧ"
                               "ɫ���������ɣ����ɣ�����ô���˰���\n" NOR, wang,
                               this_object());
        }

        ::die();
}

void check_enemys(object wang)
{
        if (! objectp(this_object()) || ! objectp(wang))
                return;

        if (! living(this_object()))
                return;

        if (is_fighting() && random(5) == 0 && living(wang))
        {
                message_vision(HIW "\n��������$N" HIW "�������ֹ�����˵Щ����\n"
                               NOR, this_object());
                add_temp("apply/damage", 10);
                add_temp("apply/defense", 10);
                receive_curing("qi", 300);
                receive_curing("jing", 150);
                receive_heal("qi", 300);
                receive_heal("jing", 150);
        }

        if (! is_fighting())
        {
                set_temp("apply/damage", 50);
                set_temp("apply/defense", 50);
                if (! living(wang))
                {
                        command("say ���º��ˣ��ҵ��������Ӳ����ܾ��ˡ�");
                        return;
                }
                message_vision(HIW "$n" HIW "��$N" HIW "�������ˣ��������ˣ���"
                               "�����ɡ�\n$N" HIW "�����������İ�$n" HIW "��"
                               "��������\n" NOR, this_object(), wang);
                wang->move(environment(this_object()));
                return;
        }

        remove_call_out("check_enemys");
        call_out("check_enemys", 1, wang);
}
