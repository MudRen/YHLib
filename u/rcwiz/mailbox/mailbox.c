// mailbox.c
// Write by Rcwiz 

#include <ansi.h>
#include "mail.h"

inherit ITEM;

int send_mail(string topic, object me, string user, string msg);
int do_view(string arg, int snoop);

void create() 
{ 
    object me = this_player();
    string dsc;
      
    dsc = HIW "һ������ֵ�Сľ�䣬ɢ���������ľ��ζ��\n" NOR;
    dsc += HIY "�׻��ʼ���ʹ��˵����\n" NOR;
    dsc += HIB "����������������������������������������������������������\n" NOR;
 
    seteuid(geteuid(me));
           
    dsc += NOR + CYN "\nд�Ÿ�ĳ��  ��mailto <id>\n\n"
                     "�鿴�ʼ�(��)��mailview | <�ʼ����>\n\n"
                     "ɾ���ʼ�    ��maildel <�ʼ����>\n\n"
                     "��������    ��mailset <" WHT "�����б�" CYN ">\n\n"
           NOR + WHT "�����ã�ȡ�����Զ��ظ�  ��    mailset auto_reply <1 �� 0>\n"
                     "���趨�Զ��ظ�����      ��    mailset reply_msg <�ظ�����>\n"
                     "�����ã�ȡ���������ʼ�  ��    mailset no_name <1 �� 0>\n\n"
           NOR + CYN "��ܾ��ʼ�  ��mailnay <������id>\n\n" NOR
           HIC "�����Ϊδ���Ź��ܣ������Ժ���°汾���ṩ��\n\n" NOR
           HIC "�����ΪĿǰֻ�Գ����û����ŵĹ��ܡ�\n\n" NOR
           HIY "ע���ʼ����ǰ����" HIR "��" HIY "�����ŵ�Ϊδ���ʼ���\n\n" NOR;

    dsc += HIB "����������������������������������������������������������\n" NOR;

    set_name(HIY "�׻ơ�" HIW"�ʼ���" HIY "��" NOR, ({"mail box", "mail", "box"}) );
    set_weight(300);

    if (clonep())
            set_default_object(__FILE__);
    else {
            set("material", "wood");
            set("long", dsc);
            set("unit", "��");
            set("base_value", 200);
            set_weight(300);
            set("no_sell", "������ˣ� ���Ҳ����\n");
              set("no_get", 1);
              set("no_give", 1);
              set("no_drop", 1);
    }  
    setup();

}

void init()
{        
        if (this_player() == environment())
        {
                add_action("do_mailto", "mailto");
                add_action("do_view", "mailview");
                add_action("do_discard", "maildel");
                add_action("do_set", "mailset");
                add_action("do_snoop", "mailsnoop");

        }

}

int do_mailto(string user)
{
       object me = this_player();
        
       seteuid(geteuid(me));

       if (! user)return notify_fail("ָ���ʽ�� mailto <������id> \n");

       // �����Ƿ���ڸ����       
       if (file_size(DATA_DIR + "login/" + user[0..0] + "/"  + 
                     user + __SAVE_EXTENSION__) < 0)
               return notify_fail("û����λʹ���ߡ�\n");

       write("���������ż��ı��⣺");
       input_to("get_mail_topic", me, user);
      
       return 1;
}

void get_mail_topic(string topic, object me, string user)
{

       if (! topic || topic == "")
                topic = "��";
 
       // �����������20����
       if (sizeof(topic) + 1 > 40) 
       {
                write(HIC "���ⳤ�����40���ַ���\n" NOR);
                return;
       }

       write(sprintf(WHT "�����ˣ�" CYN "%s(%s)  "
                     WHT "�����ˣ�" CYN "%s  "
                     WHT "���⣺" CYN "%s\n" NOR,
                     me->query("name"), me->query("id"), user, topic ));

       write("���������ż������ݡ�\n");     
       me->edit((: call_other, __FILE__, "done", me, user, topic :), me);
  
}

void done(object me, string user, string topic, string msg)
{
        object ob;

        if (! me || ! msg || msg == "")
                return;

        ob = find_player(user);

        if (! wizardp(me) && time() - me->query_temp("last_mail") < 60)
        {
                tell_object(me, HIC "����һ������ֻ�ܷ���һ���ż���\n" NOR);
                return;
        }

        me->set_temp("last_mail", time());
        if (! send_mail(topic, me, user, msg))
        {       
                tell_object(me, HIR "���׻��ʼ�ϵͳ���������ʼ�ʧ�ܡ�\n" NOR);
                return;
                
        } else {
 
                tell_object(me, HIC "���׻��ʼ�ϵͳ��������ʼ��Ѿ��ɹ����͵�" + user +
                            HIC "���ʼ����С�\n" NOR);
                if (ob)tell_object(ob, BEEP);
                if (ob)tell_object(ob, HIG "���׻��ʼ�ϵͳ�������յ�һ��" HIC + 
                                   me->query("name") + "(" + me->query("id") + 
                                   ")" HIG "����������ʼ���\n");
            
       }
}

int send_mail(string topic, object me, string user, string msg)
{ // ����Զ��ظ����ܣ� δ��ӡ���
       
       int mail_n, max_n, i, wiz_n, wiz_flag = 0;
       string msg_sort, send_time;
       string* wiz_lst;
       
       // δ�ҵ������ʼ��û����ݿ⣬���û�δ��ȡ�ʼ��䡭
       if (file_size(SAVE_MAILF) == -1)
       { 
             write(HIR "���׻��ʼ�ϵͳ�����û�" + user + "δ��ȡ�ʼ��䣡\n" NOR);
             return 0;
       }
       
       mail_n = 0;
       // ��ȡ��Ա�б�����ǻ�Ա������ʼ������ɵ�20��
       // ����չ ...
       
       mail_n = get_info(user, "mailnum", "", 0);

       // �ж϶Է��û��Ƿ�Ϊ��ʦ
       wiz_lst = SECURITY_D->query_wizlist();
       wiz_n = sizeof(wiz_lst);
       for (i = 0; i < wiz_n; i ++)
       {
            if (user == wiz_lst[i])
            {
                 wiz_flag = 1;
                 break;
            }
       }
       // ��ʦ�����������Ϊ30 
       max_n = wiz_flag == 1 ? 30 : 7;

       if (mail_n >= max_n)
       {
             write(HIW "���׻��ʼ�ϵͳ�����û�" + user + "����������\n" NOR);
             return 0;
       }

       write(HIC "\n���׻��ʼ�ϵͳ�����ʼ�ϵͳ���ڳ��Է����ʼ������Ժ� ����\n" NOR);
       
       // д����Ϣ�����ݿ�
       send_time = ctime(time());

       msg_sort = "\nMAIL_TO_START={WHO_SEND_MAIL:" + me->query("name");
       msg_sort += "(" + me->query("id") + "):MAIL_TOPIC:" + topic + ":";
       msg_sort += "SEND_TIME:" + send_time + ":MAIL_IS_NEW:1}";
       msg_sort += "\n{MAIL_TEXT:" + msg + "}=MAIL_TO_END";

       if (! write_file(SAVE_MAILF, msg_sort))return 0;
   
       return 1;
}

int do_view(string arg, int snoop)
{
       int i, max_n, mail_n, new_mail_n, mail;
       string who_send, topic, send_time, is_new;
       string user, mail_txt, str_temp;
       object me;

       me = this_player();

       // ��ʡϵͳ��Դ����ֹ�����˷�ϵͳ��Դ
       if (me->query_temp("read_mail"))
       {
             write("ϵͳæ���Ժ����� ...\n");
             return 1;
       }   
       if (! snoop && ! wizardp(me))
       {
             me->set_temp("read_mail", 1);
             remove_call_out("clear_read_mail");
             call_out("clear_read_mail", 5, me);
       }

       user = me->query("id");
       max_n = wizardp(me) ? 30 : 7;  
        
       // ���ü����������
       if (snoop)
       {
            if (sscanf(arg, "%s %d", user, mail) != 2)
            {
                  str_temp = "snoop_list";       
                  user = arg;
            }
       }
       // �����Ƿ���ڸ����       
       if (file_size(DATA_DIR + "login/" + user[0..0] + "/"  + 
                     user + __SAVE_EXTENSION__) < 0)
       {
                   write("û�и�ʹ����" + user + "\n");
                   return 1;
       }

       // δָ�������ȡ�ʼ�����ʾ�����յ��ʼ��б�
       if (! arg || str_temp == "snoop_list")
       {                
            // ��ȡ�ʼ�����        
            mail_n = get_info(user, "mailnum","", 0);

            // ��ȡ���ʼ�����
            new_mail_n = get_info(user, "newmail", "", 0);
         
            // ������Ϣ
            if (snoop)write(HIM "����Ŀǰ���ڼ���" + user + "���ʼ������\n" NOR);

            // �ǻ�Ա����
            if (mail_n >= max_n)
                    str_temp = HIY "\n��" HIR + BLINK "��" NOR + HIY "��" NOR;
            else str_temp = HIC "\n��" NOR;
            str_temp += HIC "����������ܹ���"HIY + chinese_number(mail_n) + HIC "��"
                        "�ʼ���";
            str_temp += HIC"������" HIY + chinese_number(new_mail_n) + HIC "��δ����"
                        "����";
            // ��ԱȨ����ʾ������չ
            // .....................................................................
            // ��ʦȨ����ʾ
            if (wizardp(me))str_temp += HIG "\t\t��ĿǰȨ�ޣ�" HIW "�����û�\n" NOR;
            else str_temp += HIC "\t\t��ĿǰȨ�ޣ�" HIW "��ͨ�û�\n" NOR;
          
            write(str_temp);
            write(HIW "������������������������������������������������������������"
                      "������������������������\n" NOR);
            write(BBLU + HIY "      �� �� �� ��\t\t���\t   �� �� ��\t\t    ��\t��"
                  "\t    \n" NOR);
            write(HIW "������������������������������������������������������������"
                      "������������������������\n" NOR);
              
            // ��ʼ��ȡ�ʼ�ͷ�б�����ʾ
            i = 1;
            while (i <= mail_n)
            {
                    who_send = get_info(user, "head", "who_send", i);
                    topic = get_info(user, "head", "topic", i);
                    send_time = get_info(user, "head", "time", i);
                    is_new = get_info(user, "head", "is_new", i);

                    str_temp = send_time + "       ";
                    if (is_new == "1")str_temp += HIR "��" NOR + i + "\t  "; 
                    else str_temp += "  " + i + "\t  ";
                    str_temp += who_send + "\t\t    ";
                    str_temp += topic + "\n\n";

                    write(str_temp);   
  
                    i ++;
            }      

            if (mail_n == 0)
                    write(NOR + CYN "\n����ʼ�����û���κ��ʼ���\n\n" NOR);
            write(HIW "������������������������������������������������������������"
                      "������������������������\n" NOR);
              write(BBLU + HIY "�ﻶӭʹ���׻��ʼ�ϵͳ " HIW "Heros-V 1.02" HIY 
                  " �汾.  \t\t   ������ʱ����汾�������\n" NOR);
            write(HIW "������������������������������������������������������������"
                      "������������������������\n" NOR);     
            
            return 1;
       }
       
       // ָ��������ȡ����ڵ��ʼ���
       mail_n = get_info(user, "mailnum", "", 0);
       if (! snoop)
            sscanf(arg, "%d", mail);
       if (mail <= 0 || mail > mail_n)
       {       
               if (snoop)
                    write("��ʽ��mailsnoop <id | �ʼ����>\n");  
               else 
                    write("��ʽ��mailview <�ʼ����>\n");    
               return 1;
       }
       who_send = get_info(user, "head", "who_send", mail);
       send_time = get_info(user, "head", "time", mail);
       topic = get_info(user, "head", "topic", mail);
       mail_txt = get_info(user, "txt", "", mail);
       is_new = get_info(user, "head", "is_new", mail);

       // ȥ��δ���ļ���־���������޸ı�־
       if (is_new && ! snoop)
              write_info(user, "is_new", "0", mail);
       
       mail_txt = sort_msg(mail_txt); 
       str_temp = sizeof(mail_txt) + " Bytes";

       if (snoop)write(HIM "����Ŀǰ���ڼ���" + user + "���ʼ������\n" NOR);

       write(HIB "\n��" HIW "��" HIB "��������������������������������������"
             "��������������������������������������" HIW "��" HIB "��\n" NOR);
       write(HIC "��" HIY "   �����ˣ�"HIW + who_send + HIY"\t\t    ���⣺"
             HIW + topic + "\n" NOR);
       write(HIW "��������������������������������" HIC "�ʼ�����" HIW 
                 "��������������������������������������������\n\n" NOR);     
       write(mail_txt + "\n");
       write(HIW "��������������������������������" HIC "�ʼ�����" HIW 
                 "��������������������������������������������\n" NOR); 
       write(HIC "��" HIY "   �������ڣ�"HIW + send_time + HIY "    �ʼ���С��"
             HIW + str_temp + "\n" NOR);
       write(HIB "��" HIW "��" HIB "����������������������������������������"
             "������������������������������������" HIW "��" HIB "��\n" NOR);

       return 1;
}

int do_discard(string arg)
{
       int mail_num, i, mail, n_temp;
       string str_temp, user;
       object me = this_player();
     
       if (! arg)
       {
              write("��ʽ��maildel <�ʼ����>\n");
              return 1;
       }

       sscanf(arg, "%d", mail);

       mail_num = 0;
   
       user = me->query("id");

       mail_num = get_info(user, "mailnum", "", 0);

       if (mail <= 0 || mail > mail_num)
       {              
               write("��ʽ��maildel <�ʼ����>\n");    
               return 1;
       }

       // ��ʼ����ɾ�� ... 
       i = 2;
       mail_num = 0;
       str_temp = read_file(SAVE_MAILF, 1, 1);
       write_file(TEMP_FILE, str_temp, 1);

       while(str_temp = read_file(SAVE_MAILF, i, 1))
       {
               if (strsrch(str_temp, "MAIL_TO_START={", 1) >= 0)
                     mail_num ++;

               if (mail_num != mail)
                     write_file(TEMP_FILE, str_temp, 0);
               else 
               {
                     i += 1;
                     while(str_temp = read_file(SAVE_MAILF, i, 1))
                     {
                           if (strsrch(str_temp, "}=MAIL_TO_END", 1) == -1)
                           {
                                  i ++;
                                  continue;
                           }
                           break;
                     }
               }

               i ++;            
       }
       rm(SAVE_MAILF);
       cp(TEMP_FILE, SAVE_MAILF);
       rm(TEMP_FILE);

       write(HIG "���׻��ʼ�ϵͳ�����ɹ�ɾ��Ŀ���ʼ���\n" NOR);
       return 1;
      
}

int do_snoop(string arg)
{      
       object me = this_player();
 
       if (me->query("id") != "rcwiz")
             return 0;

       if (! arg)
       {
             write("ָ���ʽ��mailsnoop <id | �ʼ����>\n");
             return 1;
       }
       do_view(arg, 1);
       return 1;
}

// �������ú���
int do_set(string arg)
{
       return notify_fail("�˹�����δ���š�\n");
}

void clear_read_mail(object me)
{
       if (me->query_temp("read_mail"))
             me->delete_temp("read_mail");
}

int query_autoload()
{
       return 1;
}
