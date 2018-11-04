#include <ansi.h>

#include "matongdl.h"
#include "matongem.h"
#include "matongfs.h"
#include "matongfz.h"
#include "matonghz.h"
#include "matongsz.h"
#include "matongxy.h"
#include "matongyd.h"
#include "matongyl.h"
#include "matongyz.h"

inherit NPC;

int do_ride();

void create()
{
        set_name("��ͯ", ({ "ma tong", "matong", "ma", "tong" }));
        set("gender", "����");
        set("age", 12);
        set("long", "��Զ�ھֵ�Сͯ������С�ʹ�����书���ף��������¶��е㹦��\n");
        set("str", 24);
        set("dex", 16);
        set("combat_exp", 50000);
        set("shen_type", 1);

        set_skill("unarmed", 60);
        set_skill("dodge", 60);
        set_skill("parry", 60);
        set_skill("force", 60);
        set_temp("apply/attack", 40);
        set_temp("apply/defense", 40);
        set_temp("apply/armor", 30);
        set("chat_chance",2);

        setup();
        carry_object("/clone/misc/cloth")->wear();
}
   
void init()
{
        object ob;

        :: init();
        if (interactive(ob = this_player()) && ! is_fighting() )
        {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
        add_action("do_rideyz", "rideyz");
        add_action("do_ridesz", "ridesz");
        add_action("do_ridehz", "ridehz");
        add_action("do_ridefz", "ridefz");
        add_action("do_ridedl", "ridedl");
        add_action("do_rideyd", "rideyd");
        add_action("do_rideyl", "rideyl");
        add_action("do_ridefs", "ridefs");
        add_action("do_rideem", "rideem");
        add_action("do_ridexy", "ridexy");
}

void greeting(object ob)
{
        if (! ob || environment(ob) != environment() ) return;
        say (CYN "��ͯЦ�����ض���˵��������ô����Ҫ�����ȥ�����𣿡�\n" NOR);
}

int accept_object(object who, object ob)
{
        object myenv ;
        if (ob->query("money_id"))
        {
                message_vision(CYN "��ͯҡͷ�����������й涨�������ھ��ڵ���"
                               "������Ǯ�������ھֵĸ�ǮҲ���С���\n" NOR,
                               who);
                return 0;
        }
        else  
                message_vision(CYN "��ͯ��ü�������ⶫ���������Ը������Űɡ�"
                               "��\n" NOR, who);
        return 1;
}

void receive_damage(string type, int n)
{
        return;
}

void receive_wound(string type, int n)
{
        return;
}
