// zhangsan.c

#include <ansi.h>

inherit NPC;
int give_ling();

void create()
{
        set_name("����", ({ "zhang san", "zhang", "san" }));
        set("title", HIY "���͵�����ʹ��" NOR);
        set("gender", "����");
        set("age", 37);
        set("long",
              "���Ǹ���������ʮ����ĺ��ӣ���ķ��֣���ɫ����\n"
        );

        set("str", 36);
        set("int", 35);
        set("con", 34);
        set("dex", 37);

        set_temp("apply/attack", 600);
        set_temp("apply/armor", 1500);
        set_temp("apply/damage", 800);
        set_temp("apply/unarmed_damage", 800);
        set_temp("apply/dodge", 600);
        set_temp("apply/parry", 600);

        set("qi", 9000);
        set("max_qi", 9000);
        set("jing", 20000);
        set("max_jing", 20000);
        set("neili", 15000);
        set("max_neili", 15000);
        set("jiali", 250);
        set("combat_exp", 5000000);
        set("score", 20000000);

        set_skill("force", 340);
        set_skill("taixuan-gong", 340);
        set_skill("dodge", 340);
        set_skill("taixuan-gong", 340);
        set_skill("unarmed", 340);
        set_skill("taixuan-gong", 340);
        set_skill("parry", 340);

        map_skill("force", "taixuan-gong");
        map_skill("dodge", "taixuan-gong");
        map_skill("unarmed", "taixuan-gong");
        map_skill("parry", "taixuan-gong");

        set("chat_chance_combat", 120);
        set("chat_msg_combat", ({
                (: exert_function, "powerup" :),
                (: perform_action, "unarmed.xuan" :),
                (: perform_action, "unarmed.hun" :),
        }) );
        create_family("���͵�", 0, "����ʹ��");
        set("inquiry",  ([
            "���Ʒ�����" : (: give_ling :),
            "������"     : "�������Ʒ���������͵��Ϳ��Ժ������࣬��Ҳ��ȥ��\n",
        ]));

        set("lingpai", 3);

        setup();

        carry_object("/clone/misc/cloth")->wear();
}


void unconcious()
{
        die();
}

int give_ling()
{
        object ling;
        object me;

        me = this_player();
      
        if (me->query("shen") < -100000)
        {
             command("heng");
             command("say ����аħ������������������ȴ�����������ˣ�\n");
             kill_ob(me);
             return 1;
        }
        
        if (me->query_skill("force", 1) < 200)
        {
             command("say �����ڹ����ã����������㻹�ǺȲ��ã�\n");
             return 1;
        }  

        if (me->query("weiwang") < 100000)
        {
             command("say ���·ǽ���������ʿ��������ذɣ�");
             return 1;
        }
       
        if (me->query_skill("martial-cognize", 1) < 200)
        {
             command("say ������ѧ����ʵ�����ޣ����������㻹�ǲ���Ϊ�ã�\n");
             return 1;
        }  
       
        if (present("shangfa ling", me))
        {
             command("heng");
             command("say ����Ҳ̫̰���˰ɣ�");
             return 1;
        }

        if (query("lingpai") < 1)
        {
             command("shake"); 
             command("say ����ͷ�ϵ����Ʒ������Ѿ�ȫ�ͳ�ȥ�ˡ�");
             return 1;
        }
        command("nod");
        command("say ��ȥ�ɣ��ǵ������͵��������࣡");

        "/clone/lonely/shangfaling"->move(me);
        return 1;
}

void reset()
{
        set("lingpai", 3);
}




