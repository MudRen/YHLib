// shanzheng.c ����

#include <ansi.h>
#include <quest.h>

inherit NPC;

void create()
{
        set_name("����", ({ "shan zheng", "shan" }));

        set("gender", "����");
        set("age", 62);
        set("long", "����̬���࣬��ò���ϣ�����һ��ͯ�պ׷���\n");
        set("attitude", "peaceful");
        set("title", "̩ɽ���ұ�");
        set("nickname", HIR "�����й�" NOR);

        set("str", 35);
        set("int", 36);
        set("con", 31);
        set("dex", 30);

        set("chat_chance_combat", 120);
        set("chat_msg_combat", ({
                (: perform_action, "blade.duan" :),
                (: perform_action, "unarmed.zhen" :),
                (: exert_function, "recover" :),
                (: exert_function, "powerup" :),
        }));

        set("inquiry", ([
                "�����й�" : "���ǽ������Ѹ����µĳƺţ���Ц�ˡ�",
                "����" : "û���������ˣ���ô���������£�",
                "��" : "����İ��ӣ�",
                "�а�" : "����İ��ӣ�",
        ]));

        set("shen_type", 1);

        set("qi", 3000);
        set("max_qi", 3000);
        set("jing", 1500);
        set("max_jing", 1500);
        set("neili", 4500);
        set("max_neili", 4500);
        set("jiali", 50);

        set("combat_exp", 800000);
        set("score", 5000000);

        set_skill("force", 150);
        set_skill("huntian-qigong", 150);
        set_skill("dodge", 160);
        set_skill("feiyan-zoubi", 150);
        set_skill("parry", 150);
        set_skill("blade", 150);
        set_skill("unarmed", 150);
        set_skill("taiji-quan", 150);
        set_skill("wuhu-duanmendao", 150);

        map_skill("force", "huntian-qigong");
        map_skill("dodge", "feiyan-zoubi");
        map_skill("parry", "taiji-quan");
        map_skill("blade", "wuhu-duanmendao");

        set_temp("apply/attack", 200);
        set_temp("apply/defense", 200);
        set_temp("apply/damage", 800);
        set_temp("apply/unarmed_damage", 800);

        setup();

        if (! clonep(this_object()))
        {
                move("/d/taishan/daizong");
                message_vision(CYN "\n$N" CYN "���˹������������ܣ�һ��"
                               "��̾��\n" NOR, this_object());
                set("startroom", "/d/taishan/daizong");
        }
        carry_object("/clone/weapon/gangdao")->wield();
        carry_object("/clone/cloth/cloth")->wear();
}

varargs int move(mixed dest, int raw)
{
        int r;

        // ִ��ԭ����MOVE����
        r = ::move(dest, raw);

        if (objectp(query_temp("run_ob")))
        {
                // ����ִ�����񣬲쿴�Ƿ��˵ص�
                remove_call_out("give_intercession");
                call_out("give_intercession", 2);
        }

        return r;
}

mixed accept_ask(object who, string topic)
{
        object *obs;
        object follow;
        object run_ob;

        obs = filter_array(children("/clone/quest/judge"),
                           (: $1->name() == $(topic) :));
        if (sizeof(obs) > 0)
        {
                if (who->query("weiwang") < 5000)
                        return "������һ�������ȻҲ���𽭺��ϵ��������ˣ�";

                follow = query_leader();

                if (objectp(follow)
                   && environment(follow) == environment(this_object()))
                {
                        // ���ڸ�������һ���ˣ��쿴��ǰִ��
                        // ������
                        run_ob = query_temp("run_ob");

                        if (follow == who)
                        {
                                // ����ľ���Ŀǰ���ʵ���
                                if (! objectp(run_ob))
                                {
                                        // ����ԭ�ȵ�����ȡ���ˣ�����
                                        // ���Ը���һ������
                                        set_temp("run_ob", obs[0]);

                                        // ȡ�����ػ��ǵ���Ķ�ʱ����
                                        remove_call_out("do_back");
                                        remove_call_out("give_intersession");

                                        // �ķ����Ժ�������״̬
                                        remove_call_out("cancel_follow");
                                        call_out("cancel_follow", 240);
                                        return "�ðɣ��ղ��Ǽ�������˵Ҳ���ˣ����Ǿͻ����ɣ�";
                                }

                                // ����ľ��Ƿ�������
                                return "���ǿ��߰ɣ�����Ҫ��" +
                                       run_ob->name() + "ô����ĥ���ˡ�";
                        }

                        if (run_ob == obs[0])
                                // ������ѯ����ͬ������
                                return "���������Ǻ�" + follow->name() +
                                       "ȥ������µģ�����������ˡ�";

                        if (objectp(run_ob))
                                // ������ѯ�ʲ�ͬ������
                                return "������Ҫ��" + follow->name() +
                                       "ȥ��" + run_ob->name() + "�����ȵȵȰɡ�";

                        message_vision(CYN "$N" CYN "��ͷ��$n" CYN "��������˵���Ǽ�����"
                                       "�Ѿ����ˣ��������ˡ�\n" NOR, this_object(), follow);
                }

                // ������û�и�˭��
                message_vision(CYN "$N" CYN "���ͷ����$n" CYN "����������Ҳ"
                               "���ж��ţ��ͺ�����һ�˰ɣ�\n" NOR,
                               this_object(), who);

                set_temp("run_ob", obs[0]);
                command("follow " + who->query("id"));

                // ȡ�����ػ��ǵ���Ķ�ʱ����
                remove_call_out("do_back");
                remove_call_out("give_intersession");

                // �ķ����Ժ�������״̬
                remove_call_out("cancel_follow");
                call_out("cancel_follow", 240);
                return 1;
        }

        switch (random(3))
        {
        case 0:
                return "Ҫ����˵�Ķ��в���֮�£������Ը����ң�"
                       "������˵�������ʵ�ڲ�̫�����";
        case 1:
                return RANK_D->query_respect(who) + "����˵��"
                       "������Ҳ�̫�������";
        default:
                return "��ֻ���˶ϰ����ǣ���˵�����������ɶ���飿";
        }
}

// �ж��Ƿ�������Ҫ����
void give_intercession()
{
        object run_ob;
        object npc1;
        object npc2;
        object me;
        int npc1_present, npc2_present;
        int percent;
        string msg;

        if (! objectp(run_ob = query_temp("run_ob")))
                // ����û�е�������
                return;

        npc1 = run_ob->query("npc1");
        npc2 = run_ob->query("npc2");
        npc1_present =  (objectp(npc1) && environment(npc1) == environment());
        npc2_present =  (objectp(npc2) && environment(npc2) == environment());
                
        if (! npc1_present || ! npc2_present)
                // �������û����Ҫ�������
                return;

        if (! npc1_present)
        {
                // ֻ��NPC2
                message_vision(CYN "$N" CYN "���˿����ܣ�ҡͷ����ֻ��" +
                               npc2->name() + CYN "һ�����ˣ�������ʲô"
                               "���һ����߰ɣ�\n" NOR, this_object());
                set_leader(0);
                call_out("do_back", 1);
                return;
        }

        if (! npc2_present)
        {
                // ֻ��NPC1
                message_vision(CYN "$N" CYN "���˿����ܣ�ҡͷ����ֻ��" +
                               npc1->name() + CYN "һ�����ˣ�������ʲô"
                               "���һ����߰ɣ�\n" NOR, this_object());
                set_leader(0);
                call_out("do_back", 1);
                return;
        }

        me = query_leader();
        message("vision", HIC + sort_msg(name() + "���˿�" + npc1->name() +
                          HIC "��" + npc2->name() + HIC "��ҡҡͷ���ȵ�����"
                          "�Ҷ���������ʿ���ο�Ϊ��ЩС����ִ���ݣ�û��ʧ��"
                          "���棡\n" NOR), environment());

        message("vision", HIY "\n" + name() + HIY "��ʼȰ˵������ˣ�������"
                          "��������ͷ���������������ҷ�����\n" NOR,
                          environment());
        if (objectp(me))
        {
                tell_object(me, WHT "������" + name() + WHT "����Ļ����"
                                "�ǵ����ۼ������ķ��ڷ������ɵð�����ο��"
                                "\n\n" NOR);

                percent = 30000 * 100 / (random(me->query("weiwang") + 1) + 30000);
                GIFT_D->bonus(me, ([ "exp" : 300 + random(250),
                                     "pot" : 200 + random(150),
                                     "score" : 10 + random(10),
                                     "weiwang" : 10 + random(20),
                                     "percent" : percent,
                                     "prompt"  : "ͨ�����Ϊ�˵������" ]));

                CHANNEL_D->do_channel(this_object(), "rumor", "��˵" + 
                                      me->name(1) + "(" + me->query("id") +
                                      ")�뵽�����й�" + name() + HIM "Ϊ" +
                                      npc1->name() + HIM "��" + npc2->name() +
                                      HIM "�ɹ��ĵ����˾��ס�" NOR);

                // ����Ϊ�����жϵ���������
                if (me->query("quest/freequest") > 0)
                        GIFT_D->delay_freequest_bonus(me);
        }

        delete_temp("run_ob");
        set_leader(0);
        run_ob->change_status(QUEST_FINISH);
        remove_call_out("cancel_follow");
        call_out("do_back", 2);
}

// ֹͣ����
void cancel_follow()
{
        object ob;

        // ȥ����������������Ϣ
        delete_temp("run_ob");

        // ����û����·�ģ�ֱ�ӷ���
        if (! objectp(ob = query_leader()))
        {
                call_out("do_back", 1);
                return;
        }

        // ���ٸ���
        set_leader(0);
        message_vision(CYN "$N" CYN "̾�����ҿ���Ҳ�����Ժ����ģ���"
                       "�ˣ��һ��������˰ɣ��Ժ�������˵��\n" NOR,
                       this_object());
        call_out("do_back", 1);
}

// ����
void do_back()
{
        string startroom;

        if (! stringp(startroom = query("startroom")))
                return;

        if (! living(this_object()))
        {
                call_out("do_back", 10);
                return;
        }

        if (is_fighting())
        {
                message_vision(CYN "$N" CYN "��Ȼ���֣������Ϸ��ܷ���"
                               "�ˣ����ˣ�\n\n" HIC "$N" HIC "�������䣬"
                               "�ͼ���ææ�����ˣ��㲻�ɵ�һ���\n" NOR,
                               this_object());
        } else
                message_vision(HIC "$N" HIC "̾�˿�����ͷҲ���ص����ˡ�"
                               "\n" NOR, this_object());

        // ���عʵ�
        move(startroom);
        message("vision", name() + "���˹�����\n", environment());
}

void unconcious()
{
        die();
}

void die()
{
        mapping my;
        string startroom;

        if (! stringp(startroom = query("startroom")))
                return;

        clear_condition(0);

        my = query_entire_dbase();
        my["eff_jing"] = my["max_jing"];
        my["jing"]     = my["max_jing"];
        my["eff_qi"]   = my["max_qi"] * 2 / 3;
        my["qi"]       = my["eff_qi"];
        my["neili"]    = my["max_neili"] * 2;

        message_vision(HIW "\n$N" HIW "Ż��һ����Ѫ���ȵ����ã����֣�����"
                       "������������\n\n" NOR, this_object());
        message("vision", name() + "����һ�ݣ���ʱ�㲻������Ӱ��\n",
                          environment());

        if (find_object(query("startroom")) != environment())
        {
                move(startroom);
                message("vision", name() + "���˹�����\n", environment());
        } else
                destruct(this_object());
}
