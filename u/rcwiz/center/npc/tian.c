#include <ansi.h>

inherit NPC;

int give_card();

void create()
{
        set_name(HIG "С��" NOR, ({"xiao tian", "xiao", "tian"}));
        set("gender", "Ů��" );
        set("long", HIM "�����׻ƻ�Ա�������ĵĹ�����Ա����˵���������Ĺ�ϵ��ͬѰ����\n" NOR);
        set("title", HIY "�׻ƻ�Ա�������Ĺ���Ա" NOR);
        set("nickname", HIR "�����޷�" NOR); 
        set("age", 20);
        set("str", 99);
        set("con", 99);
        set("int", 99);
        set("dex", 99);
        set("per", 29);
        set("combat_exp", 650000);
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
                "�׻ƻ�Ա��" : (: give_card :),               
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

        carry_object(__DIR__"obj/qunzi")->wear();
}

int give_card()
{
        object me, hycard, ob;
        int rmb;

        me = this_player();
        rmb = me->query("rmb");

        // �Ѿ���Ϊ��Ա, ��Ƭ��ʧ����ȡ
        if (me->query("is_member"))
        {
              if (ob = present("huiyuan card", me)) 
              {
                     write(HIG "С��˵���������Ѿ���ȡ���׻ƻ�Ա�����벻Ҫ���⵷�ң���\n" NOR);
                     return 1;
              }
              // �ж��Ƿ��ڹ�ʧ
              if (! me->query("card_lost"))
              {
                     write(HIR "С��˵����������㿨Ƭ��ʧ�����ȵ��׻ƻ�Ա�������Ĵ�����ʧ����\n" NOR);
                     return 1;
              }

              write(HIW "С��˵�������Ժ�С�ı��ܣ������׻ƻ�Ա���ͽ��������ˣ�\n" NOR);
              hycard = new("/clone/gift/hycard");
              hycard->move(me);
              message_vision(HIC "$N" HIC "��С�촦��ȡһ��" HIY "�׻ƻ�Ա��" NOR "��\n" NOR,
                             me);
              me->delete("card_lost");
              return 1;            
        }

        // �ǻ�Ա
        else
        {
             if (me->query("rmb") < 50)
             {
                      write(HIR "С��˵�������Բ�����ע����ʽ��㣬�޷������Ա����\n" NOR);         
                      return 1;
             }

             write(NOR + CYN "С��˵�������ðɣ������ڿ�ʼ��ͳ�Ϊ�׻ƻ�Ա�ˣ�\n" NOR);
             write(NOR + CYN "С��˵���������Ż�Ա���ͽ������ˣ��Ժ������ػ�Ա������\n" NOR);
             message_vision(HIG + me->name() + HIG "��С�촦��ȡһ��" HIY "�׻ƻ�Ա��" NOR " ��\n" NOR,
                            me);
             hycard = new("/clone/gift/hycard");
             hycard->move(me);
             me->set("is_member", 1);
             CHANNEL_D->do_channel(this_object(), "ic", me->name() + "��ʽ�����׻ƻ�Ա��");
             return 1;       
        }
}
void unconcious()
{
        die();
}

