// Hero mail system Vtest 0.11

#include <room.h>
#include <ansi.h>
//#include "mail.h"

inherit ROOM;

//int send_mail(string topic, object me, string user, string msg);
//int do_view(string arg, int snoop);

void create()
{    
    string dsc;
      
    dsc = HIW "在这里你可以给玩家发送文本格式的虚拟邮件。\n" NOR;
    dsc += HIW "如果玩家离线后将以离线消息的形式通知。\n" NOR;
    dsc += HIW "在使用该邮件系统前请先注册，如果你的邮件数据出现问题请\n"
               " “ask mao zi about 修复数据” 来修复你的数据。\n\n" NOR;               
    dsc += HIY "炎黄邮件箱使用说明：\n" NOR;
    dsc += HIB "—————————————————————————————\n" NOR;
           
    dsc += NOR + CYN "\n写信给某人  ：mailto <id>\n"
                     "查看邮件(箱)：mailview | <邮件编号>\n"
                     "删除邮件    ：maildel <邮件编号>\n"
                     "参数设置    ：mailset <" WHT "参数列表" CYN ">\n"
           NOR + WHT "☆启用（取消）自动回复  ：    mailset auto_reply <1 或 0>\n"
                     "☆设定自动回复内容      ：    mailset reply_msg <回复内容>\n"
                     "☆启用（取消）匿名邮件  ：    mailset no_name <1 或 0>\n"
           NOR + CYN "☆拒绝邮件  ：mailnay <拒收者id>\n" NOR
           HIC "带“☆”为未开放功能，将在以后更新版本中提供。\n" NOR
           HIC "带“★”为目前只对超级用户开放的功能。\n" NOR
           HIY "注：邮件编号前带“" HIR "↑" HIY "”符号的为未读邮件。\n\n" NOR;

    dsc += HIB "—————————————————————————————\n" NOR;
    set("short", HIY "炎黄邮件中心" NOR);

    dsc = HIW "关闭测试中\n"NOR;
    set("long", dsc);

    set("exits", ([
	"south": "/d/wizard/hall",                               
    ]));

    set("objects", ([
        //__DIR__"npc/maozi" : 1,
        //__DIR__"mailbox" :  1,
    ]));

    set("no_fight", 1);
    set("no_clean_up", 1);
    setup();
}

/*
void init()
{        
       add_action("do_mailto", "mailto");
       add_action("do_view", "mailview");
       add_action("do_discard", "maildel");
       add_action("do_set", "mailset");
       add_action("do_snoop", "mailsnoop");

}

int do_mailto(string user)
{
       object me = this_player();
        
       seteuid(geteuid(me));

       if (! me->query("register_heromail"))
       {
             return notify_fail("你还没有注册，请 “ask zi about 注册” 先。\n");
       }

       if (! user)return notify_fail("指令格式： mailto <收信人id> \n");

       // 查找是否存在该玩家       
       if (file_size(DATA_DIR + "login/" + user[0..0] + "/"  + 
                     user + __SAVE_EXTENSION__) < 0)
               return notify_fail("没有这位使用者。\n");

       write("请输入你信件的标题：");
       input_to("get_mail_topic", me, user);
      
       return 1;
}

void get_mail_topic(string topic, object me, string user)
{

       if (! topic || topic == "")
                topic = "无";
 
       // 标题最多允许20个字
       if (sizeof(topic) + 1 > 40) 
       {
                write(HIC "标题长度最多40个字符。\n" NOR);
                return;
       }

       write(sprintf(WHT "发信人：" CYN "%s(%s)  "
                     WHT "收信人：" CYN "%s  "
                     WHT "主题：" CYN "%s\n" NOR,
                     me->query("name"), me->query("id"), user, topic ));

       write("请输入你信件的内容。\n");     
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
                tell_object(me, HIC "你在一分钟内只能发送一封信件。\n" NOR);
                return;
        }

        me->set_temp("last_mail", time());
        if (! send_mail(topic, me, user, msg))
        {       
                tell_object(me, HIR "【炎黄邮件系统】：发送邮件失败。\n" NOR);
                return;
                
        } else {
 
                tell_object(me, HIC "【炎黄邮件系统】：你的邮件已经成功发送到" + user +
                            HIC "的邮件箱中。\n" NOR);
                if (ob)tell_object(ob, BEEP);
                if (ob)tell_object(ob, HIG "【炎黄邮件系统】：你收到一封" HIC + 
                                   me->query("name") + "(" + me->query("id") + 
                                   ")" HIG "发给你的新邮件！\n");
            
       }
}

int send_mail(string topic, object me, string user, string msg)
{ // 添加自动回复功能， 未添加……
       
       int mail_n, max_n, i, wiz_n, wiz_flag = 0;
       string msg_sort, send_time;
       string* wiz_lst;
       
       // 未找到接受邮件用户数据库，该用户未领取邮件箱…
       if (file_size(SAVE_MAILF) == -1)
       { 
             write(HIR "【炎黄邮件系统】：用户" + user + "未领取邮件箱！\n" NOR);
             return 0;
       }
       
       mail_n = 0;
       // 读取会员列表，如果是会员则最大邮件数量可到20封
       // 待扩展 ...
       
       mail_n = get_info(user, "mailnum", "", 0);

       // 判断对方用户是否为巫师
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
       // 巫师最大信箱容量为30 
       max_n = wiz_flag == 1 ? 30 : 7;

       if (mail_n >= max_n)
       {
             write(HIW "【炎黄邮件系统】：用户" + user + "信箱已满！\n" NOR);
             return 0;
       }

       write(HIC "\n【炎黄邮件系统】：邮件系统正在尝试发送邮件，请稍后 ……\n" NOR);
       
       // 写入信息到数据库
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

       if (! me->query("register_heromail"))
       {
             return notify_fail("你还没有注册，请 “ask zi about 注册” 先。\n");
       }

       // 节省系统资源，防止恶意浪费系统资源
       if (me->query_temp("read_mail"))
       {
             write("系统忙请稍后再试 ...\n");
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
        
       // 设置监听对象参数
       if (snoop)
       {
            if (sscanf(arg, "%s %d", user, mail) != 2)
            {
                  str_temp = "snoop_list";       
                  user = arg;
            }
       }
       // 查找是否存在该玩家       
       if (file_size(DATA_DIR + "login/" + user[0..0] + "/"  + 
                     user + __SAVE_EXTENSION__) < 0)
       {
                   write("没有该使用者" + user + "\n");
                   return 1;
       }

       // 未指定具体读取邮件，显示所有收到邮件列表
       if (! arg || str_temp == "snoop_list")
       {                
            // 读取邮件总数        
            mail_n = get_info(user, "mailnum","", 0);

            // 读取新邮件数量
            new_mail_n = get_info(user, "newmail", "", 0);
         
            // 监听信息
            if (snoop)write(HIM "★你目前正在监听" + user + "的邮件箱↓★\n" NOR);

            // 非会员……
            if (mail_n >= max_n)
                    str_temp = HIY "\n『" HIR + BLINK "满" NOR + HIY "』" NOR;
            else str_temp = HIC "\n★" NOR;
            str_temp += HIC "你的信箱里总共有"HIY + chinese_number(mail_n) + HIC "封"
                        "邮件。";
            str_temp += HIC"其中有" HIY + chinese_number(new_mail_n) + HIC "封未读邮"
                        "件！";
            // 会员权限显示，待扩展
            // .....................................................................
            // 巫师权限显示
            if (wizardp(me))str_temp += HIG "\t\t★目前权限：" HIW "超级用户\n" NOR;
            else str_temp += HIC "\t\t★目前权限：" HIW "普通用户\n" NOR;
          
            write(str_temp);
            write(HIW "——————————————————————————————"
                      "————————————\n" NOR);
            write(BBLU + HIY "      发 件 日 期\t\t编号\t   发 件 人\t\t    主\t题"
                  "\t    \n" NOR);
            write(HIW "——————————————————————————————"
                      "————————————\n" NOR);
              
            // 开始读取邮件头列表，并显示
            i = 1;
            while (i <= mail_n)
            {
                    who_send = get_info(user, "head", "who_send", i);
                    topic = get_info(user, "head", "topic", i);
                    send_time = get_info(user, "head", "time", i);
                    is_new = get_info(user, "head", "is_new", i);

                    str_temp = send_time + "       ";
                    if (is_new == "1")str_temp += HIR "↑" NOR + i + "\t  "; 
                    else str_temp += "  " + i + "\t  ";
                    str_temp += who_send + "\t\t    ";
                    str_temp += topic + "\n\n";

                    write(str_temp);   
  
                    i ++;
            }      

            if (mail_n == 0)
                    write(NOR + CYN "\n你的邮件箱中没有任何邮件。\n\n" NOR);
            write(HIW "——————————————————————————————"
                      "————————————\n" NOR);
              write(BBLU + HIY "★欢迎使用炎黄邮件系统 " HIW "Heros-V 1.02" HIY 
                  " 版本.  \t\t   ★请随时留意版本更新情况\n" NOR);
            write(HIW "——————————————————————————————"
                      "————————————\n" NOR);     
            
            return 1;
       }
       
       // 指定编号则读取编号内的邮件…
       mail_n = get_info(user, "mailnum", "", 0);
       if (! snoop)
            sscanf(arg, "%d", mail);
       if (mail <= 0 || mail > mail_n)
       {       
               if (snoop)
                    write("格式：mailsnoop <id | 邮件编号>\n");  
               else 
                    write("格式：mailview <邮件编号>\n");    
               return 1;
       }
       who_send = get_info(user, "head", "who_send", mail);
       send_time = get_info(user, "head", "time", mail);
       topic = get_info(user, "head", "topic", mail);
       mail_txt = get_info(user, "txt", "", mail);
       is_new = get_info(user, "head", "is_new", mail);

       // 去掉未读文件标志，监听则不修改标志
       if (is_new && ! snoop)
              write_info(user, "is_new", "0", mail);
       
       mail_txt = sort_msg(mail_txt); 
       str_temp = sizeof(mail_txt) + " Bytes";

       if (snoop)write(HIM "★你目前正在监听" + user + "的邮件箱↓★\n" NOR);

       write(HIB "\n─" HIW "↓" HIB "───────────────────"
             "───────────────────" HIW "↓" HIB "─\n" NOR);
       write(HIC "☆" HIY "   发件人："HIW + who_send + HIY"\t\t    主题："
             HIW + topic + "\n" NOR);
       write(HIW "————————————————" HIC "邮件正文" HIW 
                 "——————————————————————\n\n" NOR);     
       write(mail_txt + "\n");
       write(HIW "————————————————" HIC "邮件结束" HIW 
                 "——————————————————————\n" NOR); 
       write(HIC "☆" HIY "   发件日期："HIW + send_time + HIY "    邮件大小："
             HIW + str_temp + "\n" NOR);
       write(HIB "─" HIW "↑" HIB "────────────────────"
             "──────────────────" HIW "↑" HIB "─\n" NOR);

       return 1;
}

int do_discard(string arg)
{
       int mail_num, i, mail, n_temp;
       string str_temp, user;
       object me = this_player();

       if (! me->query("register_heromail"))
       {
             return notify_fail("你还没有注册，请 “ask zi about 注册” 先。\n");
       }
     
       if (! arg)
       {
              write("格式：maildel <邮件编号>\n");
              return 1;
       }

       sscanf(arg, "%d", mail);

       mail_num = 0;
   
       user = me->query("id");

       mail_num = get_info(user, "mailnum", "", 0);

       if (mail <= 0 || mail > mail_num)
       {              
               write("格式：maildel <邮件编号>\n");    
               return 1;
       }

       // 开始进行删除 ... 
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

       write(HIG "【炎黄邮件系统】：成功删除目标邮件！\n" NOR);
       return 1;
      
}

int do_snoop(string arg)
{      
       object me = this_player();

       if (! me->query("register_heromail"))
       {
             return notify_fail("你还没有注册，请 “ask zi about 注册” 先。\n");
       }
 
       if (me->query("id") != "rcwiz")
             return 0;

       if (! arg)
       {
             write("指令格式：mailsnoop <id | 邮件编号>\n");
             return 1;
       }
       do_view(arg, 1);
       return 1;
}

// 参数设置函数
int do_set(string arg)
{

       object me = this_player();

       if (! me->query("register_heromail"))
       {
             return notify_fail("你还没有注册，请 “ask zi about 注册” 先。\n");
       }

       return notify_fail("此功能尚未开放。\n");
}

void clear_read_mail(object me)
{
       if (me->query_temp("read_mail"))
             me->delete_temp("read_mail");
}
*/