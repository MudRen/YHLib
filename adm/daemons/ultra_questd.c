// ultra_questd.c
// Written by Vin for Heros.cn 2002/08/16.

#include <ansi.h>
#include <quest.h>

inherit F_DBASE;

// �����ṩ���ⲿ���õĽӿں���
public mixed accept_ask(object me, object who, string topic);
public mixed ask_information(object me, object who, string topic);
public void generate_information(object me);
public void give_quest(object me);
public void give_accede(object me, object who);
public void quest_guard(object me, object who);
public void quest_going(object me, object who);
public void give_gift(object me);
void start_guard(object me, object who);
void check_guard(object me, object who, object killer);
void check_going(object me, object who);

#define QUEST   "/adm/etc/questlist/"
#define QUESTER "����"
#define LURCHER "����"

private void special_bonus(object me)
{
        object ob;
        string un;

        // �����������Ʒ������
        string *ob_list = ({
                "/clone/fam/pill/puti1",
                "/clone/fam/pill/sheli1",
                "/clone/fam/pill/linghui1",
                "/clone/fam/pill/full1",
                "/clone/fam/pill/neili1",
        });

        ob = new(ob_list[random(sizeof(ob_list))]);

        // �鿴��Ʒ�ĵ�λ����
        if (ob->query("base_unit"))
                un = ob->query("base_unit");
        else
                un = ob->query("unit");

        // ������������ give ��Ϣһ��
        message_vision(me->query("ultra_quest/npc") + "�ó�һ" +
                       un + ob->name() + NOR "(" + ob->query("id") +
                       ")��$N" NOR "��\n\n" NOR, me);

        ob->move(me, 1);
}

// �������ʼ���򣬸�������������ṩ������
public mixed accept_ask(object me, object who, string topic)
{
        string msg;

        if (topic == "����" || topic == "quest")
        {
                if (who->query("ultra_quest"))
                        return "�Ҳ����Ѿ������������������Ѱ���Ϲ�������ô��";

                if (who->query("combat_exp") < 500000)
                        return "�����ڵĽ�������̫�ͣ��ﲻ����ʲôæ��";

                if (who->query("score") < 200000)
                        return "����������̫�ͣ���ͨ�������ﲻ����ʲôæ��";

                return "���š�����������Ӫҵ֤��ûǩ������������������ɡ�";

                message_vision(CYN "$N" CYN "������$n" CYN "��ã����ŵ�ͷ"
                               "�����������Ѱ���Ϲ������ɡ�\n" NOR, me, who);

                // ִ���ṩ�����ĳ��򣬱���Ԥ���趨�ṩ��
                who->set("ultra_quest/npc", me->name());
                generate_information(who);
                return 1;
        }

        if (topic == "����" || topic == "clue")
        {
                if (! who->query("ultra_quest"))
                        return "��Ҫ��ʲô�£�˵���������׵ġ�";

                if (who->query("ultra_quest/finish") == "all")
                        return "���������Ѿ��ҵ���ô������Ҫʲô������";

                // ���ֻ�������ṩ��������
                if (who->query("ultra_quest/new_begin") >= 3)
                        return "�²�������ʣ�µ��������Լ���취�����";

                switch (who->query("ultra_quest/new_begin"))
                {
                case 0:
                      msg = "������ǵ�һ�Σ�ϣ�����������»ء�";
                      break;

                case 1:
                      msg = "���Ѿ������һ���ˣ�����ǵڶ��Ρ�";
                      break;

                default:
                      msg = "���Ѿ������һ���ˣ���������Ϊ֮��";
                      break;
                }

                message_sort(WHT "\n$N" WHT "������ü����$n" WHT "������"
                             "���������������ʵ��һ�������Ĺ��̣��ܶ��"
                             "�����뾭��ĥ����ƾ�������������������ܰ�"
                             "����������������������԰������Σ�������"
                             "�����Σ��Ҿ�����Ϊ���ˡ�" + msg + "\n\n" NOR,
                             me, who);

                // ȡ����ǰ����������
                who->delete("ultra_quest/quest");

                // ��¼����ѯ�ʵĴ���
                who->add("ultra_quest/new_begin", 1);

                // ��¼�ṩ��������������
                who->set("ultra_quest/npc", me->name());

                // �����ṩ����
                generate_information(who);
                return 1;
        }
}

// ѯ�����������Ҫ�� /inherit/char/npc.c ���Ӷ�Ӧ����
public mixed ask_information(object me, object who, string topic)
{
        string msg;
        string type, obj;
        string next_npc, npc_place;

        next_npc = who->query("ultra_quest/next_npc");
        npc_place = who->query("ultra_quest/npc_place");

        if (stringp(type = who->query("ultra_quest/quest/type"))
           && stringp(obj = who->query("ultra_quest/quest/obj"))
           && topic == obj)
        {
                // �ṩ������������ṩ����������Ϣ�Ľ��
                if (me->name() == next_npc)
                {
                        switch (type)
                        {
                        case "kill" :
                                msg = "���������ҡ��Һ޲��ð�����ʬ��ϣ�";
                                break;

                        case "find" :
                                msg = "˵�����Ƕ���Ҳ�����ң����Լ�������ɡ�";
                                break;

                        case "send" :
                                msg = "��ʵ������Ҳ���Ǻ��죬���Ĵ�ȥ���ʰɡ�";
                                break;

                        case "give" :
                                msg = "�Һܾ�û�������ˣ�Ҳ�����������������";
                                break;

                        case "going" :
                                msg = "�Ҹ���˵�ú�����˰���Ī����Ҳ��ʶ·��";
                                break;
                        }
                        return msg;
                }
        }

        if (topic == next_npc)
        {
                // ѯ��Ŀ��Ϊ��һ���ṩ��Ϣ����
                if (who->query("ultra_quest/npc") == me->name())
                        return "�Һ��˼��ֲ��죬��ô֪����ô�ࡣ";
        }

        if (topic == "����" || topic == "clue")
        {
                // ѯ��Ŀ��Ϊ��һ���ṩ��Ϣ����
                if (who->query("ultra_quest/npc") == me->name())
                        return "�Ҳ�������ȥ" + npc_place + "��" HIY +
                               next_npc + NOR + CYN "ô��������������"
                               "��" NOR;

                // �����ǰ�������޷�ִ�У����ж�
                if (who->query("ultra_quest/quest/fail"))
                        return "���鵽����һ������Ҳû���ٰ����ˡ�";

                // ����Ѿ������������򷵻�
                if (who->query("ultra_quest/quest/msg"))
                        return "�Ҳ�������" +
                               who->query("ultra_quest/quest/msg") +
                               "�𣿻�����ʲô��";

                switch (random(5))
                {
                case 0:
                      msg = "��Ҫ�ҵĶ�������ȷʵ֪��һЩ������"
                            "���ȵð��Ҹ�æ��";
                      break;

                case 1:
                      msg = "�Ƕ������Ǹ������������ɡ��������"
                            "���£��Ҿ͸����㡣";
                      break;

                case 2:
                      msg = "������ȷʵ�������֪����üĿ������"
                            "��Ϣ�ɲ��ܰ׸���";
                      break;

                case 3:
                      msg = "����Ϊһ���·��������ܰ������"
                            "æ��������Ը����㡣";
                      break;

                default:
                      msg = "���Լ������鶼æ�����������ﻹ�˵�"
                            "���㣬���������ǡ�";
                      break;
                }
                message_vision(CYN "$N" CYN "ҡͷ����" + msg + "\n"
                               NOR, me, who);

                // �����������Ҫ��ִ�м������������
                if (me->query("combat_exp") >= 100000
                   && me->query("age") >= 20
                   && ! me->query_temp("need_accede")
                   && random(3) == 1)
                {
                        give_accede(me, who);
                        return 1;
                }

                // �����������Ҫ��ִ�б�����������
                if (who->query("combat_exp") > me->query("combat_exp")
                   && ! environment(who)->query("no_fight")
                   && ! me->query_temp("start_guard")
                   && random(4) == 1)
                {
                        if (random(2) == 1)
                        {
                                // ִ�б���������
                                quest_guard(me, who);
                                return 1;
                        } else
                        {
                                // ִ�л��͵�����
                                quest_going(me, who);
                                return 1;
                        }
                }

                // ����ϵͳԤ������
                give_quest(who);
                return 1;
        }
}

// ����������ķ���
public void give_accede(object me, object who)
{
        string msg, type, quest_msg;
        string skill;
        string ma, mb, wa, ac;
        int exp, lvl;

        // ���˳Ƽ������ַ�������д����
        ma = RANK_D->query_self(me);
        mb = RANK_D->query_self_rude(me);
        wa = RANK_D->query_respect(who);
        ac = "(" HIY "accede" NOR + WHT ")";

        switch (random(6))
        {
        case 0:
                msg = random(2) ? "��λ" + wa + "��" + ma + "�������о�"
                                  HIW "����" NOR + WHT "�׾��������ĵá�"
                                  "���Ҷ��˱�������" + ac + "һ�̣�����"
                                  "����ʤ���ҡ���ô" + ma + "��֪������"
                                  "�������������":

                                  wa + "�������ã�" + mb + "����û������"
                                  "�������������ұ���" + ac + "һ��" HIW
                                  "����" NOR + WHT "����������ʤ��������"
                                  "����ǩ�����̣��Ұ���֪����һ�ж�������";

                quest_msg = "���ұ�������";
                type = "mathematics";
                break;

        case 1:
                msg = random(2) ? "��λ" + wa + "��" + ma + "�������о�"
                                  HIW "ʫ��" NOR + WHT "�踳���д����"
                                  "���Ҷ��˱�����ʫ" + ac + "���ԣ�����"
                                  "���ܶ�Ӯ" + ma + "����ô����֪������"
                                  "�������������":

                                  "�ҿ�" + wa + "Ҳ����Ҫ�£���Ȼ���Ҷ�"
                                  "�˶�����ģ���������ʫ" + ac + "��"
                                  "�ԣ���ͬ̽��̽��" HIW "��ѧ" NOR + WHT
                                  "֪ʶ������������ʤ�ң�" + ma + "����"
                                  "������֮";

                quest_msg = "������ʫ�Զ�";
                type = "literate";
                break;

        case 2:
                msg = random(2) ? "��λ" + wa + "��" + ma + "�������о�"
                                  HIW "����" NOR + WHT "֮���������ĵá�"
                                  "���Ҷ��˱�������" + ac + "һ�֣�����"
                                  "����ʤ���ҡ���ô����֪��������������"
                                  "�����":

                                  wa + "��������ҿ���Ҳû��Ҫ����������"
                                  "��������ɱ" + ac + "һ��" HIW "��" NOR +
                                  WHT "��ʡ�����ġ�����������ʤ�Ҽ��ӣ���"
                                  "���֪����ȫ��������Ҳ�޷�";

                quest_msg = "������һ����";
                type = "chess";
                break;

        case 3:
                msg = random(2) ? "��λ" + wa + "�������ã�" + ma + "��Ϊ"
                                  "һ�·�������������ѵĴ��٣�" + ma +
                                  "��������һ�������Ա�ף�أ�������" HIW
                                  "�鷨" NOR + WHT "����Ƿ�ѣ��������ܰ�" +
                                  ac + "�Ҵ�������Ը��" + ma + "�м���"
                                  "��������Ҳ�����������":

                                  wa + "��������ʱ��" + ma + "��Ϊһ��"
                                  "�������˵������ǰ����һλֿ��Ϊ����"
                                  "���������Ҳ���������" + ma + "����Ѱ��"
                                  "һλ" HIW "�鷨" NOR + WHT "����Ϊ����"
                                  "д���ʣ�ȴ��֪" + wa + "�ܷ��" + ac +
                                  ma + "��������Ը";

                quest_msg = "����дһ����";
                type = "calligraphy";
                break;

        case 4:
                msg = random(2) ? "��λ" + wa + "�������ã�" + ma + "��Ϊ"
                                  "һ�·��ǰ��������ϲ�ù��ӣ�" + ma +
                                  "��������һ��ϲͼ�Ա�ף�أ�������" HIW
                                  "����" NOR + WHT "����̫��������ܰ�" +
                                  ac + "�Ҵ�������Ը��" + ma + "�м���"
                                  "��������Ҳ�����������":

                                  "�����" + ma + "�и�����֮�룬����" + wa +
                                  "��æ" + ac + "��ɡ�" + ma + "�и�����"
                                  "������֪��������λ" HIW "����" NOR + WHT
                                  "���֣�����ȥ�ݷá�ȴ��֪����α�����"
                                  "��" + wa + "�д�֮�����ܹ�Ͷ�����ã���"
                                  "��м�����";

                quest_msg = "���һ�һ����";
                type = "drawing";
                break;

        default:
                msg = random(2) ? "�š�" + wa + "�����������" + ma + "��"
                                  "�˶��֣���С�����˽�ǣ����ձ���ҽ�Ρ�"
                                  "�����θ����Ҳ���һλ" HIW "ҽ��" NOR +
                                  WHT "�õ�Ĵ�������ܰ�æ" + ac + "��"
                                  "�ô��ˣ�" + ma + "�м�����������Ҳ����"
                                  "�������":

                                  "�����㽲��" + wa + "��ǰ����" + ma +
                                  "���˹��У��������˵����ˣ�������δȬ��"
                                  "�������ⲡʹ֮��ίʵ�Ѱ�����������ͨ��"
                                  HIW "ҽ��" NOR + WHT "���ܹ�����" + ac +
                                  ma + "��ʹ�Ļ���" + ma + "����֪����һ��"
                                  "ȫ����֮";

                quest_msg = "����ҽ�β�ʹ";
                type = "medical";
                break;
        }

        // �ṩ�������������Ϣ
        msg = WHT "\n" + me->name() + WHT "��˼Ƭ�̣�����"
              "˵����" + msg + "��\n\n" NOR;

        message("vision", me->name() + "��" + who->name() +
                          "����С��˵��Щʲô��\n",
                          environment(who), ({ who }));

        tell_object(who, sort_msg(msg));

        // ����Ҫ�������
        skill = type;

        // Ϊʲô��ʮ����Ϊ��Ŀ�������ȼ��ļ���
        exp = me->query("combat_exp") * 10;

        // ����������и���ܣ���ֱ�ӵ���
        // ���û�У���ȡ�����֧�ֵȼ�������
        if (me->query_skill(skill))
                lvl = me->query_skill(skill, 1);
        else
                lvl = pow(exp, 1.0 / 3) - 50;

        // �ȼ�̫�������
        if (lvl < 80) lvl = 80;

        // �ȼ�̫��������
        if (lvl > 300) lvl = 300;

/*
        tell_object(who, HIC "��������Ϣ��" NOR + WHT + me->name() +
                         HIW " ���飺" HIC + exp / 10 +
                         HIW " ���" HIC + to_chinese(skill) +
                         HIW " �ȼ���" HIC + lvl + "\n\n" NOR);
*/

        // ע����������
        who->set("ultra_quest/quest/type", type);
        who->set("ultra_quest/quest/obj", me->name());
        who->set("ultra_quest/quest/msg", quest_msg);

        // ����ע��������
        me->set_temp("need_accede/user", who->query("id"));
        me->set_temp("need_accede/lvl", lvl); 

        return;
}

// ϵͳԤ������ķ���
public void give_quest(object me)
{
        string *lines, file;
        string quest, next_npc, msg;
        string type, obj, quest_msg;
        object item;

        next_npc = me->query("ultra_quest/next_npc");

        // û���ṩ��������
        if (! next_npc) return;

        // ����ϵͳԤ�������������������
        file = read_file(QUEST + "quest");
        lines = explode(file, "\n");
        quest = lines[random(sizeof(lines))];

        if (sscanf(quest, "%s/%s", type, obj) != 2)
                return;

        // ���ϵͳ���õ������������ṩ������������
        // ����������ִ�иó���
        if (next_npc == obj)
        {
                give_quest(me);
                return;
        }

        switch (type)
        {
        case "kill" :
                msg = random(2) ? "�����ɱ��" HIR + obj + NOR +
                                  WHT "���ˣ���������ͷ������":

                                  "��ȥ��" HIR + obj + NOR + WHT
                                  "�������ˣ��������ϵ�ͷ������";

                quest_msg = "����ɱ��" + obj;
                break;

        case "find" :
                msg = random(2) ? "������������" + obj + NOR +
                                  WHT "��ֻ���ͷ��ͷ�������":

                                  "�������ܰ����ҵ�" + obj + NOR
                                  + WHT "�������ҿ����ṩЩ����";

                quest_msg = "�����ҵ�" + obj;
                break;

        case "send" :
                msg = random(2) ? "����Ұ�������͵�" HIY + obj
                                  + NOR + WHT "���У�Ȼ����" HIW
                                  "��ִ" NOR + WHT "������":

                                  "���з���Ҫ�����͵�" HIY + obj
                                  + NOR + WHT "��������������"
                                  "����";

                quest_msg = "���Ұ����͵�" + obj + "��";
                item = new("/clone/misc/letter");
                break;

        case "give" :
                msg = random(2) ? "����Ұ���������͵�" HIY +
                                  obj + NOR + WHT "���������"
                                  "��ʲô��Ӧ":

                                  "�ͷ����˰���ת����" HIY + obj
                                  + NOR + WHT "����;��Ī˽�Դ�"
                                  "��";

                quest_msg = "���ҰѰ���ת����" + obj;
                item = new("/clone/misc/bag");
                break;
        }

        // �ṩ��������Ϣ
        message("vision", next_npc + "������" + me->name() + "��"
                          "��˵��Щʲô��\n", environment(me),
                          ({ me }));

        tell_object(me, WHT + next_npc + WHT "���Ķ���˵����" +
                        msg + "��\n" NOR);

        // ע����������
        me->set("ultra_quest/quest/type", type);
        me->set("ultra_quest/quest/obj", obj);
        me->set("ultra_quest/quest/msg", quest_msg);

        // �������������ߣ���ע���������
        if (objectp(item))
        {
                item->set("send/from", next_npc);
                item->set("send/send", obj);
                item->set("send/user", me->name());
                item->set("long", WHT "����һ" + item->query("unit") +
                                  next_npc + "׼��ת����" + obj + "��" +
                                  item->name() + "��\n" NOR);

                // �ṩ�����ת�Ƶ���Ϣ
                message_vision(next_npc + "�ó�һ" + item->query("unit") +
                               item->name() + NOR "(" + item->query("id") +
                               ")��$N" NOR "��\n" NOR, me);
                item->move(me, 1);
        }
        return;
}

// ��������ķ���
public void quest_guard(object me, object who)
{
        string msg;

        message("vision", me->name() + "��" + who->name() +
                          "����С��˵��Щʲô��\n",
                          environment(who), ({ who }));

        switch (random(3))
        {
        case 0:
                msg = "�ҵĳ�ҽ���Ҫɱ������";
                break;

        case 1:
                msg = "�����и��һ����Ҫ������";
                break;

        default:
                msg = "����˵����׼�����Ҳ���";
                break;
        }

        tell_object(who, WHT + me->name() + WHT "���Ķ���"
                         "˵����" + msg + "����" HIW "����"
                         "����" NOR + WHT "������һ�¡�\n" NOR);

        // Ϊ�˷�ֹ�����ͻ��Ŀ�����ñ���������
        me->set_temp("start_guard", 1);

        // ע�ᱣ����������
        who->set("ultra_quest/quest/type", "guard");
        who->set("ultra_quest/quest/obj", me->name());
        who->set("ultra_quest/quest/msg", "�������ﱣ����");
        who->start_call_out((: call_other, __FILE__, "start_guard",
                               me, who :), 25);
        return;
}

// ��������ķ���
public void quest_going(object me, object who)
{
        string *lines, file;
        string where, area, place;

        // ����ϵͳԤ��ĵص�����
        file = read_file(QUEST + "place");
        lines = explode(file, "\n");
        where = lines[random(sizeof(lines))];

        if (sscanf(where, "%s/%s", area, place) != 2)
                return;

        // ���ϵͳ���õĵ�������ʼ���ظ�����ֱ��ִ��
        // ϵͳԤ����������
        if (place == environment(me)->query("short"))
        {
                generate_information(who);
                return;
        }

        message("vision", me->name() + "��" + who->name() +
                          "����С��˵��Щʲô��\n",
                          environment(who), ({ who }));

        tell_object(who, WHT + me->name() + WHT "���Ķ���"
                         "˵�����������е���Ҫ��" + HIW +
                         area + NOR + WHT "��" HIW + place +
                         NOR + WHT "�����ͼ������ҹ�ȥ��"
                         "\n" NOR);

        // Ŀ�꿪ʼ�����ж�
        me->set_leader(who);
        message_vision("$N������ʼ����$nһ���ж���\n", me, who);

        // Ϊ�˷�ֹ�����ͻ��Ŀ�����ñ���������
        me->set_temp("start_guard", 1);

        // ע�Ụ����������
        who->set("ultra_quest/quest/type", "going");
        who->set("ultra_quest/quest/obj", place);
        who->set("ultra_quest/quest/msg", "���ҵ�" + area + "��" + place);

        // ��ʼ��ʱɨ��������ĵص�
        who->start_call_out((: call_other, __FILE__, "check_going",
                               me, who :), 5);
        return;
}

// ִ�б�������ĳ���
void start_guard(object me, object who)
{
        object killer;

        if (! objectp(me) || ! objectp(who)
           || environment(me) != environment(who))
                return;

        if (random(5) == 1)
        {
                message_vision(CYN "\n$N" CYN "������ͷ����Ϊ"
                               "���ε�˵�����ף��ѵ������д�"
                               "\n" NOR, me);

                if (random(3) == 1)
                {
                        message_vision(CYN "$N" CYN "��Ц����"
                                       "������$n" CYN "������"
                                       "����û�����ˣ���Ҳ����"
                                       "����һ�����Ҿ͸������"
                                       "��\n" NOR, me, who);

                        // Ŀ��ȡ��������������
                        me->delete_temp("start_guard");

                        // ������ɣ�ע�ά������
                        who->set("ultra_quest/npc", me->name());
                        who->set("ultra_quest/gift/point", 120);
                        who->set("ultra_quest/gift/msg", "��ͨ������" +
                                who->query("ultra_quest/npc") + "�Ĺ���");

                        // ϵͳ����ô�����Ľ���
                        give_gift(who);
                } else
                {
                        message_vision(CYN "$N" CYN "̾�˿���"
                                       "����$n" CYN "��������"
                                       "��û�����ˣ��һ�������"
                                       "��������������ɡ�\n"
                                       NOR, me, who);

                        // Ŀ��ȡ��������������
                        me->delete_temp("start_guard");

                        // �����жϣ�ϵͳ���·��������
                        give_quest(who);
                }
                return;
        }
        message_vision(CYN "\nͻȻ��$N" CYN "��$n" CYN "����˵��"
                       "�����ˣ�ɱ�ҵ������ˡ�\n\n" NOR, me, who);

        killer = new(CLASS_D("generate") + "/killer");
        NPC_D->set_from_me(killer, who, 100);
        killer->move(environment(me));

        message_vision(HIW "$n" HIW "���˹�������$N" HIW "��Ц"
                       "����ԭ���������������ɣ�\n" NOR, me,
                       killer);

        killer->set_leader(me);
        killer->kill_ob(me);

        // ��鱣��״̬
        who->start_call_out((: call_other, __FILE__, "check_guard",
                               me, who, killer :), 3);
}

// ��鱻���������״̬
void check_guard(object me, object who, object killer)
{
        if (! objectp(me) && ! objectp(killer))
                return;

        // ����ս�������ӳټ��
        if (objectp(killer) && objectp(me)
           && (me->is_fighting(killer)
           || who->is_fighting(killer)))
        {
                who->start_call_out((: call_other, __FILE__, "check_guard",
                                       me, who, killer :), 1);
                return;
        }

        // ������������ʧ�������ж�
        if (! objectp(me)
           && objectp(killer))
        {
                tell_object(who, HIG "���ۼ�" + who->query("ultra_quest/quest/obj") +
                                 HIG "��ɱ�������������㡣\n" NOR);

                // ��¼��ʧ�ܼ�¼
                who->set("ultra_quest/quest/fail", 1);
                return;
        }

        // ɱ����ʧ�ұ������˴��ڣ��������
        if (! objectp(killer)
           && objectp(me))
        {
                // ����������˻��ԣ�����ת��
                if (! living(me))
                        me->revive();

                message_vision(CYN "$N" CYN "���˲�������$n" CYN "��������"
                               "���������æ���м�������\n$N" CYN "���ŵ���"
                               "����֮�����Իر�����һ������֪���Ķ�������"
                               "��\n" NOR, me, who);

                // Ŀ��ȡ��������������
                me->delete_temp("start_guard");

                // ������ɣ�ע�ά������
                who->set("ultra_quest/npc", me->name());
                who->set("ultra_quest/gift/point", 250);
                who->set("ultra_quest/gift/msg", "��ͨ������" +
                        who->query("ultra_quest/npc") + "�Ĺ���");

                // ϵͳ����ô�����Ľ���
                give_gift(who);
                return;
        }
        message_vision(CYN "$N" CYN "���˿����ܣ���е�����"
                       "ʦ��BUG��BUG��\n" NOR, who);
        return;
}

// ��黤�������״̬
void check_going(object me, object who)
{
        string msg, place;

        // �������Ѿ�ʧ�ܣ���ȡ�������Բ����ж�����
        if (who->query("ultra_quest/quest/fail"))
        {
                who->delete_temp("dest_npc");
                return;
        }

        // ��������»��͵���������ˣ�ִ�����³���
        if (! objectp(me)
           || environment(me) != environment(who))
        {
                switch (who->query_temp("dest_npc"))
                {
                case 0:
                        msg = "���ͷ�����䣬ȴ������" +
                              who->query("ultra_quest/next_npc") +
                              "����֪��ʱ��������Ӱ��\n�����а���"
                              "����ǧ����������ϵ��ˣ��øϽ�����"
                              "�һ�����";
                        break;

                case 1:
                        msg = "��������Ϊ�������ף�" +
                              who->query("ultra_quest/next_npc") +
                              "�Ǽһﵽ������ȥ�ˡ�";
                        break;

                case 2:
                        msg = "���ĵ�ֱ�ʲôʱ���ˣ��Ǹ�����" +
                              who->query("ultra_quest/next_npc") +
                              "��ô������������";
                        break;

                default:
                        msg = "����������̾Ϣ���������׻��ǰ��˸�"
                              "�����ˡ�������������";

                        // ��¼��ʧ�ܼ�¼
                        who->set("ultra_quest/quest/fail", 1);
                        break;
                }

                // �������ﶪʧ��ʱ��Σ��������������ж�
                who->add_temp("dest_npc", 1);

                // ��һ��ʱ�����������ɨ��
                who->start_call_out((: call_other, __FILE__, "check_going",
                                       me, who :), 15);

                tell_object(who, HIG "\n" + msg + "\n\n" NOR);
                return;
        }

        // ����Ⱥ��������ʱ���
        if (who->query_temp("dest_npc"))
                who->delete_temp("dest_npc");

        // ���ó����͵�Ŀ�ĵ�
        place = who->query("ultra_quest/quest/obj");

        // �鿴��ǰλ�ã���ΪĿ�ĵأ����������
        if (environment(me)->query("short") == place)
        {
                // ����������˻��ԣ�����ת��
                if (! living(me))
                        me->revive();

                message_vision(CYN "$N" CYN "���˲�������$n" CYN "����лл"
                               "�㽫���͵�" + place + "��·�������鷳���ˡ�"
                               "\n$N" CYN "���ŵ����������ⷬ����ķ��ϣ���"
                               "�͸�����һЩ�����ɡ�\n" NOR, me, who);

                // Ŀ��ȡ��������������
                me->delete_temp("start_guard");

                // Ŀ�겻�ٸ���
                me->set_leader(0);

                // ������ɣ�ע�ά������
                who->set("ultra_quest/npc", me->name());
                who->set("ultra_quest/gift/point", 220);
                who->set("ultra_quest/gift/msg", "��ͨ������" +
                        who->query("ultra_quest/npc") + "�ִ�" +
                        place + "�Ĺ���");

                // ϵͳ����ô�����Ľ���
                give_gift(who);
                return;
        } else
        {
                string last_place;

                // ����¼�ʹ����ϵ͵Ļ���Ŀ��ͣ��
                if (stringp(last_place = me->query_temp("last_place"))
                   && last_place != environment(me)->query("short")
                   && ! me->is_busy()
                   && me->query("combat_exp") < 200000
                   && random(50) == 1)
                {
                        switch (random(5))
                        {
                        case 0:
                              msg = "ͻȻ��$N" HIW "�ܵü��ˣ�һ���"
                                    "�Ե�·�ߣ�����ѽѽ�и���ͣ��";
                              break;

                        case 1:
                              msg = "ֻ��$N" HIW "��Ϣ����" + who->name()
                                    + HIW "�������㡭�������������ˡ�";
                              break;

                        case 2:
                              msg = "$N" HIW "���ס���һ�����ƺ�������"
                                    "ʲô��������Ų���ʱ����������";
                              break;

                        case 3:
                              msg = "$N" HIW "��Ȼ��ɫ�Ұף�����" +
                                    who->name() + HIW "���ͷ�ͣ��ͣһ"
                                    "�ᣬ���߲����ˡ�";
                              break;

                        default:
                              msg = "ȴ��$N" HIW "������䣬�ߵ���·��"
                                    "͹���һ���ʯ��ֱʹ�ù�����ȥ��";
                              break;
                        }
                        message_vision(HIW "\n" + msg + "\n\n" NOR, me, who);
                        me->start_busy(2 + random(2));
                }

                // �趨��һ��������ĵص㣬����뵱ǰ�ص㲻ͬ����
                // ִ����������ͣ���ĳ���
                me->set_temp("last_place", environment(me)->query("short"));

                // δ����Ŀ�ĵأ���ʱ������ɨ��
                who->start_call_out((: call_other, __FILE__, "check_going",
                                       me, who :), 1);
                return;
        }
        return;
}

// ���������������ļ�������������
int need_accede(object me, object who)
{
        string skill, ma, wa;
        string suc_msg, fai_msg, msg;
        int lvl;

        // ׼���Ƚϵļ�������
        skill = who->query("ultra_quest/quest/type");
        lvl = me->query_temp("need_accede/lvl", lvl);

        // ���˳����򵥻�
        ma = RANK_D->query_self(me);
        wa = RANK_D->query_respect(who);

        switch (skill)
        {
        case "mathematics" :
                suc_msg = me->name() + "���˵�ͷ���漴�����������ڵ��滭"
                          "��Щ��ֱ������ԲȦ������д�¡�̫����Ԫ����Ԫ��"
                          "��Ԫ����Ԫ�����֡�����һ��ĬĬϸ�ۣ���ָ�����"
                          "����������Ĵ��������ڸ�֮" + me->name() +
                          "��" + me->name() + "����һ����̾������ԭ��Ϊ��"
                          "�������ˣ����ˡ�";

                fai_msg = me->name() + "���˵�ͷ���漴�����������ڵ��滭"
                          "��Щ��ֱ������ԲȦ������д�¡�̫����Ԫ����Ԫ��"
                          "��Ԫ����Ԫ�����֡�����һ�Կ��ò�֪���ƣ�ȫȻ��"
                          "֪��������֡�" + me->name() + "���˰��죬����"
                          "���޶��������ɵ������һЦ��";
                break;

        case "literate" :
                suc_msg = me->name() + "���˵�ͷ��������ɤ�ӵ����ҳ�һ��"
                          "����������ҶԳ��������������ǡ��׻�Ӣ��ʷ����"
                          "��΢΢һЦ����ڶԵ���������ɵ��Ĺ����" +
                          me->name() + "����һ���޵���������˾��";

                fai_msg = me->name() + "���˵�ͷ��������ɤ�ӵ����ҳ�һ��"
                          "����������ҶԳ����������������ǡ��׻�Ӣ��ʷ��"
                          "��������һ㶣������˰���ŵ��������������ƻ���"
                          "����" + me->name() + "�����ŭ����������ޣ���"
                          "��ʲô���ӡ����֪���ƶԺ�ô��";
                break;

        case "chess" :
                suc_msg = "�㵱������ǰȥ����" + me->name() + "�ڿ����"
                          "����������������ʱ��ȴ��" + me->name() + "��"
                          "�Ǵ����졣��������������һ�ӣ�" + me->name() +
                          "��ʱ��ɫ���࣬��Ȼ���������ˣ������ˡ�������"
                          "���ǡ�";

                fai_msg = "�㵱������ǰȥ����" + me->name() + "�ڿ����"
                          "����������������ʱ�����ѱ�" + me->name() +
                          "�Ƶýڽڰ��ˣ����������" + me->name() + "��"
                          "����ɫ���࣬��Ц������ô��������ˮƽ��������"
                          "��ô��";
                break;

        case "calligraphy" :
                suc_msg = "��΢΢һЦ����������ǰȥ���ӹ�ë�ʱ㿪ʼ��д"
                          "��������ʱֻ��������������б�ī��������"
                          "�����������ּ�����������ˮ�����潫�鷨���⾳"
                          "���ӵ����쾡�¡�" + me->name() + "��һ�Կ���"
                          "Ŀ�ɿڴ����������ޡ�";

                fai_msg = "�㵱������ǰȥ���ӹ�ë�ʱ�մīˮ���㿪ʼ��д"
                          "������������д�������緢֮����̧ͷ��ȴ����" +
                          me->name() + "��ɫ��Ϊ�ѿ������ɵ�΢΢һ㶡�" +
                          me->name() + "ҡ��ҡͷ��ʧ�����������ҽ�������"
                          "���ó��֣�������˳�Ц��ԭ����������";
                break;

        case "drawing" :
                suc_msg = "��΢΢һЦ�������ӹ����ʣ����������ī������"
                          "��ī�����죬�����۽�����ֻ�������ʣ����ƿ���"
                          "ʵ������" + me->name() + "��һ��Խ��Խ����ϲ"
                          "���������ޡ�";

                fai_msg = "�㵱������ǰȥ���ӹ������������������㻭��"
                          "�����緢֮ʱ��̧ͷ��ȴ����" + me->name() + "��"
                          "ɫ��Ϊ�ѿ������ɵ�΢΢һ㶡�" + me->name() +
                          "ҡ��ҡͷ��ʧ���������ˣ����ˡ�������ˮƽ����"
                          "û���Լ����ֻ��׵���";
                break;

        default:
                suc_msg = "����˵�ͷ�������ָ����" + me->name() + "��"
                          "���ϣ�����Ƭ�̱��ѷ����䲡�����ڡ�����Ҳ����"
                          "�飬���������ҩ����" + me->name() + "�����"
                          "ϲ�������ҽ���������" + wa + "���˷���������"
                          "���Իر���";

                fai_msg = "�����㶣�����ǰȥ��" + me->name() + "������"
                          "̽�˰��죬ȴ����" + me->name() + "�����쳣��"
                          "�ң�Զ���Լ���ʶ��" + me->name() + "�����ü"
                          "��չ�����ɵó�̾�������������˱���һ��ӹҽ��"
                          "�Σ�Ҳ����Ϊ���ˡ�";
                break;
        }

        message("vision", "ֻ��" + who->name() + "����ǰȥ����" +
                          me->name() + "�����ֹ��˼��䡣\n",
                          environment(who), ({ who }));

        if (who->query_skill(skill, 1) >= lvl)
        {
                // �ύ�ɹ���������Ϣ
                tell_object(who, sort_msg(WHT + suc_msg + "\n\n" NOR));

                // ������ɣ�ע�ά������
                who->set("ultra_quest/npc", me->name());
                who->set("ultra_quest/gift/point", 350);
                who->set("ultra_quest/gift/msg", "��ͨ���˷�����" +
                                                 me->name() + "�ľ���");

                if (! who->is_busy())
                        who->start_busy(3);

                // ������轱����Ʒ
                if (random(5) == 1)
                {
                        message_vision(CYN "$N" CYN "����" + wa + "��Ϊ��"
                                       "ʵ��" + ma + "�۷����ѡ�һ�㱡��"
                                       "���ɾ��⡣\n" NOR, me);

                        who->set("ultra_quest/gift/item", 1);
                }

                // ϵͳ����ô�����Ľ���
                give_gift(who);
        } else
        {
                // �ύʧ�ܵ�������Ϣ
                tell_object(who, sort_msg(WHT + fai_msg + "\n\n" NOR));

                message_vision(CYN "$N" CYN "ҡ��ҡͷ����$n"
                               CYN "����Ҳ�գ��һ������½���"
                               "�������������ɡ�\n" NOR, me, who);

                // �����жϣ�ϵͳ���·��������
                give_quest(who);
        }
        // ע��������������������
        me->delete_temp("need_accede");

        return 1;
}

// ���������������Ʒ
int accept_object(object me, object who, object ob)
{
        string msg;
        string type, obj;

        // ���û����ȡ����
        if (! who->query("ultra_quest/quest"))
                return 0;

        // ֻ��ɱ�ˡ�Ѱ�����/�����������ִ����Ʒ����
        if (! stringp(type = who->query("ultra_quest/quest/type"))
           || (type != "kill" && type != "find"
           && type != "give" && type != "send"))
                return 0;

        // �������Ϊ�����ż��������NPC
        if (me->name() == who->query("ultra_quest/quest/obj"))
        {
                switch (type)
                {
                case "send" :
                        if (! ob->is_letter())
                                return 0;

                        if (ob->query("send/send") != me->name())
                        {
                        	message_vision(CYN "$N" CYN "��ü�����������ô����"
                        	               "�����ֲ���д���ҵġ�\n" NOR, me);
                                return 0;
                        }

                        if (ob->query("send/user") != who->name())
                        {
                        	message_vision(CYN "$N" CYN "��ü����������˭������"
                        	               "�ģ�����ô����ʶ��\n" NOR, me);
                                return 0;
                        }

                        message_vision(CYN "$N" CYN "���˿�" + ob->name()
                                       + NOR + CYN "�����ÿɷ�ĵ��˵�ͷ��\n" NOR, me);
                        destruct(ob);
                        break;

                case "give" :
                        if (! ob->is_bag())
                                return 0;

                        if (ob->query("send/send") != me->name())
                        {
                        	message_vision(CYN "$N" CYN "��ü�����������ô����"
                        	               "�����ֲ����ø��ҵġ�\n" NOR, me);
                                return 0;
                        }

                        if (ob->query("send/user") != who->name())
                        {
                        	message_vision(CYN "$N" CYN "��ü�����������˭����"
                        	               "�ģ��������Լ����Űɡ�\n" NOR, me);
                                return 0;
                        }

                        message_vision(CYN "$N" CYN "���˿�" + ob->name()
                                       + NOR + CYN "�����ÿɷ�ĵ��˵�ͷ��\n" NOR, me);
                        destruct(ob);
                        break;
                }
                return 1;
        }

        // �������Ϊ���������NPC
        if (me->name() == who->query("ultra_quest/next_npc"))
        {
                switch (type)
                {
                case "send" :
                        message_vision(CYN "$N" CYN "���˿�" + ob->name()
                                       + NOR + CYN "�����ÿɷ�ĵ��˵�ͷ��\n" NOR, me);
                        break;

                case "give" :
                        message_vision(CYN "$N" CYN "���˿�" + ob->name()
                                       + NOR + CYN "�����ÿɷ�ĵ��˵�ͷ��\n" NOR, me);
                        break;

                case "kill" :
                        message_vision(CYN "$N" CYN "���˿�" + ob->name()
                                       + NOR + CYN "�����ÿɷ�ĵ��˵�ͷ��\n" NOR, me);
                        break;

                case "find" :
                        message_vision(CYN "$N" CYN "���˿�" + ob->name()
                                       + NOR + CYN "�����ÿɷ�ĵ��˵�ͷ��\n" NOR, me);
                        break;
                }
                return 1;
        }
}

// �������Ľ���
public void give_gift(object me)
{
        int gift;

        // ���û��ע�ά�����������ж�
        if (! me->query("ultra_quest/gift/msg")
           || ! me->query("ultra_quest/gift/point"))
                return;

        // ����������ɵ�����
        me->add("ultra_quest/finish", 1);

        // ������Ʒ����
        if (me->query("ultra_quest/gift/item"))
                special_bonus(me);

        // �����ĵ���
        gift = me->query("ultra_quest/gift/point") +
               me->query("ultra_quest/finish");

        GIFT_D->delay_work_bonus(me, ([ "prompt"  : me->query("ultra_quest/gift/msg"),
                                        "exp"     : random(gift) + gift,
                                        "pot"     : random(gift / 2) + gift / 2,
                                        "score"   : random(gift / 20) + gift / 20,
                                        "weiwang" : random(gift / 30) + gift / 30, ]));

        // ȡ����ԭ������������
        me->delete("ultra_quest/gift");
        me->delete("ultra_quest/quest");

        // �ṩ�µ��������Ա���������
        generate_information(me);
        return;
}

// �������ṩ��������Ϣ
public void generate_information(object me)
{
        string *lines, file;
        string where, next_npc, npc_place;
        string npc, msg, ma;

        npc = me->query("ultra_quest/npc");

        // û����һ���ṩ��������
        if (! npc) return;

        // ����ϵͳԤ�������������������
        file = read_file(QUEST + "npc");
        lines = explode(file, "\n");
        where = lines[random(sizeof(lines))];

        if (sscanf(where, "%s/%s", npc_place, next_npc) != 2)
                return;

        // ���ϵͳ���õ���������������������ִ�г���
        if (next_npc == npc)
        {
/*
                tell_object(me, HIC "��������Ϣ��" NOR +
                                WHT "ϵͳԤѡ����" HIY + next_npc +
                                NOR + WHT "���ṩ��������" HIY + npc +
                                NOR + WHT "��ͬ������������ѡ��\n\n" NOR);
*/
                generate_information(me);
                return;
        }

        // ��¼����һ���������Ｐ���ֵ�
        me->set("ultra_quest/next_npc", next_npc);
        me->set("ultra_quest/npc_place", npc_place);

        // �����Ŀ����ɫ
        next_npc = HIY + next_npc + NOR + WHT;

        // ���˳����򵥻�
        ma = RANK_D->query_respect(me);

        switch (random(5))
        {
        case 0:
                msg = "����˵������" + npc_place + "��" +
                      next_npc + "����" + ma + "Ҫ�ҵĶ�"
                      "����Ҳ��֪�����Ǽ�";
                break;

        case 1:
                msg = ma + "֪��" + npc_place + "������"
                      "�и�" + next_npc + "�����˽�������"
                      "������Щ����";
                break;

        case 2:
                msg = "��֪" + ma + "��ʶ" + npc_place +
                      "��" + next_npc + "�𣿴�����Ҫ�ҵ�"
                      "�Ƕ�������������";
                break;

        case 3:
                msg = "�����" + ma + "�Ƿ���ʶ" + npc_place +
                      "��" + next_npc + "���Ƕ���ʮ�а˾�"
                      "�������й�";
                break;

        default:
                msg = "�����롭" + ma + "ȥ��" + npc_place +
                      "��" + next_npc + "���ʿ��ɣ�ȥ������"
                      "��˵��������";
                break;
        }

        // ��ʼ����������������ˢ������
        if (npc == QUESTER)
        {
                if (me->query("ultra_quest/new_begin"))
                        msg = "���š���ȥ" + npc_place +
                              "����" + next_npc + "�������Ƕ�"
                              "�ƺ�����Щ����";
                else
                        msg = "�����ȥ" + npc_place +
                              "��" + next_npc + "������������"
                              "���ƺ���Щ����";
        }

        // �͵�ı���ֻҪ��Ǯ�ͺ�˵��
        if (npc == LURCHER)
        {
                switch (random(3))
                {
                case 0:
                        msg = "���ٺ١���ȥ" + npc_place +
                              "��䣬�Ƕ��и�" + next_npc +
                              "��������ɶ��֪��";
                        break;

                case 1:
                        msg = "�������ɡ���ȥ��" + next_npc +
                              "���ʿ����Ǽһ����" + npc_place +
                              "���ɱ��߶���";
                        break;

                default:
                        msg = "�㵽" + npc_place + "�����"
                              "������" + next_npc + "���ˣ�˵"
                              "�������ٺ١�����ɶ�ջ�";
                        break;
                }
        }

        // �ṩ��������Ϣ
        message("vision", npc + "������" + me->name() + "��"
                          "��˵��Щʲô��\n", environment(me),
                          ({ me }));

        // �ṩ�������������Ϣ
        msg = WHT + npc + WHT "���Ķ���˵����" + msg + "��\n" NOR;

        tell_object(me, sort_msg(msg));

        return;
}
