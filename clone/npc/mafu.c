// mafu.c ���

#include <ansi.h>
inherit NPC;

void create()
{
        set_name("���", ({ "ma fu", "mafu", "ma"}));
        set("age", 32);
        set("gender", "����");
        set("long", "�������ѱ���С��ƣ�ƽʱ����������ƥ��\n");
        set("attitude", "peaceful");
        set("str", 24);
        set("dex", 16);
        set("combat_exp", 50000);
        set("shen_type", 1);

        set("chat_chance",2);
        setup();
}

void init()
{
        object ob;

        ::init();
        if (interactive(ob = this_player()) && ! is_fighting())
        {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

void greeting(object ob)
{
        if (! ob || environment(ob) != environment())
                return;

        say(CYN "����ͷ������˵������λ�͹٣����ã�����ȥ�Ķ�����\n" NOR);
}

int accept_object(object who, object ob)
{
        if (ob->query("money_id"))
        {
                message_vision(CYN "$N" CYN "��$n" CYN "˵��������ȥ" NOR +
                               HIY "(goto)" NOR + CYN "�Ķ����ȸ���С���ٸ�"
                               "ǮҲ���١�\n" NOR, this_object(), who);
                return 0;
        }

        return 0;
}

