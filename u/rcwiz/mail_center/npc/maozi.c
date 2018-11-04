
#include <ansi.h>

inherit NPC;

#define SAVE_MAILF "/u/rcwiz/mail_center/to_user_mails/" + user + ".m"

int rebuild_data();
mixed register_mail();

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
                "�޸�����" : (: rebuild_data :),
                "ע��"     : (: register_mail :),
        ]));

        setup();

        carry_object("/clone/cloth/cloth")->wear();
        
}

mixed register_mail()
{
        object me = this_player();
        string user, str;

        if (! me->query("register_heromail"))
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
        else
        {
              write("���Ѿ�ע����ˣ�\n");
              return 1;
        }

        write("Register OK!\n");
        if (! me->query("register_heromail"))
              write(HIW "����ʼ�������һ�����ʼ���\n" NOR);
        me->set("register_heromail", 1);
  
        return 1;    
}

int rebuild_data()
{
        object me = this_player();        
        string user, str;
        
        user = me->query("id");
        // ע����ſ����޸�
        if (! me->query("register_heromail"))
               return notify_fail("ë��˵�����������ע���ȡ���\n");

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


