// person used in quest

#include <ansi.h>

inherit CLASS_D("generate") + "/chinese";

int  accept_object(object who, object ob);

void random_move();
int  leave();
int  is_stay_in_room()  { return 1; }

void create()
{
        ::create();
        set("gender", "����");
        set("age", 30 + random(30));
        set("long", "");
        set("attitude", "friendly");
        set("chat_chance", 30);
        set("chat_msg", ({ (: random_move :) }));
        set("chat_chance_combat", 120);
        set("scale", 150);
        set("no_get", 1);

        set_temp("apply/armor", 100);
        set_temp("apply/damage", 15);
        set_temp("born_time", time());
          set_temp("dest_time", 1200 + time());

        add_money("silver", 10 + random(20));

        if (clonep()) keep_heart_beat();
}

void set_from_me(object me)
{
        int exp;
        mapping my;

        NPC_D->init_npc_skill(this_object(), NPC_D->check_level(me));
        my = query_entire_dbase();

        if (my["max_qi"] > 6000)
                my["max_qi"] = 6000;

        if (my["max_jing"] < my["max_qi"] / 2)
                my["max_jing"] = my["max_qi"] / 2;

        if (my["max_jing"] > 3000)
                my["max_jing"] = 3000;

        my["eff_jing"] = my["max_jing"];
        my["jing"] = my["max_jing"];
        my["eff_qi"] = my["max_qi"];
        my["qi"] = my["max_qi"];
        my["quest_count"] = me->query("quest_count");

        exp = me->query("combat_exp") * 11 / 10;
        if (exp > query("combat_exp"))
                set("combat_exp", exp);


        if (my["combat_exp"] > 200000 && random(100) < 5)
        {
                // ���� > 200K��5%���ʳ��ֶ������
                set_temp("multi-enemy", 1);
        }


        my["jiali"] = query_skill("force") / 3;
        if (query("place") == "����")
                set_temp("dest_time", 900 + time());
        else
                set_temp("dest_time", 600 + time());
}

void kill_ob(object ob)
{
        int lvl;

        if (! is_busy())
                exert_function("powerup");

        if (ob->query("quest/id") != query("id"))
        {
                ::kill_ob(ob);
                return;
        }

        ::kill_ob(ob);
}

int filter_to_bonus(object ob, object aob)
{
        if (! playerp(ob) || ! living(ob) ||
            ! ob->is_killing(query("id")))
                // ��������Ҳ��Ҳ�����ɱ��(NPC)
                return 0;

        // Э���Ķ���һ��
        return (aob == ob->query_temp("quest/assist"));
}

// remove
void remove()
{
        object qob;

        if (objectp(qob = query_temp("quest_ob")))
                // ������Ѿ���ʧ�ˣ�ȡ�������������
                destruct(qob);

        ::remove();
}



// �漴���·���
void random_place(string msg)
{
        object old_env;
        object qob;
        string *not_place;
        string new_place;
        int limit;
        int qcount;

        // ���ԭ�ȴ��������񣬾�ֱ���޸���Ϣ
        if (objectp(qob = query_temp("quest_ob")))
                qob->set("introduce", msg);
        else
                qob = new("/clone/quest/avoid");

        // �漴ѡ������һ���ط�����NPC
        old_env = environment();
        not_place = ({ query("place") });

        if (query("combat_exp") < 500000)
                not_place += ({ "����һ��" });

        if (query("combat_exp") < 800000)
                not_place += ({ "����" });

        NPC_D->place_npc(this_object(), not_place);

        // ���ݸ�ʽ����Ϣ���ɽ��
        msg = replace_string(msg, "$N", name(1));

        qcount = query("quest_count");
        if ((qcount < 100 || qcount >= 900) && random(10) ||
            (qcount >= 100 && qcount < 900) && random(50))
        {
                new_place = query("place");
                if (new_place == "����")
                        limit = 1800;
                else
                        limit = 1200;
        } else
        {
                new_place = "��Զ�ĵط�";
                limit = 1800;

                // ���ٴ����ļ۸�
                set("ask_cheap", 3);
        }
        set_temp("dest_time", limit + time());
        msg = replace_string(msg, "PLACE",  new_place);

        // ��ʼ������¼�������
        qob->set("introduce", msg);
        qob->init_quest(name(1), old_env);
        set_temp("quest_ob", qob);

        return;
}

// �ε���ʱ���л�������
void unconcious()
{
        object *obs;
        object ob;
        mapping my;
        string msg;
        string quester;

        if (! query_temp("is_helper") && ! query_temp("help_ob"))
        {
                  if (random(100) < 8)
                {
                        // 10%��������
                        switch (random(8))
                        {
                        case 0:
                                msg = HIC "$N" HIC "���һ�������¼�"
                                      "����Ѫ���ۿ����Ѳ�֧����Ȼһ"
                                      "����Ӱ�ܳ��������������У���"
                                      "��$n" HIC "��ֻ����ôһ˲�䣬"
                                      "�����Ѿ�����$N" HIC "�����Ӷ�"
                                      "�ߣ���Ȼδ�����ۼ���\n" NOR;
                                break;
                        case 1:
                                msg = HIC "$N" HIC "ҡҡ��׹���ۿ���"
                                      "Ҫ��������Ȼ�������һ����Ѫ"
                                      "��$n" HIC "��æ����һ�ܣ�����"
                                      "��ʱ��$N" HIC "��Ȼ��������"
                                      "����һ�ݣ���ȻƮ��ʮ����֮Զ"
                                      "������Ŀ�ɿڴ���ֻ��$N" HIC
                                      "ɲ�����һ����Ӱ��������ʧ��"
                                      "\n" NOR;
                                break;
                        case 2:
                                msg = HIC "��$n" HIC "һ���֮�£�"
                                      "$N" HIC "ֻ���м�֮�������ﻹ"
                                      "�л���֮�����ۿ���Ҫ��ɥ$n" HIC
                                      "֮�֣�$N" HIC "��Ȼ��ʽһ�䣬"
                                      "�����޷����������Ϻ�����$n" HIC
                                      "��һ�����ѱ�$N" HIC "������"
                                      "�б��ˣ�ֻ��$N" HIC "������"
                                      "���Ӷݶ��ߡ�\n" NOR;
                                break;
                        case 3:
                                msg = HIC "ֻ��$N" HIC "����һ����"
                                      "����ɫ��΢����һЩ����Ȼ�ŷ�"
                                      "�����춯�ص�һ�����ֱ���"
                                      "$n" HIC "��������������һ��"
                                      "��$N" HIC "����һת��ƮȻ��"
                                      "ȥ������$n" HIC "���ֲ�����"
                                      "׷�ϲ��ϣ�\n" NOR;
                                break;
                        case 4:
                                msg = HIC "$n" HIC "�����������ۿ�"
                                      "��Ҫ���֣��������У���$N" HIC
                                      "���Ǳ��޿ɱܣ����޿��ˣ�$N"
                                      HIC "��ɫ��ɫ�ֻʣ����м��͵�"
                                      "ҧ����⣬���ۡ����³���$n"
                                      HIC "ֻ����ǰһ�����������"
                                      "ɢȥ�����ﻹ��$N" HIC "��Ӱ"
                                      "�ӣ�\n" NOR;
                                break;
                        case 5:
                                msg = HIC "$N" HIC "����һ����ȴ��"
                                      "��С�����������У�һ����"
                                      "�������ѵ�����$n" HIC "��״"
                                      "����ǰȥ����Ȼ��ǰ�ǹ�����"
                                      "���ֻ��¼��ˣ�ֻ�����˹���"
                                      "��Ц������$N" HIC "Ī�ţ���"
                                      "��Ҳ����˵������һ���֣���"
                                      "ʮ������ɳ�������$n" HIC
                                      "�ֵ����£����������$N" HIC
                                      "��ȥ�ˡ�\n" NOR;
                                break;
                        case 6:
                                msg = HIC "$N" HIC "�������£���Ȼ"
                                      "������$n" HIC "��ס��ʽ��Ц��"
                                      "����$N" HIC "���㡭��������δ"
                                      "�䣬����$N" HIC "��Ĵ���һ"
                                      "��ֱ��$n" HIC "��Ҫ����$n" HIC
                                      "���һ������æ�мܣ�ֻ������"
                                      "Ϣ���ң�����Ż�£�$N" HIC "Ҳ"
                                      "��׷����ֻ�Ǽ������ߣ�$n" HIC
                                      "���˼�������ȥ����ǰ���ƣ�ȴ"
                                      "�Ѳ���$N" HIC "����Ӱ��\n" NOR;
                                break;
                        default:
                                msg = HIC "$N�����ˣ���Ȼ���У���"
                                      "�߼�ֻ����������һʱ���$n"
                                      HIC "�������ƣ������ٻ���$N"
                                      HIC "��Ȼ�����л��ɳˣ������"
                                      "�Ź����������У�ɱ��һ��Ѫ·"
                                      "���ʹ˲�����\n" NOR;
                                break;
                        }

                        clean_up_enemy();
                        obs = query_enemy();
                        if (sizeof(obs) > 0) ob = obs[0]; else ob = 0;
                        if (! objectp(ob))
                                msg = replace_string(msg, "$n", "����");
                        message_sort("\n" + msg, this_object(), ob);

                        // ���NPC���ж�״̬
                        clear_condition(0);

                        // �ָ�NPC������
                        my = query_entire_dbase();
                        my["eff_jing"] = my["max_jing"];
                        my["jing"]     = my["max_jing"];
                        my["eff_qi"]   = my["max_qi"] * 2 / 3;
                        my["qi"]       = my["eff_qi"];
                        my["neili"]    = my["max_neili"] * 2;
                        if (! intp(query_temp("escape_times")))
                                set_temp("escape_times", 1);
                        else
                                add_temp("escape_times", 1);

                        // �Ǽ�һ�������Ա���ҿ���׷�������м�
                        switch (random(9))
                        {
                        case 0:
                                msg = "��˵$N���˴������ߣ���˵�Ƕ㵽PLACEȥ�ˡ�";
                                break;
                        case 1:
                                msg = "��˵$N���˶��֣���㱻������������"
                                      "���ǽ��������ˣ�����ȥ��PLACE��";
                                break;
                        case 2:
                                msg = "��˵��$N����һ��Ѫս�������ȫ��"
                                      "���ˣ�������ȥ��PLACE�ɡ�";
                                break;
                        case 3:
                                msg = "$N��˵����PLACE��������ǰһ�������������ġ�";
                                break;
                        case 4:
                                msg = "��˵$N���˴����˰ɣ��ף���������˵"
                                      "��PLACEҲ������ѽ��";
                                break;
                        case 5:
                                msg = "������Ҳ��̫�����������˵��������PLACE��";
                                break;
                        case 6:
                                msg = "��������ɶ����������PLACEô��";
                                break;
                        case 7:
                                msg = "ǰ��������������������أ�����Ӧ��"
                                      "��ȥ��PLACE�ɡ�";
                        default:
                                msg = "$Nѽ������˵��PLACE�������������������ˡ�";
                                break;
                        }

                        random_place(msg);
                        remove_all_enemy(1);
                        return;
                }
        }

        if (stringp(quester = query_temp("quester")))
        {
                // ����ҵ���ȡ��quest����
                if (objectp(ob = find_player(quester)))
                        ob->set_temp("quest/escape_times", query_temp("escape_times"));
        }
        ::unconcious();
}



// �������NPC������ʱ�򣬼���Ƿ���Խ��н���ĳЩ��ҡ�����
// �Ķ��󣺰�������������������������ˣ� ��Ȼ����Ҫ��ɱ��
// ��������������ɶ�����ξ�������������жԸ�NPC����ɱ
// �������Э�������������ߵ���ҡ�
void die(object killer)
{
        object *obs;            // ���������п��Խ�����
        object dob;             // �������NPC����
        object hob;             // Э����
        object aob;             // ��Э����
        int qlevel;             // ��������ĵȼ�
        int lvl;                // NPC�ĵȼ�
        int scale;              // NPC���еİ��ֺ����ܵĴ���
        int n;                  // ���Խ������˵���Ŀ
        int exp;                // ��Ҫ�Ϸֵľ���
        int pot;                // ��Ҫ�Ϸֵ�Ǳ��
        int weiwang;            // ��Ҫ�Ϸֵ�����
        int score;              // ��Ҫ�Ϸֵ�����
        int extra_exp;          // ���ε��˵Ķ��⾭��
        int extra_pot;          // ���ε��˵Ķ���Ǳ��
        string quester;         // ��Ҫ��������������ID
        object qob;             // ��Ҫ�������������Ҷ���

        // �ҵ�ɱ����(NPC)���Ǵ����ҵ���
        if (! objectp(dob = killer))
                dob = query_defeated_by();

        if (objectp(dob) && dob->query_temp("owner"))
                dob = dob->query_temp("owner");

        while (1)
        {
                // ��¼���������Ѿ���ֹ
                if (stringp(quester = query_temp("quester")))
                {
                        qob = UPDATE_D->global_find_player(quester);
                        if (qob->query("quest/id") == query("id"))
                                qob->set("quest/notice", "die");
                        UPDATE_D->global_destruct_player(qob, 1);
                }

                if (dob && dob->query("quest/id") == query("id"))
                        // ���Լ�������
                        break;

                if (dob) aob = dob->query_temp("quest/assist");
                if (aob && aob->query("quest/id") == query("id"))
                        // ��Э������ɱ����
                        break;

                // �����������߻�������������Э������ɱ�������¼֮��
                CHANNEL_D->do_channel(this_object(), "rumor",
                                      sprintf("��˵%s����ɱ���ˡ�", name()));
                log_file("static/killed_die", sprintf("%s %s(%s) died at %s because %s.\n",
                                                      log_time(), name(), query("id"),
                                                      environment()->short(),
                                                      dob ? sprintf("%s(%s)", dob->name(1), dob->query("id")) : "none"));

                break;
        }

        if (! aob) aob = dob;

        if (! aob)
        {
                // û���ҵ� QUEST ������
                ::die();
                return;
        }

        // �쿴Ŀǰ����ɱ�ҵ��ˣ��Ƿ�Ҳ��ֵ�ý�����
        obs = all_inventory(environment());
        obs = filter_array(obs, (: filter_to_bonus :), aob);

        if ((n = sizeof(obs)) > 0)
        {
                // ���Ҵ����ҵ��ˣ�����ɱ���ҵ���
                dob = query_defeated_by();

                // ���������أ��ܹ����������е��˷֣����ÿ
                // �˼���һ������������д�������˵���һ�
                // �ö����һЩ������
                lvl = NPC_D->check_level(this_object());
                exp = 15 + random(10) + lvl;
                pot = 9 + random(5) + lvl;
                weiwang = 8 + random(6) + lvl / 2;
                score = 9 + random(6) + lvl / 2;

                // �����������ĵȼ����н�������
                switch (aob->query("quest/level"))
                {
                case 1:
                        break;
                case 2:
                        exp += exp / 2;
                        pot += pot / 2;
                        weiwang += weiwang / 2;
                        score += score / 2;
                        break;
                case 3:
                        exp += exp;
                        pot += pot;
                        weiwang += weiwang;
                        score += score;
                        break;
                default:
                        exp = exp / 2 + 1;
                        pot = pot / 2 + 1;
                        weiwang = weiwang / 2 + 1;
                        score = score / 2 + 1;
                        break;
                }
                // ���NPC�����˰��֣�����Ի�ö��⾭��
                if ((scale = sizeof(query_temp("help_count") +
                     query_temp("escape_times") * 2)) > 0)
                {
                        exp += exp * scale / 2;
                        pot += pot * scale / 2;
                }
                // �����˾��־��飺Ϊʲô����n + 2��������Ϊ
                // �����ҵ��˷����ݾ��飬������n + 1���ټ���
                // ��������������1����ô����n + 2��
                exp = exp / (n + 2) + 1;
                pot = pot / (n + 2) + 1;
                weiwang = weiwang / (n + 2) + 1;
                score = score / (n + 2) + 1;

                // ��������ҵĶ��⽱��
                if (objectp(dob) && member_array(dob, obs) != -1)
                {
                        extra_exp = 1 + random(exp);
                        extra_pot = 1 + random(pot);
                        if (dob->query("combat_exp") < query("combat_exp") / 2)
                        {
                                // ���ֵ����书�Ƚϵͣ���õĶ��⽱����
                                extra_exp *= 2;
                                extra_pot *= 2;
                        } else
                        if (dob->query("combat_exp") > query("combat_exp") * 2)
                        {
                                // ���ֵ����书̫�ߣ���õĶ��⽱����
                                extra_exp /= 2;
                                extra_pot /= 2;
                        }
                }

                // ���н���
                foreach (hob in obs)
                {
                        // �����ӳٽ�����Ϊʲô��ô���ã��ܼ򵥣�
                        // ��Ϊ��ϣ������ڿ���NPC�����Ժ���ܹ�
                        // ����������
                        GIFT_D->delay_bonus(hob, ([ "exp"     : exp + random(4) +
                                                    ((hob == dob) ? extra_exp : 0),
                                                    "pot"     : pot + random(3) +
                                                    ((hob == dob) ? extra_pot : 0),
                                                    "weiwang" : weiwang + random(3),
                                                    "score"   : score + random(3),
                                                    "prompt"  : "����" + name() + "֮��" ]));
                }
        }

        // ��������
        ::die();

        return ;
}

int accept_fight(object ob)
{
        command("say �ã����ǾͱȻ��Ȼ���");
        kill_ob(ob);
        return 1;
}

int accept_hit(object ob)
{
        command("say ����ȥ�ɣ�");
        kill_ob(ob);
        return 1;
}

int accept_kill(object ob)
{
        command("say �ߣ�������");
        return 1;
}

void random_move()
{
        if (query_temp("is_helper"))
        {
                // is a helper
                if (! environment())
                {
                        // not in environment? unavaliable npc.
                        destruct(this_object());
                        return;
                }

                if (! query_temp("help_who"))
                {
                        // owner is killed. destruct this helper
                        if (! living(this_object()))
                                message_vision("$N���������˹�����\n",
                                               this_object());
                        
                        message_vision("$N�������ܣ����Ҵҵ������ˡ�\n",
                                       this_object());
                        destruct(this_object());
                        return;
                }

                // move with owner
                return;
        }

        if (time() > query_temp("dest_time"))
        {
                message_vision("$N����ææ�����ˡ�\n", this_object());
                CHANNEL_D->do_channel(this_object(), "rumor",
                                      sprintf("��˵%s���ӵ�����ɽ���󣬴Ӵ˲��ٳ�û�����䡣", name()));
                log_file("static/killed_die", sprintf("%s %s(%s) vanished because timeout(%d:%d).\n",
                                                      log_time(), name(), query("id"),
                                                      time() - query_temp("born_time"),
                                                      query_temp("dest_time") - query_temp("born_time")));
                destruct(this_object());
                return;
        }
          NPC_D->random_move(this_object());
}
