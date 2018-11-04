// giftd.c
// Written by Vin for Heros.cn 2002/07/14.

#include <ansi.h>
#include <quest.h>

inherit F_DBASE;
inherit F_CLEAN_UP;

// �����ṩ���ⲿ���õĽӿں���
varargs public void bonus(object who, mapping b, int flag);
varargs public void freequest_bonus(object who);
varargs public void gift_bonus(object who, mapping b);
varargs public void work_bonus(object who, mapping b);
public void delay_bonus(object who, mapping b);
public void delay_freequest_bonus(object who);
public void delay_gift_bonus(object who, mapping b);
public void delay_work_bonus(object who, mapping b);

void create()
{
        seteuid(getuid());
        set("channel_id", "��������");
        set_heart_beat(900);
}

// �ӳٽ�������Ϊ��ʱ����������ʱ��Ӧ������ĳЩ�¼������Ժ�
// �����ڸ��¼�����ʱ���뽱����������д�������Խ������ɵ�
// �ط����¼����ڷ�����ʱ�򣬵���Ҫ����ҿ����������¼�����
// �Ժ󡣱���ɱ�ˣ���������ʱ����뽱�����������ģ�������ϣ
// ������ڿ���NPC ��������Ϣ�Ժ�ſ�����������Ϣ����ʱ���
// ��delay_bonus�ˡ�

public void delay_bonus(object who, mapping b)
{
        who->start_call_out((: call_other, __FILE__,
                               "bonus", who, b :), 1);
}

public void delay_work_bonus(object who, mapping b)
{
        who->start_call_out((: call_other, __FILE__,
                               "work_bonus", who, b :), 1);
}

public void delay_freequest_bonus(object who)
{
        who->start_call_out((: call_other, __FILE__,
                               "freequest_bonus", who :), 3);
}

public void delay_gift_bonus(object who, mapping b)
{
        who->start_call_out((: call_other, __FILE__,
                               "gift_bonus", who, b :), 1);
}

// ��������Ľ���
varargs public void bonus(object who, mapping b, int flag)
{
        int exp;                // �����ľ���
        int pot;                // ������Ǳ��
        int mar;                // ������ʵս���
        int shen;               // ��������
        int score;              // �����Ľ�������
        int weiwang;            // �����Ľ�������
        int gongxian;           // ���������ɹ���
        int pot_limit;          // Ǳ�ܵĽ���
        int mar_limit;          // ʵս���Ľ���
        int percent;            // ��������Ч�ٷֱ�
        string msg;             // ������������Ϣ
        string league_name;
        int weiwang2, league_weiwang;


        league_weiwang = who->query("league/set/weiwang");
        // ��ý����İٷֱ�
        percent = b["percent"];
        if (percent < 1 || percent > 100)
                percent = 100;

        exp = b["exp"] * percent / 100;
        pot = b["pot"] * percent / 100;
        mar = b["mar"] * percent / 100;
        shen = b["shen"] * percent / 100;
        score = b["score"] * percent / 100;
        weiwang = b["weiwang"] * percent / 100;
        gongxian = b["gongxian"] * percent / 100;

        // ��Ҿ���̫�ߣ�����������
        if (who->query("combat_exp") >= 3000000)
        {
                exp /= 8;
                pot /= 8;
                mar /= 8;
        } else
        if (who->query("combat_exp") >= 2000000)
        {
                exp /= 4;
                pot /= 4;
                mar /= 4;
        } else
        if (who->query("combat_exp") >= 1000000)
        {
                exp /= 2;
                pot /= 2;
                mar /= 2;
        }

        if (! flag)
        {
                pot_limit = who->query_potential_limit() - who->query("potential");
                if (pot > pot_limit) pot = pot_limit;
                if (pot < 1) pot = 0;

                mar_limit = who->query_experience_limit() - who->query("experience");
                if (mar > mar_limit) mar = mar_limit;
                if (mar < 1) mar = 0;
        } else
        {
                if (who->query_potential_limit() < who->query("potential"))
                        pot = 1 + random(2);

                if (who->query_experience_limit() < who->query("experience"))
                        mar = 1;
        }

        // ������ʾ��Ϣ
        if (stringp(msg = b["prompt"]))
                msg = HIG + msg + HIG "��������";
        else
                msg = HIG "ͨ����ζ�����������";

        if (exp > 0) msg += chinese_number(exp) + "�㾭�顢";
        if (pot > 0) msg += chinese_number(pot) + "��Ǳ�ܡ�";
        if (mar > 0) msg += chinese_number(mar) + "��ʵս��ᡢ";
        if (shen > 0) msg += chinese_number(shen) + "������";
        if (shen < 0) msg += chinese_number(-shen) + "�㸺��";
        if (score > 0) msg += chinese_number(score) + "�㽭��������";

        if (stringp(league_name = who->query("league/league_name"))
            && league_weiwang)
        {                        
                if (weiwang > 0)
                {
                                                                  
                         weiwang2 = weiwang * league_weiwang / 100;
                         weiwang = weiwang - weiwang2;
                         if (weiwang <= 0 )weiwang = 0;
                         if (weiwang > 0)msg += chinese_number(weiwang) + "�㽭��������";
                         msg += "������ͬ�˵�����������" + chinese_number(weiwang2) + "�㡢";
                                        
                }

         }               
         else  if (weiwang > 0) msg += chinese_number(weiwang) + "�㽭��������";

        msg += "�����õ���������\n" NOR;
        tell_object(who, sort_msg(msg));

        // bonus
        who->add("combat_exp", exp);
        who->add("potential", pot);
        who->add("experience", mar);
        who->add("shen", shen);
        who->add("score", score);
        who->add("weiwang", weiwang);
        if (weiwang2 > 0)LEAGUE_D->add_league_fame(league_name, weiwang2);
        who->add("gongxian", gongxian);
}

// ��ͨ��������Ľ���
varargs public void work_bonus(object who, mapping b, int flag)
{
        int exp;                // �����ľ���
        int pot;                // ������Ǳ��
        int mar;                // ������ʵս���
        int shen;               // ��������
        int score;              // �����Ľ�������
        int weiwang;            // �����Ľ�������
        int gongxian;           // ���������ɹ���
        int pot_limit;          // Ǳ�ܵĽ���
        int mar_limit;          // ʵս���Ľ���
        int percent;            // ��������Ч�ٷֱ�
        string msg;             // ������������Ϣ
        string league_name;
        int weiwang2, league_weiwang;


        league_weiwang = who->query("league/set/weiwang");
        // ��ý����İٷֱ�
        percent = b["percent"];
        if (percent < 1 || percent > 100)
                percent = 100;

        exp = b["exp"] * percent / 100;
        pot = b["pot"] * percent / 100;
        mar = b["mar"] * percent / 100;
        shen = b["shen"] * percent / 100;
        score = b["score"] * percent / 100;
        weiwang = b["weiwang"] * percent / 100;
        gongxian = b["gongxian"] * percent / 100;

        if (! flag)
        {
                pot_limit = who->query_potential_limit() - who->query("potential");
                if (pot > pot_limit) pot = pot_limit;
                if (pot < 1) pot = 0;

                mar_limit = who->query_experience_limit() - who->query("experience");
                if (mar > mar_limit) mar = mar_limit;
                if (mar < 1) mar = 0;
        } else
        {
                if (who->query_potential_limit() < who->query("potential"))
                        pot = 1 + random(2);

                if (who->query_experience_limit() < who->query("experience"))
                        mar = 1;
        }

        // ������ʾ��Ϣ
        if (stringp(msg = b["prompt"]))
                msg = HIC "\n" + msg + HIC "��������";
        else
                msg = HIC "\nͨ����ζ�����������";

        if (exp > 0) msg += chinese_number(exp) + "�㾭�顢";
        if (pot > 0) msg += chinese_number(pot) + "��Ǳ�ܡ�";
        if (mar > 0) msg += chinese_number(mar) + "��ʵս��ᡢ";
        if (shen > 0) msg += chinese_number(shen) + "������";
        if (shen < 0) msg += chinese_number(-shen) + "�㸺��";
        if (score > 0) msg += chinese_number(score) + "�㽭��������";

        if (stringp(league_name = who->query("league/league_name"))
            && league_weiwang)
        {                        
                if (weiwang > 0)
                {
                                                           
                      weiwang2 = weiwang * league_weiwang / 100;
                      weiwang = weiwang - weiwang2;
                      if (weiwang <= 0 )weiwang = 0;
                      if (weiwang > 0)msg += chinese_number(weiwang) + "�㽭��������";
                      msg += "������ͬ�˵�����������" + chinese_number(weiwang2) + "�㡢";
                                        
                }

        }             
        else  if (weiwang > 0) msg += chinese_number(weiwang) + "�㽭��������";


        msg += "�����õ���������\n\n" NOR;
        tell_object(who, sort_msg(msg));

        // bonus
        who->add("combat_exp", exp);
        who->add("potential", pot);
        who->add("experience", mar);
        who->add("shen", shen);
        who->add("score", score);
        who->add("weiwang", weiwang);
        if (weiwang2 > 0)LEAGUE_D->add_league_fame(league_name, weiwang2);
        who->add("gongxian", gongxian);
}

// �ж�������������Ľ���
varargs public void freequest_bonus(object who)
{
        object gift;
        int quest;              // ��ǰ��������
        int exp;                // �����ľ���
        int pot;                // ������Ǳ��
        int mar;                // ������ʵս���
        string msg;             // ������������Ϣ

        quest = who->query("quest_count");

        exp = random(quest) + 500;

        // ��Ϊ��ý����϶����޷��ۼ��ж�����������ʱ����
        // ���޵����ơ�
        pot = random(quest / 2) + 250;
        mar = random(quest / 2) + 250;

        msg = HIC "\n������ε����������У�����ѧ�ƺ���"
              "�����µ�ͻ�ơ�������" +
              chinese_number(exp) + "�㾭�顢" +
              chinese_number(pot) + "��Ǳ�ܼ�" +
              chinese_number(mar) + "��ʵս��ᡣ\n" NOR;

        tell_object(who, sort_msg(msg));

        // bonus
        who->add("combat_exp", exp);
        who->add("potential", pot);
        who->add("experience", mar);
        who->add("quest/freequest", -1);

        if (who->query("quest/freequest") < 1)
        {
                who->delete("quest");
                message_sort(HIW "\n������ʱ��ֻ��һλ" +
                             who->query("family/family_name") +
                             "���Ӽ���ææ�ϵ�$N" HIW "��ߣ�˵"
                             "������ԭ���������ﰡ��ʦ����������"
                             "�������ء���˵��Ҫ���½�����죬��"
                             "�Ͽ��ȥ�ɣ����������ʦ������ת��"
                             "����ġ���\n" NOR, who);

                message_sort("\n" + who->query("family/family_name") +
                             "�����ó�һ�������ݸ�$N��\n\n" +
                             who->query("family/family_name") +
                             "���Ӽ���ææ���뿪�ˡ�\n" NOR, who);

                gift = new("/clone/fam/bag");
                gift->move(who, 1);
        }
}

// �����¼��Ľ���
varargs public void gift_bonus(object who, mapping b)
{
        int exp;                // �����ľ���
        int pot;                // ������Ǳ��
        int mar;                // ������ʵս���
        int score;              // �����Ľ�������
        int weiwang;            // �����Ľ�������
        int gongxian;           // ���������ɹ���
        int percent;            // ��������Ч�ٷֱ�
        string msg;             // ������������Ϣ
        string temp;            // ���̼�¼��Ϣ
        int league_weiwang;     // �ָ�ͬ�˵������ٷֱ�
        int weiwang2;           // ͬ����õõ�������
        string league_name;

        league_weiwang = who->query("league/set/weiwang");

        // ��ý����İٷֱ�
        percent = b["percent"];

        if (percent < 1 || percent > 100)
                percent = 100;

        // ���̼�¼����Ե�һ������н��������
        temp = b["temp"];

        exp = b["exp"] * percent / 100;
        pot = b["pot"] * percent / 100;
        mar = b["mar"] * percent / 100;
        score = b["score"] * percent / 100;
        weiwang = b["weiwang"] * percent / 100;
        gongxian = b["gongxian"] * percent / 100;

        // ����ҥ����Ϣ
        if (stringp(msg = b["rumor"]))
        {
                shout(HIR "�����ִ��š�" NOR + WHT "��˵" +
                      who->name() + WHT "[" + who->query("id") +
                      WHT "]" + msg + WHT "��\n" NOR);
        }

        if (! stringp(temp) || ! who->query(temp))
        {
                // ������ʾ��Ϣ
                if (stringp(msg = b["prompt"]))
                        msg = HIW "\n" + msg + HIW "��������";
                else
                        msg = HIW "\nͨ���˴ξ�����������";

                // ��¼�½���
                if (stringp(temp))
                        who->add(temp, 1);

                if (exp > 0) msg += chinese_number(exp) + "�㾭�顢";
                if (pot > 0) msg += chinese_number(pot) + "��Ǳ�ܡ�";
                if (mar > 0) msg += chinese_number(mar) + "��ʵս��ᡢ";
                if (score > 0) msg += chinese_number(score) + "�㽭��������";
                if (gongxian > 0) msg += chinese_number(gongxian) + "�����ɹ��ס�";

                if (stringp(league_name = who->query("league/league_name"))
                    && league_weiwang)
                {                        
                        if (weiwang > 0)
                        {
                                                                  
                                 weiwang2 = weiwang * league_weiwang / 100;
                                 weiwang = weiwang - weiwang2;
                                 if (weiwang <= 0 )weiwang = 0;
                                 if (weiwang > 0)msg += chinese_number(weiwang) + "�㽭��������";
                                 msg += "������ͬ�˵�����������" + chinese_number(weiwang2) + "�㡢";
                                        
                        }

                }
                
                else  if (weiwang > 0) msg += chinese_number(weiwang) + "�㽭��������";
                msg += "�����õ���������\n" NOR;
                tell_object(who, sort_msg(msg));

                // bonus
                who->add("combat_exp", exp);
                who->add("potential", pot);
                who->add("experience", mar);
                who->add("score", score);
                who->add("weiwang", weiwang);
                if (weiwang2 > 0)LEAGUE_D->add_league_fame(league_name, weiwang2);
                who->add("gongxian", gongxian);
        }
}

