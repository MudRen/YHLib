// �������search.c

#include <ansi.h>
#include <quest.h>

inherit QUEST_OB;

#define QOB             my["qob"]
#define NPC1            my["npc1"]
#define NPC2            my["npc2"]
#define QOB_NAME        my["qob_name"]
#define NPC1_NAME       my["npc1_name"]
#define NPC2_NAME       my["npc2_name"]
#define QOB_ID          my["qob_id"]
#define NPC1_ID         my["npc1_id"]
#define NPC2_ID         my["npc2_id"]
#define PLACE1          my["place1"]
#define PLACE2          my["place2"]

int npc_accept_object(object me, object who, object ob);
mixed ask_for_qob(object npc2, object qob, string qob_name);

// ������󴴽�
void create()
{
        setup();
}

// ����һ������
// ����һ����Ʒ����Ѱ�ң��Զ�������������������ص㣬����ɱ
// �˵�һ���˼��ɻ�ø���Ʒ��Ȼ�󽻸��ڶ�������ȡ������
void init_quest(string qob_name)
{
        string name;
        object qob;
        string place1, place2;
        object npc1, npc2;
        mapping my;

        if (objectp(qob = find_object(qob_name)))
        {
                if (objectp(qob->query_temp("quest_ob")))
                {
                        // ����Ʒ�Ѿ����ڲ���������������������ܽ���
                        destruct(this_object());
                        return;
                }
        } else
                // ����������Ʒ
                qob = load_object(qob_name);

        // ��¼����Ʒ����������
        qob->set_temp("quest_ob", this_object());

        // �������������
        name = "Ѱ��" + filter_color(qob->name());
        set_name(name);

        // ������������ص�
        place1 = NPC_D->random_place(({ "����" }));
        place2 = NPC_D->random_place(({ "����", place1 }));

        // ���������������
        npc1 = new(CLASS_D("generate") + "/questnpc");
        npc2 = new(CLASS_D("generate") + "/questnpc");

        npc1->set_temp("quest_ob", this_object());
        npc2->set_temp("quest_ob", this_object());

        // ��¼��Щ����ص����Ʒ��Ϣ
        my = query_entire_dbase();

        QOB = qob;
        QOB_NAME = filter_color(qob->name());
        NPC1 = npc1;
        NPC2 = npc2;
        PLACE1 = place1;
        PLACE2 = place2;
        NPC1_NAME = npc1->name();
        NPC2_NAME = npc2->name();
        QOB_ID = qob->query("id");
        NPC1_ID = npc1->query("id");
        NPC2_ID = npc2->query("id");

        // ��Ʒ����
        qob->move(npc2);

        // �������
        NPC_D->place_npc(npc1, 0, ({ place1 }));
        NPC_D->place_npc(npc2, 0, ({ place2 }));

        // ���öԻ���Ϣ
        npc1->set("inquiry", ([
                name      : "������֪��������ң��������ͣ�",
                QOB_NAME  : "��ʵ������ֵǮ�����Ƕ���ȴ����Ҫ����",
                QOB_ID    : "��ʵ������ֵǮ�����Ƕ���ȴ����Ҫ����",
                NPC1_NAME : "�Ǿ��Ǳ������ˣ�",
                NPC1_ID   : "�Ǿ��Ǳ������ˣ�",
                NPC2_NAME : "��Ҳ����˵�����ˣ�����û����ƾʵ�ݰ���",
                NPC2_ID   : "��Ҳ����˵�����ˣ�����û����ƾʵ�ݰ���" ]));

        npc2->set("inquiry", ([
                name      : "ȫ��Ϲ�֣��Ķ����¶�����",
                QOB_NAME  : (: ask_for_qob, npc2, qob, qob->name() :),
                QOB_ID    : (: ask_for_qob, npc2, qob, qob->name() :),
                NPC1_NAME : "�����������Ҷ��ʣ��������д���",
                NPC1_ID   : "�����������Ҷ��ʣ��������д���",
                NPC2_NAME : "�����������кι�ɣ�",
                NPC2_ID   : "�����������кι�ɣ�" ]));

        // ���ý�����Ʒ����Ϣ������NPC���ڵ�ʱ�����������
        // ������ڣ���Ϊ����������ʱ������NPC�������Կ���
        // ��NPC���ñ��ص�"npc_accept_object"������
        npc1->set_temp("override/accept_object", (: npc_accept_object :));

        // �л�������״̬
        change_status(QUEST_READY);

        // ������������ʱ�䣺30����
        set("live_time", 1200);

        // �Ǽ�ҥ����Ϣ
        register_information();
}

// ������ֹ
void cancel_quest()
{
        mapping my = query_entire_dbase();
        object env;

        if (! mapp(my))
                return;

        if (objectp(NPC1))
                destruct(NPC1);

        if (objectp(NPC2))
                destruct(NPC2);

        // ��������
        ::cancel_quest();
}

// user ask npc2 for quest ob
mixed ask_for_qob(object npc2, object qob, string qob_name)
{
        object me;
        string msg;

        me = this_player();
        if (me->query("special_skill/trick"))
        {
                message_vision(HIM "$N" HIM "Ƴ��$n" HIM "һ�ۣ���������������"
                               "$n" HIM "�����˿�����\n" NOR, me, npc2);

                tell_object(me, HIC "��Ȱ˵" + npc2->name() +
                                HIC "��" + qob_name +
                                HIC "����������Ҷ����¡�\n" NOR);
                if (me->query_int() > random(40))
                {
                        // �ɹ��ˣ�
                        if (objectp(qob) && environment(qob) == npc2)
                        {
                                message_vision(CYN "$N" CYN "̾��һ��������$n"
                                               CYN "�������˺��ˣ���ͱ��˵"
                                               "�ˣ�\n" NOR, npc2, me);

                                tell_object(me, HIY + npc2->name() + HIY "��" +
                                            qob_name + HIY "�������㡣\n" NOR);

                                qob->move(me, 1);
                        } else
                        {
                                message_vision(CYN "$N" CYN "̾�˿�������$n" CYN
                                               "˵����ͱ�˵�ˣ��Ƕ�����Ĳ�����"
                                               "���ϣ�\n" NOR, npc2, me);
                        }
                } else
                        message_vision(CYN "$N" CYN "�۾�һ�ɣ�����$n" CYN "���"
                                       "���������������ҷϻ���\n" NOR, npc2, me);
                return 1;
        }

        return "ʲô�����գ��ҿ�û����˵����";
}

// ѯ��NPC1 - ����Ʒ����
string ask_npc1(object knower, object me)
{
        mapping my = query_entire_dbase();

        if (! objectp(NPC1))
                return CYN "�٣���˵" HIY + NPC1_NAME + NOR CYN
                       "���˴�ù���ȶ�" HIY + QOB_NAME + NOR CYN
                       "�ٶ�������˵��Ҫ��ô�ණ����ʲô�أ�" NOR;

        return CYN "Ŷ����ѽ����˵����" + PLACE1 + "��������" +
               HIY + QOB_NAME + NOR CYN "�أ�" NOR;
}

// ѯ��NPC2 - ������Ʒ����
string ask_npc2(object knower, object me)
{
        mapping my = query_entire_dbase();

        if (! objectp(NPC2))
                return CYN "����˵" HIY + NPC2_NAME + NOR CYN
                       "�Ѿ�����ɱ�ˣ��������㿴�����ǻ�����ɣ�" NOR;

        if (me->query("combat_exp") < NPC2->query("combat_exp") / 2)
        {
                remove_call_out("whisper_to");
                call_out("whisper_to", 0, knower, me);
        }

        return CYN "Ŷ����ѽ����˵����" + PLACE2 + "�����" +
               "������ȥ�ˣ������������ޣ�" NOR;
}

// ѯ��QOB - ��Ʒ����Ϣ
string ask_qob(object knower, object me)
{
        mapping my = query_entire_dbase();

        if (! objectp(QOB))
                return CYN "�����������Ҷ��ֵģ������Ѿ�û��"
                       "֪����" HIY + QOB_NAME + NOR CYN "�������ˡ�" NOR;

        return CYN "��˵��" HIY + QOB_NAME + NOR CYN
               "������ɶ�����ܱ���ֵǮ�����ǵģ�" NOR;
}

void whisper_to(object knower, object me)
{
        mapping my = query_entire_dbase();

        if (! can_talk_with(me, knower))
                return;

        message("vision", knower->name() + "���ĵ���" +
                me->name() + "����˵��Щʲô��\n",
                environment(me), ({ me }));
        tell_object(me, WHT + knower->name() + WHT "���ĵĺ���˵��" +
                    RANK_D->query_respect(me) + "���ҿ���ͱ���"
                    "���ˮ�ˣ�" + NPC2_NAME + WHT "�������أ�\n" NOR);
}

// �������
string query_introduce(object knower)
{
        mapping my = query_entire_dbase();

        if (! objectp(NPC2))
        {
                remove_call_out("do_say");
                call_out("do_say", 1, knower);
        }

        return CYN "��˵" HIY + NPC1_NAME + NOR CYN "����" +
               HIY + QOB_NAME + NOR CYN "������˵��֪��ô�ľ��䵽��"
               HIY + NPC2_NAME + NOR CYN "�����ˡ�" NOR;
}

void do_say(object knower)
{
        if (! objectp(knower) || ! living(knower))
                return 0;

        message_vision(CYN "$N" CYN "���������������������Ҷ�ģ�"
                       "�ⲻ����Ȼ��ûʲô���³���\n" NOR, knower);
}

int npc_accept_object(object me, object who, object ob)
{
        mapping my = query_entire_dbase();
        object reward;
        int percent;
        string msg;

        if (ob != QOB)
        {
                message_vision(CYN "$N" CYN "����$n" CYN "�����˰���"
                               "�ŵ�������ʲô��\n" NOR, me, who);
                return 0;
        }

        message_vision(HIY "$N" HIY "��ϲ��������$n" HIY "˵������λ"
                       + RANK_D->query_respect(who) + "��̫��л�ˣ�"
                       + RANK_D->query_self(me) + "ʵ�ڲ�֪������ô"
                       "�����㣡\n" NOR, me, who);

        reward = new("/clone/money/gold");
        reward->set_amount(1);

        message_vision(HIC "$N" HIC "�ͳ���һЩ" NOR + YEL "�ƽ�" HIC
                       "˫�ַ��ϣ��м�����һ�㱡�񣬲��ɾ��⣬���ɾ�"
                       "�⣡\n" NOR, me, who);

        reward->move(who, 1);

        // ����
        percent = 10000 * 100 / (random(who->query("score") + 1) + 10000);

        GIFT_D->bonus(who, ([ "exp" : 200 + random(100),
                              "pot" : 150 + random(100),
                              "score" : 30 + random(20),
                              "percent" : percent ]));

        CHANNEL_D->do_channel(find_object(QUEST_D), "rumor",
                              "��˵" + who->name(1) + "(" +
                              who->query("id") + ")��" +
                              me->name() + HIM "�ҵ���" + ob->name() +
                              HIM "��ƽϢ��һ�����ַ粨��" NOR);

        // ����Ϊ�����жϵ���������
        if (who->query("quest/freequest") > 0)
                GIFT_D->delay_freequest_bonus(who);

        // ��������
        destruct(ob);
        call_out("cancel_quest", 2);
        return -1;
}

// �����Ϣ�ܹ���ɢ����
int can_rumor_by(object knower)
{
        // 20%�ļ��ʱ�ɢ��
        return (random(10) < 2);
}

// �ǼǸ��������Ϣ
void register_information()
{
        mapping my = query_entire_dbase();

        if (! clonep() || ! mapp(my))
                // �����������Բ��Ǽ�
                return;

        set_information(NPC1_NAME, (: ask_npc1 :));
        set_information(NPC2_NAME, (: ask_npc2 :));
        set_information(QOB_NAME, (: ask_qob :));
        set_information(NPC1_ID, (: ask_npc1 :));
        set_information(NPC2_ID, (: ask_npc2 :));
        set_information(QOB_ID, (: ask_qob :));
}
