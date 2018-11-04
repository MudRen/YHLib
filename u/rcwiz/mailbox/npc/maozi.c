
#include <ansi.h>

inherit NPC;

#define BOX "/u/rcwiz/mailbox/mailbox"
#define SAVE_MAILF "/u/rcwiz/mailbox/to_user_mails/" + user + ".m"

int give_mail_box();
int rebuild_data();

void create()
{
        seteuid(getuid());
        set_name("ë��", ({ "mao zi", "mao", "zi" }) );
        set("title", HIY "�׻���ʹ" NOR);
        set("nickname", HIW "��������" NOR);
        set("gender", "����" );
        set("age", 22);
        set("long", "ûʲô�ÿ��ģ��ܳ�\n");

        set("str", 40);
        set("con", 40);
        set("int", 40);
        set("dex", 40);

        set("max_qi", 100000);
        set("max_jing", 100000);
        set("neili", 100000);
        set("max_neili", 100000);
        set("jiali", 400);
        set("shen_type", 0);
        set("attitude", "peaceful");

        set_temp("apply/attack",  200);
        set_temp("apply/defense", 200);

        set("combat_exp", 8000000);

        set_skill("force", 500); 
        set_skill("dodge", 500);
        set_skill("parry", 500);
        set_skill("finger", 500);
        set_skill("martial-cognize", 500); 
        set_skill("yinyang-shiertian", 500); 

        map_skill("force", "yinyang-shiertian");
        map_skill("finger","yinyang-shiertian");
        map_skill("parry", "yinyang-shiertian");
        map_skill("dodge", "yinyang-shiertian");

        set("inquiry", ([
                "�׻��ʼ���" : (: give_mail_box :),
                "�޸��ʼ���" : (: rebuild_data :),
        ]));

        setup();

        carry_object("/clone/cloth/cloth")->wear();
        
}

int give_mail_box()
{
        object me = this_player();
        object box;
        string user, str;

        if (me->query("combat_exp") < 100000)
        {
              write(HIC "ë��˵���������ʵս����̫�٣�����Ϊ���ṩ�ʼ��䡣��\n" NOR);
              return 1;
        }
        if (box = present("mail box", me))
        {
              write(HIC "ë��ŭ�������߿��������⵷�ҡ���\n");
              return 1;
        }
        if (! me->query("get_mail_box"))     
        // ��ʼ�����ݿ�
        {
              user = me->query("id");
              str = "REFUSE={0}";
              write_file(SAVE_MAILF, str, 1);          
              str += "\nSETTINGS={REPLY:0:MSG:0:no_name:0}=SETTING_END";
              str += "\nMAIL_TO_START={WHO_SEND_MAIL:�׻��ʼ�ϵͳ:MAIL_TOPIC:��ӭʹ����";
              str += "���ʼ�ϵͳ:SEND_TIME:" + ctime(time()) + ":MAIL_IS_NEW:1}";
              str += "\n{MAIL_TEXT:������" + me->query("name") + ":\n";
              str += "    ��ã��ǳ���ӭ��ʹ���׻��ʼ�ϵͳ���������ʼ��д����κ�";
              str += "���ࡢ�������ֲ�����������Ϣ���������뼰ʱ��ϵ�׻���ʦ��ϣ��";
              str += "���ʼ�ϵͳ�ܸ������������Ҳϣ�����ܹ���и��֧���׻ƣ�";
              str += "\n                   --�׻�Ӣ��ʷ http://heros-cn.51.net";
              str += "\n}=MAIL_TO_END";
              write_file(SAVE_MAILF, str, 0);
        }
        if (box = find_object(BOX))
                 box = load_object(BOX);
        else box = new(BOX);

        box->move(me);
        write(HIC "ë���ó�һ���������Ӹ��㡣\n" NOR);
        if (! me->query("get_mail_box"))
              write(HIW "����ʼ�������һ�����ʼ���\n" NOR);
        me->set("get_mail_box", 1);
  
        return 1;    
}

int rebuild_data()
{
        object me = this_player();        
        string user, str;
        
        user = me->query("id");
        // ����ȡ�ʼ���ſ����޸�
        if (! present("mail box", me))
               return notify_fail("ë��˵���������������ȡһ���ʼ��䡣��\n");
        if (! me->query_temp("want_rebuild"))
        {
               write(HIR "ë��˵�������޸��ʼ��佫ɾ�������ʼ������������ݣ����ȷ��Ҫ"
                     "�޸���������һ�Ρ���\n" NOR);
               me->set_temp("want_rebuild", 1);

               return 1;
        }
        write("ë�ӵ��˵�ͷ˵�������ðɣ�����Ͱ����޸����ȵȡ����� \n");
                 
        str = "REFUSE={0}";
        write_file(SAVE_MAILF, str, 1);
        str = "\nSETTINGS={REPLY:0:MSG:0:no_name:0}=SETTING_END";
        str += "\nMAIL_TO_START={WHO_SEND_MAIL:�׻��ʼ�ϵͳ:MAIL_TOPIC:��ӭʹ����";
        str += "���ʼ�ϵͳ:SEND_TIME:" + ctime(time()) + ":MAIL_IS_NEW:1}";
        str += "\n{MAIL_TEXT:������" + me->query("name") + ":\n";
        str += "    ��ã��ǳ���ӭ��ʹ���׻��ʼ�ϵͳ���������ʼ��д����κ�";
        str += "���ࡢ�������ֲ�����������Ϣ���������뼰ʱ��ϵ�׻���ʦ��ϣ��";
        str += "���ʼ�ϵͳ�ܸ������������Ҳϣ�����ܹ���и��֧���׻ƣ�";
        str += "\n                   --�׻�Ӣ��ʷ http://heros-cn.51.net";
        str += "\n}=MAIL_TO_END";
        write_file(SAVE_MAILF, str, 0);        
        write("ë�Ӳ��˲�ͷ�ϵĺ�˵���������ˣ��Ѿ��޸��ˣ������ðɣ�\n");
        me->delete_temp("want_rebuild");
       
        return 1;
}      
