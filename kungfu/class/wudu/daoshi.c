#include <ansi.h>
#include "wudu.h"

inherit NPC;
inherit F_MASTER;
inherit F_DEALER;

mixed ask_me();

void create()
{
        set_name("�η�����", ({ "dao ren", "dao", "daoren" }) );
        set("gender", "����" );
        set("age", 34);
        set("long", "һ���׾����ֵĵ�ʿ����˭��Ц���еģ�����\n"
                    "�е�Ʒ��һ����衣\n");
        set("max_qi", 1800);
        set("max_jing", 1000);
        set("max_neili", 2000);
        set("neili", 2000);
        set("jiali", 50);
        set("combat_exp", 200000);
        set("attitude", "friendly");

        set_skill("force", 80);
        set_skill("wudu-xinfa", 80);
        set_skill("dodge", 80);
        set_skill("jinshe-youshenbu", 80);
        set_skill("strike", 80);
        set_skill("tianchan-zhang", 80);
        set_skill("claw", 80);
        set_skill("wusheng-zhao", 80);
        set_skill("parry", 80);
        set_skill("literate", 50);
        set_skill("poison", 80);
        set_skill("wudu-qishu", 80 );
        set_skill("martial-cognize", 60);

        map_skill("force", "wudu-xinfa");
        map_skill("dodge", "jinshe-youshenbu");
        map_skill("strike", "tianchan-zhang");
        map_skill("claw", "wusheng-zhao");
        map_skill("parry", "wusheng-zhao");
        map_skill("poison", "wudu-qishu");

        prepare_skill("strike", "tianchan-zhang");
        prepare_skill("claw", "wusheng-zhao");

        set("inquiry", ([
                "�嶾��"  : (: ask_me :),
                "��ȥ"    : (: ask_me :),
                "�ؽ�"    : (: ask_me :),
                "���嶾��": (: ask_me :),
        ]) );

        create_family("�嶾��", 13, "��������");

        set("vendor_goods", ([
               "/d/wudu/obj/jiedudan" : 300000,
        ]));

        setup();
        set("startroom", "/d/wudu/neijin");
        carry_object("/clone/misc/cloth")->wear();
        add_money("silver", 30);
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
        add_action("do_list", "list");
        add_action("do_buy", "buy");
}

void greeting(object ob)
{
        if (! ob || environment(ob) != environment() ) return;
        switch(random(3))
	{
	case 0:
        	say(CYN "�η����˺ٺ�һ���Ц������λ" + RANK_D->query_respect(ob) +
                    CYN "��Ҳ����ס�����\n" NOR);
                break;
        case 1:
                say(CYN "�η����˵��˵��ֵ�����λ" + RANK_D->query_respect(ob) +
                    CYN "���������������Ҫȥ�ǰ���\n" NOR);
                break;
        case 2:
                say(CYN "�η��������־���֮ɫ������λ" + RANK_D->query_respect(ob) +
                    CYN "ü�ֺ��������ջ��д��ѡ�\n�η����˼���˵����ƶ����һЩ����"
                    "������������㣬����ɾ���һ����\n" NOR);
                break;
        }
}

void attempt_apprentice(object ob)
{
        if (! permit_recruit(ob))
                return;

        if ((int)ob->query("shen") > -1000)
        {
                command("say �ҽ̵��ӹ�����������������α���ӡ�");
                return;
        }
        command("recruit " + ob->query("id"));
        ob->set("title", "�嶾�̽���");
        return;
}

mixed ask_me()
{
        object ob, me;
        me = this_player();

        if ((string)me->query("family/family_name") != "�嶾��")
                return "���ү�ģ���������µ�����˵ɶ�ӣ�";

        if (find_object(query("startroom")) != environment())
                return "�����ﻹ���£�����Լ��߻�ȥ�ɡ�";

        command("say ��λ"+ RANK_D->query_respect(me) + "�������ã�����"
                "������Ҫ��ɽ���£�������������һ�̰ɡ�\n");

        message_vision(HIC "�η�����һ���֣�һ����ʻ����ͣ����ǰ��\n$N"
                       HIC "��æ������У�ֻ��һ�����ı��죬��������"
                       "ȥ��\n\n" NOR, me);

        ob = load_object("/d/wudu/damen");
        ob = find_object("/d/wudu/damen");

        message("vision", HIC "\nԶ��һ������ʻ����������һ��" +
                          me->query("name") + HIC "���������˳���"
                          "��\n\n" NOR, environment(me), ({me}));

        me->move("/d/wudu/damen");
        tell_object(me, CYN "\n������˵������λ" + RANK_D->query_respect(me) +
                        CYN "�Ѿ����ˣ����³��ɡ�\n\n" NOR);
        return 1;

}

