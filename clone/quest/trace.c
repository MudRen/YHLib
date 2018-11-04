// �������trace.c

#include <ansi.h>
#include <quest.h>

inherit QUEST_OB;

#define QOB             my["qob"]
#define NPC1            my["npc1"]
#define NPC2            my["npc2"]
#define NPC1_NAME       my["npc1_name"]
#define NPC2_NAME       my["npc2_name"]
#define NPC1_ID         my["npc1_id"]
#define NPC2_ID         my["npc2_id"]
#define PLACE1          my["place1"]
#define PLACE2          my["place2"]

string ask_1_for_2();
mixed ask_2_for_1(object npc2, object npc1, string npc1_name);

// ������󴴽�
void create()
{
        setup();
}

// ����һ�������Զ���������������еڶ��˴���Ѱ
// �ҵ�һ�ˣ�ֻ��ѵڶ��˴�����һ�˴���������ȡ������
void init_quest()
{
        string name;
        string place1, place2;
        object npc1, npc2;
        mapping my;

        // ������������ص�
        place1 = NPC_D->random_place(({ "����", place1 }));
        place2 = NPC_D->random_place(({ "����", place2 }));

        // ���������������
        npc1 = new(CLASS_D("generate") + "/questnpc");
        npc2 = new(CLASS_D("generate") + "/tracenpc");

        npc1->set_temp("quest_ob", this_object());
        npc2->set_temp("quest_ob", this_object());

        // �������������
        name = "Ѱ��" + npc1->name(1);
        set_name(name);

        // ��¼��Щ����ص����Ʒ��Ϣ
        my = query_entire_dbase();

        NPC1 = npc1;
        NPC2 = npc2;
        PLACE1 = place1;
        PLACE2 = place2;
        NPC1_NAME = npc1->name();
        NPC2_NAME = npc2->name();
        NPC1_ID = npc1->query("id");
        NPC2_ID = npc2->query("id");

        // �������
        NPC_D->place_npc(npc1, 0, ({ place1 }));
        NPC_D->place_npc(npc2, 0, ({ place2 }));

        // ���öԻ���Ϣ
        npc1->set("inquiry", ([
                NPC1_NAME : "�Ǿ��Ǳ������ˣ�",
                NPC1_ID   : "�Ǿ��Ǳ������ˣ�",
                NPC2_NAME : (: ask_1_for_2 :),
                NPC2_ID   : (: ask_1_for_2 :), ]));

        npc2->set("inquiry", ([
                name      : (: ask_2_for_1, npc2, npc1, npc1->name() :),
                NPC1_NAME : (: ask_2_for_1, npc2, npc1, npc1->name() :),
                NPC1_NAME : (: ask_2_for_1, npc2, npc1, npc1->name() :),
                NPC2_NAME : "�Ǿ��Ǳ������ˣ�",
                NPC2_ID   : "�Ǿ��Ǳ������ˣ�", ]));

        // ���ö���
        npc2->set_temp("trace", NPC1_ID);

        // �л�������״̬
        change_status(QUEST_READY);

        // ������������ʱ�䣺15����
        set("live_time", 600);

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

// ѯ��NPC1�й�NPC2������
string ask_1_for_2()
{
        mapping my = query_entire_dbase();

        if (! objectp(NPC2))
                return "�찡�����ֵ���������ô�ˣ�";

        switch (random(3))
        {
        case 0:
                return "����������������׷ɱ����С�ľͺ���ʧɢ�ˣ�����";
        case 1:
                return "������ͬ���������ֵܣ�������ȴ��֪�����ںδ���";
        default:
                return "֪����������ô������������������˵�ֵ�����Σ�ա�";
        }
}

// ѯ��NPC2�й�NPC1������
mixed ask_2_for_1(object npc2, object npc1, string npc1_name)
{
        object me, follow;
        string msg;

        me = this_player();

        if (me->query("score") < 500)
                return "лл��ĺ��⣬��������������Ҳ�ﲻ��æ��";

        if (! me->query("quest/freequest"))
                return "������Ҳһ����Ҫ����������ô���鷳�㣿";

        if (! me->query_temp("trace/" + npc2->query_temp("trace")))
                return "�㡭���Ǵ����������ģ��ⲻ������¡�";

        follow = npc2->query_leader();

        if (objectp(follow) && environment(follow) == environment(npc2))
        {
                // ���ڸ�������һ���ˣ��쿴��ǰִ�е�����

                if (follow == me)
                        // ����ľ��Ƿ�������
                        return "���ǿ�𵢸��ˣ���һ���ֵ��и�����"
                               "���̿ɡ�����";
                else
                        return "����" + follow->name() + "���ڰ���"
                               "Ѱ�����ֵܣ��Ͳ��鷳���ˡ�";
        }
        message_vision(CYN "$N" CYN "һ��������ס$n" CYN "��˫�ֵ�"
                       "���㡭��֪�����ֵ�������졭�����ȥ��\n"
                       NOR, npc2, me);

        npc2->set_leader(me);
        message_vision("$N������ʼ����$nһ���ж���\n", npc2, me);

        // �ķ����Ժ�������״̬
        remove_call_out("cancel_follow");
        call_out("cancel_follow", 240, npc2, me);
        return 1;
}

// ֹͣ����
void cancel_follow(object npc2, object me)
{
        string startroom;

        if (! objectp(npc2))
                return;

        if (! stringp(startroom = npc2->query("startroom")))
                return;

        // ���ٸ���
        npc2->set_leader(0);
        message_vision(CYN "$N" CYN "��ü�����㵽��֪��֪����"
                       "�ֵܵ����䣿���ˣ��һ����Լ��Ұɡ�\n"
                       NOR, npc2);

        message_vision(HIC "$N" HIC "̾�˿�����ͷҲ���ص����ˡ�"
                       "\n" NOR, npc2);

        // ���عʵ�
        npc2->move(startroom);
        message_vision("$N���˹�����\n", npc2);
}


// ѯ��NPC1��״��
string ask_npc1(object knower, object me)
{
        mapping my = query_entire_dbase();

        if ((me->query("score") < 500
           || ! me->query("quest/freequest"))
           && ! me->query_temp("trace/have_ask"))
        {
                me->set_temp("trace/have_ask", 1);
                call_out("do_whisper", 1, knower, me);
        }

        if (! objectp(NPC1) && ! objectp(NPC2))
        {
                call_out("cancel_quest", 1);
                return CYN "�ٺ٣���˵" HIY + NPC1_NAME + NOR +
                       CYN "��" HIY + NPC2_NAME + NOR + CYN "��"
                       "�����ڼ����ˡ��������治��" NOR;
        }

        if (! objectp(NPC1))
                return CYN "������˵" HIY + NPC1_NAME + NOR +
                       CYN "���Ǳ���Ҹ������ˣ�����Ҳû����"
                       HIY + NPC2_NAME + NOR + CYN "���档" NOR;

        me->set_temp("trace/" + NPC1_ID, 1);

        return CYN "�����书���ߣ����Ǽ��������������ֵ�" HIY +
               NPC2_NAME + NOR + CYN "ʧɢ�󣬱��Ĵ���ܳ��"
               "��׷ɱ��\n" + knower->name() + CYN "�ֽ��ŵ�"
               "�����������Է��ļ����һ�����" HIY + NPC1_NAME +
               NOR + CYN "����˵�Ƕ㵽" + PLACE1 + NOR + CYN
               "ȥ�ˡ�" NOR;
}

// ѯ��NPC2��״��
string ask_npc2(object knower, object me)
{
        mapping my = query_entire_dbase();

        if ((me->query("score") < 500
           || ! me->query("quest/freequest"))
           && ! me->query_temp("trace/have_ask"))
        {
                me->set_temp("trace/have_ask", 1);
                call_out("do_whisper", 1, knower, me);
        }

        if (! objectp(NPC1) && ! objectp(NPC2))
        {
                call_out("cancel_quest", 1);
                return CYN "�ٺ٣���˵" HIY + NPC1_NAME + NOR +
                       CYN "��" HIY + NPC2_NAME + NOR + CYN "��"
                       "�����ڼ����ˡ��������治��" NOR;
        }

        if (! objectp(NPC2))
                return CYN "������˵��" HIY + NPC2_NAME + NOR +
                       CYN "����Ǳ���Ҹ������ˣ�����ǰ����"
                       "����" HIY + NPC1_NAME + NOR + CYN "�ء�" NOR;

        return "���˸����ֵ�" HIY + NPC1_NAME + NOR + CYN "ʧɢ"
               "�󣬵��ĵò����ˡ��������ڻ���" + PLACE2 + NOR +
               CYN "�����ֵ��ء�" NOR;
}

// ֪ͨ���
void do_whisper(object knower, object me)
{
        if (! can_talk_with(knower, me))
                return;

        if (me->query("score") < 500)
                tell_object(me, WHT + knower->name() + WHT "���ĵĺ���"
                                "˵�����˰ɣ�ƾ���������ӣ����˲�������"
                                "�ġ�\n" NOR);
        else
                tell_object(me, WHT + knower->name() + WHT "���ĵĺ���"
                                "˵����˵�أ���Ҳ�����������α�ȥ�����"
                                "�˵�˽�¡�\n" NOR);

        me->delete_temp("trace/have_ask");
        message("vision", knower->name() + "��" + me->name() + "�Ķ���"
                "���ĵ�˵��Щʲô��\n", environment(me), ({ me }));
}

// �������
string query_introduce(object knower)
{
        mapping my = query_entire_dbase();

        if (! objectp(NPC1) && ! objectp(NPC2))
        {
                call_out("cancel_quest", 1);
                return CYN "�ٺ٣���˵" HIY + NPC1_NAME + NOR +
                       CYN "��" HIY + NPC2_NAME + NOR + CYN "��"
                       "�����ڼ����ˡ��������治��" NOR;
        }

        return CYN "��˵" HIY + NPC2_NAME + NOR + CYN "��"
               HIY + NPC1_NAME + NOR + CYN "��" + PLACE2 +
               CYN "�����Χ׷��ɱ��˫����ƴ�˼���ʱ������"
               "��׳�ҡ�\n" + knower->name() + CYN "�ֽ���"
               "˵���������Ǽ�����ҵ��Ǳ��ɵ��ˣ�������ô"
               "һ��ͬ���������ֵ�Ҳ���ʧɢ�ˡ�" NOR;
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
        set_information(NPC1_ID, (: ask_npc1 :));
        set_information(NPC2_ID, (: ask_npc2 :));
}
