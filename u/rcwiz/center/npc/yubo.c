#include <ansi.h>

inherit NPC;

int guashi();

void create()
{
        set_name(HIW "�ನ" NOR, ({"yu bo", "yu", "bo"}));
        set("gender", "����" );
        set("long", HIC "���������е�󣬵�����ôҲ���������Ķ����ᡣ\n" NOR);
        set("title", HIY "�׻ƻ�Ա��������ӪҵԱ" NOR);
        set("nickname", HIW "�����" NOR);
        set("age", 22);
        set("str", 40);
        set("con", 40);
        set("int", 40);
        set("dex", 40);
        set("per", 1);
        set("combat_exp", 400000);
        set("attitude", "peaceful");

        set("max_qi", 8400);
        set("max_jing", 8400);
        set("neili", 8000);
        set("max_neili", 8000);
        set("jiali", 800);

        set_skill("force", 300);
        set_skill("jiuyang-shengong", 300);   
        set_skill("finger", 300);
        set_skill("liumai-shenjian", 300);  
        set_skill("dodge", 300);
        set_skill("lingbo-weibu", 300);
        set_skill("unarmed", 300);   
        set_skill("zuoyou-hubo", 300); 
        set_skill("parry", 300);
        set_skill("qiankun-danuoyi", 300);
        set_skill("martial-cognize", 300);

        map_skill("finger", "liumai-shenjian");
        map_skill("force", "jiuyang-shengong");
        map_skill("dodge", "liubo-weibu");
        map_skill("unarmed", "jiuyang-shengong");
        map_skill("parry", "qiankun-danuoyi");
      
        prepare_skill("finger", "liumai-shenjian");  
        prepare_skill("unarmed", "jiuyang-shengong");

        set("inquiry", ([
                "��ʧ" : (: guashi :),               
        ]));

        set("chat_chance_combat", 120);
                set("chat_msg_combat", ({
                (: perform_action, "sword.fei" :),
                (: perform_action, "force.ri" :),
                (: exert_function, "recover" :),
                (: exert_function, "powerup" :),
        }));

        set_temp("apply/damage", 200);
        set_temp("apply/unarmed_damage", 200);
        set_temp("apply/armor", 200);
        setup();

        carry_object(__DIR__"obj/zhifu")->wear();
}

int guashi()
{
        object me, hycard, ob, room;

        if (! room = find_object(__DIR__"dating"))
                room=load_object(__DIR__"dating");

        me = this_player();

        if (me->query("is_member"))
        {
              if (ob = present("huiyuan card", me)) 
              {
                     write(HIG "�ನŭ����������׻ƻ�Ա����û�ж�ʧ����Ҫ���⵷�ң���\n" NOR);
                     return 1;
              }

              if (me->query("card_lost"))
              {      
                     write(HIG "�ನŭ���������Ѿ���ʧ���ˣ���Ҫ���⵷�ң���\n" NOR);
                     return 1;                     
              }

              if (me->query("guashi") >= 3)
              {
                     write(HIG "�ನ�����㣺�����Ѿ���ʧ���������ˣ���Ҫ��ػ�Ա������������ʦ��ϵ����\n" NOR);
                     return 1;         
              }
              command("nod");
              write(HIC "�ನ˵���������ˣ����Ѿ��ɹ���ʧ�ˣ��������" HIG "С��" HIC 
                   "������ȡһ���׻ƻ�Ա������\n" NOR);
              write(HIG "���Ѿ��ɹ���ʧ��\n" NOR);

              me->set("card_lost", 1);
              me->add("guashi", 1);

              CHANNEL_D->do_channel(this_object(), "rumor", me->name() + "���׻ƻ�Ա���ѹ�ʧ�����"
                                   "�����ٽ���������ʦ��");
              return 1;            
        }

}

void unconcious()
{
        die();
}

