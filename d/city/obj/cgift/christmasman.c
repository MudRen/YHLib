// modify by rcwiz!

inherit NPC;

#include <ansi.h>

void init();

string give_gift();

void create()
{
	set_name(HIR "ʥ��" HIW "����" NOR, ({ "christmas man", "man", "lao ren" }) );
	set("gender", "����" );
	set("age", 65);
	set("long", HIM "ʥ�����˱���һ����ڴ���Ц�����ؿ����㣡\n" NOR);
	set("shen_type", -1);
	set("combat_exp", 10000);
	set("str", 80);
	set("dex", 82);
	set("con", 80);
	set("int", 81);

        set("max_qi", 30000);
        set("max_jing", 18000);
        set("neili", 32000);
        set("max_neili", 32000);
        set("jiali", 550);
        set("combat_exp", 15000000);
        set("score", 100000);

        set_skill("force", 600);
        set_skill("kuihua-mogong", 600);
        set_skill("dodge", 600);
        set_skill("unarmed", 600);
        set_skill("parry", 600);
        set_skill("literate", 600);
        set_skill("martial-cognize", 460);

        map_skill("force", "kuihua-mogong");
        map_skill("dodge", "kuihua-mogong");
        map_skill("unarmed", "kuihua-mogong");
        map_skill("parry", "kuihua-mogong");

        prepare_skill("unarmed", "kuihua-mogong");

        set("inquiry", ([
                "ʥ������" : (: give_gift :),
        ]));

        set("chat_chance_combat", 120);
        set("chat_msg_combat", ({
                (: perform_action, "unarmed.tian" :),
                (: perform_action, "unarmed.qiong" :),
                (: perform_action, "unarmed.bian" :),
                (: perform_action, "unarmed.sheng" :),
                (: exert_function, "recover" :),
                (: exert_function, "powerup" :),
                (: exert_function, "shield" :),
        }));

	set("attitude", "friendly");
	setup();

	carry_object(__DIR__"ccloth")->wear();

	add_money("silver", 3);
}

void init()
{
        command("say ʥ�����֣�Merry Christmas��");
}

string give_gift()
{
        object me;
        object gift;
        me = this_player();
    
        // �Ѿ���ȡ������
        if (me->query("get_christmas_gift/y2002"))
                 return HIR "ʥ��" HIW "����" HIR " Ц�����ض���˵������Merry Christmas����\n" NOR;
        
        // �Ѿ��Թ�����
        if (me->query("eat_christmas_gift/y2002"))
                 return HIR "ʥ��" HIW "����" HIR "Ц�����ض���˵������Merry Christmas����\n" NOR;

        // ��������
        message_vision(HIY "ʥ������Ц�����ض�$N˵������Merry Christmas����\n" NOR, me);
        command("smile");
        command("say �����Ҹ������������ȵȣ�");
        message_vision(HIY "ʥ�����˽����ϵĴ�ڴ����ڵط���������ȥ����\n", me);
        command("haha");
        command("say ���ˣ�����������ɣ�");
        message_vision(HIY "ʥ�����˽������$N" HIY "\n", me);        
        tell_object(me, HIG "��õ���һ������쿴���ɣ�\n");
        
        switch(random(5))
        {
             case 1 :
                  gift = new(__DIR__"jitui");
                  gift->move(me);

             case 2 :
                  gift = new(__DIR__"hanbao");
                  gift->move(me);
 
             case 3 :                  
                  gift = new(__DIR__"dabing");
                  gift->move(me);

             default :
                  gift = new(__DIR__"chang");
                  gift->move(me);

        }        
        me->set("get_christmas_gift/y2002", 1);
        return "Bye��\n";
          
}


