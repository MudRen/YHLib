// yuenv.c ԽŮ

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

mixed teach_me();

void create()
{
        set_name("ԽŮ", ({ "yue nv", "yuenv" }));
        set("long", @LONG
��һһλ���������Ů�����Ϲ���һ˿�����䲻��Ƶİ�˼��
LONG );
        set("gender", "Ů��");
        set("class", "swordsman");
        set("age", 18);
        set("attitude", "friendly");
        set("per", 29);
        set("str", 19);
        set("int", 35);
        set("con", 32);
        set("dex", 35);
        
        set("max_qi", 5000);
        set("max_jing", 2500);
        set("neili", 5000);
        set("max_neili", 5000);
        set("jiali", 50);
        set("combat_exp", 2500000);

        set_skill("force", 250);
        set_skill("dodge", 270);
        set_skill("parry", 270);
        set_skill("sword", 270);
        set_skill("yunv-xinfa", 250);
        set_skill("yuenv-jian", 270);
        set_skill("feiyan-huixiang", 250);

        map_skill("dodge", "feiyan-huixiang");
        map_skill("force", "yunv-xinfa");
        map_skill("sword", "yuenv-jian");

        set("inquiry", ([
                "ԽŮ����" : (: teach_me : ),
        ]));

        set("chat_chance_combat", 120);
        set("chat_msg_combat", ({
                (: exert_function, "powerup" :),
                (: perform_action, "sword.xin" :),
        }));

        setup();
        carry_object("/clone/cloth/cloth")->wear();
        carry_object("/clone/weapon/zhujian")->wield();
}

mixed teach_me()
{
        object me;

        me = this_player();

        if (me->query("gender") != "Ů��")
        {
                command("say �⽣��ֻ�ʺ�Ů���������㻹�����˰ɣ�");
                return 1;
        }

        if (me->query_skill("yuenv-jian, 1") >= 1)
        {
                command("say �㲻���Ѿ������𣿻������Ҹ�ʲô��");
                return 1;
        }

        if (me->query("dex") < 36)
        {
                command("shake");
                command("say ���������������޷�����ԽŮ������");
                return 1;
        }

        if (me->query_skill("dodge") < 270)
        {
                command("say ���Ṧ����㣬�޷�����ԽŮ������");
                return 1;
        }

        command("say �����Ǻðɣ��Ҿͽ���ԽŮ������");

        me->set_skill("yuenv-jian", 10);

        tell_object(me, HIG "��ѧ����ԽŮ������\n" NOR);

        command("say ��ȥ�ú���ϰ�ɡ�");
  
        return 1;    
    
}

int accept_ask(object me, string topic)
{
     switch (topic)
     {
        case "��������" :
                return MASTER_D->teach_pfm(me, this_object(),
                        ([ "perform" : "can_perform/yuenv-jian/xin",
                           "free"    : 1,
                           "name"    : "��������",
                           "sk1"     : "yuenv-jian",
                           "lv1"     : 140,
                           "neili"   : 2800,
                        ]));
                break;

        default : 
                return 0;

      }
        
}

void unconcious()
{
        die();
}
