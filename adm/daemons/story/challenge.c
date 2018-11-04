// story:challenge ��ս

#include <ansi.h>

inherit F_CLEAN_UP;

// �ڲ�����
string show_time();
mixed  create_challenger();
mixed  master_opinion(int n);
mixed  continue_story(int n);
int    find_respond(object ob);

// �ⲿ���Ե��õĺ���
void   stop_story();
string cannot_respond(object ob);
void   respone_for_challenge(object me);

mixed *story = ({
        (: show_time :),
        "һ�����ص�����������ԭ����",
        (: create_challenger :),
        (: master_opinion, 1 :),
        (: master_opinion, 2 :),
        (: master_opinion, 3 :),
        (: master_opinion, 4 :),
});

#define NOT_READY                       0
#define CHALLENGER_IS_WAITING           1
#define NO_USER_CAN_RESPOND             2
#define CHALLENGER_KILLED_BY_ULTRA      3
#define CHALLENGER_IS_TOO_CHEAP         4
#define CHALLENGER_IS_FIGHTING          5

int stop;               // FLAG: �Ƿ���Ҫ��ֹ����
int too_cheap;          // FLAG: ���˵�ˮƽ�Ƿ�̫��(������ˮƽ��Ҷ���)
int next;               // continue_story�������ݸ�ֵ����
string accepted;        // Ӧս������
object cob;             // ��ս��
object rob;             // Ӧս��
object *ultra ;         // ����ʦ

string *too_cheap_msg = ({
        "$Nŭ����˭����ô˵��������ʲô�ˣ�",
        "���顱��һ����$N����÷��˳�ȥ���ۿ��ǻ���ˡ�",
        "��Ħ��ʦ������������",
});

string *fenco = ({
        "������", "����", "����", "������",
        "Ԭ����", "ˮ��", "����", "����ɺ",
        "����ͩ", "С��Ů",
});

string *fenmsg = ({
        "���죡$C�����죡",
        "�尡��$C���尡��$C��",
        "$C�����ͣ�$C���ͣ�",
        "$CŬ��ѽ���Ϳ��������",
        "$C��Ҫ�ˣ����ϳ壡���ͣ����ͣ����ͣ�",
});

string *menco = ({
        "���", "���˷�", "����", "����",
        "��־ƽ", "ΤС��", "�����", "�¼���",
        "���", "ʯ����", "���޼�", "Ԭ��־",
});

string *menmsg = ({
        "$N����Ҫ�£����Ϲ���",
        "$N������������ȭ�Ź����У�",
        "$N����������·�������̲��ȣ�",
        "$N�칥�����֣������ַ�Ӧ����",
        "$N�����칥�����֣��������������У�",
});

string prompt() { return HIR "�� ��  ս ��" NOR; }

void create()
{
        seteuid(getuid());
        stop = 0;
        too_cheap = 0;
        accepted = 0;
        cob = 0;
        rob = 0;
        ultra = 0;
}

mixed query_story_message(int step)
{
        if (stop) return 0;
        return step < sizeof(story) ? story[step] :
                                      continue_story(step - sizeof(story));
}

string show_time()
{
        return (random(2)) ? "��֪����֮�䣬ʱ�䵽��" + NATURE_D->game_time() + "��"
                           : "��������˵����͵���" + NATURE_D->game_time() + "��";
}

mixed create_challenger()
{
        object ob;

        ob = NPC_D->create_challenger();

        if (! ob)
        {
                stop_story();
                return "�����·�ˡ�";
        }

        ob->move("/d/city/guangchang");
        message("vision", ob->name() + "��ҡ��ڵ����˹���������һ����\n",
                          environment(ob));
        CHANNEL_D->do_channel(this_object(), "rumor", "��˵" +
                "��" + ob->query("nation") + "����һ������" +
                ob->name(1) + "���ˡ�");
        next = NOT_READY;
        cob = ob;
        return ob->name() + "��" + ob->challenge();
}

mixed master_opinion(int n)
{
        object ob;
        object *u;

        if (n == 1)
                ultra = NPC_D->query_ultra_master();

        ultra -= ({ 0 });
        if (! sizeof(ultra))
                ultra = NPC_D->query_ultra_master();

        if (! cob)
        {
                stop_story();
                return "��ô��ͻȻ�Զ�����һ���������ˣ�";
        }

        ob = ultra[random(sizeof(ultra))];
        ultra -= ({ ob });

        if (n < 4)
        {
                ob->force_me("chat " + cob->query("opinion/msg")[n - 1]);
                return 1;
        }

        u = filter_array(all_interactive(), (: find_respond :));
        if (! sizeof(u))
        {
                if (! too_cheap)
                {
                        ob->force_me("chat ��ϧ����ϧ�����ڽ����о�Ȼ"
                                     "��������ʰ���ˣ�");
                        next = NO_USER_CAN_RESPOND;
                        return 1;
                }

                if (cob->query("nation") == "�ձ�")
                {
                        ob->force_me("chat �ߣ����������ձ����ӣ���" +
                                     RANK_D->query_self(ob) + "һ�У�");
                        next = CHALLENGER_KILLED_BY_ULTRA;
                        return 1;
                }

                ob->force_me("chat ��������ԭ����ʰ����˶��ˣ����书"
                             "̫���ֵ�����˳��֣����ɣ�");
                next = CHALLENGER_IS_TOO_CHEAP;
                return 1;
        }

        if (sizeof(u) < 10)
        {
                ob->force_me("chat* sigh");
                ob->force_me("chat ��������ʰ���˵Ĺ�Ȼ���٣���������"
                             "��ȷ�������޼���");
        } else
        {
                ob->force_me("chat* heng");
                ob->force_me("chat �������������ܰ�ƽ�����˴������ڣ�");
        }
        message("vision", HIG + ob->name(1) + "�����㣺��β�����Ӧ"
                          "ս(accept)�������л��������磡\n", u);
        next = CHALLENGER_IS_WAITING;
        return 1;
}

mixed continue_story(int n)
{
        string msg;

        if (! cob)
                return 0;

        switch (next)
        {
        case CHALLENGER_IS_TOO_CHEAP:
                if (n >= sizeof(too_cheap_msg))
                {
                        stop_story();
                        return 0;
                } else
                        return replace_string(too_cheap_msg[n], "$N", cob->name(1));
                return;

        case CHALLENGER_KILLED_BY_ULTRA:
                cob->force_me("chat �˸�ѽ·��");
                CHANNEL_D->do_channel(this_object(), "rumor", "��˵�ձ�"
                        "����" + cob->name(1) + "��������趼�ϲ��������ˡ�");
                destruct(cob);
                stop_story();
                return 0;

        case NO_USER_CAN_RESPOND:
                cob->force_me("chat* haha");
                stop_story();
                CHANNEL_D->do_channel( this_object(),
                        "rumor", "��˵����" + cob->query("nation") +
                        "��" + cob->name(1) + "���й���Ȼû�ж��֣�����"
                        "��ԭ���ֵ���ܴ��裡");
                return cob->name(1) + "����ԭ���֣�������ˣ���ȥ�ˣ�";

        case CHALLENGER_IS_FIGHTING:
                if (! rob || environment(rob) != environment(cob))
                {
                        stop_story();
                        if (rob)
                        {
                                rob->add("weiwang", -rob->query("weiwang") / 10);
                                rob->lost();
                        }
                        CHANNEL_D->do_channel( this_object(),
                        "rumor", "��˵" + accepted + "�ں�" + cob->query("nation") +
                        "" + cob->name(1) + "���ֵ�ʱ���������ӣ�ʹ��ԭ�������ߣ�");
                        return cob->name(1) + "��Ц��ֹ��ų���й�����һЩų�򣡹�����";
                }

                if (random(3)) return 1;
                if (rob->query("gender") == "����")
                        msg = fenco[random(sizeof(fenco))] + "����������" +
                              fenmsg[random(sizeof(fenmsg))];
                else
                        msg = menco[random(sizeof(menco))] + "����������" +
                              menmsg[random(sizeof(menmsg))];
                msg = replace_string(msg, "$N", rob->name(1));
                msg = replace_string(msg, "$C", RANK_D->query_respect(rob));
                return msg;
        }

        switch (n)
        {
        case 1:
                return cob->name(1) +
                       (random(2) ? "����ô��û�˸�Ӧսô�����Ҿ��ٵȵȣ�"
                                  : "���ٺ٣�����һЩ��С��");

        case 3:
                return cob->name(1) +
                       (random(2) ? "�ƺ��ȵúܲ��ͷ���"
                                  : "һ���������գ�һ����������棬�������������С�");

        case 5:
                return cob->name(1) +
                       (random(2) ? "����ô������û�˸�Ӧսô����������ʧ����"
                                   : "��˵ʲô������ѧ�����ԭ������ҥ����");

        case 7:
                return cob->name(1) +
                       (random(2) ? "ҡҡͷ����̾̾����һ����м�����ӡ���"
                                   : "����һ�����������ǲ�м��");

        case 9:
                return cob->name(1) +
                       (random(2) ? "�����ˣ��ҿ��һ����߰ɣ�"
                                   : "����Ҳ���������ˣ��������ǲ�Ҫ�����˷�ʱ���ˡ�");

        case 10:
                return cob->name(1) +
                       (random(2) ? "����ԭ���֣�ȫ����һЩ��ͷ�ڹ꣡���ˣ������ˣ�"
                                   : "������������ʲô����������һЩƭ�˵Ķ����������ˣ�");

        case 11:
                CHANNEL_D->do_channel(this_object(), "rumor", "��˵����" +
                        cob->query("nation") + "��" + cob->name(1) + "���й�"
                        "ҫ��������һ����Ȼ�Ļع�ȥ�ˣ����ǳ��衣");
                return 0;
        }

        return 1;
}

void stop_story()
{
        stop = 1;
}

// filter the user can respond for this challenge
int find_respond(object ob)
{
        if (ob->query("combat_exp") > cob->query("combat_exp") * 3)
        {
                too_cheap++;
                return 0;
        }

        if (ob->query("combat_exp") < cob->query("combat_exp") / 2)
                return 0;

        return 1;
}

// check the user
string cannot_accept(object ob)
{
        if (! cob)
                return "���ڻ�û����ս�ߣ�\n";

        if (rob == ob)
                return "������Ӧս�أ�\n";

        if (accepted)
                return "�����ս�Ѿ���" + accepted + "�����ˡ�\n";

        if (next != CHALLENGER_IS_WAITING)
                return "��Ȼ�����ڴ���ʦ��ǰ��ʲô�����\n";

        if (ob->query("combat_exp") > cob->query("combat_exp") * 3)
                return "��ս�ߵ�ˮƽ̫���ˣ���Ҫ�ǳ���ʵ������ʧ��ݣ�\n";

        if (ob->query("combat_exp") < cob->query("combat_exp") / 2)
                return "����书����ս����Ȳ��̫Զ�����ǲ�Ҫ��������"
                       "���˵����ˣ�\n";;

        return 0;
}

// accept challenger
void accept_for_challenge(object me)
{
        string fam;

        fam = me->query("family/family_name");
        if (! fam) fam = ""; else fam += "����";
        me->force_me("chat* heng");
        me->force_me("chat " + cob->name(1) + "��Ҫ���������ˣ�");
        CHANNEL_D->do_channel(this_object(), "rumor", "��˵" + fam +
                   me->name(1) + "ͦ�������������" + cob->name(1) + "����ս��");
        rob = me;
        accepted = me->name(1);
        if (environment(cob) != environment(me))
        {
                tell_object(me, HIG "���Ҳ�Ƶĸϵ���" + environment(cob)->short() + HIG "��\n");
                message("vision", me->name() + "ͻȻ����ææ�����ˡ�\n",
                                  environment(me), ({ me }));
                me->move(environment(cob));
                message("vision", me->name() + "����ææ�ĸ��˹�����\n",
                                  environment(me), ({ me }));
        }
        next = CHALLENGER_IS_FIGHTING;
        cob->competition_with(me);
}

void remove()
{
        if (cob)
        {
                if (environment(cob))
                {
                        message("vision", cob->name() + "���ʼ磬������Ц��ƮȻ��ȥ��\n",
                                environment(cob));
                }
                destruct(cob);
        }
}
